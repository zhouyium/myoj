#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double EPS = 1e-6;
int main(int argc, char* argv[]) {
	FILE* f_in=fopen(argv[1],"r");//��������
	FILE* f_out=fopen(argv[2],"r");//�������
	FILE* f_user=fopen(argv[3],"r");//�û����
	int ret=0; //AC=0,WA=1

	/*****spj��������*******/
	double x;
	fscanf(f_out,"%lf",&x);
	double y;
	fscanf(f_user,"%lf",&y);
	if (abs(x-y)>EPS) {
		ret=1;
	}

	/*****spj-end********/ 
	fclose(f_in);
	fclose(f_out);
	fclose(f_user);

	return ret;
}

