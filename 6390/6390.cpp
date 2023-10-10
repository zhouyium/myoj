#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL, LL>;

const LL INF=0x3f3f3f3f3f3f3f3f;

const int N=1e5+10;
vector<PLL> adj[N];
LL dis[N];
bool vis[N];

LL n;
void spfa(LL st) {
	//��ʼ��
	for (LL i=0; i<=n; i++) {
		dis[i]=INF;
		vis[i]=0;
	}
	
	//�������
	queue<LL> que;
	//�������
	dis[st]=0;
	vis[st]=1;
	que.push(st);
	
	while (que.size()) {
		LL u=que.front();
		que.pop();
		
		vis[u]=0;//u���ڶ�����
		
		//����u�����г���
		for (const auto &node : adj[u]) {
			LL v=node.first;
			LL w=node.second;
			
			//�ܷ��ɳ� 
			if (dis[v]>dis[u]+w) {
				dis[v]=dis[u]+w;
				
				//�ж�v�Ƿ��ڶ���
				if (!vis[v]) {
					vis[v]=1;
					que.push(v);
				}
			}
		}
	}
}

int main() {
	LL m;
	cin>>n>>m;
	for (LL i=1; i<=m; i++) {
		LL a,b,c;
		cin>>a>>b>>c;
		//a->b c
		adj[a].push_back({b,c});
	}
	
	spfa(1);
	
	if (dis[n]>=INF/2) {
		cout<<"impossible\n";
	} else {
		cout<<dis[n]<<"\n";
	}
} 
