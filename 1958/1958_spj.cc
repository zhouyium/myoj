#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E6+10;
LL ans[MAXN];
int main(int argc, char* argv[]) {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//测试输入
    FILE * f_in=fopen(argv[1],"r"); 
    //测试输出
    FILE * f_out=fopen(argv[2],"r");
    //用户输出
    FILE * f_user=fopen(argv[3],"r");
    int ret=0;//AC=0, WA=1
    
	/**************自己写判题逻辑**************/
	char ans1[10];
	char ans2[10];
	//读取输出第一行
	fscanf(f_user, "%s", ans1);
	fscanf(f_out, "%s", ans2);
	if (strcmp(ans1, ans2)!=0) {
		return 1;
	}
	//结果是NO 
	if (strcmp(ans1, "NO")==0) {
		return 0;
	}
	
	//读取输入
	LL a,b;
	fscanf(f_in, "%lld %lld", &a, &b);
	//读取输出第二行
	LL n;
	fscanf(f_user, "%lld", &n);
	LL x1=0;
	fscanf(f_user, "%lld", &x1);
	if (x1!=a) {
		return 1;
	}
	LL x2;
	for (LL i=2; i<=n; i++) {
		fscanf(f_user, "%lld", &x2);
		if ((x1*2)==x2 || (x1*10+1)==x2) {
			x1=x2;
		} else {
			return 1;
		}
	}
	if (x2!=b) {
		return 1;
	}
	
	/************************************/
    fclose(f_in);
    fclose(f_out);
    fclose(f_user);
    return 0;
}

