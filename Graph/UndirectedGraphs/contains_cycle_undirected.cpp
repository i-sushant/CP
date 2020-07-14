#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph {
    int V;
    map<T, list<T>> l;

public:
    Graph(int v)
    {
        V = v;
    }
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    bool cycle_helper(int node, bool* visited, int parent)
    {
        visited[node] = true;
        for (auto nbr : l[node]) {
            if (!visited[nbr]) {
                bool cycle_mila = cycle_helper(nbr, visited, node);
                if (cycle_mila)
                    return true;
            } else if (nbr != parent) { //nbr is visited but that nbr is not parent
                return true;
            }
        }
        return false;
    }
    bool contains_cycle()
    {
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }
        return cycle_helper(1, visited, -1);
    }
};

int main()
{
    Graph<int> g(4);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1);
    if (g.contains_cycle()) {
        cout << "Cyclic Graph";
    } else {
        cout << "Non cyclic!";
    }
    return 0;
}