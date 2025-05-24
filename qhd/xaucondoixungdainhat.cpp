#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define II pair<int,int>
#define fi first
#define se second
int mod=1e9+7;
int f[1001][1001];
int main(){
	int ans=1;
    string s; cin>>s;
    int n=s.size();
    s='@'+s+'@';
    for(int i=1;i<=n;i++){
    	f[i][i]=1;
	}
	for(int i=1;i<=n;i++){
		if(s[i]==s[i+1]){
			f[i][i+1]=1;
		    ans = 2;	
		}
	}
	for(int j=3;j<=s.size();j++){
		for(int i=1;i<=s.size()-j+1;i++){
			if(s[i]==s[i+j-1]){
				f[i][i+j-1]=f[i+1][i+j-1-1];
			}
			if(f[i][i+j-1]) ans=max(ans,j);
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<f[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	cout<<ans;
}
