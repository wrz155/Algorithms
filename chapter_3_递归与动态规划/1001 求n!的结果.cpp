/*
	求n!的结果
*/
long long getFactorialByRecursion(int n) {
	if (1 == n) {
		return 1LL;
	}
	return (long long)n * getFactorialByRecursion(n - 1);
}

long long getFactorialByLoop(int n) {
	long long result = 1LL;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}
