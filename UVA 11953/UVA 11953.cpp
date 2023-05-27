#include <bits/stdc++.h>
using namespace std;

int n, x, y;
vector<vector<char>> grid;
vector<vector<int>>vis;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool valid(int &i, int &j)
{
    return i >= 0 && i < n && j < n && j >=0;
}

void dfs(int i, int j)
{
    vis[i][j] = 1;
            for (int m = 0; m < 4; ++m)
            {
                x = i + dx[m], y = j + dy[m];
                if (valid(x, y) && !vis[x][y] && grid[x][y] != '.')
                    dfs(x, y);
            }
}

int Case = 1;
void Solve()
{
    cin >> n;
    grid  = vector<vector<char>>(n, vector<char>(n));
    vis   = vector<vector<int>>(n, vector<int>(n));

    for(auto &i : grid)
        for(auto &j : i)
            cin >> j;
    
    int c = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (grid[i][j] == 'x' && !vis[i][j])
                dfs(i, j), c++;

    cout << "Case "<< Case++ <<": " << c;
}
signed main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cerr.tie(0); std::cout.tie(0);
   int t;cin >> t; while (t--) Solve(), cout << '\n';
}
