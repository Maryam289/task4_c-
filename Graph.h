#pragma once
#include <vector>
#include <list>
#include <string>

class Graph {
public:
    Graph(const std::string& filename);
    void findConnectedComponents(std::vector<std::vector<int>>& components);

private:
    std::vector<std::list<int>> adjacencyList;
    void bfs(int startVertex, std::vector<bool>& visited, std::vector<int>& component);
};
