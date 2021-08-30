package com.algorithm;

import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class 统计正数负数的和 {
    /*
     *
     * 编一个程序，输入10个整数，并放在数组中，先降序输出所有的数，再统计并输出其中正数、负数和
     * */

    public static void main(String[] args) {
        Integer[] arr = new Integer[10];
        Scanner sc = new Scanner(System.in);
        for(int i = 0; i < arr.length; i++){
            arr[i] = sc.nextInt();
        }
        countArray(arr);
    }


    public static void countArray(Integer[] arr){
        Arrays.sort(arr, Collections.reverseOrder());
        for(Integer i : arr){
            System.out.println(i);
        }
    }
}
