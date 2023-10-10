#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1E6+10;
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL T;
	cin>>T;
	for (LL i=1; i<=T; i++) {
		LL n,K;
		cin>>n>>K;
		string s;
		cin>>s;
		cout<<"Case #"<<i<<": ";
		
		LL cnt=0;
		for (LL j=0; j<s.size()/2; j++) {
			if (s[j]!=s[s.size()-j-1]) {
				cnt++;
			}
		}
		cout<<abs(cnt-K)<<"\n";
	}

	return 0;
}

