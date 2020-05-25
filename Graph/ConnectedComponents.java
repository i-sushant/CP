package Graph;

import java.util.*;

public class ConnectedComponents<T> extends Graph<T> {
    public static void main(String[] args) {
        ConnectedComponents<Integer> g = new ConnectedComponents<>();
        g.addEdge(0, 1);
        g.addEdge(1, 2);
        g.addEdge(2, 3);
        g.addEdge(0, 3);
        g.addEdge(0, 4);
        g.addEdge(5, 6);
        g.addEdge(6, 7);
        g.addEdge(8, 8);
        g.dfs(0);
    }

    ConnectedComponents() {
        super();
    }

    void dfs(T src) {
        Map<T, Boolean> visited = new HashMap<>();
        l.keySet().forEach(key -> visited.put(key, false));
        int cnt = 0;
        for (var p : l.values()) {
            T node = p.getFirst();
            if (!visited.get(node)) {
                System.out.print("Component " + cnt + " --> ");
                dfs_helper(node, visited);
                cnt++;
                System.out.println();
            }
        }

    }

    void dfs_helper(T src, Map<T, Boolean> visited) {
        System.out.print(src + " ");
        visited.put(src, true);
        l.get(src).forEach(nbr -> {
            if (!visited.get(nbr))
                dfs_helper(nbr, visited);
        });
    }
}