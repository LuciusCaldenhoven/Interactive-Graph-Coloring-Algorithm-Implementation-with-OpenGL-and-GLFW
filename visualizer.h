#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <GLFW/glfw3.h>
#include <string>
#include <map>
#include "graph.h"


void drawNode(float x, float y, const std::string& name, const std::string& color);
void drawEdges(const Graph& graph, std::map<std::string, std::pair<float, float>>& positions);
void renderAndWait(const Graph& graph, GLFWwindow* window, std::map<std::string, std::pair<float, float>>& positions, int delay);
bool colorNode(Graph& graph, const std::string& node, const std::vector<std::string>& colors, int heuristic, GLFWwindow* window, std::map<std::string, std::pair<float, float>>& positions, int delay);

#endif 
