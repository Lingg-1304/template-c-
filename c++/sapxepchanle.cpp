#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	if(x%2==1 && y%2==1 && x>y) return true;
	else if(x%2==0 && y%2==0 && x<y) return true;
	else if(x%2==1 && y%2==0 && x<y) return true;
//	else if(x%2==1 < y%2==0 ) return true;
	else return false;
}
int main(){
	freopen("inp.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
