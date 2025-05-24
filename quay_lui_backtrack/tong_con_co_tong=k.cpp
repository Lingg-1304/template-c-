#include<bits/stdc++.h>
using namespace std;
int n,k,s,dem=0;
int a[1000],x[1000];
void nhap(){
	cin>>n>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
}
void Try(int i,int pos,int tong){
	for(int j=pos;j<n;j++){
		x[i]=a[j];
		tong+=x[i];
		if(tong==s){
			cout<<"[";
			string s="";
			for(int o=1;o<=i;o++){
				s+=to_string(x[o])+" ";
			}
			s.pop_back();
			cout<<s;
			cout<<"]"<<endl;
		}
		else{
			Try(i+1,j+1,tong);
		}
		tong-=x[i];
	}
}
int main(){
	nhap();
	Try(1,0,0);
}
