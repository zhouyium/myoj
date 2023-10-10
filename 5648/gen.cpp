//http://47.110.135.197/problem.php?id=5648
//http://47.110.135.197/problem.php?id=5648
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
    
    freopen("09.in", "w", stdout);
    
    //生成n,m
    LL maxx = 1e5;//1000位
    LL minx = 1e5;
    LL n = 1000;
    cout<<n<<"\n";
    
    for (int i=n; i>=1; i--) {
		cout<<n<<"\n";
	}

    return 0;
}
