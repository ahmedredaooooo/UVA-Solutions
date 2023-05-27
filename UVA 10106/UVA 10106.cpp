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
#define Test int TC; std::cin >> TC; while(TC--)


void Solve()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        if (s1 == "0" || s2 == "0")
        {
            cout <<"0\n";
            continue;
        }
        vector<int>v(s1.size() + s2.size() - 1);
        for (int i = 0; i < s1.size(); ++i)
            for (int j = 0; j < s2.size(); ++j)
                v[i + j] += (int) (s1[i] - '0') * (int) (s2[j] - '0');
        reverse(allc(v));

        for(int i = 0, x; i < v.size() - 1; ++i)
            x = v[i], v[i] %= 10, v[i+1] += x / 10;

        reverse(allc(v));
        for(auto i : v)cout << i;
        cout << "\n";

    }
/*
    12
    12

     24
    120
    2


    12
    13

    26
   130
   156
    */
}

signed main()
{
//    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cerr.tie(0); std::cout.tie(0);

    Solve();
    return 0;
}