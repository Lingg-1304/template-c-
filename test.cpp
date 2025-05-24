#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    if(m > n*9) cout<<"NOT FOUND";
    else{
    string s="";
    int k=m-1;
    //min
    for(int i=0;i<n-1;i++){
        if(k>=9){
        	s+='9';
        	k-=9;
		}
		else if(k>0 && k<9){
			s+=to_string(k);
			k=0;
		}
		else s+='0';
	}
	cout<<k+1;
	for(int i=n-2;i>=0;i--) cout<<s[i];
	cout<<endl;
    //max
    for(int i=0;i<n;i++){
    	if(m>=9){
    		cout<<"9";
    		m-=9;
		}
    	else if(m>0 && m<9){
    		cout<<m;
    		m=0;
		}
		else cout<<"0";
	}
	}
}
