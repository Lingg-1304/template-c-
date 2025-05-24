#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second
#define ii pair<int,int>
#define iil pair<ii,int>
const int maxn = 1e7 + 5;
ii f[maxn];
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n , s;
	cin >> n >> s;
	int a[n + 1] , ans = 0;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(i != j){
				f[a[i] + a[j]] = {i,j};
			}
		}
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = s - a[i] ; j >= 0 ; j--){
			if(f[j] != ii(0,0) && f[j].fi != i && f[j].se != i){
				ans = max(ans , a[i] + j);
				break;
			}
		}
	}
	cout<<ans;
}