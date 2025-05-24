#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 1e7 + 5;

struct Time{
    int s , e , stt;
};

bool cmp(Time x , Time y){
    if(x.e == y.e){
        return x.s > y.s;
    }
    return x.e < y.e;
}

int Change(string s){
    int sum = 0;
    for(int i = 0 ; i < s.size() ; i++){
        sum += (s[i] - 48);
        sum *= 10;
    }
    return sum/10;
}

int n;
vector<Time> t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    string tt; getline(cin , tt);
    for(int i = 1 ; i <= n ; i++){
        vector<int> v;
        string s;
        getline(cin , s);
        string tmp;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                tmp += s[i];
            }
            else{
                if(tmp.size() > 0){
                    v.push_back(Change(tmp));
                    tmp = "";
                }
            }
        }
        v.push_back(Change(tmp));
        //cout << v[0] << ' ' << v[1] << ' ' << v[2] << endl;
        t.push_back({v[0] , v[1] , v[2]});
    }

    sort(t.begin() , t.end() ,cmp);

    // for(int i = 0 ; i < t.size() ; i++){
    //     cout << t[i].s << ' ' << t[i].e << ' ' << t[i].stt << endl;
    // }

    int cnt = 1 , kt = t[0].e;
    vector<int> kq;
    kq.push_back(t[0].stt);
    for(int i = 1 ; i < t.size() ; i++){
        if(t[i].s > kt){
            cnt++;
            kq.push_back(t[i].stt);
            kt = t[i].e;
        }
    }
    cout << cnt << endl;
    for(int i = 0 ; i < kq.size() - 1 ; i++){
        cout << kq[i] << ",";
    }
    cout << kq[kq.size()-1];
}