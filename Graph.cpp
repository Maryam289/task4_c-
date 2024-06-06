#include "Graph.h"
#include <fstream>
#include <sstream>
#include <queue>

Graph::Graph(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open the file: " + filename);
    }

    int vertexCount;
    file >> vertexCount;
    adjacencyList.resize(vertexCount + 1); // Вершины от 1 до n

    int vertex;
    while (file >> vertex) {
        std::string line;
        std::getline(file, line);
        std::istringstream iss(line);
        int adjacentVertex;
        while (iss >> adjacentVertex) {
            adjacencyList[vertex].push_back(adjacentVertex);
        }
    }
    file.close();
}

void Graph::findConnectedComponents(std::vector<std::vector<int>>& components) {
    std::vector<bool> visited(adjacencyList.size(), false);
    for (size_t i = 1; i < adjacencyList.size(); ++i) {
        if (!visited[i]) {
            std::vector<int> component;
            bfs(i, visited, component);
            components.push_back(component);
        }
    }
}

void Graph::bfs(int startVertex, std::vector<bool>& visited, std::vector<int>& component) {
    std::queue<int> q;
    q.push(startVertex);
    visited[startVertex] = true;
    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        component.push_back(vertex);
        for (int neighbor : adjacencyList[vertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
