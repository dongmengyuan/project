/*************************************************************************
        > File Name: xueshengxinxiguanli.c
      > Author: dongmengyuan
      > Mail: 1322762504@qq.com
      > Created Time: 2016年06月01日 星期三 09时26分31秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

 
const int N = 50086;

struct student
{
    char num[10];
    char name[10];
    int score;
};

FILE *fp;
fp = fopen("test","wt+");                      /*允许读和写*/

int main()
{
    struct student stu[1000];
    struct student t;                           /*设置中间变量*/
    int i,j,n;
    printf("请输入学生人数:\n");
    scanf("%d",&n);
    for(i = 0;i < n;i++)                            /*录入学生信息*/
    {
        printf("请输入学号:\n");
        scanf("%s",stu[i].num);
        printf("请输入姓名:\n");
        scanf("%s",stu[i].name);
        printf("请输入成绩:\n");
        scanf("%d",&stu[i].score);
    }
    for(i = 0;i < n;i++)                            /*冒泡法将学生成绩升序排列*/
    {
        for(j = 0;j < n-i-1;j++)
        {
            if(stu[j].score > stu[j+1].score)
            {
                 t = stu[j];
                stu[j] = stu[j+1];
                stu[j+1] = t;
            }
        }
    }
    for(i = 0;i < n;i++)                             /*将排好顺序的输出*/
      printf("%8s%8s%8d\n",stu[i].num,stu[i].name,stu[i].score);

fclose(fp);
 
    return 0;
}
