#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int mod = 1e9+7;
const int maxn = 1e5 + 5;

int n, ans , check;
int parent[maxn];

struct dinh{
    int s , x , y , z;
};

dinh k[maxn];
bool visited[maxn];
vector<III> canh;

int cal(dinh a , dinh b){
    return min(abs(a.x - b.x) , min(abs(a.y - b.y) , abs(a.z - b.z)));
}

bool cmp1(dinh a , dinh b){
   return a.x < b.x;
}

bool cmp2(dinh a , dinh b){
   return a.y < b.y;
}

bool cmp3(dinh a , dinh b){
   return a.z < b.z;
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
    
    cin >> n;
    
    for(int i = 1 ; i <= n ; i++){
        parent[i] = i;
        k[i].s = i;
        cin >> k[i].x >> k[i].y >> k[i].z;
    }

    sort(k + 1 , k + 1 + n , cmp1);

    for(int i = 1 ; i < n ; i++){
        canh.push_back({ cal(k[i], k[i+1]) , {k[i].s , k[i+1].s} });
    }

    sort(k + 1 , k + 1 + n , cmp2);

    for(int i = 1 ; i < n ; i++){
        canh.push_back({ cal(k[i], k[i+1]) , {k[i].s , k[i+1].s} });
    }

    sort(k + 1 , k + 1 + n , cmp3);

    for(int i = 1 ; i < n ; i++){
        canh.push_back({ cal(k[i], k[i+1]) , {k[i].s , k[i+1].s} });
    }

    sort(canh.begin() , canh.end());

    for(III hh : canh){
        int u = hh.se.fi , v = hh.se.se;
        int w = hh.fi; 
        //cout << u << ' ' << v << ' ' << w << endl;
        if(Union(u,v)){
            //cout << u << ' ' << v << endl;
            ans += w;
            check++;
        }
        if(check == n - 1) break;
    }
    cout << ans << endl;
}