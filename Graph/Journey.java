package Graph;

import java.util.*;

public class Journey<T> extends Graph<T> {
    public static void main(String[] args) {
        Journey<Integer> j = new Journey<Integer>();
    }

    ArrayList<Integer> a = new ArrayList<>();

    long find() {
        long total = getNcR(10, 2);
        long same = 1;
        for (int x : a) {
            same += getNcR(x, 2);
        }
        return total - same;
    }

    static long getNcR(int n, int r) {
        long p = 1, k = 1;
        if (n - r < r) {
            r = n - r;
        }

        if (r != 0) {
            while (r > 0) {
                p *= n;
                k *= r;
                long m = __gcd(p, k);
                p /= m;
                k /= m;
                n--;
                r--;
            }
        } else {
            p = 1;
        }
        return p;
    }

    static long __gcd(long n1, long n2) {
        if (n2 == 0)
            return n1;
        return __gcd(n2, n1 % n2);
    }

    void dfs(T src) {
        Map<T, Boolean> visited = new HashMap<>();
        l.keySet().forEach(key -> visited.put(key, false));
        for (var p : l.values()) {
            T node = p.getFirst();
            if (!visited.get(node)) {
                a.add(dfs_helper(node, visited, 0));
            }
        }

    }

    int dfs_helper(T src, Map<T, Boolean> visited, int size) {
        int componentSize = 1;
        visited.put(src, true);
        for (T nbr : l.get(src)) {
            if (!visited.get(nbr))
                componentSize += dfs_helper(nbr, visited, size + 1);
        }
        return componentSize;
    }

}