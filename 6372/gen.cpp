//6372

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
int a[MAXN];
int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("09.in", "w", stdout);
    
    //生成n,m
    ll maxx = 5e5;//1000位
    ll minx = 5e5;
    ll n = rand()%(maxx-minx+1)+minx;
    cout<<n<<"\n";
    
	maxx=1e6;
	minx=9.4e5;
    for (int i=1; i<=n; i++) {
		ll t = rand()%(maxx-minx+1)+minx;
		cout<<t<<" ";
	}
	cout<<"\n";

    return 0;
}
