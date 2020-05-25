package Bitmanipulation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Ultrafast {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (t-- > 0) {
            String[] line = br.readLine().split("\\s+");
            String a = line[0];
            String b = line[1];
            sb.append(solve(a, b)).append("\n");
        }
        System.out.print(sb.toString().trim());
    }

    static String solve(String a, String b) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < a.length(); i++) {
            int x = Character.valueOf(a.charAt(i));
            int y = Character.valueOf(b.charAt(i));
            int res = x ^ y;
            sb.append(res);
        }
        return sb.toString();
    }
}