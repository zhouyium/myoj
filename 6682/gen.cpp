//6682: 倒垃圾
//http://47.110.135.197/problem.php?id=6682

#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+10;
bool a[N];

int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("09.in", "w", stdout);
    
    LL T;
    T=1;
    //cout<<T<<"\n";
    while (T--) {
	    //生成n,x,y
	    LL maxx = 1e5;
	    LL minx = 1e5;
	    LL n = rand()%(maxx-minx+1)+minx;
	    maxx=1e5;
	    minx=1e5;
	    LL m = rand()%(maxx-minx+1)+minx; 
	    cout<<n<<" "<<m<<"\n";
	    
	    //打印位置 
	    maxx=5e3;
	    minx=1;
	    LL x;
		for (LL i=1; i<=n+m; i++) {
    		x = rand()%(maxx-minx+1)+minx;
    		cout<<x<<" ";
    		minx=x+1;
    		maxx=maxx+5e3;
		}
		cout<<"\n";
		
		//人还是垃圾桶 
	    maxx=100;
	    minx=1;
	    LL cnt1=1;//人 
	    LL cnt2=1;//垃圾桶 
		for (LL i=1; i<=n+m;) {
			if (i==0) {
				cout<<"0 ";
				i++;
			} else if (i==n+m+1) {
				cout<<"0 ";
				i++;
			} else {
			    LL x = rand()%(maxx-minx+1)+minx;
			    if (x<=50 && cnt1<=n) {
			    	cout<<"0 ";
			    	cnt1++;
			    	i++;
				} else if (cnt2<=m) {
					cout<<"1 ";
					cnt2++;
					i++;
				}
			}		
		}
		cout<<"\n";
	}

    return 0;
}
