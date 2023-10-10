#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=1e6+10;
bool a[N];

void solve() {
	LL n,m;
	cin>>m>>n;
	
	LL tot=n;
	LL cnt=0;
	LL idx=0;//当前索引 
	while (tot) {
		while (a[idx]) {
			idx=(idx+1)%n;
		}
		cnt=(cnt+1)%m;
		if (cnt==0) {
			//对应idx删除
			a[idx]=1;//出列
			cout<<idx+1<<" ";
			tot--; 
		}
		idx=(idx+1)%n;
	}
	cout<<"\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);

	freopen("00.in", "r", stdin);
	freopen("00.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

