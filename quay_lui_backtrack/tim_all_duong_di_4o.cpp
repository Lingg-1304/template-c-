#include<bits/stdc++.h>
using namespace std;
int n,dem;
int a[100][100];
void nhap(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
}
string s;
void Try(int i,int j){
	a[i][j]=0;
    if(i==n && j==n){
        cout<<s<<endl;
        dem++;
    }
    if(i+1<=n && a[i+1][j]==1){
        s+="D";
        Try(i+1,j);
        s.pop_back();
    }
    if(j+1<=n && a[i][j+1]==1){
        s+="R";
        Try(i,j+1);
        s.pop_back();
    }
    if(i>1 && a[i-1][j]==1){
        s+="U";
        Try(i-1,j);
        s.pop_back();
    }
    if(j>1 && a[i][j-1]==1){
        s+="L";
        Try(i,j-1);
        s.pop_back();
    }
    a[i][j]=1;
}
int main(){
    nhap();
    Try(1,1);
    if(dem==0) cout<<"-1";
}
