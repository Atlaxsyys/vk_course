#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <limits>
#include "algorithms.hpp"

template<typename K, typename V>
void printMap(const std::map<K, V>& m)
{
    std::cout << "{ ";
    for (const auto& [key, val] : m)
    {
        std::cout << key << ":" << val << " ";
    }
    std::cout << "}" << std::endl;
}

int main() {
    std::cout << "=== Running Mini-Tests ===" << std::endl << std::endl;

    // 1.1 Connected Components (Vector)
    std::cout << "1.1 Connected Components (Vector):" << std::endl;
    {
        GraphInt graph;
        graph[1] = {2}; graph[2] = {1}; 
        graph[3] = {};                  
        
        auto components = find_connected_components(graph);
        for(size_t i = 0; i < components.size(); ++i)
        {
            std::cout << "  Comp " << i + 1 << ": ";
            for(int v : components[i]) std::cout << v << " ";
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;

    // 1.2 Connected Components (Colors)
    std::cout << "1.2 Connected Components (Colors):" << std::endl;
    {
        GraphInt graph;
        graph[1] = {2}; graph[2] = {1};
        graph[3] = {4}; graph[4] = {3};
        
        auto colors = find_connected_components_colors(graph);
        printMap(colors);
    }
    std::cout << std::endl;

    // 2. Cycle Detection
    std::cout << "2. Cycle Detection:" << std::endl;
    {
        GraphInt graphWithCycle;
        graphWithCycle[1] = {2}; graphWithCycle[2] = {1, 3}; graphWithCycle[3] = {2, 1}; 
        
        GraphInt graphNoCycle;
        graphNoCycle[1] = {2}; graphNoCycle[2] = {1, 3}; graphNoCycle[3] = {2}; 
        
        std::cout << "  Has Cycle (Yes): " << (has_cycle(graphWithCycle) ? "True" : "False") << std::endl;
        std::cout << "  Has Cycle (No):  " << (has_cycle(graphNoCycle) ? "True" : "False") << std::endl;
    }
    std::cout << std::endl;

    // 3. Is Tree
    std::cout << "3. Is Tree:" << std::endl;
    {
        GraphChar treeGraph;
        treeGraph['A'] = {'B'}; treeGraph['B'] = {'A', 'C'}; treeGraph['C'] = {'B'};
        
        GraphChar cyclicGraph;
        cyclicGraph['A'] = {'B'}; cyclicGraph['B'] = {'A', 'C'}; cyclicGraph['C'] = {'B', 'A'}; 

        std::cout << "  Is Tree (Yes): " << (isTree(treeGraph, 'A') ? "True" : "False") << std::endl;
        std::cout << "  Is Tree (No):  " << (isTree(cyclicGraph, 'A') ? "True" : "False") << std::endl;
    }
    std::cout << std::endl;

    // 4. Dijkstra
    std::cout << "4. Dijkstra:" << std::endl;
    {
        WeightedGraph weightedGraph;
        weightedGraph['A'] = {{'B', 1}, {'C', 4}};
        weightedGraph['B'] = {{'A', 1}, {'C', 2}, {'D', 5}};
        weightedGraph['C'] = {{'A', 4}, {'B', 2}, {'D', 1}};
        weightedGraph['D'] = {{'B', 5}, {'C', 1}};
        
        auto dists = dijkstra(weightedGraph, 'A');
        std::cout << "  Distances from A: ";
        printMap(dists);
    }
    std::cout << std::endl;

    // 5. Bipartite Check (DFS & BFS)
    std::cout << "5. Bipartite Check:" << std::endl;
    {
        GraphChar bipartiteGraph; 
        bipartiteGraph['A'] = {'B', 'D'}; bipartiteGraph['B'] = {'A', 'C'};
        bipartiteGraph['C'] = {'B', 'D'}; bipartiteGraph['D'] = {'A', 'C'};
        
        GraphChar nonBipartiteGraph; 
        nonBipartiteGraph['A'] = {'B', 'C'}; 
        nonBipartiteGraph['B'] = {'A', 'C'};
        nonBipartiteGraph['C'] = {'A', 'B'};

        std::cout << "  DFS Bipartite (Yes): " << (isBipartiteDFS(bipartiteGraph) ? "True" : "False") << std::endl;
        std::cout << "  DFS Bipartite (No):  " << (isBipartiteDFS(nonBipartiteGraph) ? "True" : "False") << std::endl;
        std::cout << "  BFS Bipartite (Yes): " << (isBipartiteBFS(bipartiteGraph) ? "True" : "False") << std::endl;
        std::cout << "  BFS Bipartite (No):  " << (isBipartiteBFS(nonBipartiteGraph) ? "True" : "False") << std::endl;
    }

    return 0;
}
