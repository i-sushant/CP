package Graph;

import java.util.*;

public class Graph<T> {
    protected Map<T, LinkedList<T>> l;

    Graph() {
        l = new HashMap<>();
    }

    public void addEdge(T src, T dest) {
        LinkedList<T> lls = l.get(src) == null ? new LinkedList<>() : l.get(src);
        LinkedList<T> lld = l.get(dest) == null ? new LinkedList<>() : l.get(dest);
        lls.add(dest);
        lld.add(src);
        l.put(src, lls);
        l.put(dest, lld);
    }
}