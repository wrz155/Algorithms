package com.algorithm;

public class 二分查找 {
    /*
    * 请使用java语言用非递归的方式实现整形数组的二分查找，接口自定义
    * 分析：
    *       1、arr是有序数组
    * */
    public static int binarySearch(int[] arr, int num) {
        int start = 0;
        int end = arr.length - 1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(num < arr[mid])
                end = mid - 1;
            else if(num > arr[mid])
                start = mid + 1;
            else
                return mid;
        }
        return -1;
    }

    /*
    * 扩展：
    *       递归实现二分查找
    * */
    public static int binarySearchByecursion(int[] arr, int num, int start, int end) {
        if(start > end)
            return -1;
        int mid = (start + end) / 2;
        if(num < arr[mid])
            return binarySearchByecursion(arr,num,start,mid - 1);
        else if(num > arr[mid])
            return binarySearchByecursion(arr,num,mid + 1, end);
        else
            return mid;
    }

    public static void main(String[] args) {
        int[] arr = {1, 3, 5, 7, 9, 11, 13, 15, 17};

        System.out.println(binarySearch(arr, 11));

        System.out.println(binarySearchByecursion(arr, 11, 0, arr.length - 1));
    }
}
