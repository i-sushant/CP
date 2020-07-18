#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph {
    unordered_map<T, list<pair<T, int>>> g;

public:
    void addEdge(T u, T v, int dist, bool isBir = true)
    {
        g[u].push_back({ v, dist });
        if (isBir)
            g[v].push_back({ u, dist });
    }
    void printAdj()
    {
        //iterate over all the keys in map
        for (auto j : g) {
            cout << j.first << " ->";
            for (auto l : j.second) {
                cout << " (" << l.first << ", " << l.second << ")";
            }
            cout << endl;
        }
    }
    void disjkstraSSSP(T src)
    {
        unordered_map<T, int> dist;
        for (auto j : g) {
            dist[j.first] = INT_MAX;
        }
        //make a set to find a node with minimum distance
        set<pair<int, T>> s;
        dist[src] = 0;
        s.insert({ 0, src });
        while (!s.empty()) {
            //find the pair at the front
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());
            //iterate over neighbours of current node
            for (auto childPair : g[node]) {
                if (nodeDist + childPair.second < dist[childPair.first]) {
                    //in the set update is not possible , so
                    //we have to remove the pair and then insert again
                    T dest = childPair.first;
                    auto f = s.find({ dist[dest], dest });
                    if (f != s.end()) {
                        s.erase(f);
                    }
                    //insert the new pair
                    dist[dest] = nodeDist + childPair.second;
                    s.insert({ dist[dest], dest });
                }
            }
        }
        //print dist of all other node from src
        for (auto d : dist) {
            cout << d.first << " is located at a distance of " << d.second << " from " << src << endl;
        }
    }
};
int main()
{
    Graph<string> india;
    india.addEdge("Amritsar", "Delhi", 1);
    india.addEdge("Amritsar", "Jaipur", 4);
    india.addEdge("Jaipur", "Delhi", 2);
    india.addEdge("Jaipur", "Mumbai", 8);
    india.addEdge("Bhopal", "Agra", 2);
    india.addEdge("Mumbai", "Bhopal", 3);
    india.addEdge("Agra", "Delhi", 1);
    // india.printAdj();
    india.disjkstraSSSP("Amritsar");
}
