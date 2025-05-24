#include<bits/stdc++.h>
using namespace std;
int const maxn = 1e5 + 5;
int a[maxn], w[maxn], n;
int bit[maxn];
void update(int pos){
	for(int i = pos; i<=n; i+= i & (-i)){
		bit[i]++;
	}
}
int get(int pos){
	int kq = 0;
	for(int i = pos; i>=1; i-= i & (-i)){
		kq += bit[i];
	}
	return kq;
}
int main(){
	cin>>n;
	for (int i=n;i>0;i--)
        cin>>a[i];
    int res=0;
    for (int i=1;i<=n;i++)
    {
        res= res+get(a[i]-1);
        update(a[i]);
    }
    cout<<res;
}
