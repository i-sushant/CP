package Recursion5;

import java.util.*;

public class InterleavedString {
    public static void main(String[] args) {
        Map<String, Boolean> dp = new HashMap<>();

        if (solve("AB", "CD", "ABCE", dp))
            System.out.println('1');
        else
            System.out.println('0');
    }

    public static boolean solve(String s1, String s2, String is, Map<String, Boolean> dp) {

        if (s1.isBlank() && s2.isEmpty() && is.isEmpty())
            return true;
        if (is.isEmpty())
            return false;
        String str = s1 + "|" + s2 + "|" + is;
        if (dp.containsKey(str))
            return dp.get(str);
        boolean first = (!s1.isEmpty() && s1.charAt(0) == is.charAt(0))
                && solve(s1.substring(1), s2, is.substring(1), dp);
        boolean second = (!s2.isEmpty() && s2.charAt(0) == is.charAt(0))
                && solve(s1, s2.substring(1), is.substring(1), dp);
        dp.put(str, first || second);
        return dp.get(str);

    }
}