#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,t="",tmp;
    cin>>s;
    stringstream ss(s);
    while(getline(ss,tmp,'/')){
        if(tmp.size()==1){
            t+="0"+tmp+"/";
        }
        else t+=tmp+"/";
    }
    for(int i=0;i<t.size()-1;i++) cout<<t[i];
}
