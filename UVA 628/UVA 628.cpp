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

vector<string>Wrds;
    int n;
string s;
vector<string>out(1000);
void Solve(int idx)
{
    if (idx == s.size())
    {
        for (int i = 0; i < idx; ++i) cout << out[i];
        cout << "\n";
        return;
    }
    if (s[idx] == '0')
    {
        for (int i = 0; i < 10; ++i) out[idx] = to_string(i%10), Solve(idx+1);
    }
    else
    {
        for (int i = 0; i < n; ++i) out[idx] = Wrds[i], Solve(idx+1);
    }
}


void Solve()
{
    while (cin >> n)
    {
        cout <<"--\n";
        Wrds.clear();
        for (int i = 0; i < n; ++i)
        {
            string tmp;cin>>tmp;Wrds.push_back(tmp);
        }
        int numOfRules;cin >> numOfRules;
        while (numOfRules--)
        {
            cin >> s;
            Solve(0);
        }
    }
}

signed main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cerr.tie(0);
//    cout.tie(0);
//Test
//cout << to_string(0);
    Solve();
//    return 0;
}