package Maths.Challenges;

import java.util.*;
import java.io.*;

public class Boston {
    public static void main(String[] args) throws Exception {
        ArrayList<Integer> primes = sieve();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if (isBoston(n)) {
            System.out.println(1);
        } else {
            System.out.println(0);
        }
    }

    static ArrayList<Integer> sieve() {
        int[] prime = new int[100005];
        prime[2] = 1;
        for (int i = 3; i < prime.length; i += 2) {
            prime[i] = 1;
        }
        for (int i = 2; i < prime.length; i++) {
            for (int j = i; i * i < j; j += i) {
                if (prime[i] == 1) {
                    prime[i] = 0;
                }
            }
        }
        ArrayList<Integer> a = new ArrayList<>();
        for (int i = 3; i < prime.length; i += 2) {
            if (prime[i] == 1)
                a.add(i);
        }
        return a;
    }

    static boolean isBoston(int n) {
        int temp = n;
        int sum = 0;
        while (temp != 0) {
            int d = temp % 10;
            sum += d;
            temp /= 10;
        }
        ArrayList<Integer> p = new ArrayList<>();
        int csum = 0;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                p.add(i);
                n /= i;
                while (n % i == 0) {
                    n /= i;
                    p.add(i);
                }
            }
        }
        if (n != 1) {
            p.add(n);
        }
        for (int x : p) {
            while (x != 0) {
                int d = x % 10;
                csum += d;
                x /= 10;
            }
        }
        return csum == sum;
    }
}