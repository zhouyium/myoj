//http://47.110.135.197/problem.php?id=5601
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1.2e5+10;
int v[MAXN];
const int MAXF=1e6+10;
int f[MAXF];
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int cnt=0;
	int sum=0;
	for (int i=1; i<=6; i++) {
		int ss;
		scanf("%d", &ss);
		sum+=i*ss;
		
		//二进制分解
		for (int j=1; j<=ss; j*=2) {
			v[++cnt]=j*i;
			ss      =ss-j;
		}
		if (ss) {
			v[++cnt]=i*ss;
		}
	}
	
	if (1==sum%2) {
		printf("Can't be divided.\n");
		return 0;
	}
	
	//01背包
	sum=sum/2;
	for (int i=1; i<=cnt; i++) {
		for (int j=sum; j>=v[i]; j--) {
			f[j]=max(f[j], f[j-v[i]]+v[i]);
		}
	}
	
	if (f[sum]==sum) {
		printf("Can be divided.\n");
	} else {
		printf("Can't be divided.\n");
	}
	
	return 0;
}

