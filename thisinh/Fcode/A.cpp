#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 5e5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    while(getline(cin,s)){
        // for(int i = 0 ; i < s.size() ; i++) cout << s[i];
        // cout << endl;

        string tmp = "";
        for(int i = 0 ; i <= s.size() ; i++){

            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')){
                tmp += s[i];
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                if(tmp.size() > 0){
                    reverse(tmp.begin() , tmp.end());
                    cout << tmp;
                    tmp = "";
                }
                cout << s[i];
            }
            else if((s[i] == ',' ) || (s[i] == '.') || (s[i] == ';') || (s[i] == '?') || (s[i] == '!') || (s[i] = ' ')){
                if(tmp.size() > 0){
                    reverse(tmp.begin() , tmp.end());
                    cout << tmp;
                    tmp = "";
                }
                cout << s[i];
            }
        }
        cout << endl;

    }


    // for(char i = '0' ; i <= '9' ; i++){
    //     cout << i << ' ';
    // }
}