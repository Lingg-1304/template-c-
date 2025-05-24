#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n,s,t,u,v,a[101][101];
void inp(){
    cin>>n>>s>>t>>u>>v;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
}
void loang(int i,int j){
    a[i][j]=0;
    if(i>0 && j>0 && i<=n && j<=n){    
    if(a[i-1][j-2]==1) loang(i-1,j-2);
    
    if(a[i-1][j+2]==1) loang(i-1,j+2);
    
    if(a[i+1][j-2]==1) loang(i+1,j-2);
    
    if(a[i+1][j+2]==1) loang(i+1,j+2);
    
    if(a[i+2][j-1]==1) loang(i+2,j-1);
    
    if(a[i+2][j+1]==1) loang(i+2,j+1);
    
    if(a[i-2][j-1]==1) loang(i-2,j-1);    
        
    if(a[i-2][j+1]==1) loang(i-2,j+1);
    }
}
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    inp();
    loang(s,t);
    if(a[u][v]==0) cout<<"YES";
    else cout<<"NO";
}
