//6570: ÊýÉ½·å£¨Ò»£©
//http://47.110.135.197/problem.php?id=6570
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
	
	//freopen("12.in", "r", stdin);
	//freopen("12.out", "w", stdout);
	
	LL n;
	cin>>n;
    for (LL i=1;i<=n;i++) {
    	LL x,y;
    	cin>>x>>y;
        a[i].l=x-y;
        a[i].r=x+y;
    }
    sort(a+1,a+n+1,mycmp);
    
    LL maxx=0;
    LL res=0;
    for(int i=1;i<=n;i++) {
    	if (a[i].r>maxx) {
    		res++;
    		maxx=a[i].r;
		}
    }
    cout<<res<<"\n";
    
    return 0;
}

