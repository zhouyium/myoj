#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(int argc, char* argv[]) {
	FILE* f_in=fopen(argv[1],"r");//��������
	FILE* f_out=fopen(argv[2],"r");//�������
	FILE* f_user=fopen(argv[3],"r");//�û����
	int ret=0; //AC=0,WA=1

	/*****spj��������*******/
	double x;
	fscanf(f_user,"%lf",&x);
	double y;
	fscanf(f_out,"%lf",&y);
	x=abs(x-y);
	if (1>abs(y)) {
		y=1.0;
	}
	if (x/y>1e-9) {
		ret=1;
	}

	/*****spj-end********/ 
	fclose(f_in);
	fclose(f_out);
	fclose(f_user);

	return ret;
}

