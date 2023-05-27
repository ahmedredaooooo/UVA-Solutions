#include <bits/stdc++.h>
using namespace std ;
#define Test unsigned int TC; cin >> TC; while(TC--)
int s = 0, reach, n;
vector <int>v;
bool f(int idx = 0, int target = reach)
{
    if(!target) return 1;
    if (idx == n)    return 0;
    return f(idx + 1, target) || f(idx + 1, target - v[idx]);
}


void slv()
{

    cin >> reach >> n;
    v.resize(n);
    for(auto &i:v)cin >> i;
    
    cout<<(f()?"YES":"NO");
    v.clear();;
}


signed main()
{
 

   Test slv(), cout<<"\n";
}