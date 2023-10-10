//http://47.110.135.197/problem.php?id=4671
//归并排序模板 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
int a[MAXN];
int tmp[MAXN];
int n;
 ans;

void quick_sort(int l, int r) {
	//出口条件
	if (l>=r) {
		return;
	}
	int i=l-1, j=r+1, num=a[(l+r)/2];
	while (i<j) {
		do {
			i++;
		} while (a[i]<num);
		do {
			j--;
		} while (a[j]>num);
		if (i<j) {
			swap(a[i], a[j]);
		}
	}
	
	quick_sort(l, j);
	quick_sort(j+1, r);
}

//归并排序 
void merge_sort(int l, int r) {
	//出口条件 
	if (l>=r) {
		return;
	}
	
	//分 
	int mid=(l+r)/2;
	merge_sort(l, mid);//对左区间排序
	merge_sort(mid+1, r) ;//对右区间排序 
	
	//治 
	int i=l;//前半部分
	int j=mid+1;//后半部分
	int k=1;
	while (i<=mid && j<=r)  {
		if (a[i]<=a[j]) {
			tmp[k++]=a[i++];
		} else {
			tmp[k++]=a[j++];
			ans +=(mid-i+1);
		}
	}
	//前半部分还有数据
	while (i<=mid) {
		tmp[k++]=a[i++];
	}
	//后半部分还有数据
	while (j<=r) {
		tmp[k++]=a[j++];
	}
	
	//拷贝回来
	for (i=l, j=1; i<=r; i++, j++) {
		a[i]=tmp[j];
	}
}

int main() {
	//freopen("9.in", "r", stdin);
	//freopen("9.out", "w", stdout);
	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
	}
	merge_sort(1, n);
	
	printf("%d\n", ans);

	return 0;
}

