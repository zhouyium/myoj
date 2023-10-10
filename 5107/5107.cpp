//http://47.110.135.197/problem.php?id=5107
//5107: MAPÑµÁ· I

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	freopen("08.in", "r", stdin);
	freopen("08.out", "w", stdout);
	int T;
	cin>>T;
	while (T--) {
		int n;
		cin>>n;
		
		unordered_map<string, int> hash;
		for (int i=1; i<=n; i++) {
			string s;
			int x;
			cin>>s>>x;
			hash[s]=x;
		}
		
		int q;
		cin>>q;
		for (int i=1; i<=q; i++) {
			string s;
			cin>>s;
			if (hash.count(s)>0) {
				cout<<hash[s]<<"\n";
			} else {
				cout<<"error\n";
			}
		}
	}

	return 0;
}

