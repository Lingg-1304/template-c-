#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<long long,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 50005;

int n,m;
int parent[maxn];

void setup(){
    for(int i = 1; i <= n ; i++) parent[i] = i;
}

int Find(int u){
    if(u == parent[u]){
        return u;
    }
    return parent[u] = Find(parent[u]);
}

bool Union(int u , int v){
    u = Find(u);
    v = Find(v);
    if(u == v){
        return false;
    }
    else{
        parent[u] = v;
        return true;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int tplt = n;
    setup();
    for(int i = 0 ; i < m ; i++){
        int u , v; cin >> u >> v;
        if(Union(u,v)) tplt--;
    }
    cout << tplt;
}