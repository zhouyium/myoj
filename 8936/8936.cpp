#include <bits/stdc++.h>
using namespace std;
int n;
string s;
char a[105][105];//����������
int main() {
    cin>>n;
    cin>>s;
    int x=1;//��ʼλ�õ���
    int y=1;//��ʼλ�õ���
    for (int i=0;i<s.length();i++){//��s�ִ������ַ����ȥ
        a[x][y]=s[i];//���ַ�
        if ((x+y)%2==0){//����������Ϊż����������������
            x--;
            y++;
            if (y>n){//�����Խ�磬����һб�߿�ʼ
                y-=1;
                x+=2;
            }
            if(x<1){//���XԽ�磬����һб�߿�ʼ
                x++;
            }
        }else{//x+yΪ����������������
            x++;
            y--;
            if (x>n){//���xԽ�磬����һб��
                x-=1;
                y+=2;
            }
            if (y<1){//���yԽ�磬����һб��
                y++;
            }
        }
    }
    for (int i=1;i<=n;i++){//ѭ����ӡ
        for (int j=1;j<=n;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}
