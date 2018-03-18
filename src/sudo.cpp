#include <iostream>
#include <stdlib.h>
using namespace std;

bool shudu_check(int shudu[][9],int x,int y)
{
    int i,j;
    int temp = shudu[x][y];
    //����ͬһ�����Ƿ����ظ�
    for(i=0;i<9;i++)
    {
        if(i!=x && shudu[i][y] == temp)
            return false;
    }
    //����ͬһ�����Ƿ����ظ�
    for(j=0;j<9;j++)
    {
        if(j!=y && shudu[x][j] == temp)
            return false;
    }
    //����С�Ź��������Ƿ����ظ�
    int x0=(x/3)*3;
    int y0=(y/3)*3; //(x0,y0)��(x,y)����С�Ź��������Ͻǵ�һ�������
    for (i = x0; i<x0+3; i++)
    {
        for(j=y0; j<y0+3; j++)
        {
            if(i!=x && j!=y && shudu[i][j]==temp)
                return false;
        }
    }
    return true;
}
//�������
void shudu_print(int shudu[][9])
{
    int i,j;
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {cout << shudu[i][j] <<" ";}
        cout<<endl;
    }
}
void shudu_generate(int flag)
{
    int shudu[9][9]={0};
    int x, y;
    shudu[0][0]=rand()%9+1;
    
    //�����������ֵ���Ź���
    for(int i=0; i<9; i++)
    {
        int a=rand()%81;
        if(a/9!=0 || a%9!=0) 
            shudu[a/9][a%9]=i+1;
    }
    
    //���ݷ���������
	int t=1;
    while(flag==1)
    {
        x=t/9;
        y=t%9;
        while(flag==1)
        {
            shudu[x][y]++;
            if(shudu[x][y]>9)
            {
                shudu[x][y]=0; //���ݣ��˻ز��Ϸ�����ֵ��������
                t--;break;
            }
            else if(shudu_check(shudu,x,y)==true)//��ֵ����Ϸ��������һ����
            {
                t++;break;
            }
        }
        if(t==81)
        {
            shudu_print(shudu);
            cout<<endl;
            flag=0;
        }
    }
}
int main()
{

	cout<<"������Ҫ���ɵ�����������N:";
	int num;
	cin>>num;
	cout<<num<<"���������̽�������sudoku.txt��..."<<endl;
	freopen("sudoku.txt","w",stdout);
	for(int i=0;i<num;i++)
	{
		shudu_generate(1);
	}
	fclose(stdout);
	system("pause");
    return 0;
}