//1048
//http://47.110.135.197/problem.php?id=1048
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E6+10;
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	string s;
	cin>>s;
	
	LL len=1;
	for (LL i=0; i<s.size(); i++) {
		if (s[i]==s[i+1]) {
			len++;
		} else {
			cout<<len<<s[i];
			len=1;
		}
	}
	cout<<"\n";

	return 0;
}

