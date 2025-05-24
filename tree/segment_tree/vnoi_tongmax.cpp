/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
struct Node{
    ll sum , pre , sur , ma;
};
int n;
Node tree[maxn*4];

Node meg(const Node &a , const Node &b){
    Node ans;
    ans.ma = max( {a.ma , b.ma , a.sur + b.pre} );
    ans.pre = max(a.pre , a.sum + b.pre);
    ans.sur = max(b.sur , b.sum + a.sur);
    ans.sum = a.sum + b.sum;
    return ans;
}

void update(int id , int l , int r , int pos , int val){
    if(pos < l || pos > r) return;
    if(l == r){
        tree[id] = { val , max(0,val) , max(0,val), max(0,val) };
        return;    
    }
    int mid = (l+r)/2;
    update(2*id , l , mid , pos , val);
    update(2*id+1 , mid + 1 , r , pos , val);
    
    tree[id] = meg(tree[2*id] , tree[2*id+1]);
}

Node get(int id , int l , int r , int u , int v){
	if(v < l || r < u) return {0,0,0,0};
	if(u == l && v == r) return tree[id];
	int mid = (l+r)/2;
	return meg(get(2*id , l , mid , u , v) , get(2*id + 1 , mid + 1 , r , u , v));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        int val; cin >> val;
        update(1,1,n,i,val);
    }
    cin >> t;
    while(t--){
//        int pos ,val;
//        cin >> pos >> val;
//        update(1,1,n,pos,val);
//        cout<<tree[1].ma<<endl;
		int l , r; cin >> l >> r;
		cout<<get(1,1,n,l,r).ma<<endl;
    }
    
    return 0;
}
