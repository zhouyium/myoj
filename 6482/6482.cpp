/*
Çóax=b (mod m) -> ax=b+my -> ax+my=b 
*/
#include <bits/stdc++.h>
using namespace std;
using LL=long long;

LL exgcd(LL a,LL b,LL &x,LL &y) {
    if (b==0) {
        x=1;y=0;
        return a;
    }
    LL gcd=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return gcd;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    freopen("09.in", "r", stdin);
    freopen("09.out", "w", stdout);
    
    LL n;
    cin>>n;
    while (n--) {
        LL a,b,m,x,y;
        cin>>a>>b>>m;
        LL gcd=exgcd(a,m,x,y);
        if (b%gcd!=0) {
            cout<<"impossible\n";
        } else {
        	b/=gcd;
        	m/=gcd;
            LL ans=(x*b%m+m)%m;
            cout<<ans<<"\n";
		}
    }
    return 0;
}
