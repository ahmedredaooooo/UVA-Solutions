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


vector<bool>prime(33), isUsed(50);
int n;
vector<vector<int>>V, V1;
vector<int>tmp;

bool check()
{

}

void generate(int idx = 1)
{
    if(idx == n && prime[tmp[n-1]+1])
    {

        return(V1.push_back(tmp));
    }
    else if (idx == n)return;

    for (int i = 2; i <= n; ++i)
    {

        if (prime[tmp[idx - 1] + i] && !isUsed[i])
        {

            tmp[idx] = i, isUsed[i] = 1;
            generate(idx + 1);
            isUsed[i] = 0;
        }
    }
}

void Solve() {

    int testt = 1;
    while(cin >> n) {
        tmp = vector<int>(n);
        prime[2] = prime[3] = prime[5] = prime[7] = prime[11] = prime[13] = prime[17] = prime[19] = prime[23] = prime[29] = prime[31] = tmp[0] = 1;
        generate();
//
//        tmp.resize(n);
//        for (int i = 0; i < n; ++i)
//            tmp[i] = i + 1;
//
//        do
//        {
//            if (check() && tmp[0] == 1)V.push_back(tmp);
//        } while (next_permutation(allc(tmp)));
//        set<vector<int>> SV;
//        for (auto i: V)
//        {
//            vector<int> tmp = i;
//            reverse(1 + i.begin(), i.end());
//            if (!SV.count(i) && !SV.count(tmp))
//                SV.insert(i);
//        }
////    generate();
////    for(auto i : V)
////    {
////        for (auto j: i) {
////            cout << j << " ";
////        }
////        cout << "\n";
////    }
//        debug(V);
//        debug(SV);

        if (testt != 1)cout << "\n";
        cout << "Case " << testt++ << ":\n";
        for (auto i: V1)
        {
            for (int j = 0; j < i.size(); ++j)
                cout << i[j] << " \n" [j == i.size() - 1];
//            cout << "\n";
        }
//        cout << "\n";
        V1.clear();
//        SV.clear();
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cerr.tie(0);cout.tie(0);

    Solve();
    return 0;
}