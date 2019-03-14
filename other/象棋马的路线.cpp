/*
	招商银行:
		象棋10条横线，9条总线，共90个交叉点，数组p[9][10],马走日
		最快的行进路线，求出一条即可，不考虑蹩马脚
		返回跳几步
*/

#include <iostream>
#include <queue>

using namespace std;

//定义马
typedef struct 
{
	int x;
	int y;
	int istep;
}Horse;

bool visit[9][10];

//马走日
const int dx[] = { 1,1,-1,-1,2,2,-2,-2 };
const int dy[] = { 2,-2,2,-2,1,-1,1,-1 };		//第一题

int run(int Sx, int Sy, int Ex, int Ey)
{
	Horse start;
	start.x = Sx;
	start.y = Sy;
	start.istep = 0;

	queue<Horse> q;
	q.push(start);
	visit[Sx][Sy] = true;

	while (!q.empty())
	{
		Horse temHorse = q.front();
		q.pop();
		//到达目的地，终止
		if (temHorse.x == Ex&&temHorse.y == Ey)		//第二题
		{
			return temHorse.istep;					//第三题
		}

		//走所有可能的日字
		for (int i = 0; i < 8; i++)
		{
			int tx = temHorse.x + dx[i];
			int ty = temHorse.y + dy[i];
			//越界
			if (tx > 8 || ty > 9)
			{
				continue;
			}
			//是否走过
			if (visit[tx][ty])
			{
				continue;
			}
			//加入队列
			visit[tx][ty] = true;
			Horse newHorse;
			newHorse.x = tx;
			newHorse.y = ty;
			newHorse.istep = temHorse.istep + 1;		// 第四题
			q.push(newHorse);
		}

	}
	return -1;
}

int main()
{
	int a = run(0, 0, 0, 4);
	cout << a;
	cin >> a;

	return 0;
}