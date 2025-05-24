#include <bits/stdc++.h>
using namespace std;
int main(){
//	freopen("inp.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,s;
	cin>>n>>s;
	string ss="";
	if(s> n*9) cout<<"NOT FOUND";
	else if(s==n*9){
		for(int i=0;i<n;i++) cout<<"9";
	}
	else{
		int dem=0;
		while(s > 9){
			ss+="9";
			s-=9;
			dem++;
		}	
	cout<<s;
	for(int i=ss.size()-1;i>=0;i--) cout<<ss[i];
	cout<<endl<<ss<<s;
	}
}
