#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=1e3+10;
char a[N][N];
LL n,m;
LL sx,sy;//���
LL ex,ey;//�յ� 
queue<PLL> qv;//�ҽ�
LL disv[N][N];//�ҽ����� 
LL dism[N][N];//�˾��� 
//�߷� 
const LL dx[]={0,1,0,-1, 0};
const LL dy[]={0,0,1, 0,-1};

void init() {
	//����������
}

bool check(LL x,LL y){
	if (x<1||x>n||y<1||y>m||a[x][y]=='#'){
		return false;
	}
	return true;
}

//�ҽ�BFS ��ԴBFS 
void bfs() {
	while (qv.size()){
		auto now=qv.front();
		qv.pop();
		
		LL x=now.first;
		LL y=now.second;
		LL t=disv[x][y];
		for (LL i=1;i<=4;i++){
			LL nx=x+dx[i];
			LL ny=y+dy[i];
			if (check(nx,ny)){
				if (disv[nx][ny]>t+1){
					disv[nx][ny]=t+1;
					qv.push({nx,ny});
				}
			}
		}
	}
} 

//����bfs ��Դbfs
void bfs1(){
	queue<PLL> que;
	que.push({sx,sy});
	
	while (que.size()) {
		auto now=que.front();
		que.pop();
		
		LL x=now.first;
		LL y=now.second;
		LL t=dism[x][y];
		for (LL i=1;i<=4;i++){
			LL nx=x+dx[i];
			LL ny=y+dy[i];
			if (check(nx,ny)){
				if (dism[nx][ny]>t+1){
					dism[nx][ny]=t+1;
					que.push({nx,ny});
				}
			}
		}
	}
}

void solve() {
	cin>>n>>m;
	init();
	for (LL i=1;i<=n;i++){
		for (LL j=1;j<=m;j++){
			disv[i][j]=dism[i][j]=INF;
			
			cin>>a[i][j];
			if (a[i][j]=='!'){
				disv[i][j]=0;
				qv.push({i,j});
			} else if (a[i][j]=='S'){
				dism[i][j]=0;
				sx=i;sy=j;
			} else if (a[i][j]=='E'){
				ex=i;ey=j;
			}
		}
	}
	bfs();//�ҽ�BFS
	bfs1();//��BFS
	if (dism[ex][ey]<=disv[ex][ey]){
		cout<<"Yes\n";
	}else{
		cout<<"No\n";
	}
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	//freopen("marathon.in", "r", stdin);
	//freopen("marathon.out", "w", stdout);

	int T=1;
	cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

