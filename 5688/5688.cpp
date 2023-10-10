//http://47.110.135.197/problem.php?id=5688
//5688: 降雨统计

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e3+10;
int ans[MAXN][MAXN];
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("9.in", "r", stdin);
	//freopen("9.out", "w", stdout);
	int n,m;
	cin>>n>>m;
	string s;
	for (int i=1; i<=n; i++) {
		cin>>s;
		
		//前缀和 
		for (int j=1; j<=m; j++) {
			if (s[j-1]=='#') {
				ans[i][j]=1;
			}
			ans[i][j]+=ans[i][j-1];
		}
	}
	
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}

	return 0;
}

