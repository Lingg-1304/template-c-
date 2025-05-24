#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int mod = 1e9+7;
int f[1001][1001];
int main(){
    fast;
    string a,b; cin>>a>>b;
    int n = a.size();
    int m = b.size();
    a='@'+a;
    b='@'+b;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		if(a[i]==b[j]){
    			f[i][j]=1+f[i-1][j-1];
			}
			else{
				f[i][j]=max(f[i-1][j],f[i][j-1]);
			}
		}
	}
	cout<<f[n][m];
	//truy vet
	string ans="";
	int i = n; 
    int j = m;
    while(f[i][j] != 0){ // Ði?u ki?n d?ng
        if(a[i] == b[j]){  // N?u b?ng nhau
            ans += a[i];   // C?ng a[i-1] vào xâu con
            i--;
            j--;
        }
        else{  // N?u khác nhau
            if(f[i-1][j] >= f[i][j-1]) // So sánh
                i--;
            else
                j--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<endl<<ans;
}
