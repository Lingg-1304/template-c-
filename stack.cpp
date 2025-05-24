#include<bits/stdc++.h>
using namespace std;
int k;
string s;
void check(string s){
	stack<char> st;
	int dem=0;
	for(int i=0;i<s.size();i++){
		dem++;
		st.push(s[i]);
		if(s[i]!=s[i+1]){
			if(dem==k){
			for(int j=0;j<k;j++){
				st.pop();
			}
			s.erase(i+1-k,k);
			i=0;
		    }
			dem=0; 
		}
    }
    if(s.size()==0){
    	cout<<"EMPTY";
	}
	else cout<<s;
}
int main(){
	getline(cin,s);
	cin>>k;
	string kq="";
	stack<char> st;
	int dem=0;
	for(int i=0;i<s.size();i++){
		dem++;
		st.push(s[i]);
		if(s[i]!=s[i+1]){
			if(dem==k){
			for(int j=0;j<k;j++){
				st.pop();
			}
			s.erase(i+1-k,k);
			i=0;
		    }
			dem=0; 
		}
    }
    check(s);
	
}
