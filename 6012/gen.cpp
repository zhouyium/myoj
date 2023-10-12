//http://47.110.135.197/problem.php?id=6012
//6012: 扩展欧几里得算法
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
    LL n = rand()%(maxx-minx+1)+minx;
    cout<<n<<"\n";
    
    for (int i=1; i<=n; i++) {
		maxx=1e9;
		minx=9e8;
		LL u = rand()%(maxx-minx+1)+minx;
		maxx=1e5;
		minx=1e3;
		LL v = rand()%(maxx-minx+1)+minx;
		cout<<u<<" "<<v<<"\n";
	}

    return 0;
}
