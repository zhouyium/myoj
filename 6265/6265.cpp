//http://47.110.135.197/problem.php?id=6265
//6265: 图中点的层次

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E5+10;//顶点数量 
const int MAXM=2*MAXN;//边数量 

//连接表定义
LL h[MAXN]; //每个顶点队头
LL e[MAXM], ne[MAXM], idx; //保存边 

void init() {
	fill(h, h+MAXN-2, -1);
}
//u->v边 
void add(LL u, LL v) {
	e[idx]=v;
	ne[idx]=h[u];
	h[u]=idx;
	idx++;
}

LL n,m;

LL dis[MAXN];//距离
LL que[MAXM];//队列
LL hh;//对头
LL tt;//队尾 
 
LL bfs() {
	//处理
	fill(dis, dis+MAXN-2, -1);
	
	//处理起点
	dis[1]=0;
	que[0]=1;
	
	while (hh<=tt) {
		//获取队首 
		LL t=que[hh++];
		
		//遍历所有边 
		for (LL i=h[t]; i!=-1; i=ne[i]) {
			LL j=e[i];//下一个顶点
			if (dis[j]==-1) {
				//没有访问
				dis[j]=dis[t]+1;
				que[++tt] = j;
			}
		}
	}
	
	return dis[n];
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	//初始化图 
	init();
	
	cin>>n>>m;
	for (LL i=1; i<=m; i++) {
		LL u,v;
		cin>>u>>v;
		add(u,v);//有向图 
	}
	
	cout<<bfs()<<"\n";
	
	return 0;
}

