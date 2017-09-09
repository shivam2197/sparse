#include<stdio.h>
void transpose(int c[][])
{
int i,j,b[100][3],k;
for(i=0;i<c[0][1];i++)
for(j=0;j<c[0][2];j++)
if(c[j][1]==i)
{
b[k][0]=c[j][1];
b[k][1]=c[j][0];
b[k][2]=c[j][2];
k++;
}
printf("Transpose =\n");
for(i=0;i<c[0][2];i++)
printf("%d\n",b[i][2]);
}
void sparse(int **p,int row,int col)
{
int a[100][3];
int i,j,k=1;
a[0][0]=row;
a[0][1]=col;
for(i=0;i<row;i++)
for(j=0;j<col;j++)
{
if(*(*(p+j)+i)!=0)
{
a[k][0]=i;
a[k][1]=j;
a[k][2]=*(*(p+j)+i);
k++;
}
}
a[0][2]=k+1;
transpose(a);
}
void main()
{
int **p,row,col,i,j;
printf("Enter the no. of rows and column\n");
scanf("%d%d",row,col);
p=(int *)malloc(row*sizeof(*p));
for(j=0;j<row;j++)
*(p+j)=(int **)malloc(col*sizeof(**p));
printf("Enter the elements :\n");
for(i=0;i<row;i++)
for(j=0;j<col;j++)
scanf("%d",(*(p+j)+i));
sparse(p,row,col);
}












