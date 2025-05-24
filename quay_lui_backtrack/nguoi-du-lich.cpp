#include<bits/stdc++.h>
using namespace std;
int n , kq = 1e9 , cmin = 1e9 , dem;
int a[25][25];
bool visit[25];
void xuly(){
	for(int i = 2 ; i <= n ; i++) visit[i] = false;
	int x[n-1];
	for(int i = 0 ; i < n - 1 ; i++) x[i] = i + 2;
	do{
		dem++;
		int res = a[1][x[0]] , check = 0;
		for(int i = 0 ; i < n - 2 ; i++){
			visit[x[i]] = true;
			if(res + cmin*(n-i-1) > kq){
				for(int j = i + 1 ; j < n - 1 ; j++){
					for(int k = n ; k >= 2 ; k--){
						if(!visit[k]){
							visit[k] = true;
							x[j] = k;
							break;
						}
					}
				}
				check = 1;
				break;
			}
			res += a[x[i]][x[i+1]];
		}
		if(check == 0) kq = min(kq,res + a[1][x[n-2]]);
		//cout<<res<<endl;

 	}while(next_permutation(x,x+n-1));

}
int main(){
	freopen("hi.inp","r",stdin);
	freopen("hi.out","w",stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1 ; i <= n ; i++) a[i][i] = 1e9;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			cmin = min( cmin , a[i][j] );
		}
	}
	visit[1] = true;
	xuly();
	cout<<kq<<endl<<dem;
}