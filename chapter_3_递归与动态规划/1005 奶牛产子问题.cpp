/*
	ĸţÿ����һֻĸţ���³�����ĸţ�ɳ������Ҳ��ÿ����һֻĸţ�����費������
	��N���ĸţ������
��չ��
	���ÿֻĸţֻ�ܻ�10�꣬��N���ĸţ������
*/
int cowNumber(int n) {
	if (n < 1) {
		return 0;
	}
	if (n == 1 || n == 2 || n == 3) {
		return n;
	}
	return cowNumber(n - 1) + cowNumber(n - 3);
}

int cowNumberCorrect(int n) {
	if (n < 1) {
		return 0;
	}
	if (n == 1 || n == 2 || n == 3) {
		return n;
	}
	int res = 3;
	int pre = 2;
	int prepre = 1;
	int tmp1 = 0;
	int tmp2 = 0;
		for (int i = 4; i <= n; i++) {
			tmp1 = res;
			tmp2 = pre;
			res = res + prepre;
			pre = tmp1;
			prepre = tmp2;
		}
		return res;
	}

	public static void main(String[] args) {
		int n = 20;
		System.out.println(cowNumber1(n));
		System.out.println(cowNumber2(n));
	}

}
