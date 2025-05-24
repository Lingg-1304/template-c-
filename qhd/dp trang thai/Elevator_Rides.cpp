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
const int MAX = 20 + 5;

int n, X;
pii f[1 << MAX];
// (fi : so lan su dung thang may, se : trong luong con lai cua thang may hien tai)
int w[MAX];
void run_case() {
    cin >> n >> X;
    for (int i = 0; i < n; ++i)
        cin >> w[i];

    for (int i = 0; i < (1 << n); i++)
        f[i] = {INF, 0};

    f[0] = {1, 0};
    for (int msk = 0; msk < (1 << n); msk++) {
        for (int j = 0; j < n; j++) {
            if (msk & (1 << j))
                continue;
            int nxt_msk = msk | (1 << j);
            pii cur = f[msk];
            if (cur.se + w[j] <= X)
                cur.se += w[j];
            else {
                cur.fi++;
                cur.se = w[j];
            }
            f[nxt_msk] = min(f[nxt_msk], cur);
        }
    }
    cout << f[(1 << n) - 1].fi << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
