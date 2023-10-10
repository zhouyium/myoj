#include <cstdio>
#include <map>

int main() {
	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
    int t;
    scanf("%d", &t);

    std::map<long long, long long> coef;
    int i, j;
    for (i=0; i<t; i++) {
        coef.clear();

        int c;
        scanf("%d", &c);

        for (j=0; j<c; j++) {
            long long n, m;
            scanf("%lld%lld", &n, &m);
            coef[m] += n;
        }

        std::map<long long, long long>::reverse_iterator rit;
        bool flag = false;
        for (rit=coef.rbegin(); rit!=coef.rend(); rit++) {
            if (0 != rit->second) {
                flag = true;
                if (rit != coef.rbegin()) {
                    if (rit->second > 0) {
                        printf("+");
                    }
                }
                if (-1 == rit->second) {
                    if (0==rit->first) {
                        printf("-1");
                    } else {
                        printf("-");
                    }
                } else if (1 != rit->second) {
                    printf("%lld", rit->second);
                }
                if (1 == rit->first) {
                    printf("x");
                } else if (0 != rit->first) {
                    printf("x^%lld", rit->first);
                }
            }
        }

        if (false == flag) {
            printf("0");
        }
        printf("\n");
    }

    return 0;
}
