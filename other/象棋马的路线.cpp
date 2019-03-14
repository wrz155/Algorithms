/*
	��������:
		����10�����ߣ�9�����ߣ���90������㣬����p[9][10],������
		�����н�·�ߣ����һ�����ɣ������������
		����������
*/

#include <iostream>
#include <queue>

using namespace std;

//������
typedef struct 
{
	int x;
	int y;
	int istep;
}Horse;

bool visit[9][10];

//������
const int dx[] = { 1,1,-1,-1,2,2,-2,-2 };
const int dy[] = { 2,-2,2,-2,1,-1,1,-1 };		//��һ��

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
		//����Ŀ�ĵأ���ֹ
		if (temHorse.x == Ex&&temHorse.y == Ey)		//�ڶ���
		{
			return temHorse.istep;					//������
		}

		//�����п��ܵ�����
		for (int i = 0; i < 8; i++)
		{
			int tx = temHorse.x + dx[i];
			int ty = temHorse.y + dy[i];
			//Խ��
			if (tx > 8 || ty > 9)
			{
				continue;
			}
			//�Ƿ��߹�
			if (visit[tx][ty])
			{
				continue;
			}
			//�������
			visit[tx][ty] = true;
			Horse newHorse;
			newHorse.x = tx;
			newHorse.y = ty;
			newHorse.istep = temHorse.istep + 1;		// ������
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