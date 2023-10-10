//http://47.110.135.197/problem.php?id=7480
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int AC=0;
const int WA=1;

const int N=1e6+10;
LL a[N];
LL b[N];

int main(int argc,char *args[]) {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif

    ifstream f_in;
    f_in.open(args[1]); 
    ifstream f_out;
    f_out.open(args[2]); 
    ifstream f_user;
    f_user.open(args[3]); 
    
    int ret=AC;
/**************�Լ�д�����߼�**************/
	LL n;
	f_in>>n;
	//�ر���2��3 
	if (n==2||n==3) {
		string s;
		getline(f_user, s);
		if (s!="NO SOLUTION") {
			return WA;			
		} else {
			return AC;
		}
	}
	
    for (LL i=1; i<=n; i++) {
        f_user>>a[i];
        b[a[i]]++;
    }
    //���b�Ϸ��� 
    //ÿ�����ֳ���һ�� 
    for (LL i=1; i<=n; i++) {
    	if (b[i]!=1) {
    		return WA+1;
		}
	}
	//����������ֲ�
	for (LL i=1; i<n; i++) {
		LL t=abs(a[i]-a[i+1]);
		if (t==1 || t==0) {
			return WA+2;
		}
	}

/************************************/
	f_in.close();
	f_out.close();
	f_user.close();
	
	return AC;
}

