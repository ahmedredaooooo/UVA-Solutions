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

int n, x;

vector < vector<char>>grid;
vector < vector<bool>>vis;

vector<vector<vector<pair<int, int>>>>adj;

bool isValid(int i, int j)
{
	return 0 <= i && i < n && 0 <= j && j < n;
}

void DFS(int i, int j)
{
	vis[i][j] = 1;

	for (auto [ci, cj] : adj[i][j])
		if (!vis[ci][cj])
			DFS(ci, cj);
}
int tst = 1;
void Solve()
{

	grid = vector<vector<char>>(n+5, vector<char>(n+5));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> grid[i][j];

	adj = vector<vector<vector<pair<int, int>>>>(n+5,  vector<vector<pair<int, int>>>(n+5));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = -1; k <= 1; ++k)
				for (int l = -1; l <= 1; ++l)
				{
					int ni = i + k, nj = j + l;
				    	if ((k || l) && isValid(ni, nj) && grid[i][j] == '1' && grid[ni][nj] == '1')
					    	adj[i][j].push_back({ni, nj});
				}
//	debug(adj);
	vis = vector<vector<bool>>(n+5, vector<bool>(n+5));
	int c = 0;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (!vis[i][j] && grid[i][j] == '1')
				DFS(i, j), c++;

	cout << "Image number "<<tst++<<" contains "<<c<<" war eagles.";

}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cerr.tie(0); cout.tie(0);
	// Test
	while(cin >> n)Solve(), cout << "\n";
	return 0;
}

