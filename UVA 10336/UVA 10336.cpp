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
int n, m;
vector<vector<vector<pair<int, int>>>>graph;
vector<vector<char>>grid;
vector<vector<bool>>vis;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int ni, nj;
bool isValid(int i, int j)
{
	return i >= 0 and j >= 0 and i < n and j < m;
}

void DFS(int i, int  j)
{
	vis[i][j] = 1;
	for (auto[l, r] : graph[i][j])
		if (!vis[l][r])DFS(l, r);
}
int tst;
void Solve() {
	cin >> n >> m;
	graph = vector<vector<vector<pair<int, int>>>>(n, vector<vector<pair<int, int>>>(m));
	grid = vector<vector<char>>(n, vector<char>(m));
	vis = vector<vector<bool>>(n, vector<bool>(m));

	map<char, int>mp;
	vector<pair<char, int>>ans;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> grid[i][j], mp[grid[i][j]];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			for (int k = 0; k < 4; ++k)
			{
				ni = i + dx[k];
				nj = j + dy[k];
				if (isValid(ni, nj) && grid[ni][nj] == grid[i][j])
					graph[i][j].push_back({ni, nj});
			}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (!vis[i][j])
				mp[grid[i][j]]++ , DFS(i, j);
	for (auto [l, r] : mp)
		ans.push_back({l, r});

	sort(allc(ans), [&](auto l, auto r) {
		if (l.second == r.second)
			return l.first < r.first;
		return l.second > r.second;
	});
	cout << "World #" << ++tst << '\n';
	for (auto [l, r] : ans)
		cout << l << ": " << r << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cerr.tie(0); cout.tie(0);
	Test
	Solve();
	return 0;
}
