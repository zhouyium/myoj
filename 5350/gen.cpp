#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
ll a[MAXN];
ll b[MAXN];
int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //�в���
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("12.in", "w", stdout);
    
    //����n,m
    ll maxx = 2e5;//1000λ
    ll minx = 2e5;
    ll n = rand()%(maxx-minx+1)+minx;
    maxx=545;
    ll m=1;
    printf("%lld %lld\n", n, maxx);
    cout<<"get 1\n";
    do {
		int t=rand()%100+1;
    	cout<<"add "<<m<<" "<<t<<"\n";
    	cout<<"join "<<m<<" "<<m+1<<"\n";
    	for (int i=1; i<=m+1; i++) {
	    	cout<<"get "<<i<<"\n";
		}
    	m++;
	} while (m<maxx);

    return 0;
}
