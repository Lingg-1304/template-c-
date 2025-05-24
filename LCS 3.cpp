#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int mod = 1e9+7;
int f[1001][1001][1001];
int max3(int a,int b,int c){
	if(a>b && a>c) return a;
	if(b>a && b>c) return b;
	return c;
}
int main(){
    fast;
    string a,b,c; cin>>a>>b>>c;
    int n = a.size();
    int m = b.size();
    int k = c.size();
    a='@'+a;
    b='@'+b;
    c='@'+c;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		for(int o=1;o<=k;o++){
    			if(a[i]==b[j] && b[j]==c[o]){
    				f[i][j][o]= 1 + f[i-1][j-1][o-1];
				}
				else{
					f[i][j][o] = max3(f[i-1][j][o],f[i][j-1][o],f[i][j][o-1]);
				}
			}
		}
	}
	cout<<f[n][m][k];
}
