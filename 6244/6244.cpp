#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    LL n;
    cin>>n;
    LL minx=1e6;
    for (LL i=1; i<=n; i++) {
        LL x;
        cin>>x;
        if (x<minx) {
            minx=x;
        }
    }
    cout<<minx<<"\n";
    return 0;
}
