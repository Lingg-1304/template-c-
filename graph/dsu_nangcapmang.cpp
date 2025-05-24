#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cable {
    int u, v, cost;
};

bool cmp(const Cable& a, const Cable& b) {
    return a.cost < b.cost;
}

int find(vector<int>& parent, int u) {
    if (parent[u] == u)
        return u;
    parent[u] = find(parent, parent[u]);
    return parent[u];
}

void unionSets(vector<int>& parent, int u, int v) {
    int pu = find(parent, u);
    int pv = find(parent, v);
    if (pu != pv)
        parent[pu] = pv;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<Cable> cables(m);
    for (int i = 0; i < m; ++i) {
        cin >> cables[i].u >> cables[i].v >> cables[i].cost;
    }

    sort(cables.begin(), cables.end(), cmp);

    vector<int> parent(n + 1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    int totalCost = 0;
    for (int i = 0; i < m; ++i) {
        int u = cables[i].u;
        int v = cables[i].v;
        int cost = cables[i].cost;

        if (find(parent, u) != find(parent, v)) {
            unionSets(parent, u, v);
            totalCost += cost;
        }
    }

    cout << totalCost << endl;

    return 0;
}
