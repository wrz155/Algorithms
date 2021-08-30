package com.algorithm.problems.self;

public class 爬楼梯 {

    public int climbStairs(int n) {
        int f1 = 1;
        int f2 = 2;
        int f3 = 3;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        for (int i = 3; i < n + 1; i++) {
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        return f3;
    }
}
