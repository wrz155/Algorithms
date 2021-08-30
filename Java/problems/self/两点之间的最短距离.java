package com.algorithm.problems.self;

/*
* uva 10245 - The Closest Pair Problem
* 给定N个点，找到所有点中距离最小的两个点
*       输出最短的距离
*
* 貌似有两种解法：
*       1、分治法
*           步骤1：根据点的y值和x值对S中的点排序。
            步骤2：找出中线L将S划分为SL和SR
            步骤3：将步骤2递归的应用解决SL和SR的最近点对问题，并令d=min(dL,dR)。
            步骤4：将L-d~L+d内的点以y值排序，对于每一个点(x1,y1)找出y值在y1-d~y1+d内的所有点，计算距离为d'。如果d'小于d，令d=d'，最后的d值就是答案
*
*       2、KDTree
* */

public class 两点之间的最短距离 {
}
