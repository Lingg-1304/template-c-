#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 1e5;

int a[maxn] , b[maxn];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];

    stack<int> st;

    for(int i = n ; i >= 1 ; i--){
    	while(!st.empty() && a[i] > st.top()){
            st.pop();
		}
        if(st.empty()) b[i] = -1;
        else b[i] = st.top();
        st.push(a[i]);
	}

    for(int i = 1 ; i <= n ; i++){
        cout << b[i] << ' ';
    }
}