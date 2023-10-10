#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=1e3+10;
LL f[N][N];//����
LL dis[N][N];//���� 
char g[N][N];

LL dx[4]={0,0,1,-1};//���������ĸ�����
LL dy[4]={-1,1,0,0};

void solve() {
	LL n,m;
	cin>>n>>m;
	for(LL i=1;i<=n;i++){
		for(LL j=1;j<=m;j++){
			cin>>g[i][j];
			f[i][j]=dis[i][j]=0;
		}
	}
	
	//ע�⣬������Ҫ��̾���
	//���Ʋ��ܱ�֤��̾���
	//��Ҫʹ��BFS
	f[1][1]=1;
	dis[1][1]=0;
	queue<PLL> que;
	que.push({1,1});
	while(que.size()){
		auto node=que.front();que.pop();
		
		LL x=node.first;
		LL y=node.second;
		if(x==n&&y==m){
			break;
		}
		for(LL i=0;i<4;i++){
			LL nx=x+dx[i];
			LL ny=y+dy[i];
			//�Ϸ���
			if(nx<1||nx>n||ny<1||ny>m||g[nx][ny]=='#') {
				continue;
			}
			if(g[nx][ny]=='.'&&dis[nx][ny]==0){
				//�״ε���
				f[nx][ny]=f[x][y];
				dis[nx][ny]=dis[x][y]+1;
				que.push({nx,ny});
			}else if(dis[nx][ny]>0 && dis[nx][ny]==dis[x][y]+1){
				//���״ε����Ҳ���ͬ�״ε�����ͬ
				f[nx][ny]=(f[nx][ny]+f[x][y])%MO;
			}
		}
	}
	cout<<f[n][m]<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

