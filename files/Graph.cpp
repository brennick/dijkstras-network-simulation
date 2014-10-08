#include "Graph.h"

void Graph::addNode(int node_id)
{
    _nodes[node_id] = new Node(node_id);
}
void Graph::addEdge(int start_id, int end_id, int weight)
{
    _nodes[start_id]->addEdge(_nodes[end_id], weight);
}
Node* Graph::getNode(int node_id)
{
    return _nodes[node_id];
}
Path* Graph::computeShortestPath(int start_id, int end_id)
{
    unordered_map<int, Path *> finished;
    priority_queue<Path *, vector<Path *>, PathCompare> working_nodes;
    Node *current_node = _nodes[start_id];
    working_nodes.push(new Path(current_node));
    while (working_nodes.empty() == false)
    {
        Path *path = working_nodes.top();
        working_nodes.pop();
        current_node = path->getTopNode();
        unordered_map<Node *, int> edges = current_node->getEdges();
        for (unordered_map<Node *, int>::iterator it = edges.begin(); it != edges.end(); it++)
        {
            unordered_map<int, Path*>::const_iterator cit = finished.find(it->first->getId());
            //if (finished[it->first->getId()] == nullptr)
            if (cit == finished.end())
            {
                Path *new_path = new Path(path->getPath(), path->getDistance());
                new_path->addNodeToPath(new_path->getTopNode(), it->first);
                working_nodes.push(new_path);
            }
        }
        
        if (finished[current_node->getId()] == nullptr)
        {
            finished[current_node->getId()] = path;
        }
            
        if (path->getDistance() < finished[current_node->getId()]->getDistance())
        {
            finished[current_node->getId()] = path;
        }
            
        if (finished.size() == _nodes.size())
        {
            break;
        }
    }
        
    return finished[end_id];
}