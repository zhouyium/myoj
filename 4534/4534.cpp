#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
ll a[MAXN];//全部初始化为0 
int main() {
	freopen("9.in", "r", stdin);
	//freopen("6.out", "w", stdout);
	int n;
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
	}
	
	//数据处理
	//计数，计数方法 
	int ans=0;//答案
	ll last=a[0];//上一山的高度
	for (int i=1; i<=n; i++) {
		if (a[i]>last) {
			ans++;
			last=a[i];//更新现在的高度 
		}
	} 
	
	cout<<ans<<"\n";
	
	return 0;
}
