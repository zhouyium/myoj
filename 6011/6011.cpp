#include <bits/stdc++.h>

using namespace std;

//如果提交到OJ，不要定义 __LOCAL
//#define __LOCAL
typedef long long ll;
const int MAXN=2e5+4;
ll a[MAXN];

int main() {
#ifndef __LOCAL
	//这部分代码需要提交到OJ，本地调试不使用
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
#endif
	freopen("00.in", "r", stdin);
	freopen("00.out", "w", stdout);
	
	int t;
    scanf("%d", &t);
	//cin>>t;
	while (t--) {
		ll n,k;
        scanf("%lld %lld", &n, &k);
		//cin>>n>>k;

		for (int i=1; i<=n; i++) {
            scanf("%lld", &a[i]);
			//cin>>a[i];
		}

		//求gcd
		ll ans=0;
		for (int i=1; i<n; i++) {
			ans = __gcd(ans, a[i+1]-a[i]);
		}

		//判断关系
		if ((k-a[1])%ans == 0) {
            printf("YES\n");
			//cout<<"YES\n";
		} else {
            printf("NO\n");
			//cout<<"NO\n";
		}
	}

#ifdef __LOCAL
	//这部分代码不需要提交到OJ，本地调试使用
	system("pause");
#endif
	return 0;
}

