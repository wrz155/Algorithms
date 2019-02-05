﻿/*
1007 素数对猜想 （20 分）
让我们定义d(n) = p(n+1) - p(n),其中p(i)是第i个素数。显然有d(1) = 1,
且对于n>1有d(n)​是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。
现给定任意正整数N(<10^5​)，请计算不超过N的满足猜想的素数对的个数。

输入格式:
输入在一行给出正整数N。

输出格式:
在一行中输出不超过N的满足猜想的素数对的个数。

输入样例:
20

输出样例:
4

*/

#include <cmath>
#include <iostream>

bool isPrime(int n){
	for (int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n,cnt = 0;
    scanf("%d",&n);
	for (int i = 3; i + 2 <= n; i += 2) {
		if (isPrime(i) == true && isPrime(i + 2) == true) {
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}