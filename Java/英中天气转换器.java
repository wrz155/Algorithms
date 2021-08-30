package com.algorithm;

import java.util.Scanner;

public class 英中天气转换器 {
    /*
     * 实现一个简单的英中天气转换器：输入表1中天气状况英文单词的第一个字母，
     * 根据输入来判断天气状况，并输出天气的中文形式。
     * 用户可重复输入进行转换，输入n退出系统。
     * 干躁	潮湿	炎热	下雨
     * Dry	Moisture	Hot	Rainy
     *
     * */

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            String input = sc.next().trim();
            weatherTrans(input);
        }
    }

    public static void weatherTrans(String input){
        //Dry	Moisture	Hot	Rainy
        if(input.equals("D"))
            System.out.println("Dry");
        else if(input.equals("M"))
            System.out.println("Moisture");
        else if(input.equals("H"))
            System.out.println("Hot");
        else if(input.equals("R"))
            System.out.println("Rainy");
        else if(input.equals("N"))
            System.exit(0);
        else;
    }
}
