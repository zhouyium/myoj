#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const double PI=acos(-1.0);
int main(int argc, char* argv[]) {
	//��������
    FILE * f_in=fopen(argv[1],"r"); 
    //�������
    FILE * f_out=fopen(argv[2],"r");
    //�û����
    FILE * f_user=fopen(argv[3],"r");
    int ret=1;//AC=0, WA=1
    
	/**************�Լ�д�����߼�**************/
	//�������ж�ȡ��������
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
	//����� 
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
