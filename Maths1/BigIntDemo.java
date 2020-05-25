package Maths1;

import java.math.BigInteger;

public class BigIntDemo {
    public static void main(String[] args) {
        playWithBigInt();
    }

    static void playWithBigInt() {
        BigInteger b1 = new BigInteger("12223232");
        BigInteger b2 = new BigInteger("122222222222222222222");
        b1 = b1.add(b2);
        System.out.println(b1);
        b1 = b1.multiply(b2);
        System.out.println(b1);

        System.out.println(b1.bitCount());
        System.out.println(b1.bitLength());

        // Integer to big integer
        int a = 543424;
        int b = 232432;
        BigInteger b3 = BigInteger.valueOf(a);
        BigInteger b4 = BigInteger.valueOf(b);
        System.out.println(b3.gcd(b4));

        BigInteger b5 = new BigInteger("1001", 2);
        System.out.println(b5);

        System.out.println(b3.pow(20));

        BigInteger b6 = new BigInteger("1");
        for (int i = 2; i <= 180; i++) {
            b6 = b6.multiply(BigInteger.valueOf(i));
        }
        System.out.println(b);
    }
}