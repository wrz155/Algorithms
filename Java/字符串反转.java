package com.algorithm;

public class 字符串反转 {

    public static String reverse_1(String s){
        return new StringBuilder(s).reverse().toString();
    }

    // 可以重新拼接字符出串
    public static String reverse_2(String s){
        char[] chars = s.toCharArray();
        String res = "";
        for(int i = s.length() - 1; i >= 0; i--)
            res += chars[i];
        return res;
    }

    // 在原字符串上进行调整
    public static String reverse_3(String s) {
        char[] chars = s.toCharArray();
        int len = s.length() - 1;
        for(int i = 0; i < len / 2; i++){
            char tmp = chars[i];
            chars[i] = chars[len - 1 - i];
            chars[len - 1 - i] = tmp;
        }
        return String.valueOf(chars);
    }

    public static void main(String[] args) {
        String str = "hell world";

        System.out.println(reverse_1(str));
        System.out.println(reverse_2(str));
        System.out.println(reverse_3(str));
    }
}
