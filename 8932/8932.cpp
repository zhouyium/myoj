#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e6+10;

priority_queue<LL> que;//优先队列

void solve() {
	LL n,m;
	cin>>n>>m;
	
	LL ans=0;
	LL sum=0;//积压订单每天产生的不悦值总和
	for(LL i=1;i<=n;i++){
		LL x;
		cin>>x;
		
		sum+=x;//求出目前积压订单一天产生的不悦值总和
		ans+=sum;//累计不悦值
		
		que.push(x);//加入优先队列
		if(i>m){
			//如果当天可以处理订单
			LL y=que.top();//取得最大值
            que.pop();//从优先队列中弹出
            ans-=y;//去掉这个订单当天产生的不悦值
            sum-=y;//更新积压订单每天产生不悦值的总和
		}
	}
	
	//处理不悦值最大的订单，直至订单处理完
	while(que.size()){
		LL y=que.top();
		que.pop();
		sum-=y;//更新积压订单每天产生的不悦值总和
		ans+=sum;//累计不悦值
	}
	
	cout<<ans<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

