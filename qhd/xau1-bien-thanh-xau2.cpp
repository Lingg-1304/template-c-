#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e3 + 5;
int f[10001][10001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s1 , s2;
	cin >> s1 >> s2;
	int sz1 = s1.size() , sz2 = s2.size();
	s1 = '@' + s1;
	s2 = '@' + s2;
	for(int i = 1 ; i <= sz1 ; i++) f[i][0] = i;
	for(int i = 1 ; i <= sz2 ; i++) f[0][i] = i;
	for(int i = 1 ; i <= sz1 ; i++){
		for(int j = 1 ; j <= sz2 ; j++){
			if(s1[i] == s2[j]){
				f[i][j] = f[i-1][j-1];
			}
			else{
				f[i][j] = min({f[i-1][j] + 1 , f[i][j-1] + 1 , f[i-1][j-1] + 1});
			}
		}
	}
	cout<<f[sz1][sz2];
}