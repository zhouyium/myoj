//http://47.110.135.197/problem.php?id=4601
//4601: 数字全排列

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=10;
bool vis[MAXN];
int  ans[MAXN];

int n;
/*
第一个参数：当前的数字
第二个参数：当前数量 
*/
void dfs(int num, int cnt) {
	if (cnt>n) {
		for (int i=1; i<=n; i++) {
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	
	for (int i=1; i<=n; i++) {
		if (false==vis[i]) {
			vis[i]=true;
			ans[cnt]=i;
			dfs(i+1, cnt+1);
			vis[i]=false;			
		}
	}
}
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	cin>>n;
	
	dfs(1, 1);

	return 0;
}

