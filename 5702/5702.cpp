//http://47.110.135.197/problem.php?id=5702
//https://iai.sh.cn/problem/444

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1e5+10;
int x[MAXN];
int y[MAXN];
int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	int n;
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>x[i]>>y[i];
	}
	//城市的中心点就在中位数 
	sort(x+1, x+n+1);
	sort(y+1, y+n+1);
	
	//中心点
	int a=x[(n+1)/2];
	int b=y[(n+1)/2];
	int sum=0;
	for (int i=1; i<=n; i++) {
		sum+=(abs(x[i]-a)+abs(y[i]-b));
	}
	cout<<sum<<"\n";

	return 0;
}

