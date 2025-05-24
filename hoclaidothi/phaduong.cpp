#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 1e5 + 5;

int n,m;
int parent[maxn];
II canh[maxn];
bool check[maxn];

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
    int q; cin >> q;
    int del[q] , ans[q+1];
    int tplt = n;
    memset(check , false , sizeof(check));
    setup();
    for(int i = 1 ; i <= m ; i++){
        int u , v; cin >> u >> v;
        canh[i] = {u,v};
    }
    for(int i = 0 ; i < q ; i++){
        cin >> del[i];
        check[del[i]] = true;
    }
    for(int i = 1 ; i <= m ; i++){
        if(!check[i]){
            if(Union(canh[i].fi,canh[i].se)){
                tplt--;
            }
        }
    }
    ans[q] = tplt;
    for(int i = q - 1 ; i >= 0 ; i--){
        if(Union(canh[del[i]].fi , canh[del[i]].se)){
            tplt--;
        }
        ans[i] = tplt;
    }
    for(int i = 1 ; i <= q ; i++){
        cout << ans[i] << endl;
    }
}