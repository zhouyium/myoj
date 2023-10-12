#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=1e5+10;
vector<LL> tree[N];
LL deep[N];
LL fa[N];

void dfs(LL u,LL fath){
	if (fath==-1){
		deep[u]=0;
	}else{
		deep[u]=deep[fath]+1;
	}
	for(const auto &v:tree[u]){
		dfs(v,u);
	}
}

void solve() {
	LL n;
	cin>>n;
	//初始化 
	for(LL i=0;i<n;i++){
		fa[i]=-1;
	}
	for(LL i=1;i<=n;i++){
		LL id,k;
		cin>>id>>k;
		for(LL j=1;j<=k;j++){
			LL x;
			cin>>x;
			tree[id].push_back(x);
			fa[x]=id;
		}
	}
	//找跟节点
	LL rt;
	for(LL i=0;i<n;i++){
		if(fa[i]==-1){
			rt=i;
			break;
		}
	}

	dfs(rt,-1);
	for(LL i=0;i<n;i++){
		LL m=tree[i].size();
		cout<<"node "<<i<<": parent = "<<fa[i]<<", depth = "<<deep[i]<<", ";
		if(deep[i]==0){
			cout<<"root";
		}else if(m==0){
			cout<<"leaf";
		}else{
			cout<<"internal node";
		}
		cout<<", [";
		for(LL j=0;j<m;j++){
			cout<<tree[i][j];
			if(j!=m-1){
				cout<<", ";
			}
		}
		cout<<"]\n";
	}
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	freopen("12.in", "r", stdin);
	//freopen("12.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

