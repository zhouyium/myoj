#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
	LL a,b,c;
	cin>>a>>b>>c;
	//���ֵ���ڵ�һ���� 
	LL maxx=a;//max x
	//�Ƚϵڶ����� 
	if(maxx<b){
		maxx=b;
	}
	//�Ƚϵ�������
	if(maxx<c){
		maxx=c;
	} 
	cout<<maxx<<"\n";
	return 0;
}

