// package TCS;

import java.io.*;
import java.util.*;

public class GroovingMonkeys {
    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO();
        int t = io.nextInt();
        StringBuilder sb = new StringBuilder();
        while (t-- > 0) {
            int n = io.nextInt();
            int arr[] = Arrays.stream(io.chars()).mapToInt(Integer::valueOf).toArray();
            sb.append(solve(n, arr));
        }
        System.out.println(sb.toString());
    }

    private static int solve(int n, int[] arr) {
        HashSet<Integer> set = new HashSet<>();
        for (int i = 1; i <= n; i++) {
            if (arr[i] == 0)
                continue;
            int count = 0;
            int current = i;
            int block = i;
            while (true) {
                current = arr[current];
                arr[block] = 0;
                block = current;
                count++;
                if (current == i)
                    break;
            }
            set.add(count);
        }
        return t;
    }

    private static int solve(int[] arr) {

    }

    static class FastIO {
        BufferedReader br;

        FastIO() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public String[] chars() throws IOException {
            return br.readLine().split("\\s+");
        }

        public String next() throws IOException {
            return br.readLine();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(br.readLine());
        }
    }
}
