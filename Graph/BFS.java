package Graph;

import java.util.*;

public class BFS {
    public static void main(String[] args) {
        BFSearch<Integer> g = new BFSearch<Integer>();
        g.addEdge(0, 1);
        g.addEdge(1, 2);
        g.addEdge(2, 3);
        g.addEdge(3, 4);
        g.addEdge(4, 5);

        g.bfs(0);
        g.bfs(3);
    }

    static class BFSearch<T> extends Graph<T> {
        BFSearch() {
            super();
        }

        public void bfs(T src) {
            Map<T, Boolean> visited = new HashMap<>();
            l.keySet().forEach(i -> visited.put(i, false));
            Queue<T> q = new LinkedList<>();
            StringBuilder sb = new StringBuilder();
            visited.put(src, true);
            q.add(src);
            while (!q.isEmpty()) {
                T node = q.peek();
                q.poll();
                sb.append(node + " ");
                l.get(node).forEach(nbr -> {
                    if (!visited.get(nbr)) {
                        q.add(nbr);
                        visited.put(nbr, true);
                    }
                });
            }
            System.out.println(sb);
        }
    }
}