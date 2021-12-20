#include<stdio.h>
#include<stdlib.h>

int memsize,pgsize,offset;
int p[10],s[20],fno[10][20],pgt[20];
int nofpg,n,pno,rempage;
int i,j,a=0;
int choice,flag=0;
void allocate();
void terminate();
void display();
void displaypgt();
//void findaddress();
void main()
{

for(i=0;i<20;i++)
{
pgt[i]=0;
s[i]=0;
}

printf("Enter the memory size: ");
scanf("%d",&memsize);
printf("\nEnter the page size: ");
scanf("%d",&pgsize);

nofpg=memsize/pgsize;
rempage=nofpg;

printf("\nThe no: of frames available in memory=%d",nofpg);
printf("\n               Paging Menu");
printf("\n|-------------------------------------|");
printf("\n| 1.Enter processes	                |");
printf("\n| 2.Terminate process         	|");
printf("\n| 3.Display pages	                |");
printf("\n| 4.Display pagetable for processes	|");
printf("\n| 5.Find address of a process	        |");
printf("\n| 6.Exit	                        |");
printf("\n|-------------------------------------|");

while(1)
{
printf("\nEnter your choice: ");
scanf("%d", &choice);
switch(choice)
{
case 1:allocate();break;
case 2:terminate();break;
case 3:display();break; 
case 4:displaypgt();break;
// case 5:findaddress();break;
case 6:return;
default:break;
}
}
}

void allocate()
{

if(flag==1)
{
printf("\nDo you want to enter previous process again(1.Yes/2.No:");
scanf("%d",&flag);
}
if(flag==1)
{
flag=0;
n=1;
}
else
{
printf("\nEnter number of processes:");
scanf("%d",&n);
}
for(i=0;i<n;i++)
{
printf("\nEnter number of pages required for process ->p:%d:-",a);
scanf("%d",&s[a]);
printf("\n-------------------------");
if(s[a]>rempage)
{
printf("\nMemory full! Returning to menu....\n\n");
display();
flag = 1;
return;
}

printf("\n---------------------------");
printf("\nEnter pagetable for process ->p:%d:-",a);

for(j=0;j<s[a];j++)
{
scanf("%d",&fno[a][j]);
pgt[fno[a][j]]=1;
rempage--;
}
a++;
}
}

void terminate()
{
printf("\nEnter the process id to terminate:");
scanf("%d",&i);
if(s[i])
{
for(j=0;j<s[i];j++)
{
pgt[fno[i][j]]=0;
rempage++;
}
s[i] = 0;
return;
}
printf("\nProcess does not exist");
}

void display()
{
printf("\nPage number\tStatus");
for(i=0;i<nofpg;i++)
printf("\n%d\t\t%d",i,pgt[i]);
}

void displaypgt()
{
printf("\n Pid \t Page table");
for(i=0;i<a;i++)
if(s[i]!=0)
{
printf("\n%d\t",i);
for(j=0;j<s[i];j++)
 printf("->%d", fno[i][j]);
}
}


/* void findaddress()
{
printf("\nEnter process number,page number and offset: ");
scanf("%d%d%d",&i,&j,&offset);
if(i>nofpg||j>=s[i]||offset>=pgsize)
 printf("\n\nInvalid Entry\n");
else
 printf("\n\nTne physical address is %d\n",fno[i][j-1]*pgsize+offset);
} */

	



























