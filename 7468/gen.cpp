//http://47.110.135.197/problem.php?id=7468
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1e5+10;
int a[MAXN];
int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("04.in", "w", stdout);
    
    LL maxx = 1e4;
    LL minx = 1e4;
    LL n = rand()%(maxx-minx+1)+minx;
	//cout<<n<<"\n";
	
	//A胜利
	for (LL i=1; i<=n-12; i+=4) {
		cout<<"A1B1";
	}
	//cout<<"A2A2A2A2A2A1\n";
	cout<<"B2B2B2B2B2B1\n";
	
    return 0;
}
