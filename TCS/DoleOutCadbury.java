package TCS;

import java.io.*;

public class DoleOutCadbury {
    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO();
        int p, q, r, s;
        p = io.nextInt();
        q = io.nextInt();
        r = io.nextInt();
        s = io.nextInt();
        int ans = 0;
        if ((p > 0 && p < q && q < 1501) && (r > 0 && r < s && r < 1501)) {
            for (int i = p; i <= q; i++) {
                for (int j = r; j <= s; j++) {
                    ans = ans + numberOfChildren(i, j);
                }
            }
        }
        System.out.println(ans);
    }

    private static int numberOfChildren(int i, int j) {
        int count = 0;
        while (i > 0 && j > 0) {
            count++;
            if (i > j)
                i = i - j;
            else
                j = j - i;
        }
        return count;
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
