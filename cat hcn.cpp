#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define II pair<int,int>
#define fi first
#define se second
int mod=1e9+7;
int dem=0;
int xuly(int n,int m){
    if(n==m) return dem;
    dem++;
    if(n==1 || m==1) return dem + max(n,m) - 2;
    return xuly(min(n,m),abs(n-m)); 
}
int main(){
    int n,m; cin>>n>>m;
    cout<<xuly(n,m);
}
