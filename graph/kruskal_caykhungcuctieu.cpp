#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct edge{
    int x, y, w;
};

int n, m, max_size = 1;
int parent[100005], sz[100005];
vector<edge> dscanh;


void ktao(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1; 
    }
}

int Find(int u){
    if(u == parent[u]){
        return u;
    }
    return parent[u] = Find(parent[u]);
}

bool Union(int u, int v){
    u = Find(u); 
    v = Find(v); 
    if(u == v){
        return false;
    }
    else{
        if(sz[u] > sz[v]){
            parent[v] = u;
            sz[u] += sz[v];
        }
        else{
            parent[u] = v;
            sz[v] += sz[u];
        }
        return true;
    }
}
bool cmp(edge a, edge b){
    return a.w < b.w;
}

void kruskal(){
    //B1 : Sort danh sach canh theo trong so tang dan
    sort(dscanh.begin(), dscanh.end(), cmp);
    //B2 : lua
    ll d = 0; // cay khung cuc tieu
    vector<edge> mst; // luu cay khung
    for(int i = 0; i < m; i++){
        if(mst.size() == n - 1) break; // n - 1
        if(Union(dscanh[i].x, dscanh[i].y)){
            mst.push_back(dscanh[i]);
            d += dscanh[i].w;
        }
    }
    if(mst.size() < n - 1){
        cout << "IMPOSSIBLE\n";
    }
    else
        cout << d << endl;
}
int main(){
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    #endif
    cin >> n >> m;
    ktao();
    for(int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        dscanh.push_back({x, y, w});
    }
    kruskal();
}
