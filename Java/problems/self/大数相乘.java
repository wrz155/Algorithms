package com.algorithm.problems.self;

/*
 * 输入数据
 *   num1    5432981
 *   num2    1287912
 *   求num1 * num2
 * */
public class 大数相乘 {
    class Solution {
        public String multiply(String n1, String n2) {
            int n = n1.length(), m = n2.length();
            int[] res = new int[n + m];
            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    int a = n1.charAt(i) - '0';
                    int b = n2.charAt(j) - '0';
                    int r = a * b;
                    r += res[i + j + 1];
                    res[i + j + 1] = r % 10;
                    res[i + j] += r / 10;
                }
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n + m; i++) {
                if (sb.length() == 0 && res[i] == 0) continue;
                sb.append(res[i]);
            }
            return sb.length() == 0 ? "0" : sb.toString();
        }
    }

    public static void main(String[] args) {
        int num = Integer.valueOf("12345");
    }
}
