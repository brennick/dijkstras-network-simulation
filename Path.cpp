#include "Path.h"

Path::Path()
{
    _distance_traveled = 0;
}
Path::Path(Node *node)
{
    _node_path.push(node);
    _distance_traveled = 0;
}
Path::Path(stack<Node *> previous_path, int distance)
{
    _node_path = previous_path;
    _distance_traveled = distance;
}
void Path::addNodeToPath(Node *start_node, Node *end_node)
{
    _node_path.push(end_node);
    _distance_traveled += start_node->getWeight(end_node) * end_node->getLoadFactor();
}
Node* Path::getTopNode()
{
    return _node_path.top();
}
void Path::dequeuePath()
{
    _node_path.pop();
}
bool Path::isEmpty() const
{
    return _node_path.empty();
}
int Path::getDistance() const
{
    return _distance_traveled;
}
stack<Node *> Path::getPath() const
{
    return _node_path;
}
stack<Node *> Path::getPathQueue()
{
    stack<Node *> queue;
    while (_node_path.empty() == false)
    {
        Node *node = _node_path.top();
        queue.push(node);
        _node_path.pop();
    }
    return queue;
}