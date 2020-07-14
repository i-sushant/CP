#include <bits/stdc++.h>
using namespace std;
int odd_cycle = 0;
template <typename T>
class Graph {

    map<T, list<T>> l;

public:
    int V;
    Graph(int v)
    {
        V = v;
    }
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void dfs(int node, int* visited, int parent, int col)
    {
        visited[node] = col;
        for (auto nbr : l[node]) {
            if (!visited[nbr]) {
                dfs(nbr, visited, node, 3 - col);
            } else if (nbr != parent && col == visited[nbr]) {
                //backedge and odd length cycle
                odd_cycle = 1;
            }
        }
        return;
    }
    void check_bipartite()
    {
        int* visited = new int[V];
        for (int i = 0; i < V; i++) {
            visited[i] = 0;
        }
        dfs(1, visited, 0, 1);
    }
};

int main()
{

    // g.addEdge(1, 2);
    // g.addEdge(2, 3);
    // g.addEdge(3, 4);
    // g.addEdge(4, 5);
    // g.addEdge(5, 1);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif
    int n, m, ans;
    cin >> n >> m;
    Graph<int> graph(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph.addEdge(x, y);
    }
    graph.check_bipartite();
    if (odd_cycle) {
        cout << "Not bipartite\n";
    } else {
        cout << "Bipartite\n";
    }
    return 0;
}