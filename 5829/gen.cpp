//5829

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
int a[MAXN];
int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //�в���
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("09.in", "w", stdout);
    
    //����n,m
    ll maxx = 1000;//1000λ
    ll minx = 1000;
    ll n = rand()%(maxx-minx+1)+minx;
	maxx=200;
	minx=100;
    ll K = rand()%(maxx-minx+1)+minx;
    cout<<n<<" "<<K<<"\n";
    
	maxx=500;
	minx=300;
    for (int i=1; i<=n; i++) {
		ll t = rand()%(maxx-minx+1)+minx;
		cout<<t<<" ";
	}
	cout<<"\n";

    return 0;
}
