//6682: µ¹À¬»ø
//http://47.110.135.197/problem.php?id=6682
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2E5+10;
LL a[N];
LL b[N];//ÈË 
LL cnt_b;
LL c[N];//À¬»øÍ° 
LL cnt_c;
LL ans[N];

//>=val min
bool check1(LL mid, LL val) {
    return c[mid]>=val;
}
LL bsearch1(LL l, LL r, LL val) {
    LL mid;
    while (l<r) {
        mid=(l+r)/2;
        if (check1(mid, val)) {
            r=mid;
        } else {
            l=mid+1;
        }
    }
    return l;
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	LL n,m;
	cin>>n>>m;
	for (LL i=1; i<=n+m; i++) {
		cin>>a[i];
	}
	for (LL i=1; i<=n+m; i++) {
		LL x;
		cin>>x;
		if (x==1) {
			c[++cnt_c]=a[i];
		} else {
			b[++cnt_b]=a[i];
		}
	}
	
	if (n!=cnt_b||m!=cnt_c) {
		cout<<"error\n";
		return 0;
	}
	
	//ÕÒÀëÈË×î½üµÄÀ¬»øÍ° 
	c[0]=-9e18;
	c[m+1]=9e18;
	for (LL i=1; i<=n; i++) {
		//¶þ·Ö
		LL pos=lower_bound(c, c+m+2, b[i])-(c);
		//LL pos=bsearch1(0, m+1, b[i]);
		//cout<<pos<<" "<<pos1<<"\n";
		LL t1=b[i]-c[pos-1];
		LL t2=c[pos]-b[i];
		if (t1<=t2) {
			ans[pos-1]++;
		} else {
			ans[pos]++;
		}
	}
	
	for (LL i=1; i<=m; i++) {
		cout<<ans[i]<<" ";
	}
	cout<<"\n";

	return 0;
}

