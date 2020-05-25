package Maths1;

import java.math.BigInteger;
import java.util.*;

public class Julka {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = 10;
        BigInteger n, k;
        while (t-- > 0) {
            n = sc.nextBigInteger();
            k = sc.nextBigInteger();
            compute(n, k);
        }
        sc.close();
    }

    static void compute(BigInteger n, BigInteger k) {
        BigInteger x, y;
        x = n.subtract(k);
        x = x.divide(BigInteger.valueOf(2));
        y = x.add(k);
        System.out.println(y);
        System.out.println(x);
    }
}