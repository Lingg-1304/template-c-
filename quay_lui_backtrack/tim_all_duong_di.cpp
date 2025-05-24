#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000][1000];
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
	if(i==n && j==n){
		cout<<s<<endl;
	}
	if(a[i+1][j]==1){
		s+="D";
		Try(i+1,j);
		s.pop_back();
	}
	if(a[i][j+1]==1){
		s+="R";
		Try(i,j+1);
		s.pop_back();
	}
}
int main(){
	nhap();
	Try(1,1);
}
