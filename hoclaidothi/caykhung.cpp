#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<long long,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 10005;

int n , m;
int parent[maxn];

struct canh{
    int x,y,w;
};

vector<canh> v;

bool cmp(canh a , canh b){
    return a.w < b.w;
}

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
    for(int i = 0 ; i < m ; i++){
        canh h;
        cin >> h.x >> h.y >> h.w;
        v.push_back(h);
    }
    sort(v.begin() , v.end() , cmp);

    int check = 0 , ans = 0;
    for(canh h : v){
        if(check == n - 1) break;
        if(Union(h.x , h.y)){
            ans += h.w;
            check++;
        }
    }
    if(check != n - 1) cout << 0;
    else cout << ans ;
}