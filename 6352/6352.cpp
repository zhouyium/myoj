//http://47.110.135.197/problem.php?id=6352
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=3E2+10;

struct NODE {
	LL x,y,h;
	bool operator <(const NODE &x) const {
		return h<x.h;
	}
};

LL a[N][N], ans;
bool flag[N][N];

LL dx[]={0,-1,0,0,1};
LL dy[]={0,0,-1,1,0};

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL T;
	cin>>T;
	for (LL t=1; t<=T; t++) {
		cout<<"Case #"<<t<<": ";
		
		LL n,m;
		cin>>n>>m;
		
		priority_queue<NODE> que;
		for (LL i=1; i<=n; i++) {
			for (LL j=1; j<=m; j++) {
				flag[i][j]=false;
				cin>>a[i][j];
				que.push((NODE){i,j,a[i][j]});
			}
		}
		
		LL ans=0;
		while (que.size()) {
			NODE now=que.top();
			que.pop();
			
			if (flag[now.x][now.y]) {
				continue;
			}
			flag[now.x][now.y]=true;
			
			LL x=now.x;
			LL y=now.y;
			for (LL i=1; i<=4; i++) {
				LL nx=x+dx[i];
				LL ny=y+dy[i];
				if (1<=nx&&nx<=n&&1<=ny&&ny<=m&&flag[nx][ny]==false&&now.h-1>a[nx][ny]) {
					ans+=now.h-a[nx][ny]-1;
					a[nx][ny]=now.h-1;
					que.push((NODE){nx, ny, a[nx][ny]});
				}
			}
		}
		
		cout<<ans<<"\n";
	}

	return 0;
}

