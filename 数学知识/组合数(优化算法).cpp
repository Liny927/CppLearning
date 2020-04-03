int res[1010][1010] = {0};
int C(int n, int m, int p) {
	if(m == 0 || m == n) return 1;
	if(res[n][m] != 0) return res[n][m];
	return res[n][m] = (C(n - 1, m) + C(n - 1, m - 1)) % p;
}