//
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;
const LL MOD=32767;
const int MAXN=1e6+10;
LL a[MAXN];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	LL x;
	cin>>x;
	string ans;
	while (x) {
		if (x%26==0) {
			ans.push_back('Z');
			x-=26;
		} else {
			char t='A'-1+x%26;
			ans.push_back(t);
		}
		x/=26;
	}
	for (LL i=ans.size()-1; i>=0; i--) {
		cout<<ans[i];
	}
	cout<<"\n";
	return 0;
}

