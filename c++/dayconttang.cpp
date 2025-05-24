#include<bits/stdc++.h>
using namespace std;
int main(){
//    freopen("hi.inp","r",stdin);
//    freopen("hi.out","w",stdout);
    int n;
    cin>>n;
    int a[n],thuan[n],nguoc[n];
    for(int i=0;i<n;i++){
      cin>>a[i];
      thuan[i]=a[i];
      nguoc[i]=a[i];
    }
    for(int i=0;i<n;i++){
     for(int j=0;j<i;j++){
          if(a[i]>a[j]){
               thuan[i]=max(thuan[i],thuan[j]+a[i]);
          }
     }
    }
    for(int i=n-1;i>=0;i--){
     for(int j=i-1;j>=0;j--){
          if(a[j]>a[i]){
               nguoc[i]=max(nguoc[i],nguoc[j]+a[i]);
          }
     }
    }
    int maxc=0;
    for(int i=0;i<n;i++){
    	maxc=max(maxc,thuan[i]+nguoc[i]-a[i]);
    }
    cout<<maxc;
    return 0;
}

