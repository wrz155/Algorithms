package com.algorithm;

public class 打车软件 {
    /*
    * 假设有一条长长的街道（一维坐标从0到10000），街道上居住着M名司机和N名乘客，彼此坐标不重叠
    * 现需要研发一款打车软件，规则是：每位乘客的订单只会分配给离他最近的司机，
    * 如果两名司机距离相等，则选择坐标最小的。
    * 假设所有乘客同时下单，求每名司机可以收到多少订单？
    *
    * 输入：
    *   第一行，两个整数M和N，分别表示司机和乘客的数量
    *   第二行，M+N个整数，表示每个居民的坐标值
    *   第三行，M+N个标记，表示每个居民的身份，1表示司机，0表示乘客
    * 输出：
    *   M个整数，表示每个司机收到多少个订单
    *
    * 示例：
    *   //输入
    *   2 3
    *   2 3 4 5 6
    *   1 0 0 0 1
    *   //输出
    *   2 1
    *
    *   //输入
    *   1 3
    *   1 2 3 10
    *   0 0 1 0
    *   //输出
    *   3
    *
    * */

    public static int[] getOrders(int[] drivers, int[] customers){
        int M = drivers.length;
        int N = customers.length;
        int[] orders = new int[M];
        if(M == 1){
            orders[0] = N;
            return orders;
        }

        for (int i = 0; i < N; i++){
            int drive = 0;
            int customer = customers[i];
            int start = Math.abs(drivers[0] - customer);

            for(int j = 1; j < M; j++){
                int abs = Math.abs(drivers[j] - customer);
                if(start < abs)
                    continue;
                else if(start > abs){
                    drive = j;
                    continue;
                }
                else{
                    drive = drivers[drive] < drivers[j] ? drive : j;
                }
            }
            orders[drive]++;
        }
        return orders;
    }


    public static void main(String[] args) {
        int[] M = {2, 6};
        int[] N = {3, 4, 5};

        int[] res = getOrders(M, N);
        for (int i = 0; i < res.length; i++) {
            System.out.println(res[i]);
        }
    }
}
