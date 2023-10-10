//http://47.110.135.197/problem.php?id=5289
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=10007;
const int MAXN=1e2+10;
int v[MAXN];
const int MAXF=1e6+10;
int f[MAXF];
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int n,K;
	scanf("%d%d", &n, &K);
	for (int i=1; i<=n; i++) {
		scanf("%d", &v[i]);
	}
	
	f[0]=1;
	for (int i=1; i<=n; i++) {
		for (int j=K; j>=0; j--) {
			//ÄÜÁ¦ÅÐ¶Ï
			if (j+v[i]>=K)  {
				f[K]=(f[j]+f[K])%MOD;
			} else {
				f[j+v[i]]=(f[j+v[i]]+f[j])%MOD;
			}
		}
	}
	
	printf("%d\n", f[K]);
	
	return 0;
}

