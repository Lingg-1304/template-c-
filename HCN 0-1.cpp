#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
int n,m;
ll xuly(vector<int> a){
	stack<int> st;
	int b[m+5],c[m+5];
	ll s[m+5];
	st.push(1);
    for(int i=1;i<=m;i++){
    	while(!st.empty() && a[i] < a[st.top()]){
    		b[st.top()] = i;
    		st.pop();
		}
		st.push(i);
	}
	while(!st.empty()){
		b[st.top()] = -1;
		st.pop();
	}
	st.push(m);
    for(int i=m;i>=1;i--){
    	while(!st.empty() && a[i] < a[st.top()]){
    		c[st.top()] = i;
    		st.pop();
		}
		st.push(i);
	}
	while(!st.empty()){
		c[st.top()] = -1;
		st.pop();
	}
	
    for(int i=1;i<=m;i++){
    	if(c[i] == -1 && b[i] != -1){
    		s[i] = 1ll* a[i] * (b[i] -1);
		}
    	else if(b[i] == -1 && c[i] != -1){
    		s[i] = 1ll* a[i] * (m - c[i]);
		}
		else if(b[i] == -1 && c[i] == -1){
    		s[i] = 1ll* a[i] * m;
		}
		else{
			if(b[i] - 1 == i && c[i] + 1 == i)  s[i] = a[i];
			else s[i] = 1ll* abs(b[i] - c[i] -1) * a[i];
		}
	}

	return *max_element(s+1,s+m+1);
}
int main(){
    fast;
    ll kq = 0;
    cin>>n>>m;
    int x[n+5][m+5];
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		cin>>x[i][j];
		}
	}
	for(int i=n;i>=1;i--){
		vector<int> v;
		v.push_back(-1);
		for(int j=1;j<=m;j++){
			if(x[i][j] == 0) v.push_back(0);
			else{
				int dem=0;
				for(int k=i;k>=1;k--){
					if(x[k][j] == 1) dem++;
					else break;
				}
				v.push_back(dem);
			}
		}
		kq=max(kq,xuly(v));
	}
	cout<<kq;
}
