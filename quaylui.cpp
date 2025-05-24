#include<bits/stdc++.h>
using namespace std;
int n,k,dem;
int a[100][100];
void nhap(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            a[i][j]=1;
        }
    }
}
void Try(int i,int j){
    if(i==n && j==k){
        dem++;
    }
    if(i+1<=n && a[i+1][j]==1){
        Try(i+1,j);
    }
    if(j+1<=k && a[i][j+1]==1){
        Try(i,j+1);
    }
}
int main(){
    nhap();
    Try(1,1);
    cout<<dem;
}
