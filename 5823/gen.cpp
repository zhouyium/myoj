//5823
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    //freopen("09.in", "w", stdout);
    
    //生成n,m
    ll maxx = 6;//1000位
    ll minx = 5;
    ll n = rand()%(maxx-minx+1)+minx;
    cout<<n<<"\n";
    maxx=n-1;
	minx=0;
    for (ll i=1; i<=n; i++) {
    	ll x=rand()%(maxx-minx+1)+minx;
    	cout<<x<<" ";
	}
	cout<<"\n";

    return 0;
}
