#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

/*
我们可以固定每个数 a_i，并以 a_i 作为最大值，
求以 a_i 为最大值的区间个数，那么我们只需找到距离 
i 左边最近的大于它的位置以及右边最近的大于它的位置即可，
不妨记做 l_i 和 r_i 然后，根据乘法原理，以 a_i 为最大值
的区间个数就是 (i-l_i)*(r_i-i)
对于 l_i 和 r_i 可以用单调栈来求
于是  \sum_{1<=i<=j<=n}max(a_i,a_{i+1},...,a_j)
=\sum_{i=1}^{n}(i-l_i)*(r_i-i)*a_i
*/

const int N=5e5+10;
LL a[N];
LL l[N];
LL r[N];
//单调栈
LL stk[N],top; 

void solve() {
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	
	//初始化
	for(LL i=0;i<=n;i++){
		l[i]=0;
		r[i]=n;
	}
	
	for(LL i=1;i<=n;i++){
		while(top>0 && a[stk[top]]<=a[i]){
			r[stk[top]]=i;
			top--;
		}
		if(top==0){
			l[i]=-1;
		}else{
			l[i]=stk[top];
		}
		stk[++top]=i;
	}
	
	LL ans=0;
	for(LL i=1;i<=n;i++){
		ans+=(i-l[i])*(r[i]-i)*a[i];
	}
	cout<<ans<<"\n";
}

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	//freopen("marathon.in", "r", stdin);
	//freopen("marathon.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

