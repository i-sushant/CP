#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<pair<int, int>>* l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<pair<int, int>>[V];
    }
    void addEdge(int u, int v, int cost)
    {
        l[u].push_back(make_pair(v, cost));
        l[v].push_back(make_pair(u, cost));
    }
    int dfs_helper(int node, bool* visited, int* count, int& ans)
    {
        visited[node] = true;
        count[node] = 1;
        for (auto nbr_pair : l[node]) {
            int nbr = nbr_pair.first;
            int wt = nbr_pair.second;
            if (!visited[nbr]) {
                count[node] += dfs_helper(nbr, visited, count, ans);
                int nx = count[nbr];
                int ny = V - nx;
                ans += 2 * min(nx, ny) * wt;
            }
        }
        return count[node];
    }
    int dfs()
    {
        bool* visited = new bool[V] { false };
        int* count = new int[V] { 0 };

        int ans = 0;
        dfs_helper(0, visited, count, ans);
        return ans;
    }
};

int main()
{
    // int t;
    // cin >> t;
    // while (t--) {
    //     int n;
    //     cin >> n;
    //     Graph g(n);
    //     for (int i = 0; i < n; i++) {
    //         int x, y, z;
    //         cin >> x >> y >> z;
    //         g.addEdge(x, y, z);
    //     }
    //     cout << g.dfs() << endl;
    // }
    Graph g(4);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 2);
    g.addEdge(4, 3, 2);
    cout << g.dfs() << endl;
}