#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 100005;

int n, ans;

struct dinh{
    int x , y , z;
};

dinh k[maxn];
bool visited[maxn];

int cal(dinh a , dinh b){
    return min(abs(a.x - b.x) , min(abs(a.y - b.y) , abs(a.z - b.z)));
}

void prim(){
    visited[1] = true;
    priority_queue<II , vector<II> , greater<II>> q;

    for(int i = 2 ; i <= n ; i++){
        q.push({cal(k[1] , k[i]) , i});
    }

    int check = 0;

    while(!q.empty()){
        II top = q.top(); q.pop();
        int u = top.se , w = top.fi;
        if(!visited[u]){
            check++;
            ans += w;
            visited[u] = true;
            if(check == n - 1) return;
            for(int i = 1 ; i <= n ; i++){
                if(!visited[i]){
                    q.push({cal(k[u] , k[i]) , i});
                }
            }
        }
    }   
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    memset(visited , false , sizeof(visited));

    for(int i = 1 ; i <= n ; i++){
        cin >> k[i].x >> k[i].y >> k[i].z;
    }

    prim();

    cout << ans;

    //cout << cal(k[1] , k[2]);

}