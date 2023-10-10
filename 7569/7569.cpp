#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const LL MO=1e9+7;

const int N=1E3+10;
char a[N][N];
LL n,m; 
//��·���� 
const LL dx[]={0,1,0,-1,0};
const LL dy[]={0,0,1,0,-1};
//����ض��� 
LL disa[N][N];//�˾��� 
LL pre[N][N];//pre[i][j]��ʾ 
LL sx,sy;//���
LL ex,ey;//�յ� 
//������ض��� 
vector<PLL> vm;//���� 
LL dism[N][N];//������� 

bool check(LL x,LL y){
	if (x<1||x>n||y<1||y>m||a[x][y]!='.'){
		return false;
	}
	return true;
}

void bfsa() {
	//����bfs
	queue<PLL> que;
	que.push({sx,sy});
	disa[sx][sy]=0;
	
	while (que.size()){
		auto now=que.front();
		que.pop();
		
		LL x=now.first;
		LL y=now.second;
		LL t=disa[x][y];
		for (LL i=1;i<=4;i++){
			LL nx=x+dx[i];
			LL ny=y+dy[i];
			
			if (false==check(nx,ny)){
				continue;
			}
			if (disa[nx][ny]>t+1) {
				disa[nx][ny]=t+1;
				pre[nx][ny]=i;//��i���� 
				que.push({nx,ny});
			}
		}
	}
}

void bfsm() {
	//������bfs����Դ
	queue<PLL> que;
	for (const auto &node:vm) {
		dism[node.first][node.second]=0;
		que.push(node);
	}
	
	while (que.size()) {
		auto now=que.front();
		que.pop();
		
		LL x=now.first;
		LL y=now.second;
		LL t=dism[x][y];
		for (LL i=1;i<=4;i++){
			LL nx=x+dx[i];
			LL ny=y+dy[i];
			
			if (false==check(nx,ny)){
				continue;
			}
			if (dism[nx][ny]>t+1) {
				dism[nx][ny]=t+1;
				que.push({nx,ny});
			}
		}
	}
}

void print(LL x,LL y){
	if (x==sx&&y==sy){
		return;
	}
	LL idx=pre[x][y];
	print(x-dx[idx],y-dy[idx]);
	if (idx==1){
		cout<<'D';
	} else if (idx==2) {
		cout<<'R';
	} else if (idx==3) {
		cout<<'U';
	} else {
		cout<<'L';
	}
}

void solve() {
	ex=ey=-1;
	cin>>n>>m;
	for (LL i=1;i<=n;i++){
		for (LL j=1;j<=m;j++){
			cin>>a[i][j];
			
			disa[i][j]=dism[i][j]=INF;
			if (a[i][j]=='A'){
				//��� 
				sx=i;sy=j;
			} else if (a[i][j]=='M') {
				//����
				vm.push_back({i,j});
			}
		}
	}
	
	bfsa();//����bfs
	bfsm();//������bfs 
	
	//����һ�����Թ���Ե
	for (LL i=1;i<=m;i++) {
		if (disa[1][i]!=INF && (dism[1][i]==INF||disa[1][i]<dism[1][i])) {
			cout<<"YES\n";
			cout<<disa[1][i]<<"\n";
			print(1,i);
			return;
		}
		if (disa[n][i]!=INF && (dism[n][i]==INF||disa[n][i]<dism[n][i])) {
			cout<<"YES\n";
			cout<<disa[n][i]<<"\n";
			print(n,i);
			return;
		}		
	}
	for (LL i=1;i<=n;i++){
		if (disa[i][1]!=INF && (dism[i][1]==INF||disa[i][1]<dism[i][1])) {
			cout<<"YES\n";
			cout<<disa[i][1]<<"\n";
			print(i,1);
			return;
		}
		if (disa[i][m]!=INF && (dism[i][m]==INF||disa[i][m]<dism[i][m])) {
			cout<<"YES\n";
			cout<<disa[i][m]<<"\n";
			print(i,m);
			return;
		}		
	}
	cout<<"NO\n"; 
}

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("00.in", "r", stdin);
	//freopen("my.out", "w", stdout);
	LL T=1;
	//cin>>T;
	for (LL i=1; i<=T; i++) {
		//cout<<i<<"\n";
		solve();
	}

	return 0;
}
