//1045: ��������Fire��
//http://47.110.135.197/problem.php?id=1045 
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E1+10;
const char db='o';
char a[MAXN][MAXN];
LL n;
LL ans;

//���(x,y)�ܷ�ŵﱤ 
bool check(LL x, LL y) {
	//x����
	for (LL i=1; i<=n; i++) {
		if (i==x) {
			continue;
		} else if (a[i][y]==db) {
			//�ﱤ 
			return false;
		} else if (a[i][y]=='X') {
			//ʯǽ 
			break;
		}
	}
	//y����
	for (LL i=1; i<=n; i++) {
		if (i==y) {
			continue;
		} else if (a[x][i]==db) {
			//�ﱤ 
			return false;
		} else if (a[x][i]=='X') {
			//ʯǽ 
			break;
		}
	}

	return true;
}

void dfs(LL step) {
	if (step>ans) {
		ans=step;
	}

	for (LL i=1; i<=n; i++) {
		for (LL j=1; j<=n; j++) {
			if (a[i][j]=='.' && check(i, j)) {
				a[i][j]=db;//��ʾ�ﱤ
				dfs(step+1);
				a[i][j]='.';
			}
		}
	}
}
int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	cin>>n;
	for (LL i=1; i<=n; i++) {
		for (LL j=1; j<=n; j++) {
			cin>>a[i][j];
		}
	}
	
	ans=0;		
	dfs(1);
	cout<<ans-1<<"\n";

	return 0;
}

