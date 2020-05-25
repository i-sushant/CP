#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph {
    map<T, list<T>> l;

public:
    void addEdge(T x, T y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void dfs_helper(T src, map<T, bool>& visited)
    {
        cout << src << " ";
        visited[src] = true;
        for (T nbr : l[src]) {
            if (!visited[nbr]) {
                dfs_helper(nbr, visited);
            }
        }
    }
    void dfs(T src)
    {
        map<T, bool> visited;
        for (auto x : l) {
            T node = x.first;
            visited[node] = false;
        }
        int cnt = 0;
        for (auto p : l) {
            T node = p.first;
            if (!visited[node]) {
                cout << "Component " << cnt << " --> ";
                dfs_helper(node, visited);
                cnt++;
                cout << endl;
            }
        }
        dfs_helper(src, visited);
        cout << endl;
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.dfs(0);
    g.dfs(3);
    return 0;
}