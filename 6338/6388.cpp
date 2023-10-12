#include <bits/stdc++.h>
using namespace std;
using LL=long long;

const LL INF=0x3f3f3f3f3f3f3f3f;

//bellman-ford 存图用的是链式前向星
const int N=1e4+10;
struct NODE {
	LL u,v,w;
} a[N]; 

LL dis[N];
LL bak[N];

LL n,m;

void bellman_ford(LL st, LL K) {
	//初始化变量 
	for (LL i=0; i<=n; i++) {
		dis[i]=INF;
	}
	dis[st]=0;
	
	for (LL i=1; i<=K; i++) {//保证有K条边 
		memcpy(bak, dis, sizeof dis);
		//遍历所有m条边 
		for (LL j=1; j<=m; j++) {
			LL u=a[j].u;
			LL v=a[j].v;
			LL w=a[j].w;
			if (dis[v]>bak[u]+w) {
				dis[v]=bak[u]+w;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	LL K;
	cin>>n>>m>>K;
	for (LL i=1; i<=m; i++) {
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	
	bellman_ford(1, K);
	
	if (dis[n]>=INF/2) {
		cout<<"impossible\n";
	} else {
		cout<<dis[n]<<"\n";
	}
	
	return 0;
}
