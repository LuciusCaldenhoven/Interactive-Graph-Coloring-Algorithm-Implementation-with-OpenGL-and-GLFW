#include "graph.h"
#include <algorithm>
#include <limits>

// Initialize Graph 1
void initializeGraph1(Graph& graph) {
    graph["A"] = {"", {"D", "E", "B"}};
    graph["B"] = {"", {"A", "C"}};
    graph["C"] = {"", {"D", "E", "B"}};
    graph["D"] = {"", {"A", "C", "E"}};
    graph["E"] = {"", {"A", "D", "C"}};
}

// Initialize Graph 2
void initializeGraph2(Graph& graph) {
    graph["A"] = {"", {"B", "D"}};
    graph["B"] = {"", {"A", "G", "C"}};
    graph["C"] = {"", {"B", "D", "F"}};
    graph["D"] = {"", {"A", "C", "F", "E"}};
    graph["E"] = {"", {"D", "F", "G"}};
    graph["F"] = {"", {"D", "C", "E", "G"}};
    graph["G"] = {"", {"F", "B", "E"}};
}

// Check if the color assignment is valid
bool isValid(const Graph &graph, const std::string &node, const std::string &color) {
    for (const auto &neighbor : graph.at(node).neighbors) {
        if (graph.at(neighbor).color == color) {
            return false;
        }
    }
    return true;
}

// Select the next node based on heuristic
std::string selectNextNode(Graph &graph, int heuristic) {
    std::string selectedNode;
    int minAvailableColors = std::numeric_limits<int>::max();
    int maxDegree = -1;

    for (auto& node : graph) {
        if (!node.second.color.empty()) continue;
        std::vector<std::string> availableColors = {"red", "green", "yellow"};
        for (const auto& neighbor : node.second.neighbors) {
            availableColors.erase(
                std::remove(availableColors.begin(), availableColors.end(), graph[neighbor].color),
                availableColors.end());
        }

        int degree = node.second.neighbors.size();
        if (heuristic == 1 && availableColors.size() < minAvailableColors) {
            minAvailableColors = availableColors.size();
            selectedNode = node.first;
        }
        if (heuristic == 2 && degree > maxDegree) {
            maxDegree = degree;
            selectedNode = node.first;
        }
    }

    return selectedNode;
}

// Check if all nodes are colored
bool allColored(const Graph &graph) {
    for (const auto &node : graph) {
        if (node.second.color.empty()) {
            return false;
        }
    }
    return true;
}
