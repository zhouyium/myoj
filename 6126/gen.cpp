//http://47.110.135.197/problem.php?id=6126
//6126: K倍区间
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=1e5+10;
int a[N];
int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("09.in", "w", stdout);
    
    //生成n,m
    LL maxx = 50000;//1000位
    LL minx = 50000;
    LL n = rand()%(maxx-minx+1)+minx;
	maxx=1000;
	minx=10;
    LL m = rand()%(maxx-minx+1)+minx;
    cout<<n<<" "<<m<<"\n";
    
	maxx=100;
	minx=1;
    for (int i=1; i<=n; i++) {
		LL t = rand()%(maxx-minx+1)+minx;
		cout<<t*m<<" ";
	}
	cout<<"\n";

    return 0;
}
