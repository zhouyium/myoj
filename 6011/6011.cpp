#include <bits/stdc++.h>

using namespace std;

//����ύ��OJ����Ҫ���� __LOCAL
//#define __LOCAL
typedef long long ll;
const int MAXN=2e5+4;
ll a[MAXN];

int main() {
#ifndef __LOCAL
	//�ⲿ�ִ�����Ҫ�ύ��OJ�����ص��Բ�ʹ��
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

		//��gcd
		ll ans=0;
		for (int i=1; i<n; i++) {
			ans = __gcd(ans, a[i+1]-a[i]);
		}

		//�жϹ�ϵ
		if ((k-a[1])%ans == 0) {
            printf("YES\n");
			//cout<<"YES\n";
		} else {
            printf("NO\n");
			//cout<<"NO\n";
		}
	}

#ifdef __LOCAL
	//�ⲿ�ִ��벻��Ҫ�ύ��OJ�����ص���ʹ��
	system("pause");
#endif
	return 0;
}

