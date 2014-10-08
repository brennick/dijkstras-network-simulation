#include "Node.h"

Node::Node(int id)
{
    _id = id;
    _load_factor = 1;
}
int Node::getId() const
{
    return _id;
}
int Node::getLoadFactor() const
{
    return _load_factor;
}
int Node::getWeight(Node *node)
{
    return _edges[node];
}
void Node::increaseLoadFactor()
{
    _load_factor++;
}
void Node::decreaseLoadFactor()
{
    _load_factor--;
}
void Node::addEdge(Node *node, int weight)
{
    _edges[node] = weight;
}
unordered_map<Node *, int> Node::getEdges()
{
    return _edges;
}