#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define  ll long long int
#define  mp make_pair
#define pb push_back
#define endl "\n"
#define vi vector<int>
using namespace std;
const int mod=1e9+7;
const int N=1e5+7;


void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll>a(n,0);
    vector<ll>b(m,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int j=0;j<m;j++){
        cin>>b[j];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i=0;
    int j=0;
    int count=0;
    while(i<n && j<m){
        if(abs(a[i]-b[j])<=k){
            i++;
            j++;
            count++;
        }
        else if(a[i]<b[j]) i++;
        else if(b[j]<a[i]) j++;
    }
    cout<<count<<endl;
        

}
   
int32_t  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    solve();
    

}