#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n , parent[maxn] , sum[maxn] , t[maxn];
int ans = 0;
bool visit[maxn];
vector<int> kq;
int findset(int u){
	if(u == parent[u]) return u;
	return parent[u] = findset(parent[u]);
}
bool Union(int u){
	u = findset(u);
	int a = findset(u+1) , b = findset(u-1);
	if(visit[u+1] && visit[u-1]){
		sum[u] += sum[a] + sum[b];
		ans = max(ans , sum[u]);
		parent[a] = u;
		parent[b] = u;
		return true;
	}
	else if(visit[u+1]){
		sum[u] += sum[a];
		ans = max(ans , sum[u]);
		parent[a] = u;
		return true;
	}
	else if(visit[u-1]){
		sum[u] += sum[b];
		ans = max(ans , sum[u]);
		parent[b] = u;
		return true;
	}
	ans = max(ans,sum[u]);
	return false;
}
int main(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> sum[i];
	for(int i = 1 ; i <= n ; i++){
		parent[i] = i;
		visit[i] = false;
	}

	for(int i = n ; i >= 1 ; i--) cin >> t[i];
	kq.push_back(0);
	for(int i = 1 ; i < n ; i++){
		visit[t[i]] = true;
		Union(t[i]);
		kq.push_back(ans);
	}
	reverse(kq.begin(),kq.end());
	for(int x : kq) cout<<x<<endl;
}