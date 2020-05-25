package STL.challenges;

import java.util.*;

public class unlock {
    public static void main(String[] args) {
        int a[] = { 3, 4, 1, 2, 5 };
        int[] ans = solve(a, 5, 2);
        Arrays.stream(ans).forEach(i -> System.out.print(i + " "));
    }

    public static int[] solve(int a[], int n, int k) {
        Map<Integer, Integer> m = new HashMap<>();
        for (int i = 0; i < n; i++) {
            m.put(a[i], i);
        }

        int temp = n;
        int i = 0;
        while (k > 0 && i < n) {
            if (a[i] != temp) {
                int f = m.get(a[i]);
                int s = m.get(temp);

                int t = a[f];
                a[f] = a[s];
                a[s] = t;

                m.put(a[f], f);
                m.put(a[s], s);

                k++;
            }
            temp--;
            i++;
        }
        return a;
    }
}