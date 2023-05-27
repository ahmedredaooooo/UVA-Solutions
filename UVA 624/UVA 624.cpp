/*                                                     لا اله الا الله محمد رسول الله                                              */
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define sad cin.tie(0);cin.sync_with_stdio(0);
#define el "\n"
#define all(x) x.begin(), x.end()
#define ll  long long
#define Test unsigned int TC; cin >> TC; while(TC--)
#define sz(s) int(s.size())

ll k, n;
vector<ll>a, songs;
bool Break;


ll b_sum(int idx = 0, ll sum = 0) {
    if (idx == n)
        return 0;
    if (a[idx] + sum <= k)
        return max((a[idx] + b_sum(idx + 1, sum + a[idx])), (b_sum(idx + 1, sum)));
    else
        return (b_sum(idx + 1, sum));
}

void takenSongs (int idx, ll sm) {
    if (!sm)
        Break = true;
    if (idx == n || sm < 0 || Break)
        return;
    if (!Break) {
        songs.push_back(idx);
        takenSongs(idx + 1, sm - a[idx]);
    }

    if (!Break) {
        songs.pop_back();
        takenSongs(idx + 1, sm);
    }

}

void solve () {
    Break = 0;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    ll sum = b_sum();
    takenSongs(0,sum);
    for (ll tmp : songs) {
        cout << a[tmp] << " ";
    }
    cout << "sum:" << sum << el;
    a.clear(),songs.clear();
}

int main () {
    while (cin >> k >> n) solve();
}

/*
5 3 1 3 4
10 4 9 8 4 2
20 4 10 5 7 4
90 8 10 23 1 2 3 4 5 7
45 8 4 10 44 43 12 9 8 2

 */