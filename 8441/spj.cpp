//8441: 病毒
//http://47.110.135.197/problem.php?id=8441
#include<bits/stdc++.h>
#include"../testlib.h"
 
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-4;

const int N=2e3+10;
LL dis[N][N];
queue<PLL> que;
LL n,m;

void bfs() {
	const LL dx[]={0,-1,0,1, 0};
	const LL dy[]={0, 0,1,0,-1};
	while (que.size()) {
		auto node=que.front(); que.pop();
		
		LL x=node.first;
		LL y=node.second;
		LL t=dis[x][y];
		for (LL i=1;i<=4;i++) {
			LL nx=x+dx[i];
			LL ny=y+dy[i];
			//合法性判断
			if (nx<1||nx>n||ny<1||ny>m) {
				continue;
			} 
			if (dis[nx][ny]>t+1) {
				dis[nx][ny]=t+1;
				que.push({nx,ny});
			}
		}
	}
} 

void solve(LL T) {
	//从inf读取 
	n=inf.readLong();
	m=inf.readLong();
	LL K=inf.readLong();
	for (LL i=1;i<=n;i++){
		for (LL j=1;j<=m;j++){
			dis[i][j]=INF;
		}
	}
	for (LL i=1;i<=K;i++){
		LL x=inf.readLong();
		LL y=inf.readLong();
		//加入队列 
		que.push({x,y});
		dis[x][y]=0; 		
	}
	
	//从ouf中读取
	LL outx=ouf.readLong();
	LL outy=ouf.readLong();
	
	//从ans中读取 
	LL ansx=ans.readLong();
	LL ansy=ans.readLong();
	
	if (outx==ansx&&outy==ansy) {
		quitf(_ok, "The answer is correct.\n");
		return;
	}
	
	//答案不一样
	bfs();
	
	//找答案，在所有最短举例中最大值 
	LL maxx=0;
	for (LL i=1;i<=n;i++){
		for (LL j=1;j<=m;j++){
			maxx=max(maxx,dis[i][j]);
		}
	}

	bool f=false;
	for (LL i=1;i<=n;i++){
		for (LL j=1;j<=m;j++){
			if (dis[i][j]==maxx&&i==ansx&&j==ansy) {
				quitf(_ok, "The answer is correct.\n");
				return;
			}
		}
	}
	quitf(_wa, "The answer is wrong.\n");	
}

int main(int argc, char *argv[]) {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	registerTestlibCmd(argc, argv);

	//freopen("marathon.in", "r", stdin);
	//freopen("marathon.out", "w", stdout);

	int T=1;
	//T=inf.readLong();
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve(i);
	}
	
	return 0;
}

