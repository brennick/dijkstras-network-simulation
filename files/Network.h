#ifndef NETWORK_H
#define NETWORK_H

#include <iomanip>
#include <fstream>
#include <iostream>
#include "Graph.h"
#include "Message.h"
#include "StringSplitter.h"

using namespace std;

class Network
{
private:
    Graph _graph;
    int _tick_count;
    Message _message;
    unordered_map<int, Packet *> _packets;
    unordered_map<int, Packet *> _delivered;
public:
    Network();
    void addNode(int node_id);
    void addEdge(int start_id, int end_id, int weight);
    void addMessage(string message, int start_id, int end_id);
    Path *computeShortestPath(int start_id, int end_id);
    void createGraph(ifstream &input_file);
    void tick();
    bool isRunning() const;
    void displayResults();
};

#endif
