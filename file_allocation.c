#include<stdio.h>

void sequential();
void indexed();
void linked();
void main()
{
int choice;
printf("\t\tFile Allocation Methods");
printf("\nEnter your choice: ");
do
{

printf("\n1.Sequential");
printf("\n2.Indexed");
printf("\n3.Linked");
printf("\n4.Exit\n\n");

scanf("\n%d",&choice);
switch(choice)
{
case 1: sequential(); break;
case 2: indexed(); break;
case 3: linked(); break;
case 4: break;
}
}
while(choice!=4);
}


void sequential()
{
int f[50],st,i,len,c,k;
for(int i=0;i<50;++i)
f[i]=0;

while(1)
{
printf("\n\nSequential file allocation\n");
printf("Enter the starting block & length of file: ");
scanf("%d%d", &st,&len);
for(int i=st;i<(st+len);i++)
{

if(f[i]==0)
{
f[i] =1;
printf("\n %d-> %d",i,f[i]);
}
else
{
printf("Block already allocated");
break;
}
}

if(i==(st+len))
printf("\n The file is allocated to disk");
printf("\n If you want to enter more files? (y=1/n=0)");
scanf("%d",&c);

if(c!=1)
break;
}
}




void indexed()
{
int f[50],ind[50],i,j,k,n,c,p,count=0,flag;
for(i=0;i<50;i++)
f[50]=0;

printf("\n\nIndexed file allocation \n");

while(1)
{
flag==1;
printf("Enter index block \t");
scanf("%d", &p);
if(f[p] ==0)
{
f[p] =1;
printf("Enter no: of files on index \t");
scanf("%d", &n);
}
else
{
printf("Block already allocated \n");
continue;
}

for(i=0;i<n;i++)
scanf("%d", &ind[i]);
for(i=0;i<n;i++)
{
if(f[ind[i]] ==1)
{
printf("Block already allocated");
flag = 0;
}
}

for(j=0;j<n&&flag==1;j++)
f[ind[j]] =1;

printf("\n Allocated");
printf("\n File indexed");

for(k=0;k<n;k++)
printf("\n %d-> %d: %d",p,ind[k],f[ind[k]]);
printf("Enter 1 to enter more files and 0 to exit");
scanf("%d", &c);

if(c!=1)
break;
}
}


void linked()
{
int f[50],p,i,j,k,a,st,len,n,c,flag;
for(i=0;i<50;i++)
f[i] = 0;
printf("\n\nLinked file allocation\n");
printf("Enter how many blocks that are already allocated: ");
scanf("%d", &p);
if(p!=0)
{
printf("Enter the block no.s that are already allocated: ");
for(i=0;i<p;i++)
{
scanf("%d",&a);
f[a]=1;
}
}
while(1)
{
printf("Enter the start block and length: ");
scanf("%d%d",&st,&len);
k=len;
for(j=st;j<(k+st);j++)
{
if(f[j]==0)
{
f[j] = 1;
printf("\n %d->%d",j,f[j]);
}
else
{
printf("\n%d->file is already allocated",j);
k++;
}
}

printf("\n If you want to enter one more file? (yes=1/n=0)");
scanf("%d",&c);
if(c!=1)
break;
}
}































