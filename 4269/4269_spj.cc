#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const double PI=acos(-1.0);
int main(int argc, char* argv[]) {
	//测试输入
    FILE * f_in=fopen(argv[1],"r"); 
    //测试输出
    FILE * f_out=fopen(argv[2],"r");
    //用户输出
    FILE * f_user=fopen(argv[3],"r");
    int ret=1;//AC=0, WA=1
    
	/**************自己写判题逻辑**************/
	//从输入中读取所有数据
	LL T;
	fscanf(f_in, "%lld", &T);
	map<LL, bool> M;
	while(T--) {
		LL x;
		fscanf(f_in, "%lld", &x);
		M[x]=true;
	}
	
	LL n0, n1;
	fscanf(f_out, "max=%lld", &n0);
	fscanf(f_user, "max=%lld", &n1);
	if (n0!=n1) {
		return 1;
	}
	//检查结果 
	while (n1--) {
		LL now, prev=-2e18;
		fscanf(f_user, "%lld", &now);
		printf("%lld ", now);
		if (M.count(now)==0 || now<=prev) {
			return 1;
		}
		prev=now;
	}
	printf("correct answer\n");
	/************************************/
	
    fclose(f_in);
    fclose(f_out);
    fclose(f_user);
    return 0;
}
