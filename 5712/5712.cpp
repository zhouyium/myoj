//http://47.110.135.197/problem.php?id=5712
//5712: 小希的迷宫

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//并查集
const int MAXN=1e5+10;
int fa[MAXN];
int sa[MAXN]; 
int n;
void init() {
	for (int i=0; i<=1e5; i++) {
		fa[i]=i;
		sa[i]=1;
	}
}
int find(int x) {
	if (fa[x]!=x) {
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
bool circle;
void join(int x, int y) {
	x=find(x);
	y=find(y);
	if (x==y) {
		circle=true;
		return;
	}
	if (sa[x]<sa[y]) {
		swap(x, y);
	}
	fa[y]=x;
	sa[x]+=sa[y];		
}
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	set<int> s;//顶点个数 
	init();
	int x,y;
	int sum=0;//边的数量
	circle=false;
	while (cin>>x>>y) {
		if (x==0 && y==0) {
			if (0==sum && circle==false) {
				cout<<"Yes\n";
			} else if (circle==false && s.size()==sum+1) {
				cout<<"Yes\n";
			} else {
				cout<<"No\n";
			}
			
			init();
			s.clear();
			sum=0;//边的数量
			circle=false;
		} else if (x==-1 && y==-1) {
			break; 
		} else {
			//保存顶点 
			s.insert(x);
			s.insert(y);
			join(x, y);
			sum++;
		}
	}

	return 0;
}

