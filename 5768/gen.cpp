//5768
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1e2+10;
int a[MAXN][MAXN];

int main(int argc, char *argv[]) {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif	
    int seed = time(NULL);
    if (argc>1) {
        //ÓÐ²ÎÊý
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("09.in", "w", stdout);
	
	ll maxx=1e7;
	ll minx=1e7;
	ll m = rand()%(maxx-minx+1)+minx;
	maxx=1e4;
	minx=1e4;
	ll n = rand()%(maxx-minx+1)+minx;
	cout<<m<<" "<<n<<"\n";

    return 0;
}
