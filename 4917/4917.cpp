#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
	LL n;
	cin>>n;
	//�����������Ǿͼӱ���
	//����cin��ȡ�����ݣ�����Ҫ����ֵ 
	LL jsh=0;//������
	LL osh=0;//ż���� 
	for(LL i=1; i<=n; i++){
		LL x;
		cin>>x;
		//��ż���ж�
		if(x%2==0){
			osh=osh+x;//�ۼ���� 
		} else{
			jsh=jsh+x;
		}
	}
	
	cout<<jsh<<"\n"<<osh<<"\n";
	return 0;
}
