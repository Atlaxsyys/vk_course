#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <limits>

// 1.1 & 1.2
using GraphInt = std::map<int, std::vector<int>>;

void dfs(GraphInt& graph, int v, std::map<int, bool>& visited, std::vector<int>& component)
{
    visited[v] = true;
    component.push_back(v);
    for (int neighbor : graph[v])
    {
        if (!visited[neighbor])
        {
            dfs(graph, neighbor, visited, component);
        }
    }
}

std::vector<std::vector<int>> find_connected_components(GraphInt& graph)
{
    std::map<int, bool> visited;
    for (auto const& [node, neighbors] : graph)
    {
        visited[node] = false;
    }

    std::vector<std::vector<int>> connected_components;
    for (auto const& [node, neighbors] : graph)
    {
        if (!visited[node])
        {
            std::vector<int> component;
            dfs(graph, node, visited, component);
            connected_components.push_back(component);
        }
    }
    return connected_components;
}

void dfs_color(GraphInt& graph, int node, std::map<int, int>& visited, int color)
{
    visited[node] = color;
    for (int neighbor : graph[node])
    {
        if (visited[neighbor] == 0)
        {
            dfs_color(graph, neighbor, visited, color);
        }
    }
}

std::map<int, int> find_connected_components_colors(GraphInt& graph)
{
    std::map<int, int> visited;
    for (auto const& [node, neighbors] : graph)
    {
        visited[node] = 0;
    }

    int color = 0;
    for (auto const& [node, neighbors] : graph)
    {
        if (visited[node] == 0)
        {
            color++;
            dfs_color(graph, node, visited, color);
        }
    }
    return visited;
}

// 2
bool dfs_cycle(GraphInt& graph, int vertex, int parent, std::map<int, bool>& visited)
{
    visited[vertex] = true;
    for (int neighbor : graph[vertex])
    {
        if (neighbor != parent)
        {
            if (visited[neighbor])
                return true;
            if (dfs_cycle(graph, neighbor, vertex, visited))
                return true;
        }
    }
    return false;
}

bool has_cycle(GraphInt& graph)
{
    std::map<int, bool> visited;
    for (auto const& [node, neighbors] : graph)
        visited[node] = false;

    for (auto const& [vertex, neighbors] : graph)
    {
        if (!visited[vertex])
        {
            if (dfs_cycle(graph, vertex, -1, visited))
                return true;
        }
    }
    return false;
}

// 3
using GraphChar = std::map<char, std::vector<char>>;

bool isTree(GraphChar& graph, char startNode)
{
    std::vector<char> visited;
    std::map<char, bool> visitedMap;
    std::queue<char> q;
    std::map<char, char> parent;

    q.push(startNode);
    visitedMap[startNode] = true;
    visited.push_back(startNode);
    parent[startNode] = '\0';

    while (!q.empty())
    {
        char vertex = q.front();
        q.pop();

        for (char neighbor : graph[vertex])
        {
            if (!visitedMap[neighbor])
            {
                visitedMap[neighbor] = true;
                visited.push_back(neighbor);
                q.push(neighbor);
                parent[neighbor] = vertex;
            }
            else
            {
                if (parent[vertex] != neighbor)
                    return false;
            }
        }
    }
    return visited.size() == graph.size();
}

// 4
using WeightedGraph = std::map<char, std::map<char, int>>;
const int INF_VAL = std::numeric_limits<int>::max();

std::map<char, int> dijkstra(WeightedGraph& graph, char start)
{
    std::map<char, int> distances;
    for (auto const& pair : graph)
    {
        distances[pair.first] = INF_VAL;
    }
    distances[start] = 0;

    using PII = std::pair<int, char>;
    std::priority_queue<PII, std::vector<PII>, std::greater<PII>> priority_queue;

    priority_queue.push(std::make_pair(0, start));

    while (!priority_queue.empty())
    {
        int current_distance = priority_queue.top().first;
        char current_vertex = priority_queue.top().second;
        priority_queue.pop();

        if (current_distance > distances[current_vertex])
        {
            continue;
        }

        if (graph.find(current_vertex) != graph.end())
        {
            for (auto const& pair : graph.at(current_vertex))
            {
                char neighbor = pair.first;
                int weight = pair.second;

                int distance = current_distance + weight;
                if (distance < distances[neighbor])
                {
                    distances[neighbor] = distance;
                    priority_queue.push(std::make_pair(distance, neighbor));
                }
            }
        }
    }
    return distances;
}

// 5
std::map<char, int> colors_dfs_map;

bool dfs_bipartite(const GraphChar& graph, char node, int c)
{
    colors_dfs_map[node] = c;
    if (graph.find(node) == graph.end())
        return true;

    for (char neighbor : graph.at(node))
    {
        if (colors_dfs_map[neighbor] == 0)
        {
            if (!dfs_bipartite(graph, neighbor, -c))
                return false;
        }
        else
        {
            if (colors_dfs_map[neighbor] == colors_dfs_map[node])
                return false;
        }
    }
    return true;
}

bool isBipartiteDFS(const GraphChar& graph)
{
    colors_dfs_map.clear();
    for (const auto& pair : graph)
        colors_dfs_map[pair.first] = 0;

    for (const auto& pair : graph)
    {
        char node = pair.first;
        if (colors_dfs_map[node] == 0)
        {
            if (!dfs_bipartite(graph, node, 1))
                return false;
        }
    }
    return true;
}

bool bfs_bipartite(const GraphChar& graph, char start, std::map<char, int>& colors)
{
    std::queue<char> q;
    q.push(start);
    colors[start] = 1;

    while (!q.empty())
    {
        char node = q.front();
        q.pop();

        if (graph.find(node) == graph.end())
            continue;

        for (char neighbor : graph.at(node))
        {
            if (colors[neighbor] == 0)
            {
                colors[neighbor] = -colors[node];
                q.push(neighbor);
            }
            else
            {
                if (colors[neighbor] == colors[node])
                    return false;
            }
        }
    }
    return true;
}

bool isBipartiteBFS(const GraphChar& graph)
{
    std::map<char, int> colors;
    for (const auto& pair : graph)
        colors[pair.first] = 0;

    for (const auto& pair : graph)
    {
        char node = pair.first;
        if (colors[node] == 0)
        {
            if (!bfs_bipartite(graph, node, colors))
                return false;
        }
    }
    return true;
}
