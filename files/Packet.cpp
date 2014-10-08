#include "Packet.h"

Packet::Packet(char value, int order, Node *destination, Node *start_location)
{
    _value = value;
    _order = order;
    _current_wait = -1; // Means not in the network yet
    _arrival_time = 0;
    _destination = destination;
    _previous_location = start_location;
    _next_location = nullptr;
}
char Packet::getValue() const
{
    return _value;
}
int Packet::getOrder() const
{
    return _order;
}
int Packet::getCurrentWait() const
{
    return _current_wait;
}
Node* Packet::getDestination() const
{
    return _destination;
}
Node* Packet::getPreviousLocation() const
{
    return _previous_location;
}
Node* Packet::getNextLocation() const
{
    return _next_location;
}
int Packet::getArrivalTime() const
{
    return _arrival_time;
}
void Packet::setPreviousLocation(Node *node)
{
    _previous_location = node;
}
void Packet::setNextLocation(Node *node)
{
    _next_location = node;
}
void Packet::setCurrentWait(int wait)
{
    _current_wait = wait;
    _arrival_time += wait;
}
void Packet::setStartTime(int start)
{
    _arrival_time = start;
}
bool Packet::tick()
{
    if (_current_wait > 0)
    {
        _current_wait--;
        return false;
    }
    
    else if (_current_wait == 0)
    {
        return true;
    }
    
    else
    {
        return true;
    }
}
void Packet::addVisitedNode(Node *node)
{
    _visited_nodes.push(node);
}
queue<Node *> Packet::getVisitedNodes()
{
    return _visited_nodes;
}