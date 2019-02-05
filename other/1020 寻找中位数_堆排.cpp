/*

中位数（又称中值，英语：Median），统计学中的专有名词，代表一个样本、种群或概率分布中的一个数值，
其可将数值集合划分为相等的上下两部分。
对于有限的数集，可以通过把所有观察值高低排序后找出正中间的一个作为中位数。
如果观察值有偶数个，则中位数不唯一，通常取最中间的两个数值的平均数作为中位数。

Description
多组输入
第一行：一个正整数N (0<N<1000000)
第二行：N个正整数。(0=<A[i]<2^30)

Input
每组数据先输出”Case X:”,X表示测试数据的编号，从1开始。
第二行输出N个数，第i个数对应数组前i个值的中位数。（精确到小数点后一位）

Output
1
2
3
4
5
5
1 2 3 4 5
6
2 5 4 8 7 4
 
Sample Input
1
2
3
4
5

Case 1:
1.0 1.5 2.0 2.5 3.0

Case 2:
2.0 3.5 4.0 4.5 5.0 4.5
 
Sample Output
输出换行请使用\r\n 


很容易想到的方法是先排序，再找中位数。每输入一个数字，对已输入的数字进行插入排序。输入第k个数字，由于之前的数字已经排好了，所以用二分插入排序有O(logk) <= O(logn)的比较次数。这样总的比较次数也有O(n*logn)。但是这个方法有一个问题，就是移动元素的次数可能很多（最坏情况，每次新来的元素都是最小的，这样要移动O(n^2)次）。

利用堆排序可能很好的解决这个问题（这里假设大家知道如何在堆中进行插入和删除）。
我们维护两个数组和一个变量mid_value。
两个数组分别是小于mid_value的元素组成的的大顶堆（即堆顶是最大的元素）和大于mid_value的元素组成的小顶堆。
如果新来的数字比mid_value大，则将其插入大于mid_value的最小堆。否则，插入最大堆。 
case<1> 如果此时大于mid_value的元素比小于mid_value的多两个，
那么将mid_value插入小于mid_value的最大堆，将大于mid_value的最小堆的最小值赋给mid_value，并且删除该最小堆的堆顶。 
case<2> 如果此时小于mid_value的元素比大于mid_value的元素多。
那么将mid_value插入大于mid_value的小顶堆中，将小于mid_value的大顶堆堆顶赋给mid_value，并且删除该堆顶。

插入第k个元素，堆的插入和删除操作的复杂度（不管是比较次数还是移动次数）都是O(logk)<=O(logn)，这样总的时间复杂度就是O(n*logn)。

*/


#include <iostream>
#include <set>
#include <cstdio>
using namespace std;
 
#define rep(i,a,b) for(int i=a;i<=b;i++)
int t, n;
multiset<double>mpt;
 
void mid_num(){
    double x;
    printf("Case %d:\r\n", ++t);
    mpt.clear();
    scanf("%lf", &x);
    mpt.insert(x);
    multiset <double> ::iterator it = mpt.begin();
    printf("%.1lf", x);
    rep(i, 2, n){
        scanf("%lf", &x);
        mpt.insert(x);
        if (x < *it){
            if (i & 1) printf(" %.1lf", *(--it));
            else {
                multiset <double> ::iterator it1 = it;
                printf(" %.1lf", (*it + *(--it1)) / 2.0);
            }
        }
        else {
            if (i & 1) printf(" %.1lf", *it);
            else {
                ++it;
                multiset <double> ::iterator it1 = it;
                printf(" %.1lf", (*it + *(--it1)) / 2.0);
 
            }
        }
    }
    printf("\r\n");
}
 
int main(){
    while (~scanf("%d", &n))
        mid_num();
    return 0;
}

// 不用容器的解法
#include <stdio.h>
#include <string.h>
int lstack[500001], ltot, rstack[500001], rtot, mid;
int Max(int a, int b){
    return a > b ? a : b;
}
int Min(int a, int b){
    return a<b ? a : b;
}
void lup(int step){
    while (step != 1){
        if (lstack[step]>lstack[step / 2])lstack[step] ^= lstack[step / 2] ^= lstack[step] ^= lstack[step / 2];
        else break;
        step = step / 2;
    }
    if (step == 1 && lstack[1] > mid) lstack[1] ^= mid ^= lstack[1] ^= mid;
}
void ldown(){
    if (ltot > 1 && mid < lstack[1]) mid ^= lstack[1] ^= mid ^= lstack[1];
    else return;
    int step = 1;
    while (step * 2 < ltot){
        if (step * 2 + 1 >= ltot){
            if (lstack[step] < lstack[step * 2])
                lstack[step] ^= lstack[step * 2] ^= lstack[step] ^= lstack[step * 2], step = step * 2;
            else return;
        }
        else{
            if (lstack[step] <= lstack[step * 2] && lstack[step * 2 + 1] <= lstack[step * 2])
                lstack[step] ^= lstack[step * 2] ^= lstack[step] ^= lstack[step * 2], step = step * 2;
            else if (lstack[step] <= lstack[step * 2 + 1] && lstack[step * 2] <= lstack[step * 2 + 1])
                lstack[step] ^= lstack[step * 2 + 1] ^= lstack[step] ^= lstack[step * 2 + 1], step = step * 2 + 1;
            else return;
        }
    }
}
void rup(int step){
    while (step != 1){
        if (rstack[step]<rstack[step / 2])rstack[step] ^= rstack[step / 2] ^= rstack[step] ^= rstack[step / 2];
        else break;
        step = step / 2;
    }
    if (step == 1 && rstack[1]<mid) rstack[1] ^= mid ^= rstack[1] ^= mid;
}
void rdown(){
    if (rtot>1 && mid>rstack[1]) mid ^= rstack[1] ^= mid ^= rstack[1];
    else return;
    int step = 1;
    while (step * 2 < rtot){
        if (step * 2 + 1 >= rtot){
            if (rstack[step] > rstack[step * 2])
                rstack[step] ^= rstack[step * 2] ^= rstack[step] ^= rstack[step * 2], step = step * 2;
            else return;
        }
        else{
            if (rstack[step] >= rstack[step * 2] && rstack[step * 2 + 1] >= rstack[step * 2])
                rstack[step] ^= rstack[step * 2] ^= rstack[step] ^= rstack[step * 2], step = step * 2;
            else if (rstack[step] >= rstack[step * 2 + 1] && rstack[step * 2] >= rstack[step * 2 + 1])
                rstack[step] ^= rstack[step * 2 + 1] ^= rstack[step] ^= rstack[step * 2 + 1], step = step * 2 + 1;
            else return;
        }
    }
}
int main()
{
    int t = 1, n, i;
    while (scanf("%d", &n) != EOF){
        printf("Case %d:\r\n", t++);
        scanf("%d", &mid);
        ltot = rtot = 1;
        printf("%.1lf", (double)mid);
        for (i = 1; i < n; i++){
            if (i % 2){
                scanf("%d", &lstack[ltot]);
                lup(ltot);
                rdown();
                ltot++;
                printf(" %.1lf", (mid + lstack[1]) / 2.0);
            }
            else{
                scanf("%d", &rstack[rtot]);
                rup(rtot);
                ldown();
                rtot++;
                printf(" %.1lf", (double)mid);
            }
        }
        printf("\r\n");
    }
    return 0;
}