//6650: 最长上升子序列 II
//http://47.110.135.197/problem.php?id=6650 
/*
保存一个堆栈，利用二分的思路 
*/ 
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1E6+10;
LL a[N];//保存数据 
LL st[N];//堆栈
LL top;//栈顶指针  

LL bsearch(LL l, LL r, LL num) {
	LL mid;
	while (l<r) {
		mid=(l+r)/2;
		if (st[mid]>=num) {
			r=mid;
		} else {
			l=mid+1;
		}
	}
	return l;
}

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	LL n;
	cin>>n;
	for (LL i=1; i<=n; i++) {
		cin>>a[i];
	}
	

#if 1
	st[++top]=a[1];
	for (LL i=2; i<=n; i++) {
		if (a[i]>st[top]) {
			st[++top]=a[i];
		} else {
			LL pos=bsearch(1, top, a[i]);
			st[pos]=a[i];
		}
	}
	cout<<top<<"\n";
#else
	//使用STL	
	vector<LL> stk;//模拟堆栈，保存当前最大元素 
	//当前最长序列 
	stk.push_back(a[1]);
	for (LL i=2; i<=n; i++) {
		if (a[i]>stk.back()) {
			//大于栈顶推入 
			stk.push_back(a[i]);
		} else {
			//找到第一个大于等于该数字的数替换
			*lower_bound(stk.begin(), stk.end(), a[i]) = a[i];
		}
	}
	cout<<stk.size()<<"\n";
#endif

	return 0;
}

