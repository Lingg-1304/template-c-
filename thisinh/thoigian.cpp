#include<bits/stdc++.h>
using namespace std;
int main(){
	int h , p , s;
	cin >> h >> p >> s;
	if(s == 59){
		s = 0;
		if(p == 59){
			p = 0;
			h += 1;
		}
	    else{
	    	p += 1;
	    }
	}
	else{
		s += 1;
	}
	cout<<h<<" "<<p<<" "<<s<<endl;
	return 0;
}