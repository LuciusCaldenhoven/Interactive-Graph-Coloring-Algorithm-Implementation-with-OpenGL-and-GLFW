#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <map>

// Node structure
struct Node {
    std::string color;
    std::vector<std::string> neighbors;
};

typedef std::map<std::string, Node> Graph;

// Functions to initialize graphs
void initializeGraph1(Graph& graph);
void initializeGraph2(Graph& graph);

// Heuristic and validation functions
bool isValid(const Graph &graph, const std::string &node, const std::string &color);
std::string selectNextNode(Graph &graph, int heuristic);
bool allColored(const Graph &graph);

#endif 
