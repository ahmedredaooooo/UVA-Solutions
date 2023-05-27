/*                                                     لا اله الا الله محمد رسول الله                                              */
#include <bits/stdc++.h>

using namespace std;
#define sad ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define el '\n'
#define all(x) x.begin(), x.end()
#define LL  long long
#define int LL
#define ld long double
#define un unsigned
#define Test unsigned int TC; cin >> TC; while(TC--)
#define sz(s) int(s.size())
#define NO cout<<"NO";
#define YES cout<<"YES";
#define FILE freopen("Input.txt", "r", stdin);

string tolower_String(string s) {
    string tmp= "";
    for (char& ch: s) {
        ch = towlower(ch);
        if (ch >= 'a' and ch <= 'z')
            tmp.push_back(ch);
        else
            return tmp;
    }
    return tmp;
}
bool IsLowerCharacter(char c) {
    return c >= 'a' && c <= 'z';
}

void Solve() {
    set<string> st;
    vector<string> v;
    string s;
    while (cin >> s) {
        string cur = "";
        for (int i = 0; i < s.size(); ++i) {
            char c = tolower(s[i]);
            if (IsLowerCharacter(c))
                cur += c;
            else if (cur != "") {
                st.insert(cur);
                cur = "";
            }
        }
        if (cur != "")
            st.insert(cur);
    }
    for (auto it = st.begin(); it != st.end(); ++it)
        cout << *it << '\n';
}


signed main() {
    sad
    Solve();

}
