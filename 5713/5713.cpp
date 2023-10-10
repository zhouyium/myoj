//http://47.110.135.197/problem.php?id=5713
//5713: �����ʵ�·��

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=5e3+10;
int fa[MAXN];
int sa[MAXN];
void init(int n) {
	for (int i=0; i<=n; i++) {
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

const int MAXM=5e3+10;
struct EDGE {
	int x,y;
	int v;
} edge[MAXM];

bool mycmp(const EDGE &a, const EDGE &b) {
	return a.v<b.v;
}

const double INF=2e18+10;

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T;
	cin>>T;
	while (T--) {
		int n,m;
		cin>>n>>m;
		
		//���·����Ϣ 
		for (int i=1; i<=m; i++) {
			cin>>edge[i].x>>edge[i].y>>edge[i].v;
		}
		sort(edge+1, edge+m+1, mycmp);
		
		//��ȡ����յ� 
		int s, t;
		cin>>s>>t;
		
		//�����߿�ʼ���������С�ı� 
		double radio=INF;
		int maxv=0;
		int minv=0;
		for (int i=m; i>=1; i--) {
			init(n);
			int j;
			for (j=i; j>=1; j--) {
				//����ʹS����T������ٶ�
				//�ϲ� 
				int x=find(edge[j].x);
				int y=find(edge[j].y);
				if (x==y) {
					continue;
				}
				fa[y]=x;
				
				//�鿴�յ������Ƿ���һ��
				if (find(s)==find(t)) {
					break;
				}
			}
			
			if (0==j) {
				//�����յ㲻��ͬһ������ 
				break;
			}
			
			//�鿴��ֵ
			if (1.0*edge[i].v/edge[j].v<radio) {
				radio=1.0*edge[i].v/edge[j].v;
				maxv=edge[i].v;
				minv=edge[j].v;
			}
		}
		
		//����GCD
		int gcd=__gcd(maxv, minv) ;
		if (radio==INF) {
			cout<<"IMPOSSIBLE\n";
		} else if (0==maxv%minv){ 
			cout<<maxv/minv<<"\n";
		} else {
			cout<<maxv/gcd<<"/"<<minv/gcd<<"\n";
		}
	}
	return 0;
}

