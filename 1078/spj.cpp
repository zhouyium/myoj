//1078: §6.2.2 原点平移的反乘幂法
//http://8.129.55.4/problem.php?id=1078
//ax=b%m
#include <bits/stdc++.h>
using namespace std;
using LL=long long;

int main(int argc, char *argv[]) {
	//测试输入
    FILE * f_in=fopen(argv[1],"r"); 
    //测试输出
    FILE * f_out=fopen(argv[2],"r");
    //用户输出
    FILE * f_user=fopen(argv[3],"r");
    int ret=0;//AC=0, WA=1
    
    LL n;
    fscanf(f_in, "%lld", &n);
    for (LL i=1; i<=n; i++) {
    	LL a,b,m;
    	fscanf(f_in, "%lld %lld %lld", &a,&b,&m);
    	char ans_std[20], ans_user[20];
    	fscanf(f_out, "%s", ans_std);
    	fscanf(f_user, "%s", ans_user);
		cout<<"std:"<<ans_std<<" user:"<<ans_user<<"\n";
    	if (0==strcmp(ans_std, ans_user)) {
    		continue;
		}
		if (0==strcmp(ans_std, "impossible")) {
			return 1;
		}
		
		//ax=b%m
		LL x=atoi(ans_user);
		x=(x%m+m)%m;
		if (a*x%m!=b%m) {
			return 1;
		}
	}

	return 0;
}
