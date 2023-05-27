#include <bits/stdc++.h>

using namespace std;
#define sad cin.tie(0);cin.sync_with_stdio(0);
#define el "\n"
#define ll  long long
#define Test unsigned int TC; cin >> TC; while(TC--)
int mx = 1e9;


vector<int> v(5);
bool x = false;

void fun(int i, int sum) {

    if (i == 5) {
        if (sum == 23)
            x = true;
        return;
    }

    fun(i + 1, sum + v[i]);

    fun(i + 1, sum - v[i]);

    fun(i + 1, sum * v[i]);
}

int main() {
    sad
    while (1) {

        x = false;

        for (int i = 0; i < 5; ++i)
            cin >> v[i];

        if (v[0] == 0 && v[1] == 0 && v[2] == 0 && v[3] == 0 && v[4] == 0)
            break;

        sort(v.begin(), v.end());
        do {
            fun(1, v[0]);
        } while (next_permutation(v.begin(), v.end()));

        if (x)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
}

