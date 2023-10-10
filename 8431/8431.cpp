#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const LL MO=1e9+7;

const int N=1E6+10;

void solve() {
	vector<LL> v;
	v.push_back(-2147483647);
	v.push_back(2147483647);
	LL q;
	cin>>q;
	for (LL i=1;i<=q;i++) {
		LL op,x;
		cin>>op>>x;
		if (op==1) {
			//二分查询x排名 
			auto it=lower_bound(v.begin(),v.end(),x);
			cout<<it-v.begin()<<"\n";
		} else if (op==2) {
			cout<<v[x]<<"\n";
		} else if (op==3) {
			//求 x 的前驱
			auto it=lower_bound(v.begin(),v.end(),x);
			cout<<*(it-1)<<"\n";
		} else if (op==4) {
			//求 x 的后继
			auto it=upper_bound(v.begin(),v.end(),x);
			cout<<*it<<"\n";
		} else if (op==5) {
			//插入
			auto it=upper_bound(v.begin(),v.end(),x);
			v.insert(it,x);
		}
	}
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL T=1;
	//cin>>T;
	for (LL i=1; i<=T; i++) {
		//cout<<i<<"\n";
		solve();
	}

	return 0;
}
