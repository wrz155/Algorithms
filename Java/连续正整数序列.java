package com.algorithm;

public class 连续正整数序列 {

    /*
    * 6编程题：实现一个方法，传入正整数n，输出所有和为n的连续正整数序列。
        例子：
        输入n=15，输出
        1，2，3，4，5
        4，5，6
        7，8
     思路：
     *  1、从1开始加到n/2，开始检测
     *  2、等差数列求和公式
     *      (a + b)(b - a + 1) / 2 = N, 求a、b的值
     *      b = a + i - 1
    * */
    public static int consecutiveNumbersSum(int N) {
        N *= 2;
        int resCount = 0;
        for(int i = (int) Math.sqrt(N); i > 0; --i){//穷举项数
            if(N % i == 0){
                int a = (N / i + 1 - i) / 2;
                int b = a + i -1;
                if((a + b) * (b - a + 1) == N){//检测求和公式
                    if (a == b)
                        continue;
                    while (a <= b){
                        System.out.print(a + " ");
                        a++;
                    }
                    System.out.println();
                    ++resCount;
                }
            }
        }
        return resCount;
    }

    public static void main(String[] args) {
        System.out.println(consecutiveNumbersSum(15));
    }

}
