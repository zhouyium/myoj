#include <bits/stdc++.h>
using namespace std;
const int MAXN=10;
int s[MAXN];
const int MAXF=1e6+10;
int f[MAXF];
int main() {
	int n;
	scanf("%d", &n);
	int sum=0;
	for (int i=1; i<=n; i++) {
		scanf("%d", &s[i]);
		sum+=s[i];
	}
	
	if (0!=sum%2) {
		printf("0\n");
		return 0;
	}
	
	int W=sum/2;
	f[0]=1;
	for (int i=1; i<=n; i++) {
		for (int j=W; j>=s[i]; j--) {
			f[j]=f[j]+f[j-s[i]];
		}
	}
	if (f[W]%2) {
		printf("0\n");
	} else {
		printf("%d\n", f[W]/2);
	}
	
	return 0;
}
