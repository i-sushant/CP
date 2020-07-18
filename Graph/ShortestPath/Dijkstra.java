package Graph.ShortestPath;

import java.util.*;

class Pair<T> {
    T first;
    int second;

    Pair() {
    }

    Pair(T first, int second) {
        this.first = first;
        this.second = second;
    }
}

public class Dijkstra {
    public static void main(String[] args) {
        Graph<String> india = new Graph<>();
        india.addEdge("Amritsar", "Delhi", 1);
        india.addEdge("Amritsar", "Jaipur", 4);
        india.addEdge("Jaipur", "Delhi", 2);
        india.addEdge("Jaipur", "Mumbai", 8);
        india.addEdge("Bhopal", "Agra", 2);
        india.addEdge("Mumbai", "Bhopal", 3);
        india.addEdge("Agra", "Delhi", 1);
        india.disjkstraSSSP("Amritsar");
    }

    static class Graph<T> {
        Map<T, List<Pair<T>>> g = new HashMap<>();

        void addEdge(T src, T dest, int dist) {
            if (!g.containsKey(src)) {
                g.put(src, new ArrayList<>());
            }
            List<Pair<T>> ll = g.get(src);
            ll.add(new Pair<T>(dest, dist));
            g.put(src, ll);
            if (!g.containsKey(dest)) {
                g.put(dest, new ArrayList<>());
            }
            List<Pair<T>> lld = g.get(dest);
            lld.add(new Pair<T>(src, dist));
            g.put(dest, lld);
        }

        void disjkstraSSSP(T src) {
            Map<T, Integer> dist = new HashMap<>();
            g.keySet().forEach(key -> dist.put(key, Integer.MAX_VALUE));
            TreeSet<Pair<T>> s = new TreeSet<>((a, b) -> a.second - b.second);
            s.add(new Pair<>(src, 0));
            dist.put(src, 0);
            while (!s.isEmpty()) {
                var p = s.first();
                var node = p.first;
                int nodeDist = p.second;
                s.remove(p);
                for (var childPair : g.get(node)) {
                    var dest = childPair.first;
                    if (nodeDist + childPair.second < dist.get(dest)) {
                        s.remove(new Pair<>(dest, dist.get(dest)));
                        dist.put(dest, nodeDist + childPair.second);
                        s.add(new Pair<>(dest, dist.get(dest)));
                    }
                }
            }
            dist.entrySet().forEach(entry -> System.out
                    .println(entry.getKey() + " is located at a distance of " + entry.getValue() + " from " + src));
        }
    }
}