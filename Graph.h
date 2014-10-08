#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"
#include "Path.h"

#include <queue>

using namespace std;

class Graph
{
private:
    unordered_map<int, Node *> _nodes;
public:
    void addNode(int node_id);
    void addEdge(int start_id, int end_id, int weight);
    Node *getNode(int node_id);
    Path *computeShortestPath(int start_id, int end_id);
};

#endif