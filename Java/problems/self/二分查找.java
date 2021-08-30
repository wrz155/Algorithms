package com.algorithm.problems.self;

public class 二分查找 {

    public static boolean binarySearchUnrecu(int[] arr, int key) {
        int left = 0;
        int right = arr.length - 1;
        int mid = (right - left) / 2;

        while (mid >= left && mid <= right) {
            if (arr[mid] == key)
                return true;
            else if (arr[mid] > key) {
                right = mid - 1;
                mid = (right - left) / 2;
            } else if (arr[mid] < key) {
                left = mid + 1;
                mid = (right - left) / 2;
            }
        }
        return false;
    }

    public static boolean binarySearchUnrecu2(int[] arr, int target) {
        int l = 0;
        int r = arr.length - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (arr[mid] == target)
                return true;
            if (arr[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }


    public static void main(String[] args) {
        int arr[] = {1, 2, 3, 4, 10, 50, 100};
        System.out.println(binarySearchUnrecu2(arr, 50));

    }
}
