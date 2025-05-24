#include <bits/stdc++.h>
using namespace std;
bool check(string s){
	int k=1e6;
	vector<int> y;
	vector<int> t;
	vector<int> h;
	vector<int> o;
	vector<int> n;
	for(int i=0;i<s.size();i++){
		if(s[i] == 'y') y.push_back(i);
		if(s[i] == 't') t.push_back(i);
		if(s[i] == 'h') h.push_back(i);
		if(s[i] == 'o') o.push_back(i);
		if(s[i] == 'n') n.push_back(i);
	}
	for(int i=0;i<s.size();i++){
		if(s[i] == 'p'){
			k=i;
			break;
		}
	}
	if(k==1e6) return false;
	else if(y.size()==0 || t.size()==0 || h.size()==0 || o.size()==0 || n.size()==0) return false;
	else{
        int Y=*lower_bound(y.begin(),y.end(),k); if(Y==0 || Y>10000) return false;	
	    int T=*lower_bound(t.begin(),t.end(),Y); if(T==0 || T>10000) return false; 
	    int H=*lower_bound(h.begin(),h.end(),T); if(H==0 || H>10000) return false;
	    int O=*lower_bound(o.begin(),o.end(),H); if(O==0 || O>10000) return false;
	    int N=*lower_bound(n.begin(),n.end(),O); if(N==0 || N>10000) return false;
	    return true;
	}
}
int main(){
	string s;
	cin>>s;
	if(check(s) && s.size()>=6) cout<<"YES";
	else cout<<"NO";
}
