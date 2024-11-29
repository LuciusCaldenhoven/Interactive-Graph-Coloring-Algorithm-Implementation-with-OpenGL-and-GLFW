# Graph Coloring Visualization

This project visualizes the process of **graph coloring** using C++, OpenGL, and GLFW. The program dynamically assigns colors to graph nodes based on specific constraints and demonstrates this process step-by-step with a delay between each action.

---

## Features

### 1. **Graph Coloring with Backtracking**
- Ensures that adjacent nodes do not share the same color, following graph coloring rules.
- Uses a **backtracking algorithm** to explore and resolve conflicts in color assignments.

### 2. **Two Heuristic Options**
Users can select between two heuristic options to determine the order of node coloring:
- **Option 1:** Selects the node with the fewest available colors first (most constrained heuristic).
- **Option 2:** Selects the node with the highest degree of connections (most restrictive heuristic).

### 3. **Dynamic Visualization**
- Nodes are colored sequentially with a configurable delay (default: 1.5 seconds) between steps.
- Automatically restarts the coloring process after completion, creating a continuous animation.

### 4. **Interactive Input**
- Users can choose between two predefined graphs:
  - **Graph 1:** A smaller graph with five nodes.
  - **Graph 2:** A larger graph with seven nodes.
- Users select the heuristic for node ordering at runtime.

---

## Technologies Used
- **C++:** Core programming language for implementing the graph and backtracking algorithms.
- **OpenGL:** For rendering nodes (as circles) and edges (as lines) on a 2D plane.
- **GLFW:** For handling window creation, user input, and managing OpenGL contexts.
- **Standard Libraries:**
  - `<map>` and `<vector>` for graph representation.
  - `<thread>` and `<chrono>` for handling animation delays.

---
## DEMO
- Below is an example using Graph 2 with the most constrained heuristic:
![Graph Coloring Demo](GIF.gif)
