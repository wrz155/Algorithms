package com.algorithm.problems.self;

public class 移动零 {
    public void moveZeroes(int[] nums) {
        // 下一个非0元素的index
        int j = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                if (i != j) {
                    nums[i] = 0;
                }
                j++;
            }
        }
    }

    public static void main(String[] args) {

    }
}
