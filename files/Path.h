#ifndef PATH_H
#define PATH_H

#include "Node.h"

#include <stack>

using namespace std;

class Path
{
private:
    stack<Node *> _node_path;
    int _distance_traveled;
public:
    Path();
    Path(Node *node);
    Path(stack<Node *> previous_path, int distance);
    void addNodeToPath(Node *start_node, Node *end_node);
    Node *getTopNode();
    void dequeuePath();
    bool isEmpty() const;
    int getDistance() const;
    stack<Node *> getPath() const;
    stack<Node *> getPathQueue();
};

struct PathCompare
{
    bool operator()(const Path *path1, const Path *path2) const
    {
        return path1->getDistance() > path2->getDistance();
    }
};

#endif