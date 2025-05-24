#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second
#define ii pair<int,int>
#define iil pair<ii,int>
const int maxn = 1e7 + 5;
int f[maxn] , a[maxn] , ans;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n; cin >> n;
	for(int i = 1 ; i <= n ; i++) cin>>a[i];
	for(int i = 1 ; i <= n ; i++) f[i] = f[i-1] + a[i];
	for(int i = 1 ; i <= n - 1 ; i++){
		for(int j = i + 1 ; j <= n ; j++){
			int sum = f[j] - f[i-1];
			if(sum % 2 == 0){
				for(int k = i ; k <= j ; k++){
					int s = f[k] - f[i - 1];
					if(s == sum){
						ans = max(ans , j - i);
						break;
					}
					else if(s >= sum) break;
				}
			}
		}
	}
	cout<<ans;
}