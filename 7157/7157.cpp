#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;

const int N=1E6+10;
LL a[N];
LL cnt[N];

LL C2(LL x) {
	return x*(x-1)/2;
}
LL C3(LL x) {
	return C2(x)*(x-2)/3;
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	
	LL n;
	cin>>n;
	for (LL i=1; i<=n; i++) {
		LL x;
		cin>>x;
		a[i]=x;
		cnt[x]++;
	}
	
#if 0
	//逆向思维，用总数-不符合条件的；
	LL ans=C3(n);//从n个数中选择3个
	for (LL i=1; i<N; i++)  {
		if (cnt[i]>1) {
			ans-=C2(cnt[i])*(n-cnt[i]);
			if (cnt[i]>2) {
				ans-=C3(cnt[i]);//出现x,x,x的次数 
			}
		}
	}
#else	
	//方案2：将题目转化为求 Ai < Aj < Ak
	for (LL i=1; i<N; i++) {
		cnt[i]+=cnt[i-1];
	}
	LL ans=0;
	for (LL i=1; i<=n; i++) {
		LL t=a[i];
		ans+=cnt[t-1]*(n-cnt[t]);
	}
#endif	
	cout<<ans<<"\n";

	return 0;
}

