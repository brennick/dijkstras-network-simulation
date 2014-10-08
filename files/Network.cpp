#include "Network.h"


Network::Network()
{
    _tick_count = 0;
}
void Network::addNode(int node_id)
{
    _graph.addNode(node_id);
}
void Network::addEdge(int start_id, int end_id, int weight)
{
    _graph.addEdge(start_id, end_id, weight);
}
void Network::addMessage(string message, int start_id, int end_id)
{
    _message = Message(message, _graph.getNode(start_id), _graph.getNode(end_id));
}
Path* Network::computeShortestPath(int start_id, int end_id)
{
    return _graph.computeShortestPath(start_id, end_id);
}
void Network::createGraph(ifstream &input_file)
{
    string line;
    int items_found = 0;
    while (input_file.good() == true)
    {
        getline(input_file, line);
        string *pieces = StringSplitter::split(line, " ", items_found);
        if (items_found == 1)
        {
            addNode(stoi(pieces[0]));
        }
        
        else if (items_found == 3)
        {
            addEdge(stoi(pieces[0]), stoi(pieces[1]), stoi(pieces[2]));
        }
        
        else
        {
            exit(0);
        }
    }
}
void Network::tick()
{
    _tick_count++;
    if (_message.isEmpty() == false)
    {
        Packet *packet = _message.getNextPacket();
        Path *path = computeShortestPath(packet->getPreviousLocation()->getId(), packet->getDestination()->getId());
        stack<Node *> path_stack = path->getPathQueue();
        Node *previous = path_stack.top();
        path_stack.pop();
        Node *next = path_stack.top();
        path_stack.pop();
        packet->setPreviousLocation(previous);
        packet->setNextLocation(next);
        packet->setStartTime(_tick_count);
        packet->setCurrentWait(_graph.getNode(previous->getId())->getWeight(next) * next->getLoadFactor());
        packet->addVisitedNode(previous);
        previous->increaseLoadFactor();
        next->increaseLoadFactor();
        _packets[packet->getOrder()] = packet;
        cout << "Sending packet " << packet->getValue() << " to vertex " << packet->getNextLocation()->getId() <<
        " with a wait of " << packet->getCurrentWait() << " at time " << _tick_count << endl;
        
    }
    
    for (unordered_map<int, Packet *>::iterator it = _packets.begin(); it != _packets.end(); it++)
    {
        bool finished = it->second->tick();
        if (finished == true)
        {
            if (it->second->getDestination() != it->second->getNextLocation())
            {
                it->second->getPreviousLocation()->decreaseLoadFactor();
                it->second->getNextLocation()->decreaseLoadFactor();
                Path *path = computeShortestPath(it->second->getNextLocation()->getId(), it->second->getDestination()->getId());
                stack<Node *> path_stack = path->getPathQueue();
                it->second->addVisitedNode(it->second->getNextLocation());
                Node *previous = path_stack.top();
                path_stack.pop();
                Node *next = path_stack.top();
                path_stack.pop();
                it->second->setPreviousLocation(previous);
                it->second->setNextLocation(next);
                it->second->setCurrentWait(_graph.getNode(previous->getId())->getWeight(next) * next->getLoadFactor());
                previous->increaseLoadFactor();
                next->increaseLoadFactor();
                cout << "Sending packet " << it->second->getValue() << " to vertex " << it->second->getNextLocation()->getId() <<
                " with a wait of " << it->second->getCurrentWait() << " at time " << _tick_count << endl;
            }
            
            else if (_delivered[it->second->getOrder()] == nullptr)
            {
                it->second->addVisitedNode(it->second->getNextLocation());
                it->second->getPreviousLocation()->decreaseLoadFactor();
                it->second->getNextLocation()->decreaseLoadFactor();
                _delivered[it->second->getOrder()] = it->second;
            }
        }
    }
}
bool Network::isRunning() const
{
    if (_delivered.size() == _message.getSize())
    {
        return false;
    }
    else
    {
        return true;
    }
}
void Network::displayResults()
{
    cout << "Packet - Arrival Time - Route" << endl;
    for (int index = 0; index < _message.getSize(); index++)
    {
        cout << _delivered[index]->getValue() << setw(10) << _delivered[index]->getArrivalTime() << setw(14);
        queue<Node *> visited = _delivered[index]->getVisitedNodes();
        while (visited.empty() == false)
        {
            cout << visited.front()->getId();
            if (visited.size() > 1)
            {
                cout << ", ";
                visited.pop();
            }
            else
            {
                cout << endl;
                visited.pop();
            }
        }
    }
}