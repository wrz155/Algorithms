package com.algorithm;

public class 快速排序 {
    public static void swap(int[] arr, int i, int j){
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    public static int[] patition(int[] arr, int l, int r){
        int less = l - 1;
        int more = r;
        while (l < more) {
            if (arr[l] < arr[r])
                swap(arr, ++less, l++);
            else if (arr[l] > arr[r])
                swap(arr, --more, l);
            else
                l++;
        }
        swap(arr, more, r);
        return new int[]{less + 1, more};
    }


    public static void quickSort(int[] arr, int l, int r){
        if(l < r){
            swap(arr, l + (int) (Math.random() * (r - l + 1)), r);
            int[] p = patition(arr, l, r);
            quickSort(arr, l, p[0] - 1);
            quickSort(arr, p[1] + 1, r);
        }
    }

    public static void printArray(int[] arr) {
        if (arr == null) {
            return;
        }
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void quickSort(int[] arr){
        if (arr == null || arr.length < 2){
            return;
        }
        quickSort(arr, 0, arr.length - 1);
    }

    public static void main(String[] args) {
        int[] arr = {9,8,7,6,5,4,3,2,1};
        quickSort(arr);
        printArray(arr);

    }
}
