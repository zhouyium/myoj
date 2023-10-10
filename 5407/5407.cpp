//http://47.110.135.197/problem.php?id=5407
//5407: map基本练习：map的基本使用 II

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	freopen("9.in", "r", stdin);
	freopen("9.out", "w", stdout);
	
	int n,q;
	cin>>n>>q;
	unordered_map<string, double> hash;
	for (int i=1; i<=n; i++) {
		string s;
		double x;
		cin>>s>>x;
		hash[s]=x;
	}
	
	for (int i=1; i<=q; i++) {
		string s;
		cin>>s;
		if (hash.count(s)>0) {
			cout<<fixed<<setprecision(1)<<hash[s]<<"\n";
		} else {
			cout<<"-1\n";
		}
	}

	return 0;
}

