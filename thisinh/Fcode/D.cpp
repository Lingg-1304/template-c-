#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;

vector<int> adj[MAXN]; 
int capacity[MAXN][MAXN];
int parent[MAXN]; 

bool bfs(int s, int t, int n) {
    memset(parent, -1, sizeof(parent));
    queue<pair<int, int>> q;
    q.push({s, INT_MAX});
    
    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
        
        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next] > 0) { 
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

int edmonds_karp(int s, int t, int n) {
    int max_flow = 0, flow;
    
    while (flow = bfs(s, t, n)) {
        max_flow += flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= flow;
            capacity[cur][prev] += flow;
            cur = prev;
        }
    }
    return max_flow;
}

void dfs(int node, bool visited[], int n) {
    visited[node] = true;
    for (int next : adj[node]) {
        if (!visited[next] && capacity[node][next] > 0) {
            dfs(next, visited, n);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int u, v, cap;
        cin >> u >> v >> cap;
        adj[u].push_back(v);
        adj[v].push_back(u); 
        capacity[u][v] = cap;
    }
    
    int s = 0, t = N - 1; 
    int max_flow = edmonds_karp(s, t, N);
    
    bool visited[MAXN] = {false};
    dfs(s, visited, N);
    
    vector<int> cut_set;
    for (int u = 0; u < N; u++) {
        if (visited[u]) {
            for (int v : adj[u]) {
                if (!visited[v] && capacity[u][v] == 0) {
                    cut_set.push_back(u);
                }
            }
        }
    }
    
    cout << max_flow << endl;
    
    for (int u : cut_set) {
        cout << u << " ";
    }
    cout << endl;
    
    return 0;
}
