#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E6+10;
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL n;
	cin>>n;
	
	//假设一共有x个房子，我家是y号
	//总和x*(x+1)/2-3*y=n 
	//假设 sum 为总和，cnt 是我的房子号 
	//门牌号大于0 -> sum>n
	//门牌号为整数 -> (sum-n)%3==0
	//门牌号不能大于最大门牌号 -> (sum-n)/3<=cnt 
	LL cnt=1, sum=1;
	while (!(sum>n && (sum-n)%3==0 && (sum-n)/3<=cnt)) {
		cnt++;
		sum+=cnt; 
	}
	
	cout<<(sum-n)/3<<" "<<cnt<<"\n";

	return 0;
}

