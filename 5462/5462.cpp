#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+4;
int a[MAXN];
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	freopen("09.in", "r", stdin);
	freopen("09.out", "w", stdout);
	
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++) {
        cin>>a[i];
    }

    int ans=0;
    //解决编号最小 
    for (int i=1; i<=n; i++) {
        if (a[i]>k) {
            break;
        } else {
            ans++;
        }
    }
    //解决编号最大 
    if (ans<n) {
        for (int i=n; i>=1; i--) {
            if (a[i]>k) {
                break;
            } else {
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
    
    return 0;
}
