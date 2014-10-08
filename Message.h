#ifndef MESSAGE_H
#define MESSAGE_H

#include <queue>
#include <string>
#include "Packet.h"
#include "Node.h"

using namespace std;

class Message
{
private:
    queue<Packet *> _packets;
    Node *_starting_node;
    Node *_ending_node;
    int _size;
public:
    Message();
    Message(string message, Node *starting_node, Node *ending_node);
    bool isEmpty() const;
    Packet *getNextPacket();
    int getSize() const;
};

#endif
