//6650: ����������� II
//http://47.110.135.197/problem.php?id=6650 
/*
����һ����ջ�����ö��ֵ�˼· 
*/ 
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1E6+10;
LL a[N];//�������� 
LL st[N];//��ջ
LL top;//ջ��ָ��  

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
	//ʹ��STL	
	vector<LL> stk;//ģ���ջ�����浱ǰ���Ԫ�� 
	//��ǰ����� 
	stk.push_back(a[1]);
	for (LL i=2; i<=n; i++) {
		if (a[i]>stk.back()) {
			//����ջ������ 
			stk.push_back(a[i]);
		} else {
			//�ҵ���һ�����ڵ��ڸ����ֵ����滻
			*lower_bound(stk.begin(), stk.end(), a[i]) = a[i];
		}
	}
	cout<<stk.size()<<"\n";
#endif

	return 0;
}

