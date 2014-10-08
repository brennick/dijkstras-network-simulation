#ifndef NODE_H
#define NODE_H

#include <unordered_map>

using namespace std;

class Node
{
private:
    int _id;
    int _load_factor;
    unordered_map<Node *, int> _edges;
public:
    Node(int id);
    int getId() const;
    int getLoadFactor() const;
    int getWeight(Node *node);
    void increaseLoadFactor();
    void decreaseLoadFactor();
    void addEdge(Node *node, int weight);
    unordered_map<Node *, int> getEdges();
};

#endif