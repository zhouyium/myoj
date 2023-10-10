//1958: Transformation: from A to B
//http://47.110.135.197/problem.php?id=1958

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E6+10;
LL ans[MAXN];
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	freopen("1.in", "r", stdin);
	freopen("my.out", "w", stdout);
	LL a,b;
	cin>>a>>b;
	
	LL cnt=0;
	while (b>=a) {
		ans[++cnt]=b;
		if (b%2==1) {
			//ÆæÊý
			b=(b-1)/10; 
		} else {
			b=b/2;
		}
	}
	
	if (ans[cnt]==a) {
		cout<<"YES\n"<<cnt<<"\n";
		for (LL i=cnt; i>=1; i--) {
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
	} else {
		cout<<"NO\n";
	}

	return 0;
}

