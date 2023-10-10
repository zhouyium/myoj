#include <bits/stdc++.h>
using namespace std;
using LL=long long;

const int N=2e6+10;
LL a[N];
LL ans[N];//答案

unordered_map<LL, bool> mp;

//欧拉筛
bool vis[N];
LL prime[N];
void shai() {
    vis[1]=1;
    for (LL i=2; i<N; i++) {
        if (!vis[i]) {
            prime[++prime[0]]=i;
        }
        for (LL j=1; j<=prime[0]&&prime[j]*i<N; j++) {
            vis[i*prime[j]]=1;
            if (i%prime[j]==0) {
                break;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("09.in", "r", stdin);
    freopen("09.out", "w", stdout);

    shai();

    LL n,q;
    cin>>n>>q;

    LL cnt=1;
    for (LL i=1; i<=n; i++) {
        cin>>a[i];
        mp[a[i]]=1;
        //构造
        while (mp[prime[cnt]]) {
            cnt++;
        }
        ans[i]=prime[cnt];
    }

    for (LL i=1; i<=q; i++) {
        LL x;
        cin>>x;
        cout<<ans[x]<<"\n";
    }

    return 0;
}
