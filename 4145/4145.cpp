#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e2+10;
int nums[MAXN];
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int n;
	scanf("%d", &n);
    int cnt = 0;//次数
    int idx  = -1;//对应的索引	
	for (int i=1; i<=n; i++) {
		int x;
		scanf("%d", &x);
		nums[x+50]++;
        if (cnt < nums[x+50]) {
            cnt = nums[x+50];
            idx = x+50;
        }
	}
	
    if (cnt*2 >= n) {
        printf("%d\n", idx-50);
    } else {
    	printf("no\n");
    }

	return 0;
}

