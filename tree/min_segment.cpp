#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n,t;
int a[1000005];
ll tree[4*1000005];
void build(int v,int l,int r){
    if(l == r) tree[v] = a[l];
    else{
        int mid = (l+r)/2;
        build(2*v , l, mid);
        build(2*v+1,mid+1,r);
        tree[v] = min(tree[2*v],tree[2*v+1]);
    }
}

ll mint(int u,int tl,int tr,int l,int r){
    if(l > r) return 1e9;
    if(l == tl && r == tr) return tree[u];
    int mid = (tl + tr)/2;
    return min( mint(2*u , tl , mid , l , min(r,mid) ) , mint(2*u+1 , mid+1 , tr , max(l,mid+1) , r) );
}
int main(){
    cin>>n>>t;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    while(t--){
        int l,r; cin>>l>>r;
        cout<<mint(1,1,n,l,r)<<endl;
    }
}
