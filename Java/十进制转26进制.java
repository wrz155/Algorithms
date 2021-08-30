package com.algorithm;

public class 十进制转26进制 {

    public static String _10to26(int num){
        String str = "";
        while(num > 0){
            int tmp = num % 26;
            if(tmp == 0)
                tmp = 26;
            str = (char)(tmp + 'A' - 1) + str;
            num  = (num - tmp) / 26;
        }
        return str;
    }

    public static void main(String[] args) {
        int num = 26;
        System.out.println(_10to26(num));
    }
}
