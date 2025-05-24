/*
Lingg
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 5e5 + 5;
int a[maxn] , b[maxn] , c[maxn] , d[maxn] , e[maxn];
void Solve(){

    int n; cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }

    stack<int> st;

    for(int i = n ; i >= 1 ; i--){
    	while(!st.empty() && a[i] > a[st.top()]){
            st.pop();
		}
        if(st.empty()) b[i] = -1;
        else b[i] = st.top();
        st.push(i);
	}

    stack<int> stt;

    for(int i = 1 ; i <= n ; i++){
    	while(!stt.empty() && a[i] < a[stt.top()]){
            stt.pop();
		}
        if(stt.empty()) c[i] = -1;
        else c[i] = stt.top();
        stt.push(i);
	}

    // stack<int> st1;

    // for(int i = 1 ; i <= n ; i++){
    // 	while(!st1.empty() && a[i] > a[st1.top()]){
    //         st1.pop();
	// 	}
    //     if(st.empty()) d[i] = -1;
    //     else d[i] = st1.top();
    //     st1.push(i);
	// }

    // stack<int> st2;

    // for(int i = n ; i >= 1 ; i--){
    // 	while(!st2.empty() && a[i] > a[st2.top()]){
    //         st2.pop();
	// 	}
    //     if(st2.empty()) e[i] = -1;
    //     else e[i] = st2.top();
    //     st2.push(i);
	// }

    // for(int i = 1 ; i <= n ; i++){
    //     cout << b[i] << ' ';
    // }
    // cout << endl;
    // for(int i = 1 ; i <= n ; i++){
    //     cout << c[i] << ' ';
    // }
    // cout << endl;

    for(int i = 1 ; i <= n ; i++){
        int ans = a[i] , pos = i;
        for(int k = 1 ; k <= 100 ; k++){
            if(c[i] != -1){
                pos = c[i];
                ans = max(ans , a[c[i]]);
            }
            else if(e[i] != -1){
                pos = e[i];
                ans = max(ans , a[e[i]]);
            }
            else if(b[i] != -1){
                pos = b[i];
                ans = max(ans , a[b[i]]);
            }
            else{
                pos = d[i];
                ans = max(ans , a[d[i]]);
            }
        }
        cout << ans << ' ';
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test = 1; 
    cin >> test;
    while (test--)
    {
        Solve();
    }

}