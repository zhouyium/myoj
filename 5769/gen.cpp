//5769
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //�в���
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("09.in", "w", stdout);
    ll maxx = 1e4;//1000λ
    ll minx = 1e4;
    ll n = rand()%(maxx-minx+1)+minx;
    printf("%lld\n", n);
    maxx = 2147483647;//1000λ
    minx = 1e9;
    while (n--) {
	    ll m = rand()%(maxx-minx+1)+minx;
	    printf("%lld\n", m);
	}

    return 0;
}
