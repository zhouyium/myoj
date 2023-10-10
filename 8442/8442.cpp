#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e3+10;
LL n,m;
LL dis[N][N];
queue<PLL> que;

void bfs() {
	const LL dx[]={0,1,0,-1,0};
	const LL dy[]={0,0,1, 0,-1};
	
	while (que.size()) {
		auto node=que.front();
		que.pop();
		
		LL x=node.first;
		LL y=node.second;
		LL t=dis[x][y];
		for (LL i=1;i<=4;i++) {
			LL nx=x+dx[i];
			LL ny=y+dy[i];
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

void solve() {
	cin>>n>>m;
	for (LL i=1;i<=n;i++) {
		for (LL j=1;j<=m;j++) {
			dis[i][j]=INF;
			
			char ch;
			cin>>ch;
			if (ch=='g') {
				que.push({i,j});
				dis[i][j]=0;
			}
		}
	}
	
	bfs();
	
	LL K;
	cin>>K;
	for (LL i=1;i<=n;i++){
		for (LL j=1;j<=m;j++) {
			if (dis[i][j]>K) {
				cout<<".";
			} else {
				cout<<"g";
			}
		}
		cout<<"\n";
	}
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	freopen("00.in", "r", stdin);
	freopen("00.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

