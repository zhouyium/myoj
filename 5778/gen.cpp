//5778
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
    ll maxx = 280;//1000λ
    ll minx = 250;
    ll T = rand()%(maxx-minx+1)+minx;
    printf("%lld\n", T);    
    while (T--) {
	    //����n
	    maxx = 400;//1000λ
	    minx = 100;
	    ll n = rand()%(maxx-minx+1)+minx;
	    printf("%lld\n", n);
	}

    return 0;
}
