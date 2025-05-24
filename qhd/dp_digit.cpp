#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#ifdef JASPER2
#include "debug.h"
#else
#define debug(...) 166
#endif
 
using pii = pair < int, int >;
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
 
int n, m;
int a[MAX];
ll f[18][2][18 * 9];
// i, smaller, sum;
// Dem cac so trong doan [0, X]
string s;
 
ll solve(int i, bool smaller, ll sum) {
    if (i == n)
        return sum;
    if (f[i][smaller][sum] != -1)
        return f[i][smaller][sum];
    // Xac dinh gioi han cua s(i) chuan bi xay dung
    int lim = smaller? 9 : (s[i] - '0');
    ll ans = 0;
    for (int d = 0; d <= lim; ++d) {
        bool nxt_smaller = smaller || (d < s[i] - '0');
        ans += solve(i + 1, nxt_smaller, sum + d);
    }
    return f[i][smaller][sum] = ans;
}
 
ll count(ll x) {
    if (x <= 0)
        return 0;
    s = to_string(x);
    n = s.size();
    memset(f, -1, sizeof f);
    return solve(0, 0, 0);
}
 
void run_case() {
    ll a, b;
    cin >> a >> b;
    cout << count(b) - count(a - 1) << "\n";
}
 
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){
        run_case();
    }
}
 
