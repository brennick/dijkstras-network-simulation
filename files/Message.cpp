#include "Message.h"

Message::Message()
{
    _starting_node = nullptr;
    _ending_node = nullptr;
    _size = 0;
}
Message::Message(string message, Node *starting_node, Node *ending_node)
{
    _starting_node = starting_node;
    _ending_node = ending_node;
    for (int index = 0; index < message.length(); index++)
    {
        _packets.push(new Packet(message[index], index, ending_node, starting_node));
    }
    _size = _packets.size();
}
bool Message::isEmpty() const
{
    return _packets.empty();
}
Packet* Message::getNextPacket()
{
    Packet *packet = _packets.front();
    _packets.pop();
    return packet;
}
int Message::getSize() const
{
    return _size;
}