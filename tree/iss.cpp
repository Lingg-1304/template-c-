#include<bits/stdc++.h>
using namespace std;
int const maxn = 1e5 + 5;
int a[maxn], b[maxn], n , f[maxn];
int bit[maxn];
void update(int pos, int val){
	for(int i = pos; i >= 1 ; i -= i & (-i)){
		bit[i] += val;
		//bit[i] = max(bit[i] , val);
	}
}
int get(int pos){
	int kq = 0;
	for(int i = pos; i >= 1 ; i -= i & (-i)){
		kq += bit[i];
	}
	return kq;
}
int main(){
	cin>>n;
	for (int i = 1 ; i <= n ; i++) cin>>a[i];
    for (int i = 1 ; i <= n ; i++) cin>>b[i];
    
   	for (int i=1;i<=n;i++)
    {
        f[i] += get(a[i]+1);
        update(a[i],b[i]);
    }

    for(int i = 1 ; i <= n ; i++) cout<<f[i]<<' ';

}
