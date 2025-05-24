#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<long long,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 5e5;

vector<int> dinh[maxn];
int n , m;
int parent[maxn];

void setup(){
    for(int i = 1 ; i <= n ; i++){
        parent[i] = i;
        dinh[i].push_back(i);
    }
}

int Find(int u){
    if(u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}

bool Union(int u , int v){
    u = parent[u];
    v = parent[v];
    if(u == v){
        return false;
    }
    else{
        if(dinh[u].size() > dinh[v].size()){
            for(int x : dinh[v]){
                dinh[u].push_back(x);
            }
            dinh[v].clear();
            parent[v] = u;
        }
        else{
            for(int x : dinh[u]){
                dinh[v].push_back(x);
            }
            dinh[u].clear();
            parent[u] = v;
        }
        return true;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    setup();
    for(int i = 1 ; i <= m ; i++){
        int u,v; cin >> u >> v;
        Union(u,v);
    }

    for(int i = 1 ; i <= n ; i++){
        cout << parent[i] << " : ";
        for(int x : dinh[i]){
            cout << x << ' ';
        }
        cout << endl;
    }
}