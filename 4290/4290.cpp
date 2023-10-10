#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const LL MO=1e9+7;
 
const int N=2E6+10;
LL x[N],y[N];
//Å·À­É¹
LL primes[N],cnt;
bool vis[N];
 
void euler(LL n){
    vis[0]=true;
    vis[1]=true;
    for(LL i=2;i<=n;i++){
        if(vis[i]==false){
            primes[++cnt]=i;
        }
        for(LL j=1;j<=cnt&&i*primes[j]<=n;j++){
            vis[i*primes[j]]=true;
            if(i%primes[j]==0){
                break;
            }
        }
    }
}
 
void solve() {
    LL n;
    cin>>n;
    for(LL i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
     
    LL res=0;
    for(LL i=1;i<=n;i++){
        for(LL j=i+1;j<=n;j++){
            if(i==j){
                continue;
            }
            //¼ÆËã
            LL t=abs(x[i]-x[j])+abs(y[i]-y[j]);
            if (vis[t]==false){
                res++;
            }
        }
    }
    cout<<res<<"\n";
}
 
int main() {
#if 1
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    freopen("10.in", "r", stdin);
    freopen("10.out", "w", stdout);
    euler(2e6);
    LL T=1;
    //cin>>T;
    for (LL i=1; i<=T; i++) {
        //cout<<i<<"\n";
        solve();
    }
 
    return 0;
}
