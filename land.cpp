#include<bits/stdc++.h>
using namespace std;
int a[1001][1001],b[1001][1001],n,m;
void inp(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
}
void loang(int i,int j){
	b[i][j]=0;
	if(i<=n&&j<=m){
	if(b[i-1][j]!=0) loang(i-1,j);
	if(b[i+1][j]!=0) loang(i+1,j);
	if(b[i][j-1]!=0) loang(i,j-1);
	if(b[i][j+1]!=0) loang(i,j+1);
	}
}
int xuly(int test){
	int dem=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]<=test){
				b[i][j]=0;
			}
			else b[i][j]=a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]>0){
				loang(i,j);
				dem++;
			}
		}
	}
	return dem;
}
int main(){
    freopen("land.inp","r",stdin);
    freopen("land.out","w",stdout);
    inp();
	int k;
	cin>>k;
	for(int i=1;i<=k;i++){
		int x; cin>>x;
		cout<<xuly(x)<<" ";
	}
}

