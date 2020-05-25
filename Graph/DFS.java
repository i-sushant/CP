package Graph;

import java.util.*;

public class DFS<T> extends Graph<T> {
    public static void main(String[] args) {
        DFS<Integer> g = new DFS<Integer>();
        g.addEdge(0, 1);
        g.addEdge(1, 2);
        g.addEdge(2, 3);
        g.addEdge(3, 4);
        g.addEdge(4, 5);

        g.dfs(0);
        g.dfs(3);
    }

    DFS() {
        super();
    }

    void dfs(T src) {
        Map<T, Boolean> visited = new HashMap<>();
        l.keySet().forEach(key -> visited.put(key, false));
        dfs_helper(src, visited);
        System.out.println();
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
