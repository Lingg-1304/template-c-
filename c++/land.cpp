#include<bits/stdc++.h>
using namespace std;
int a[1001][1001],n,m;
void inp(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
}
void loang(int i,int j,int up){
	a[i][j]=up;
	if(i<=n&&j<=m){
	if(a[i-1][j]>up) loang(i-1,j,up);
	if(a[i+1][j]>up) loang(i+1,j,up);
	if(a[i][j-1]>up) loang(i,j-1,up);
	if(a[i][j+1]>up) loang(i,j+1,up);
	}
}
int xuly(int test){
	int dem=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]>test){
				loang(i,j,test);
				dem++;
			}
		}
	}
	return dem;
}
int main(){
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
    inp();
//	int k;
//	cin>>k;
//	for(int i=1;i<=k;i++){
//		int x; cin>>x;
//		cout<<xuly(x)<<" ";
//	}
    xuly(2);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

