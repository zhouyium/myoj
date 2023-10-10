#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1E6+10;
LL a[N];
LL n,m;

//��midΪ�磬���ܷ��Ϊm�� 
bool check(LL mid) {
	LL cnt=0;
	LL sum=0;
	for (LL i=1; i<=n; i++) {
		if (sum+a[i]<=mid) {
			sum+=a[i];
		} else {
			//�µ�һ������
			cnt++;
			sum=0; 
		}
	}
	if (sum>0) {
		cnt++;
	}
	//cnt>m˵���������ˣ�mid����С�ˣ�mid��� 
	return cnt>=m;
}

//���������С min
LL bsearch(LL l, LL r) {
	LL mid;
	while (l<r) {
		mid=(l+r)/2;
		if (check(mid)) {
			l=mid; 
		} else {
			r=mid-1;
		}
	}
}

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	cin>>n>>m;
	for (LL i=1; i<=m; i++) {
		cin>>a[i];
	}
	
	cout<<bsearch(1, n)<<"\n";

	return 0;
}

