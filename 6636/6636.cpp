//6636: 前缀最值差
//http://47.110.135.197/problem.php?id=6636

#include <bits/stdc++.h>

using namespace std;
using LL=long long;

const int N=1e6+10;

LL a[N];
LL sb[N], ss[N];

//预处理出来最大值， 最小值， 然后查表 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("09.in", "r", stdin);
	freopen("09.out", "w", stdout);
	
	LL n,q;
	cin>>n;
	for(LL i=1;i<=n;i++) {
		cin>>a[i];
		if(i==1) {
			sb[i]=a[i];
			ss[i]=a[i];
		} else {
			sb[i]=max(a[i], sb[i-1]);
			ss[i]=min(a[i], ss[i-1]);
		}
	}
	cin>>q;
	while(q--) {
		LL x;
		cin>>x;
		cout<<sb[x]-ss[x]<<" ";
	}
	cout<<"\n";
	
	return 0;
}
