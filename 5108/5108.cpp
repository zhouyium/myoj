//http://47.110.135.197/problem.php?id=5108
//5108: MAPÑµÁ· II

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	int T;
	cin>>T;
	while (T--) {
		int n;
		cin>>n;
		map<string, int> hash;
		for (int i=1; i<=n; i++) {
			string s;
			cin>>s;
			hash[s]++;
		}
		
		n=hash.size();
		cout<<n<<"\n";
		for (map<string, int>::iterator it=hash.begin(); it!=hash.end(); it++) {
			cout<<it->first<<": "<<it->second<<"\n";
		}
		cout<<"\n";
	}

	return 0;
}

