//http://47.110.135.197/problem.php?id=5657
//5657: Children Holiday
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e3+10;
ll t[MAXN];
ll y[MAXN];
ll z[MAXN];
ll m, n;

//>= min
bool check(ll mid) {
	//mid时间 
	ll cnt=0;
	for (ll i=1; i<=n; i++) {
		//计算第i个人在mid的时间能冲多少个气球。 
		ll bt=t[i]*z[i]+y[i];//第i个人的时间 
		ll bn=mid/bt;
		ll rn=min(mid%bt, t[i]*z[i]);
		ll num=bn*z[i]+rn/t[i];
		cnt+=num;
		if (cnt>=m) {
			return true;
		}
	}
	return false;	
}
ll bsearch(ll l, ll r) {
	ll mid;
	while (l<r) {
		mid=(l+r)/2;
		if (check(mid)) {
			r=mid;
		} else {
			l=mid+1;
		}
	}
	return l;
}

int main() {
	scanf("%lld%lld", &m, &n);
	for (ll i=1; i<=n; i++) {
		scanf("%lld%lld%lld", &t[i], &z[i], &y[i]);
	}
	
	ll l=0;
	ll r=1e18;
	ll ans=bsearch(l, r);
	printf("%lld\n", ans);
	
	//计算 
	for (ll i=1; i<=n; i++) {
		//计算第i个人在mid的时间能冲多少个气球。 
		ll bt=t[i]*z[i]+y[i];//第i个人的时间 
		ll bn=ans/bt;
		ll rn=min(ans%bt, t[i]*z[i]);
		ll num=bn*z[i]+rn/t[i];
		num=min(num, m);
		m-=num;
		printf("%lld ", num);
	}
	printf("\n");
	
	return 0;
}

8 10
1 1 3 3 3 5 8 8
1 3 3 4 5 5 5 8 8 8

