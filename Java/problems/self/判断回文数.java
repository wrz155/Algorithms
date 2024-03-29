package com.algorithm.problems.self;

public class 判断回文数 {
    //不转成字符串
    public static boolean isPalindrome(int n) {
        if (n < 0)
            return false;

        int help = 1;
        while (n / help >= 10)
            help *= 10;

        while (n != 0) {
            if (n / help != n % 10) {
                return false;
            }
            n = (n % help) / 10;
            help /= 100;
        }

        return true;
    }


    public static void main(String[] args) {

    }
}
