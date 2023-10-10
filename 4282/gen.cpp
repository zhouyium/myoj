//4282
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1e3+10;
ll a[MAXN];

int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("09.in", "w", stdout);
    ll maxx = 1000;//1000位
    ll minx = 1000;
    ll n = rand()%(maxx-minx+1)+minx;
    cout<<n<<"\n";
    maxx = 1000;//1000位
    minx = 0;
    for (int i=1; i<=n; i++) {
	    a[i] = i;
	}
    for (int i=1; i<=n; i++) {
		cout<<a[i]<<" ";
	}
	cout<<"\n";

    return 0;
}
