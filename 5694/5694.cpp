//http://47.110.135.197/problem.php?id=5694
//5694: ×î¶ÌÊ±¼ä

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	freopen("9.in", "r", stdin);
	freopen("9.out", "w", stdout);
	int T;
	cin>>T;
	while (T--) {
		int n,m,r,c;
		cin>>n>>m>>r>>c;
		
		cout<<max(abs(n-r), abs(1-r))+max(abs(m-c),abs(1-c))<<"\n";
	}

	return 0;
}

