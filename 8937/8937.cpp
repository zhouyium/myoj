#include <bits/stdc++.h>
using namespace std;
int n;
int s;
int a[12][4100][4100];//a[i][j][k]�����i�֣���j�У���k�е�ֵ
int main() {
    //freopen("10.in", "r", stdin);
    //freopen("00.out", "w", stdout);
    cin>>n;
    cin>>s;
    a[0][1][1]=s;//��ʼ����0��
    for (int i=1;i<=n;i++){//ѭ��n��
        int t=(1<<(i-1));//tΪn-1�ֵķ�Χ��2��i-1�η���
        if(i==n){
        	//cout<<"t="<<t<<"\n";
		}
        for (int j=1;j<=t;j++){//ѭ��t��
            for (int k=1;k<=t;k++){//ѭ��k��
                if (a[i-1][j][k]==0){//�������0
                    a[i][j*2][k*2]=1;//���½�Ϊ1
                }else{//��������1
                    a[i][j*2][k*2-1]=1;//���½�Ϊ1
                    a[i][j*2-1][k*2]=1;//���Ͻ�Ϊ1
                    a[i][j*2-1][k*2-1]=1;//���Ͻ�Ϊ1
                }
            }
        }
    }
    for (int i=1;i<=(1<<n);i++){//ѭ����ӡ��n�ֵĽ��
        for (int j=1;j<=(1<<n);j++){
            cout<<a[n][i][j];
        }
        cout<<"\n";
    }
    return 0;
}
