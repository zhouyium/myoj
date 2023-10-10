#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=3e5+10;
LL h[N];
struct NODE {
	LL w;//位置
	LL h;//高度 
};
NODE stk[N];//单调栈 
LL top;

void solve() {
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>h[i];
	}
	
	LL ans=0;//答案 
	LL cnt=0;//数量 
	//起点 
	stk[++top]={0,0};
	for(LL i=1;i<=n+1;i++){
		//依次入栈计算（增加了n-1个点，高度为0，确保全部出栈）
		while(top>0 && h[i]<=stk[top].h){
			//当前高度小于栈顶，则计算栈顶高度的最大面积
			LL hh=stk[top].h;
			top--;
			
			if(top==0){
				continue;
			}
			
			//计算面积
			LL area=hh*(i-stk[top].w-1);
			if(area>ans){
				ans=area;
				cnt=1;
			}else if(area==ans){
				cnt++;
			}
		}
		stk[++top]={i,h[i]};
	}
	
	cout<<ans<<"\n"<<cnt<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	//freopen("07.in", "r", stdin);
	//freopen("07.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

