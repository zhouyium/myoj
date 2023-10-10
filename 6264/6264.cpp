//http://47.110.135.197/problem.php?id=6264
//DD
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;

const int MAXN=1E5+10;
const int MAXM=4e5+10;

LL n,m;
LL tot, fir[MAXN];
LL nex[MAXM], to[MAXM], id[MAXM];

//建边 
void add(LL x, LL y, LL c) {
	tot++;
	to[tot]=y;
	id[tot]=c;
	nex[tot]=fir[x];
	fir[x]=tot;
}

bool vis[MAXM];
LL dis[MAXM];

struct NODE {
	LL x,y;
	bool operator<(const NODE &a) const {
		return y>a.y;
	}
};
priority_queue<NODE> Q;

LL dij(LL st) {
	fill(dis, dis+MAXM-2, 0x3f3f3f3f);
	for (LL i=fir[st]; i; i=nex[i]) {
		dis[i]=1;
		Q.push({i,1});
	}
	
	while (Q.size()) {
		LL d=Q.top().x;
		Q.pop();
		if (vis[d]) {
			continue;
		}
		vis[d]=1;
		
		LL u=to[d];
		if (u==n) {
			return dis[d];
		}
		
		for (LL i=fir[u]; i; i=nex[i]) {
			int t=(id[i]==id[d])?0:1;//判断是否同一个公司 
			if (vis[i]==false && dis[i]>dis[d]+t) {
				dis[i]=dis[d]+t;
				Q.push({i, dis[i]});
			}
		}
	}
	
	return -1;
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	cin>>n>>m;
	for (LL i=1; i<=m; i++) {
		LL u,v,c;
		cin>>u>>v>>c;
		//建边 
		add(u,v,c);
		add(v,u,c);
	}
	
	cout<<dij(1)<<"\n";

	return 0;
}

