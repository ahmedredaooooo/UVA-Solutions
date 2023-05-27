#include <bits/stdc++.h>
using namespace std ;
#define ll long long
#define Test unsigned int TC; cin >> TC; while(TC--)
int n, x;

ll f(int i)
{
    if(!i) return 0;
    return i % 10 + f(i / 10);
}


void slv()
{
    while(n >= 10) n = f(n);
    cout << n;

}


signed main()
{
    while (1)
    {
        cin >> n;
        if(!n)break;
        slv();
        cout << "\n";
    }
}