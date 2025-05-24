#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
struct job{
	int st, end, v;
};
job a[200005];
bool cmp(job a, job b){
	return a.end < b.end;
}
int last_pos(int r, int x){
	int l = 0;
	int res = -1;
	while(l<=r){
		int mid = (l+r)/2;
		if(a[mid].end < x){
			res = mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return res;
}
int main(){
    fast;
    int n; cin>>n;
    for(int i=0;i<n;i++){
    	cin>>a[i].st>>a[i].end>>a[i].v;
	}
	sort(a,a+n,cmp);
	ll f[n];
	f[0]=a[0].v;
	for(int i=1;i<n;i++){
		int pos = last_pos(i-1,a[i].st);
		if(pos == -1){
			f[i]=max(f[i-1], (ll)a[i].v);
		}
		else f[i]=max(f[i-1],f[pos] + a[i].v);
	}
	cout<<f[n-1];
}
