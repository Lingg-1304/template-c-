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

int d[MAX];
using T = tuple <int, int, int>;
// trong so, chi phi, dinh den
// tuple no se sap xep tu phan tu dau tien
vector <T> adj[MAX];
int n, m, k;

void run_case() {
    cin >> k >> n >> m;
    for (int i = 1; i <= n; ++i) adj[i].clear();

    for (int i = 1; i <= m; ++i) {
        int u, v, w, c;
        cin >> u >> v >> w >> c;
        adj[u].push_back({w, c, v});
    }

    priority_queue <T, vector <T>, greater <T>> q;
    // du, cu, u;
    q.push({0, 0, 1});
    while (!q.empty()) {
        auto [du, cu, u] = q.top(); q.pop();
//        debug(du, cu, u);
        if (u == n) {
            cout << du << "\n";
            return;
        }
        for (auto [w, c, v] : adj[u]) {
            if (cu + c <= k) {
                q.push({du + w, cu + c, v});
            }
        }
    }
    cout << "-1\n";
}

signed main() {
    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

