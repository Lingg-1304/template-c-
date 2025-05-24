#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 1e5 + 5;

int n , m;
vector<int> adj[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 1 ; i < n ; i++){
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}