#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
//O(NWS) 1e2*1e2*1e2*2e1=2e7
//O(NWlogs)->O(NW)
const int MAXN=1e6+10;
LL w[MAXN], v[MAXN];
LL dp[MAXN];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("6.out", "w", stdout);
    LL T;
    cin>>T;
    while (T--) {
        //初始化
        fill(dp, dp+MAXN-2, 0);
        //fill(w, w+MAXN-2, 0);
        //fill(v, v+MAXN-2, 0);

        LL n,W;
        cin>>W>>n;

        //二进制优化
        LL cnt=0;
        for (LL i=1; i<=n; i++) {
            LL ww,vv,ss;
            cin>>ww>>vv>>ss;
            for (LL j=1; j<=ss; j*=2) {
                cnt++;
                w[cnt]=ww*j;
                v[cnt]=vv*j;
                ss    =ss-j;
            }
            if (ss) {
                cnt++;
                w[cnt]=ww*ss;
                v[cnt]=vv*ss;
            }
        }

        //01
        for (LL i=1; i<=cnt; i++) {
            for (LL j=W; j>=w[i]; j--) {
                dp[j]=max(dp[j], dp[j-w[i]]+v[i]);
            }
        }

        cout<<dp[W]<<"\n";
    }
    return 0;
}
