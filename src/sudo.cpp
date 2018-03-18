#include <iostream>
#include <stdlib.h>
using namespace std;

bool shudu_check(int shudu[][9],int x,int y)
{
    int i,j;
    int temp = shudu[x][y];
    //检验同一列数是否有重复
    for(i=0;i<9;i++)
    {
        if(i!=x && shudu[i][y] == temp)
            return false;
    }
    //检验同一行数是否有重复
    for(j=0;j<9;j++)
    {
        if(j!=y && shudu[x][j] == temp)
            return false;
    }
    //检验小九宫格内数是否有重复
    int x0=(x/3)*3;
    int y0=(y/3)*3; //(x0,y0)是(x,y)所属小九宫格内左上角第一格的坐标
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
//输出数独
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
    
    //生成随机数赋值给九宫格
    for(int i=0; i<9; i++)
    {
        int a=rand()%81;
        if(a/9!=0 || a%9!=0) 
            shudu[a/9][a%9]=i+1;
    }
    
    //回溯法构造数独
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
                shudu[x][y]=0; //回溯，退回不合法的数值重新置零
                t--;break;
            }
            else if(shudu_check(shudu,x,y)==true)//数值检验合法则检验下一个数
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

	cout<<"请输入要生成的数独棋盘数N:";
	int num;
	cin>>num;
	cout<<num<<"个数独棋盘将生成在sudoku.txt中..."<<endl;
	freopen("sudoku.txt","w",stdout);
	for(int i=0;i<num;i++)
	{
		shudu_generate(1);
	}
	fclose(stdout);
	system("pause");
    return 0;
}