//7319: Pythagorean Pair
//http://47.110.135.197/problem.php?id=7319
#include <bits/stdc++.h>
using namespace std;
using LL=long long;

const int N=1e3+10; 
LL w[N], v[N];
LL idx[N];
LL cnt;

int main(int argc, char *argv[]) {
	//测试输入
    FILE * f_in=fopen(argv[1],"r"); 
    //测试输出
    FILE * f_out=fopen(argv[2],"r");
    //用户输出
    FILE * f_user=fopen(argv[3],"r");
    int ret=0;//AC=0, WA=1

	//读取输入文件
	LL T;
	fscanf(f_in, "%lld", &T);
	cout<<"T="<<T<<"\n";
	for (LL i=1; i<=T; i++) {
		LL n;
		fscanf(f_in, "%lld", &n);
		cout<<"n="<<n<<"\n";
		//读取标准输出
		LL std_out1, std_out2; 
		LL usr_out1, usr_out2;
		fscanf(f_out, "%lld", &std_out1);
		cout<<"std_out1="<<std_out1<<"\n";
		fscanf(f_user, "%lld", &usr_out1);
		cout<<"usr_out1="<<usr_out1<<"\n";
		cout<<"Test case "<<i;
		if (std_out1==-1) {
			if (usr_out1!=-1) {
				fscanf(f_user, "%lld", &usr_out2);
				cout<<" fail, answer is -1\n";
				return 1;
			} else {
				cout<<"ok!\n";
			}
		} else {
			//读取第二个输出 
			fscanf(f_out, "%lld", &std_out2);
			fscanf(f_user, "%lld", &usr_out2);
			cout<<"std_out2="<<std_out2<<"\n";
			cout<<"usr_out2="<<usr_out2<<"\n";
			LL x=usr_out1*usr_out1+usr_out2*usr_out2;
			if (x!=n) {
				cout<<" fail, "<<usr_out1<<"*"<<usr_out1<<"+"<<usr_out2<<"*"<<usr_out2<<"="<<x<<" not eqaul to "<<n<<"\n";
				return 2;
			} else {
				cout<<"ok!\n";
			}
		}
	}
	return 0;
}
