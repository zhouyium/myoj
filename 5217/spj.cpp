#include <bits/stdc++.h>
using namespace std;
using LL=long long;

const int N=1100;
LL in[N];
LL ans[N];
LL std_o[N];
bool ok;

int main(int argc, char *argv[])
{
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
	
	LL n;
	fscanf(f_in, "%lld", &n);
	cout<<n<<"\n";
	
	LL wa=0;
	for (LL i=1; i<n; i++) {
		LL m=0, stdm=0;
		wa=0; 
		while (fscanf(f_user, "%lld", &ans[m])) {
			cout<<ans[m]<<" ";
			m++;
		}
		cout<<"\n";
		while (fscanf(f_out, "%lld", &std_o[stdm])) {
			cout<<std_o[stdm]<<" ";
			stdm++;
		}
		cout<<"\n";
		cout<<"\n";
		
		if (m!=stdm){
			wa=1;
			break;
		}
		
		for (LL i=1;i<=m;i++) {
			if (ans[i]<=ans[i-1]) {wa=2;break;}
		} 
		if (wa) break;
		if (ans[1]!=1||ans[m]!=n){wa=5;break;}
		for (LL k=2;k<=m;k++){
			ok=false;
			for (LL i=1;i<=k-1&&!ok;i++)
				for (LL j=1;j<=k-1&&!ok;j++)
					if (ans[k]==ans[i]+ans[j]) ok=true;
			if (!ok){wa=3;break;}
		}
		if (wa) {
			break;
		}	
	}

	return wa;
#if 0
	if (wa==1) quitf(_wa,"Your sequence is longer or shorter than the standard one! QAQ");
	else if (wa==2) quitf(_wa,"Your sequence is not a monotone increasing sequence! QAQ");
	else if (wa==3) quitf(_wa,"Your sequence does not satisfy the requirement: for EACH k, ak=ai+aj! QAQ");
	else if (wa==5) quitf(_wa,"Your sequence does not satisfy the requirement: a0=1 ,am=n! QAQ");
	else if (wa==4) quitf(_wa,"Your output is more than the standard output! QAQ");
	else quitf(_ok,"Your output is acceptable! ^ ^");
#endif
}
