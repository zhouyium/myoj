//http://47.110.135.197/problem.php?id=5544
//5544: ÇÐµ°¸â
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int n;
	cin>>n;
	
	int x=2;
	int ans=2;
	for (int i=2; i<=n; i++) {
		ans+=x;
		x++;
	}
	
	cout<<ans<<"\n";

	return 0;
}

