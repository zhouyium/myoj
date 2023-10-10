//5598: 选取（choose）
//http://47.110.135.197/problem.php?id=5598
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2E1+10;
LL a[N];
LL n,K;
LL ans;

bool prime(LL x) {
	if (x==1) {
		return false;
	}
	for (LL i=2; i*i<=x; i++) {
		if (x%i==0) {
			return false;
		}
	}
	return true;
}

//step: 当前第几个数，就是数组下标 
//tot:  已经选了几个数
//sum:  当前和 
void dfs(LL step, LL tot, LL sum) {
	//cout<<"step="<<step<<" tot="<<tot<<" sum="<<sum<<"\n";
	if (tot>=K) {
		if (prime(sum)) {
			//cout<<"tot="<<tot<<" sum="<<sum<<"\n";
			ans++;
		}
		return;
	}
	if (step>n) {
		//cout<<step<<">"<<n<<"\n";
		return;
	}
	//选
	dfs(step+1, tot+1, sum+a[step]);
	//不选
	dfs(step+1, tot, sum);
	 
}
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	cin>>n>>K;
	for (LL i=1; i<=n; i++) {
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans<<"\n";

	return 0;
}

