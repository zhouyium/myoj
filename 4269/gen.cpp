//4269产生随机数据 
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=2e2+10;
LL a[MAXN];
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	freopen("04.in", "w", stdout);
	
	srand(time(0));
	
	LL n=200;
	cout<<n<<"\n";
	
	//随机一个数组
	LL maxx=1e6;
	LL minx=1e5;
	map<LL, bool> M;
	for (LL i=1; i<=n; i++) {
		do {
			a[i]=minx-i+1;
		} while (M.count(a[i])>0);
		M[a[i]]=true;
		cout<<a[i]<<" ";
	} 
	cout<<"\n";
	
	return 0;
}

