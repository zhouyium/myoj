#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

//多源BFS 
const int N=2e3+10;
LL dis[N][N];
const int K=12;
queue<PLL> que;//BFS的队列 
LL n,m;
PLL ans[N];

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

LL ran(LL l=1,LL r=1e3) {
	if (l>r) {
		swap(l,r);
	}
	return rand()%(r-l+1)+l;
}
 
void solve() {
	LL K;
	cin>>n>>m>>K;
	for (LL i=1;i<=n;i++){
		for (LL j=1;j<=m;j++){
			dis[i][j]=INF;
		}
	}

	for (LL k=1;k<=K;k++){
		LL x,y;
		cin>>x>>y;
		//加入队列 
		que.push({x,y});
		dis[x][y]=0; 
	}
	
	//多源bfs
	bfs();
	
	//找答案，在所有最短举例中最大值 
	LL maxx=0;
	for (LL i=1;i<=n;i++){
		for (LL j=1;j<=m;j++){
			maxx=max(maxx,dis[i][j]);
		}
	}
	
	//将答案放入ans
	LL cnt=0;
	for (LL i=1;i<=n;i++){
		for (LL j=1;j<=m;j++){
			if (dis[i][j]==maxx) {
				++cnt;
				ans[cnt].first=i;
				ans[cnt].second=j;
			}
		}
	}
	//cout<<cnt<<"\n";
	
	//随机生成一个答案
	srand(time(NULL)); 
	LL idx=ran(1,cnt);
	cout<<ans[idx].first<<' '<<ans[idx].second<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	freopen("10.in", "r", stdin);
	freopen("10.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}
