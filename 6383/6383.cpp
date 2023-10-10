//http://47.110.135.197/problem.php?id=6383
//6383: ºÚµ•Œ Ã‚
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1E6+10;
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL p1,p2,p3,p4,a,b;
	cin>>p1>>p2>>p3>>p4>>a>>b;
	
	LL t1=min(min(p1,p2), min(p3,p4));
	LL t2=min(b,t1);
	LL ans=t2-a+1;
	if (b>=t1) {
		ans--;
	}
	if (ans<0) {
		ans=0;
	}
	cout<<ans<<"\n";

	return 0;
}

