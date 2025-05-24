#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int mod = 1e9+7;
const int maxn = 105;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int a[maxn][maxn] , visited[maxn][maxn];
int n , m;

priority_queue<III , vector<III> , greater<III>> q;

void bfs(){
    while(!q.empty()){
        III k = q.top(); q.pop();
        int x = k.se.fi , y = k.se.se , h = k.fi;
        visited[x][y] = true;
        for(int i = 0 ; i < 4 ; i++){
            int i1 = x + dx[i];
            int j1 = y + dy[i];
            if(!visited[i1][j1] && a[i1][j1] )
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 2 ; i < m ; i++){
        q.push({a[1][i] , {1,i}});
    }
    for(int i = 2 ; i < m ; i++){
        q.push({a[n][i] , {n,i}});
    }

    for(int i = 2 ; i < n ; i++){
        for(int j = 1 ; j <= m ; j++){
            q.push({a[i][j] , {i,j}});
        }
    }

    while(!q.empty()){
        III x = q.top(); q.pop();
        cout << x.fi << " : " << x.se.fi << "," << x.se.se << endl;
    }
}