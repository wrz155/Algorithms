package com.algorithm.problems.self;

public class 盛最多水的容器 {
    public int maxArea(int[] height) {
        int max = 0;
        for (int i = 0; i < height.length - 1; ++i) {
            for (int j = i + 1; j < height.length; ++j) {
                int area = (j - i) * Math.min(height[i], height[j]);
                max = Math.max(area, max);
            }
        }
        return max;
    }

    public static int maxArea1(int[] height) {
        int max = 0;
        for (int i = 0, j = height.length - 1; i < j; ) {
            int minHeight = height[i] < height[j] ? height[i++] : height[j--];
            max = Math.max(max, (j - i + 1) * minHeight);
        }
        return max;
    }


    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4};
        System.out.println(maxArea1(arr));
    }
}
