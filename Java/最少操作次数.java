package com.algorithm;

public class 最少操作次数 {
    /*
    * 实现一个函数，对一个正整数n，算得到1需要的最少操作次数。
    * 操作规则为：
    *       如果n为偶数，将其除以2；
    *       如果n为奇数，可以加1或减1；
    *       一直处理下去,得到1的时候需要的最少操作次数
    *
    * 思路：
    *       由以上的分析可知，奇数的时候加1或减1，完全取决于二进制的后两位，
    *       如果后两位是10、00那么肯定是偶数，选择除以2，
    *       如果后两位是01、11，那么选择结果会不一样的，
    *           如果是*****01，那么选择减1，
    *           如果是*****11，那么选择加1，
    *           特殊情况是就是n是3的时候，选择减1操作。
    * */
    public static int minOp(int num){
        if(num == 1)
            return 0;
        if(num % 2 == 0)
            return 1 + minOp(num / 2);
        if(num == 3)
            return 2;
        if((num & 3) == 3)
            return 1 + minOp(num + 1);
        else
            return 1 + minOp(num - 1);
    }

    public static void main(String[] args) {
        System.out.println(3 & 2);
        System.out.println(minOp(11));
    }
}
