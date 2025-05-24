#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n,m,s,t;
vector<II> water;
char a[1505][1505];
int timer[1505][1505];
int d[1505][1505];
void loang(int i,int j){
	timer[i][j] = 0;
    queue<II> q;
    q.push({i,j});
    while(!q.empty()){
        int x = q.front().fi; 
        int y = q.front().se;
        q.pop();
        a[x][y] = 'S';
        for(int k=0;k<4;k++){
            int i1 = x + dx[k];
            int j1 = y + dy[k];
            if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 'O'){
                q.push({i1,j1});
                a[i1][j1] = 'S';
                timer[i1][j1] = max(timer[i1][j1] , timer[x][y] + 1);
            }
        }     
    }
}
void bfs(int i,int j){
	d[i][j] = 0;
    queue<II> q;
    q.push({i,j});
    while(!q.empty()){
        int x = q.front().fi; 
        int y = q.front().se;
        q.pop();
        a[x][y] = 'K';
        for(int k=0;k<4;k++){
            int i1 = x + dx[k];
            int j1 = y + dy[k];
            if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m){
				if(a[i1][j1] == 'O'){
					q.push({i1,j1});
					d[i1][j1] = d[x][y] + 1;
					a[i1][j1] = 'K';
				}
				else if(a[i1][j1] == 'S' && d[x][y] + 1 < timer[i1][j1]){
                	q.push({i1,j1});
                	d[i1][j1] = d[x][y] + 1;
                	a[i1][j1] = 'K';
				}
            }
        }     
    }
}
int main(){
    fast;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j] == 'E'){
            	s=i;
            	t=j;
			}
			else if(a[i][j] == 'S'){
				water.push_back({i,j});
			}
        }
    }
    
    for(II k : water){
    	loang(k.fi , k.se);
	}
    bfs(s,t);
    
//    for(int i=1;i<=n;i++){
//    	for(int j=1;j<=m;j++){
//    		cout<<a[i][i]<<","<<d[i][j]<<' ';
//		}
//		cout<<endl;
//	}
    
    
    int kq = 1e9;
    for(int i=1;i<=m;i++){
    	if(a[1][i] == 'K'){
    		kq = min(kq,d[1][i]);
		}
	}
	for(int i=1;i<=n;i++){
    	if(a[i][1] == 'K'){
    		kq = min(kq,d[i][1]);
		}
	}
	for(int i=1;i<=m;i++){
    	if(a[n][i] == 'K'){
    		kq = min(kq,d[n][i]);
		}
	}
	for(int i=1;i<=n;i++){
    	if(a[i][m] == 'K'){
    		kq = min(kq,d[i][m]);
		}
	}
	if(kq == 1e9){
		cout<<"-1";
	}
	else cout<<kq+1;
}
