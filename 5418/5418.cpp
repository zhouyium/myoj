//http://47.110.135.197/problem.php?id=5418
//5418: Êý×ÖÊ¶±ð II

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e2+10;
int a[MAXN];
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	ll n;
	cin>>n;
	if (0==n) {
		cout<<"1\n0\n";
		return 0;
	}
	int cnt=0;
	while (n) {
		cnt++;
		a[cnt]=n%10;
		n/=10;
	}
	
	cout<<cnt<<"\n";
	for (int i=cnt; i>=1; i--) {
		cout<<a[i]<<"\n";
	}
	
	return 0;
}

