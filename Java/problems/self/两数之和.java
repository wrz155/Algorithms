package com.algorithm.problems.self;

import java.util.HashMap;
import java.util.Map;

public class 两数之和 {
    // 1、两重循环 暴力求解
    // 2、用hash记录


    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> hashtable = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; ++i) {
            if (hashtable.containsKey(target - nums[i])) {
                return new int[]{hashtable.get(target - nums[i]), i};
            }
            hashtable.put(nums[i], i);
        }
        return new int[0];
    }

    public static void main(String[] args) {

    }
}
