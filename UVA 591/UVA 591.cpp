#include <bits/stdc++.h>
using namespace std;

#define un unsigned
#define el "\n"
#define ll  long long
#define Test unsigned int TC; cin >> TC; while(TC--)
#define loop(n) for(int i =0; i<n; i++)

void FAST()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
}

void solve() {}
int main() {
    ll a=1;
    while(2002) {
        int n;
        cin >> n;
        if (n == 0)break;
        int arr[n + 7], s = 0;
        loop(n) {
            cin>>arr[i];
            s += arr[i];
        }
        int avg = s/n;
        int ans = 0;
        loop(n)
        {
            if (arr[i] > avg){
                ans += arr[i]-avg;
            }
        }
        cout<< "Set #" << a++ << el << "The minimum number of moves is "<<ans<<".\n\n";
    }
}
