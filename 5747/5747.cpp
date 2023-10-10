//http://47.110.135.197/problem.php?id=5747
//http://acm.hdu.edu.cn/showproblem.php?pid=1394
//5747: 最小反转数

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=5e3+10;
int a[MAXN];//需要排序的数组
int t[MAXN];//归并排序附加 
int b[MAXN];//备份数组 

int n;
ll num;

void merge_sort(int L, int R) {
	if (L>=R) {
		return;
	}
	
	//分 
	int mid=(L+R)/2;
	merge_sort(L, mid);
	merge_sort(mid+1, R);
	
	//治
	int i=L;
	int j=mid+1;
	int k=L;
	while (i<=mid && j<=R) {
		if (a[i]<=a[j]) {
			t[k++]=a[i++];
		} else {
			t[k++]=a[j++];
			//cout<<mid-i+1<<"\n";
			num+=(mid-i+1);
		}
	}
	while (i<=mid) {
		t[k++]=a[i++];
	}
	while (j<=R) {
		t[k++]=a[j++];
	}
	for (i=L, j=L; i<=R; i++, j++) {
		a[i]=t[j];
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
	while (cin>>n) {
		num=0;
		for (int i=1; i<=n; i++) {
			cin>>a[i];
			b[i]=a[i];
		}
		merge_sort(1, n);
		
		ll ans=num;
		for (int i=1; i<=n; i++) {
			num-=b[i];
			num+=(n-1-b[i]);
			ans=min(ans, num);
		}
		cout<<ans<<"\n";
	}

	return 0;
}

