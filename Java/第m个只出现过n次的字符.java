package com.algorithm;

/*
* 1、输入字符串str，输出第m个只出现过n次的字符。
* 如在字符串gbgkkdehh中找到第2个只出现1次的字符，
* 则输出d
* */

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class 第m个只出现过n次的字符 {

    public static char getChar(String str, int m, int n){
        Map<String, Integer> map = new HashMap<>();
        List<String> list = new ArrayList<>();

        for(int i = 0; i < str.length(); i++){
            String s = str.substring(i, i+1);
            if(map.containsKey(s)){
                int value = map.get(s);
                map.put(s, value + 1);
            }
            else{
                map.put(s, 1);
                list.add(s);
            }

        }

        int index = 0;
        for(int i = 0; i < list.size(); i++) {
            if(n == map.get(list.get(i))){
                if (index == m - 1)
                    return list.get(i).charAt(0);
            }
        }
        return 'e';
    }

    public static void main(String[] args) {

    }
}
