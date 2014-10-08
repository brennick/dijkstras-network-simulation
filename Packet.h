#ifndef PACKET_H
#define PACKET_H

#include "Node.h"
#include <queue>

using namespace std;

class Packet
{
private:
    char _value;
    int _order;
    int _current_wait;
    int _arrival_time;
    Node *_destination;
    Node *_previous_location;
    Node *_next_location;
    queue<Node *> _visited_nodes;
public:
    Packet(char value, int order, Node *destination, Node *start_location);
    char getValue() const;
    int getOrder() const;
    int getCurrentWait() const;
    Node *getDestination() const;
    Node *getPreviousLocation() const;
    Node *getNextLocation() const;
    int getArrivalTime() const;
    void setPreviousLocation(Node *node);
    void setNextLocation(Node *node);
    void setCurrentWait(int wait);
    void setStartTime(int start);
    bool tick();
    void addVisitedNode(Node *node);
    queue<Node *> getVisitedNodes();
};

#endif