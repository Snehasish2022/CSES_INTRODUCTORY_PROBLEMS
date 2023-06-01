#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,mw;
ll profit[101][100005];
ll w[100005];
ll v[100005];
void solve(){
    memset(profit,0,sizeof(profit));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=mw;j++){
            if(j-w[i]>=0){
                profit[i][j]=max(profit[i-1][j],profit[i-1][j-w[i]]+v[i]);
            }
            else{
                profit[i][j]=profit[i-1][j];
            }
        }
    }
    cout<<profit[n][mw]<<endl;

    
}
int main() {
    cin>>n>>mw;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    solve();

}
