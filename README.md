Dijkstras-Network-Simulation
=============================

A simulation involving Dijkstra's alogorithm for path-finding and sending packets or messages over a network.

Building
========

To build this project, clone the repo and run `make` inside the directory.

Running
=======

To run, first build the simulation and then run `./NetworkSim`. Use `ExampleGraph.txt` and vertex 1 as the start vertex and 3 as the end vertex, supplying your own message. The program will send the message as fast as possible using Dijkstra's algorithm and record what tick interval each packet (character) arrives at the end vertex.

Creating Your Own Graph
=======================

The graph format first starts out with listing each vertex's id on a single line. For instance, to initialize vertexes 1, 2, 3 and 5, you would start with:
```
1
2
3
5
```
Then, supply the edges in the following format (start, end, weight). For example, to create an edge between 1 and 3 with weight 4 and also an edge between 3 and 5 with weight 8, you would then put in:
```
1 3 4
3 5 8
```

Note: Edges are one-way direction, so to make a bidirection edge of weight 4 between 1 and 3, you would need to supply:
```
1 3 4
3 1 4
```

Information About the Project
=============================

This assignment was used for a final project for a class involving Advanced Data Structures. It has been posted with permission from the professor.

Future Possibilities
====================
- Clean up code
- Rewrite in C#
