#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e5+10;
PLL a[N];

bool mycmp(const PLL &x,const PLL &y){
	if(x.first==y.first){
		return x.second<y.second;
	}
	return x.first<y.first;
}

//单调队列
LL que[N];
LL cnt;
 
void solve() {
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	sort(a+1,a+n+1,mycmp);
	
	for(LL i=1;i<=n;i++){
		if(a[i].second>=que[cnt])	{
			//如果比最大的大，则加入
			cnt++;
			que[cnt]=a[i].second;
		}else{
			//替换掉大于他的最小的那个
			LL pos=upper_bound(que+1,que+cnt+1,a[i].second)-que;
			que[pos]=a[i].second;
		}
	}
	
	cout<<cnt<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	freopen("09.in", "r", stdin);
	freopen("09.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

