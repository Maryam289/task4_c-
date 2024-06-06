#include "Graph.h"
#include <iostream>
#include <fstream>
#include <vector>

int main() {
    try {
        Graph graph("graph.txt");
        std::vector<std::vector<int>> components;
        graph.findConnectedComponents(components);

        std::ofstream outputFile("components.txt");
        if (!outputFile.is_open()) {
            throw std::runtime_error("Failed to open the file: components.txt");
        }

        for (const auto& component : components) {
            for (int vertex : component) {
                outputFile << vertex << " ";
            }
            outputFile << std::endl;
        }
        outputFile.close();
        std::cout << "Components written to file successfully" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
    return 0;
}
