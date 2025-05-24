#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int mod = 1e9+7;
ll a[105];
ll f[1000001];
int main(){
    fast;
    ll s,n; cin>>n>>s;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        f[a[i]]=1;
        for(int j=a[i]+1;j<=s;j++){
            if(f[j-a[i]]>0){
                if(f[j]>0){
                    f[j]=min(f[j],f[j-a[i]]+1);
                }
                else f[j]=f[j-a[i]]+1;
            }
        }
    }
    cout<<f[s];
}
