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
    
    freopen("0.in", "w", stdout);
    
    //����n,m
    ll maxx = 10;//1000λ
    ll minx = 6;
    ll n = rand()%(maxx-minx+1)+minx;
	printf("%lld\n", n);

	//��������
	maxx=-10;
	minx=-20;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=i; j++) {
			ll t=rand()%(maxx-minx+1)+minx;
			printf("%lld ", t);
		}
		printf("\n");
	}
	
    return 0;
}
