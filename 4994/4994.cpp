//http://47.110.135.197/problem.php?id=4994
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e4+10;
int a[MAXN];
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	string s;
	cin>>s;
	int n=s.length();
	for (int i=0; i<n; i++) {
		if ('B'==s[i]) {
			a[i+1]=1+a[i];
		} else {
			a[i+1]=-1+a[i];
		}
	}
	
	int ans=0;
	for (int i=1; i<=n; i++) {
		if (0==a[i]) {
			ans=max(ans, i);
		}
	}
	for (int i=1; i<=n; i++) {
		if (0==a[i]) {
			continue;
		}
		for (int j=i+ans+1; j<=n; j++) {
			if (a[j]==a[i]) {
				ans=max(ans, j-i);
			}
		}
	}
	
	printf("%d\n", ans);

	return 0;
}

