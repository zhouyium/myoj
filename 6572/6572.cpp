#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=1e5+10;

struct REN{
    LL l,r;
}a[N];

bool mycmp(const REN &p, const REN &q) {
    return q.l>p.l||(q.l==p.l&&q.r<p.r);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	
	LL n;
	cin>>n;
    for (LL i=1;i<=n;i++) {
    	LL x,y;
    	cin>>x>>y;
        a[i].l=x-y;
        a[i].r=x+y;
    }
    sort(a+1,a+n+1,mycmp);
    
    LL r=a[1].r;
    LL res=(a[1].r-a[1].l)*(a[1].r-a[1].l);
    for(int i=2;i<=n;i++) {
    	LL t=(a[i].r-a[i].l)*(a[i].r-a[i].l);
    	if (a[i].l>=r) {
    		//没有交集
			res+=t;
			r=a[i].r;
		} else {
			//有交集 
			if (a[i].r<=r) {
				//全部包括 
			} else {
				//部分包括
				LL t1=(r-a[i].l)*(r-a[i].l);
				res+=(t-t1);
				r=a[i].r;
			}
		}
    }
    cout<<res<<"\n";
    
    return 0;
}

