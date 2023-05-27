#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "Debug.cpp"
#define FileI(fileName)
#define FileO(fileName)
#else
#define FileI(fileName) freopen(#fileName, "r", stdin);
#define FileO(fileName) freopen(#fileName, "w", stdout);
#define debug(...) 1
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

vector<int>row(8);
vector<vector<int>>vvv;
vector<bool>R(9), D1(15), D2(15);
void rec(int idx = 0) {
    if (idx == 8)return (vvv.push_back(row));
    for (int i = 0; i < 8; ++i) {
        if (!R[i] && !D1[i + idx] && !D2[i - idx + 7]) {
            row[idx] = i + 1, R[i] = D1[i + idx] = D2[i - idx + 7] = 1,
                    rec(idx + 1);
            R[i] = D1[i + idx] = D2[i - idx + 7] = 0;
        }
    }

}

void Solve()
{
    rec();
    vector<int>in(8);
    int cc = 1;
    while (cin >> in[0]){
        int ans = LLONG_MAX;
        for (int i = 1; i < 8; ++i)cin >> in[i];
        for(auto i : vvv)
        {
            int cntr = 0;
            for(int j = 0; j < i.size(); ++j)
            {
                if (i[j] != in[j])
                    cntr++;
            }
            debug(cntr);
            ans = min(cntr , ans);
        }
        cout << "Case " << cc << ": " << ans << "\n";
        cc++;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cerr.tie(0);
    cout.tie(0);

    Solve();
    return 0;
}