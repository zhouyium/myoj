//6666: DP4 ��С������¥��
//http://47.110.135.197/problem.php?id=6666
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+10;

int random(int l, int r) {
	if (l>r) {
		swap(l,r);
	}
	return rand()%(r-l+1)+l;
}

int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //�в���
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("09.in", "w", stdout);
    
    LL T=1;
    //cout<<T<<"\n";
    while (T--) {
	    //����n,x,y
	    LL n = random(1e5,1e5);
	    cout<<n<<"\n";
	    
	    for (LL i=1; i<=n; i++) {
	    	LL a = random(5e3,1e4);
			cout<<a<<" ";
		}
		cout<<"\n";
	}

    return 0;
}
