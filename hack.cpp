#include<bits/stdc++.h>
using namespace std;
int main(){
    int dem=0;
    stack<char> st;
    string s; cin>>s;
    for(int i=0;i<s.size();i++){
        if( s[i] == '(' ){
            st.push(s[i]);
        }
        else{
            if(!st.empty()){
                st.pop();
            }
            else{
                dem++;
            }
        }
    }
    if(st.size() == dem){
		cout<<st.size()+dem;
	}
	else if(st.size() > dem){
		cout<<dem*2+(st.size()-dem)/2;
	}
    else{
    	cout<<st.size()*2+(dem-st.size())/2;
	}
}
