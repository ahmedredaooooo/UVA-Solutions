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

int n;
int numOfDivisors(int x)
{
    int c = 0;
    for (int i = 1; i * i <= x; ++i) {
        if (i * i == x)
            c++;
        else if (x % i == 0)
            c += 2;
    }
    return c;
}
void Solve()
{
    cout << ((int)sqrtl(n) * (int)sqrtl(n) == n ?"yes": "no") ;
}

signed main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cerr.tie(0); std::cout.tie(0);

   while (1){cin >> n; if (n)Solve(), cout << "\n"; else
    return 0;}
}