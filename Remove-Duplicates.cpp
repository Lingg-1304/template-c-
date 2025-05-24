#include<bits/stdc++.h>
using namespace std;
int main(){
    int dem=0;
    stack<char> st;
    string s; cin>>s;
    st.push(s[0]);
    cout<<s[0];
    for(int i=1;i<s.size();i++){
        if(s[i]!=st.top()){
            st.push(s[i]);
            cout<<s[i];
        }
    }
}
