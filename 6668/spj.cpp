//6668: 01����·�� I
//http://47.110.135.197/problem.php?id=6668
#include <bits/stdc++.h>
using namespace std;
using LL=long long;

const int N=1e3+10; 
LL w[N], v[N];
LL idx[N];
LL cnt;

int main(int argc, char *argv[]) {
	//��������
    FILE * f_in=fopen(argv[1],"r"); 
    //�������
    FILE * f_out=fopen(argv[2],"r");
    //�û����
    FILE * f_user=fopen(argv[3],"r");
    int ret=0;//AC=0, WA=1

	//��ȡ�����ļ�
	LL n,W;
	fscanf(f_in, "%lld%lld", &W, &n);
	for (LL i=1; i<=n; i++) {
		fscanf(f_in, "%lld%lld", &w[i], &v[i]);
	}
    
    //��ȡ����ֵ 
    LL ans_std;
    fscanf(f_out, "%lld", &ans_std);
    //cout<<"ans_std="<<ans_std<<"\n";
    
    //��ȡ�û����
    LL ans_usr;
    fscanf(f_user, "%lld", &ans_usr);
    //cout<<"ans_usr="<<ans_usr<<"\n";
    if (ans_usr!=ans_std) {
    	//�𰸴��� 
    	//cout<<"ans_usr not equal ans_std. error\n";
    	return 1;
	}

	//��֤�û���� 
	LL sum_v=0;
	LL sum_w=0;
	LL t;
	while (fscanf(f_user, "%lld", &t)!=EOF) {
		if (t<1||t>n) {
			return 2;
		}
		sum_v+=v[t];
		sum_w+=w[t];
		if (sum_w>W) {
			return 3;
		}
	}
	if (sum_v!=ans_std) {
		return 4;
	}

	return 0;
}
