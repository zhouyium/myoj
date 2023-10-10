//7893: 导火线
//http://47.110.135.197/problem.php?id=7893
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e5+10;

int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("09.in", "w", stdout);
    
    LL maxx = 2e3;
    LL minx = 1e3;
    LL T = 1;
	//cout<<n<<"\n";
	
	for (LL i=1; i<=T; i++)	{
		//数字 N
		minx=1e5;
		maxx=1e5;
		LL n = rand()%(maxx-minx+1)+minx;
		cout<<n<<"\n";
		
		//n个数据
		for (LL j=1; j<=n; j++) {
			minx=1;
			maxx=1e3;
			LL a = rand()%(maxx-minx+1)+minx;
			LL b = rand()%(maxx-minx+1)+minx;
			cout<<a<<" "<<b<<"\n";
		}
	}
	
    return 0;
}
