#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<long long,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 1005;

int n , m;
struct canh{
    int u , v , t;
};

bool cmp(canh a , canh b){
    return a.t < b.t;
}

vector<canh> v;
int parent[maxn];

void setup(){
    for(int i = 1 ; i <= n ; i++) parent[i] = i;
}

int Find(int u){
    if(u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}

bool Union(int u , int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    parent[u] = v;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    cin >> n >> m;
    setup();

    for(int i = 0 ; i < m ; i ++){
        canh k;
        cin >> k.u >> k.v >> k.t;
        v.push_back(k);
    }

    sort(v.begin() , v.end() , cmp);

    int check = 0 , d = 0;
    for(canh x : v){
        if(Union(x.u , x.v)){
            d = max(d,x.t);
            check++;
        }
        if(check == n - 1) break;
    }
    cout << d;
}