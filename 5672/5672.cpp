#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
const int MAXN=1e3+10;
int pa[MAXN];//���� 
int sa[MAXN];//������Ԫ�ظ���

//��ʼ�� 
void init() {
	for (int i=1; i<=n; i++) {
		pa[i]=i;
		sa[i]=1;
	}
} 

//�Ҹ��� 
int find(int x) {
	if (pa[x]!=x) {
		pa[x]=find(pa[x]);
	}
	return pa[x];
}

//������ϵ
void join(int x, int y) {
	int px=find(x);
	int py=find(y);
	if (px!=py) {
		pa[px]=py;
		sa[py]+=sa[px];
	}
}

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	while (cin>>n && n!=0) {
		int m;
		cin>>m;
		
		init();
		for (int i=1; i<=m; i++) {
			int x,y;
			cin>>x>>y;
			join(x, y);
		}
		
		//����һ�¸������Լ���
		int ans=0;
		for (int i=1; i<=n; i++) {
			if (i==find(i)) {
				ans++;
			}
		}
		cout<<ans-1<<"\n";
	}

	return 0;
}

