#include<bits/stdc++.h>
#define ii pair<int,int>
#define fi first
#define se second
using namespace std;
int c[105][105] , parent[105];
int n , m , s , t ;
vector<ii> canh;
vector<int> adj[105];
int dijk(){
	int d[105];
	for(int i = 1 ; i <= n ; i++) d[i] = 1e9;
	d[s] = 0;
	priority_queue<ii , vector<ii> , greater<ii> > q;
	q.push({0,s});
	while(!q.empty()){
		ii top = q.top(); q.pop();
		int u = top.se , w = top.fi;
		if(w > d[u]) continue;
		for(int i = 0 ; i < adj[u].size() ; i++){
			int v = adj[u][i];
			if(w + c[u][v] < d[v]){
				d[v] = w + c[u][v];
				parent[v] = u;
				q.push({d[v] , v});
			}
		}
	}
	//truy vet duong di
	int e = t;
	vector<int> trace;
	while(e != parent[e]){
		trace.push_back(e);
		e = parent[e];
	}
	for(int i = 0 ; i < trace.size() - 1 ; i++){
		//cout<<trace[i]<<' '<<trace[i+1]<<endl;
		c[trace[i]][trace[i+1]] = -c[trace[i]][trace[i+1]];
	}
	for(int i = trace.size() - 1 ; i > 0 ; i--){
		//cout<<trace[i]<<' '<<trace[i-1]<<endl;
		c[trace[i]][trace[i-1]] = 1e9;
	}

	//tao danh sach canh
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j < i ; j++){
			if(c[i][j] != 1e9){
				canh.push_back({i,j});
			}
		}
		for(int j = i + 1 ; j <= n ; j++){
			if(c[i][j] != 1e9){
				canh.push_back({i,j});
			}
		}
	}

	return d[t];
}

int bellman(){
	// cout<<n<<' '<<canh.size()<<' '<<s<<endl;
	// for(int j = 0 ; j < canh.size() ; j++){
	// 	int u = canh[j].fi , v = canh[j].se , w = c[u][v];
	// 	cout<<u<<' '<<v<<' '<<w<<endl;
	// }

	int d[105];
	for(int i = 1 ; i <= n ; i++) d[i] = 1e9;
	d[s] = 0;
	for(int i = 1 ; i < n ; i++){
		for(int j = 0 ; j < canh.size() ; j++){
			int  u = canh[j].fi , v = canh[j].se , w = c[u][v];
			if(d[u] != 1e9 && d[u] + w < d[v]){
				d[v] = d[u] + w;	
			}
		}
	}
	return d[t];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("tourist.inp","r",stdin);
	// freopen("tourist.out","w",stdout);

	cin >> n >> m >> s >> t;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			c[i][j] = 1e9;
		}
	}
	for(int i = 1 ; i <= n ; i++) c[i][i] = 0;
	for(int i = 0 ; i < m ; i++){
		int u , v , w;
		cin >> u >> v >> w;
		c[u][v] = c[v][u] = w;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int kq = dijk() + bellman();
	cout<<kq<<endl;
}