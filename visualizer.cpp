#include "visualizer.h"
#include <thread>
#include <chrono>

// Draw a node
void drawNode(float x, float y, const std::string& name, const std::string& color) {
    int num_segments = 20;
    float radius = 0.05;

    glColor3f(1.0, 1.0, 1.0); // Default to white
    if (color == "red") glColor3f(1.0, 0.0, 0.0);
    else if (color == "green") glColor3f(0.0, 1.0, 0.0);
    else if (color == "yellow") glColor3f(1.0, 1.0, 0.0);

    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float cx = radius * cosf(theta);
        float cy = radius * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

// Draw edges
void drawEdges(const Graph& graph, std::map<std::string, std::pair<float, float>>& positions) {
    glColor3f(0.5, 0.5, 0.5); // Gray color
    for (const auto& node : graph) {
        auto origin = positions[node.first];
        for (const auto& neighbor : node.second.neighbors) {
            auto destination = positions[neighbor];
            glBegin(GL_LINES);
            glVertex2f(origin.first, origin.second);
            glVertex2f(destination.first, destination.second);
            glEnd();
        }
    }
}

// Render and wait
void renderAndWait(const Graph& graph, GLFWwindow* window, std::map<std::string, std::pair<float, float>>& positions, int delay) {
    glClear(GL_COLOR_BUFFER_BIT);

    for (const auto& node : graph) {
        auto pos = positions[node.first];
        drawNode(pos.first, pos.second, node.first, node.second.color);
    }

    drawEdges(graph, positions);

    glfwSwapBuffers(window);
    glfwPollEvents();
    std::this_thread::sleep_for(std::chrono::seconds(delay));
}

// Color a node with backtracking
bool colorNode(Graph& graph, const std::string& node, const std::vector<std::string>& colors, int heuristic, GLFWwindow* window, std::map<std::string, std::pair<float, float>>& positions, int delay) {
    if (node.empty()) {
        return allColored(graph);
    }

    for (const auto& color : colors) {
        if (isValid(graph, node, color)) {
            graph[node].color = color;
            renderAndWait(graph, window, positions, delay);
            std::string nextNode = selectNextNode(graph, heuristic);
            if (colorNode(graph, nextNode, colors, heuristic, window, positions, delay)) {
                return true;
            }
            graph[node].color = ""; // backtrack
        }
    }
    return false;
}
