//http://47.110.135.197/problem.php?id=5682
//5682: 最长连续序列

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e4+10;
int fa[MAXN];
int sa[MAXN];
int n;
void init() {
	for (int i=0; i<=n; i++) {
		fa[i]=i;
		sa[i]=1;
	}
}
int find(int x) {
	if (fa[x]!=x) {
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
void join(int x, int y) {
	x=find(x);
	y=find(y);
	if (x==y) {
		return;
	}
	if (sa[x]<sa[y]) {
		swap(x, y);
	}
	fa[y]=x;
	sa[x]+=sa[y];
}

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	map<int, int> hash;
	cin>>n;
	init();
	for (int i=1; i<=n; i++) {
		int num;
		cin>>num;
		hash[num]++;
		if (hash.count(num-1)>0) {
			join(num, num-1);
		}
		if (hash.count(num+1)>0) {
			join(num, num+1);
		}
	}
	
	int ans=0;
	for (int i=1; i<=n; i++) {
		ans=max(ans, sa[find(i)]);
	}
	cout<<ans<<"\n";

	return 0;
}

