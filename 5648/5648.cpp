#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	freopen("09.in", "r", stdin);
	freopen("09.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		
		bool flag=false;
		for (int x=0; x<=n/3 && false==flag; x++) {
			for (int y=0; y<=n/5 && false==flag; y++) {
				int z=(n-3*x-5*y)/7; 
				if (3*x+5*y+7*z==n) {
					printf("%d %d %d\n", x, y, z);
					flag=true; 
				}
			}
		}
		if (false==flag) {
			printf("-1\n");
		}
	}

	return 0;
}

