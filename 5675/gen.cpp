#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
ll a[MAXN];
ll b[MAXN];
int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("9.in", "w", stdout);
    
    //生成n,m
    ll maxx = 3e3+30;//1000位
    ll minx = 3e3;
    ll n = rand()%(maxx-minx+1)+minx;
    ll m = rand()%(maxx-minx+1)+minx;
    printf("%lld\n", n);
    maxx=10000;
    minx=1;
    for (int i=1; i<=n; i++) {
    	for (int j=1; j<=n; j++) {
    		int t=rand()%maxx+1;
    		if (i==j) {
    			t=1;
			} else if (t<=1) {
				t=1;
			} else {
				t=0;
			}
			printf("%lld ", t);
		}
		printf("\n");
	}

    return 0;
}
