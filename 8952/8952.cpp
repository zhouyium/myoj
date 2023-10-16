//8952: DP54 小红的树
//http://47.110.135.197/problem.php?id=8952

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=1e5+10;
LL h[N];
LL f[N];
/*
f[i]表示以第i个结点为根的子树红色结点个数  
 */
const int M=2*N;
LL e[M], ne[M], idx;
string s;

void init(LL n){
	for(LL i=0;i<=n;i++){
		h[i]=-1;
		f[i]=0;
	}
	idx=0;
}

void add(LL a,LL b){
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}

LL dfs(LL u, LL fa){
	LL cnt=0;
	if(s[u]=='R'){
		cnt++;
	}
	for(LL i=h[u];i!=-1;i=ne[i]){
		LL v=e[i];
		if(v==fa){
			continue;
		}
		cnt+=dfs(v,u);
	}
	return f[u]=cnt;
}

void solve() {
	LL n;
	cin>>n;
	init(n);
	for(LL i=2;i<=n;i++){
		LL j;
		cin>>j;
		add(i,j);
		add(j,i);
	}
	cin>>s;
	s=" "+s;
	
	dfs(1,0);//构建数组
	
	LL q;
	cin>>q;
	while(q--){
		LL u;
		cin>>u;
		cout<<f[u]<<"\n";
	}
}

int main() {
#if 1
	//提交到OJ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	LL T=1;
	//cin>>T;
	while(T--) {
		//cout<<i<<"\n";
		solve();
	}
#else
	int n=13;
	for(int i=0;i<n;i++){
		char in[16];
		sprintf(in, "%02d.in", i);
		char out[16];
		sprintf(out, "%02d.out", i);
		
		freopen(in, "r", stdin);
		freopen(out, "w", stdout);
		
		LL T=1;
		//cin>>T;
		while(T--) {
			//cout<<i<<"\n";
			solve();
		}
		
		fclose(stdin);
		fclose(stdout);
	}
#endif
	
	return 0;
}
