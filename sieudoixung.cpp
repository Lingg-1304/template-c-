#include<bits/stdc++.h>
using namespace std;
int main(){
	// freopen("dx.inp","r",stdin);
	// freopen("dx.out","w",stdout);
	string s , k; cin >> s;
	int sz = s.size();
	if(s[0] >= '1' && s[0] <= '8'){
		for(int i = 1 ; i <= sz ; i++){
			k += s[0];
		}
		if(k > s){
			cout<<stoll(k) - stoll(s);
		}
		else{
			string a;
			for(int i = 1 ; i <= sz ; i++){
				a += s[0] + 1;
			}
			cout<<stoll(a) - stoll(s);
		}
	}
	else{
		string a;
		for(int i = 1 ; i <= sz ; i++){
			a += "9";
		}
		if(a > s) cout<<stoll(a) - stoll(s);
		else{
			string b;
			for(int i = 1 ; i <= sz + 1; i++){
				b += "1";
			}
			cout<<stoll(b) - stoll(s);
		}
	}
}