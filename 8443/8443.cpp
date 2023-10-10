#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=1e3+10;
LL dis[N][N];
char a[N][N];
const int P=10;
LL s[P];

queue<PLL> que;
LL n,m;

void check(LL x,LL y){
	if(x<1||x>n||y<1||y>m||a[x][y]!='.'){
		return false;
	}
	return true;
}

void bfs() {
	const LL dx[]={0,-1,0,1, 0};
	const LL dy[]={0, 0,1,0,-1};
	
	while (que.size()) {
		auto now=que.front();
		que.pop();
		
		LL x=now.first;
		LL y=now.second;
		LL t=dis[x][y];
		for (LL i=1;i<=4;i++){
			LL nx=x+dx[i];
			LL ny=y+dy[i];
			if (check(nx,ny)==false){
				continue;
			}
			if (dis[nx][ny]>t+1){
				dis[nx][ny]=t+1;
				que.push({nx,ny});
			}
		}
	}
}

void solve() {
	LL p;
	cin>>n>>m>>p;
	for (LL i=1;i<=p;i++){
		cin>>s[i];
	}
	for (LL i=1;i<=n;i++){
		for (LL j=1;j<=m;j++){
			cin>>a[i][j];
			dis[i][j]=INF;
		}
	}
	
	for (LL k=1;k<=p;k++){
		for (LL i=1;i<=n;i++){
			for (LL j=1;j<=m;j++){
				if (a[i][j]-'0'==k){
					dis[i][j]=0;
					que.push({i,j});
				}
			}
		}
	}
	
	bfs();
}

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	//freopen("marathon.in", "r", stdin);
	//freopen("marathon.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

