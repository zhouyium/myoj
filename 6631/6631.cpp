//6631: [JSOI2007]建筑抢修
//http://47.110.135.197/problem.php?id=6631
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1E6+10;
struct NODE {
	LL t1, t2;
} a[N];

//按照报废时间排序 
bool mycmp(const NODE &a, const NODE &b) {
	return a.t2<b.t2;
}

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
	for (LL i=1; i<=n; i++) {
		cin>>a[i].t1>>a[i].t2;
	}
	sort(a+1, a+n+1, mycmp);
	
	LL sum=0;//当前使用时间 
	LL cnt=0;//修复的建筑 
	priority_queue<LL> que;//保存修复时间 
	for (LL i=1; i<=n; i++) {
		if (sum+a[i].t1<=a[i].t2) {
			//可以修理
			cnt++;
			sum+=a[i].t1;
			que.push(a[i].t1);
		} else {
			//不能修理
			//看看优先队列是否有更好的选择
			if (que.top()>a[i].t1) {
				sum-=que.top();
				que.pop();
				sum+=a[i].t1;
				que.push(a[i].t1);
			}
		}
	}
	cout<<cnt<<"\n";

	return 0;
}

