#include <bits/stdc++.h>
int main() {
	freopen("09.in", "r", stdin);
	//freopen("01.out", "w", stdout);
    int l,m,i,j;
    int tree[10001] = {};
    int start, end;
    int cnt = 0;

    scanf("%d %d", &l, &m);
    for (i = 0; i < m; ++i) {
        scanf("%d %d", &start, &end);
        for (j = start; j <= end; ++j) {
            if (0 == tree[j]) {
                tree[j] = 1;
            }
        }
    }

    for (i = 0; i <= l; ++i) {
        if (0 == tree[i]) {
            cnt++;
        }
    }

    printf("%d\n", cnt);
    return 0;
}
