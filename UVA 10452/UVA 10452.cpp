#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "Debug.cpp"
#define FileI(fileName)
#define FileO(fileName)
#else
#define FileI(fileName) freopen(#fileName, "r", stdin);
#define FileO(fileName) freopen(#fileName, "w", stdout);
#define Time(i, x...) x
#endif
#define un unsigned
#define ld long double
#define LL long long
#define int LL
#define allc(x) x.begin(), x.end()
#define rallc(x) x.rbegin(), x.rend()
#define all(x,i,j) x.begin() + i, x.begin() + j
#define Test int TC; cin >> TC; while(TC--)

int n, m, head, r;
string path = "IEHOVA#";
vector<vector<char>> g;

vector<int>di = {0, 0, -1}, dj = {1, -1, 0};
vector<string>direction = {"right", "left", "forth"}, answer;

bool isValid(int i, int j)
{
	return i >= 0 && i < n && j >= 0 && j < m;
}

int c;
void dfs(int i, int j)
{
	if (c > 7)return;
	for (int k = 0; k < 3; ++k)
	{
		int iRoad = di[k] + i, jRoad = dj[k] + j;
		if (isValid(iRoad, jRoad) && path[c] == g[iRoad][jRoad])
		{
			answer.push_back(direction[k]); c++;
			dfs(iRoad, jRoad);
		}
	}
}

void Solve()
{
	g.clear();
	answer.clear();
	c = 0;
	int startX, startY;
	cin >> n >> m;
	g.resize(n, vector<char>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			cin >> g[i][j];
			if (g[i][j] == '@')
				startX = i, startY = j;
		}
	dfs(startX, startY);
	cout << answer[0];
	for (int i = 1; i < 7; ++i)
		cout << ' ' << answer[i];
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cerr.tie(0); cout.tie(0);
	Test
	Solve(), cout << "\n";
	return 0;
}

