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

bool check()
{

}
int k;
vector<int>S;
void generate()
{
    for (int i = 0; i < k - 5; ++i)
    for (int j = i+1; j < k - 4; ++j)
    for (int l = j+1; l < k - 3; ++l)
    for (int m = l+1; m < k - 2; ++m)
    for (int n = m+1; n < k - 1; ++n)
        for (int ii = n+1; ii < k; ++ii) {
            cout << S[i] << ' ' <<S[j] << ' ' <<S[l] << ' ' << S[m] << ' ' <<S[n] << ' ' << S[ii] << "\n";
        }


}

void Solve()
{
    bool f = 0;
    while (cin >> k)
    {
        if (k == 0)return;
        if(!f)f=1; else cout <<"\n";
        S = vector<int>(k);
        for (int i = 0; i < k; ++i)
            cin >> S[i];
        generate();
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cerr.tie(0);cout.tie(0);

    Solve();
    return 0;
}