#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const double PI=acos(-1.0);
int main(int argc, char* argv[]) {
	char ans[130];
	//��������
    FILE * f_in=fopen(argv[1],"r"); 
    //�������
    FILE * f_out=fopen(argv[2],"r");
    //�û����
    FILE * f_user=fopen(argv[3],"r");
    int ret=0;//AC=0, WA=1
    
	/**************�Լ�д�����߼�**************/
	LL n;
	fscanf(f_in, "%lld", &n);
	//������
	fscanf(f_user, "%s", ans); 
	//�жϸ���ans�ܷ�����n����
	LL len=strlen(ans);
	LL tot=0;
	//printf("%s, len=%lld\n", ans, len);
	for (LL i=0; i<len && len<=120; i++) {
		if (ans[i]=='A') {
			tot++;
		} else if (ans[i]=='B') {
			tot*=2;
		} else {
			ret=1;
			//printf("break\n");
			break;
		}
		//printf("i=%lld tot=%lld\n", i, tot);
	}
	
	//printf("tot=%lld\n", tot);
	if (ret==0 && tot==n) {
		ret=0;
	}
	/************************************/
	
    fclose(f_in);
    fclose(f_out);
    fclose(f_user);
    return ret;
}
