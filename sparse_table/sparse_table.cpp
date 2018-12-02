#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; ++i)

int n, m, x, y;

int t[400005][20], Log = 17;
int F[100005];

inline int Get(int l, int r)
{
	if (l == r)
	{
		return t[l][0];
	}
	if (l > r)
	{
		swap(l, r);
	}
	int Len = F[r - l + 1];
	return min(t[l][Len], t[r - (1 << Len) + 1][Len]);
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> t[1][0] >> x >> y;

	FOR(i, 2, n + 1)
	{
		t[i][0] = (t[i - 1][0] * 23 + 21563) % 16714589;
	}

	FOR(j, 1, Log)
	{
		for(int i = 1;i + (1 << j) - 1 <= n;++i)
		{
			t[i][j] = min(t[i][j-1], t[i+(1 << (j - 1))][j-1]);
		}
	}

	FOR(i, 1, 100005)
	{
		F[i] = 0;
		while((1 << F[i]) < i)
		{
			++F[i];
		}
		F[i]--;
	}

	int Min = Get(x, y);
	FOR(i, 2, m + 1)
	{
		x = ((17 * x + 751 + Min + 2 * (i - 1)) % n) + 1;
		y = ((13 * y + 593 + Min + 5 * (i - 1)) % n) + 1;
		Min = Get(x, y);
	}

	cout << x << ' ' << y << ' ' << Min << endl;


	return 0;
}







