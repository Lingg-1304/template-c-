#include<bits/stdc++.h>
using namespace std;
string check(string s){
    string tmp,res="";
    stringstream ss(s);
    while(getline(ss,tmp,'/')){
        if(tmp.size()==2 && tmp[0]=='0'){
            res+=tmp[1];
        }
        else res+=tmp;
    }
    return res;
}
int main(){
	freopen("inp.txt","r",stdin);
	freopen("out.txt","w",stdout);
	map<string,int> mp;
    string tmp;
    int n;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
    	string k,tt="";
    	getline(cin,k);
    	stringstream ss(k);
        int dem=0;
        string s[100]={""};
        while(ss>>tmp){
            s[dem]=tmp;
            dem++;
        }
        for(int j=0;j<s[dem-2].size();j++){
            s[dem-2][j]=tolower(s[dem-2][j]);
            cout<<s[dem-2][j];
            tt+=s[dem-2][j];
        }
        mp[tt]++;
        if(mp[tt] == 1) cout<<"nv@xyz.edu.vn";
        else cout<<"nv"<<mp[tt]<<"@xyz.edu.vn";
        cout<<endl<<check(s[dem-1])<<endl;
    }
}
