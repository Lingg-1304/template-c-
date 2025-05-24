#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int mod = 1e9+7;
void nhap(){
	
}
string cong_xau(string a, string b){
	if(b.size()>a.size()) swap(a,b);
	string sum="";
	int nho = 0;
	int i=a.size()-1, j=b.size()-1;
	while(i>=0 && j>=0){
		int tmp = a[i] - '0' + b[j] - '0' + nho;
		if(tmp > 10){
			nho = 1;
			sum = to_string(tmp%10) + sum;
			i--; j--;
		}
		else{
			nho = 0;
		    sum = to_string(tmp) + sum;
		    i--; j--;
		}
	}
	if(i>0){
		sum = to_string(a[i]-'0'+nho) +sum;
		nho = 0;
		i--;
		for(int k=0;k<=i;k++) sum = a[k] + sum;
	}
	if(nho == 1) sum = '1' + sum;
	return sum;
}
int main(){
    fast;
    
}
