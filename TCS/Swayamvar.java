package TCS;

import java.io.*;
import java.util.LinkedList;
import java.util.Queue;

public class Swayamvar {
    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO();
        int n = io.nextInt();
        String[] bg = io.chars();
        char[] brides = new char[n];
        brides = bg[0].toCharArray();
        char[] groom = bg[1].toCharArray();
        Queue<Character> b = new LinkedList<>();
        for (char c : brides) {
            b.add(c);
        }
        Queue<Character> g = new LinkedList<>();
        for (char c : groom) {
            g.add(c);
        }
        int reject = 0;
        while (reject != g.size()) {
            if (b.peek() == g.peek()) {
                b.poll();
                g.poll();
                reject = 0;
            } else {
                g.add(g.poll());
                reject++;
            }
        }
        System.out.println(b.size());

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
