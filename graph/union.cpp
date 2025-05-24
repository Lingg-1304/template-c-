#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int mod = 1e9+7;
int n,m;
int parent[1505],sz[1505];
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
int main(){
    fast;
    
}
