//http://47.110.135.197/problem.php?id=4671
//�鲢����ģ�� 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
int a[MAXN];
int tmp[MAXN];
int n;
 ans;

void quick_sort(int l, int r) {
	//��������
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

//�鲢���� 
void merge_sort(int l, int r) {
	//�������� 
	if (l>=r) {
		return;
	}
	
	//�� 
	int mid=(l+r)/2;
	merge_sort(l, mid);//������������
	merge_sort(mid+1, r) ;//������������ 
	
	//�� 
	int i=l;//ǰ�벿��
	int j=mid+1;//��벿��
	int k=1;
	while (i<=mid && j<=r)  {
		if (a[i]<=a[j]) {
			tmp[k++]=a[i++];
		} else {
			tmp[k++]=a[j++];
			ans +=(mid-i+1);
		}
	}
	//ǰ�벿�ֻ�������
	while (i<=mid) {
		tmp[k++]=a[i++];
	}
	//��벿�ֻ�������
	while (j<=r) {
		tmp[k++]=a[j++];
	}
	
	//��������
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

