#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> II;
int main(){
    int n,kq=1;
    cin>>n;
    II a[n];
    for(int i=0;i<n;i++){
        cin>>a[i].second>>a[i].first;
    }
    sort(a,a+n);
    int tg=a[0].first;
    for(int i=0;i<n-1;i++){
        if(tg <= a[i+1].second){
            kq++;
            tg=a[i+1].first;
        }
    }
    cout<<kq;
}
