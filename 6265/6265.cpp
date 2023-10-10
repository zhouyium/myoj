//http://47.110.135.197/problem.php?id=6265
//6265: ͼ�е�Ĳ��

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E5+10;//�������� 
const int MAXM=2*MAXN;//������ 

//���ӱ���
LL h[MAXN]; //ÿ�������ͷ
LL e[MAXM], ne[MAXM], idx; //����� 

void init() {
	fill(h, h+MAXN-2, -1);
}
//u->v�� 
void add(LL u, LL v) {
	e[idx]=v;
	ne[idx]=h[u];
	h[u]=idx;
	idx++;
}

LL n,m;

LL dis[MAXN];//����
LL que[MAXM];//����
LL hh;//��ͷ
LL tt;//��β 
 
LL bfs() {
	//����
	fill(dis, dis+MAXN-2, -1);
	
	//�������
	dis[1]=0;
	que[0]=1;
	
	while (hh<=tt) {
		//��ȡ���� 
		LL t=que[hh++];
		
		//�������б� 
		for (LL i=h[t]; i!=-1; i=ne[i]) {
			LL j=e[i];//��һ������
			if (dis[j]==-1) {
				//û�з���
				dis[j]=dis[t]+1;
				que[++tt] = j;
			}
		}
	}
	
	return dis[n];
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	//��ʼ��ͼ 
	init();
	
	cin>>n>>m;
	for (LL i=1; i<=m; i++) {
		LL u,v;
		cin>>u>>v;
		add(u,v);//����ͼ 
	}
	
	cout<<bfs()<<"\n";
	
	return 0;
}

