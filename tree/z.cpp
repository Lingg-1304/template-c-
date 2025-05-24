#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int const maxn = 1e5 + 5;
int n , q ;
ll a[maxn] , tree[maxn * 4] , lazy[maxn * 4];
void build(int id , int l , int r){
    if(l == r) {
        tree[id] = a[l];
        return;
    }
    int mid = (l+r) / 2;
        build(2*id , l , mid);
        build(2*id + 1 , mid + 1 , r);
        tree[id] = max(tree[2*id] , tree[2*id+1]);
}
void down(int id, int l, int r) {
    ll t = lazy[id];
    if (!t) return;
    tree[id] += (r - l + 1) * t;
    if (l != r) {
        lazy[id * 2] += t;
        lazy[id * 2 + 1] += t;
    }
    lazy[id] = 0;
}
void update(int id , int l , int r , int u , int v , ll val){
    down(id, l, r);
    if(u > r || v < l) return;
    if(u <= l && r <= v){
        lazy[id] += val;
        down(id, l, r);
        return;
    }
    int mid = (l+r)/2;
    update(2*id , l , mid , u , v , val);
    update(2*id+1 , mid + 1 , r , u , v , val);
    tree[id] = max(tree[2*id] , tree[2*id + 1]);
}
ll get(int id , int l , int r , int u , int v){
    down(id, l, r);
    if(u > r || v < l) return 0;
    if(u <= l && r <= v) return tree[id];
    int mid = (l+r)/2;
    ll x = get(2*id , l , mid , u , v);
    ll y = get(2*id+1 , mid+1 , r , u , v);
    return max(x , y);
}
int main(){
    cin>>n;
    
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }

    build(1,1,n);
    cin >> q;
    while(q--){
        int x; cin>>x;
        if(x == 1){
            int l,r;
            ll val; 
            cin>>l>>r>>val;
            update(1,1,n,l,r,val);
        }
        else{
            int l,r; cin >> l >> r;
            cout<<get(1,1,n,l,r)<<endl;
        }
    }
}
