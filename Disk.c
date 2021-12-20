#include<stdio.h>
#include<stdlib.h>
void FCFS (int rq[],int num,int init);
void SCAN(int rq[],int num,int init,int size);
void CSCAN(int rq[],int num,int init,int size);


int main()
{
int i,n,initial,select,RQ[100],size;
printf("\n\t\tDISK SCHEDULING ALGORITHMS\n\t\t");
printf("Enter the number of requests:");
scanf("%d",&n);
printf("\n Enter the requests sequence: \n");
for(i=0;i<n;i++)
scanf("%d",&RQ[i]);

printf("\nEnter initial head position: ");
scanf("%d",&initial);
printf("\nEnter total disk size:");
scanf("%d",&size);

do
{
printf("\n\t----------------------");
printf("\n\tSelect the algorithm:\n");
printf("\n\t\t1.FCFS\n\t\t2.SCAN\n\t\t3.CSCAN\n\t\t4.Exit\n\t\tSelect:");
scanf("%d",&select);
printf("\t---------------------\n");
switch(select)
{
case 1:
	FCFS(RQ,n,initial);
	break;
case 2:
	SCAN(RQ,n,initial,size);
	break;
case 3:
	CSCAN(RQ,n,initial,size);
	break;
case 4:
	break;
}
}
while(select!=4);
}

void FCFS(int rq[],int num,int init)
{
int i,seekTime=0;
printf("\nFCFS\n-------------");
printf("\nSeek sequence:%d",init);
for(i=0;i<num;i++)
{
seekTime+=abs(rq[i]-init);
init = rq[i];
printf("->%d",rq[i]);
}
printf("\n\nTotal seek time:%d\n\n",seekTime);
}


void SCAN(int rq[],int num,int init,int size)
{
int move,i,j,temp,seekTime=0;
printf("\nSCAN\n-------");
for(i=0;i<num;i++)
{
for(j=0;j<num-i-1;j++)
{
if(rq[j]>rq[j+1])
{
int temp;
temp=rq[j];
rq[j]=rq[j+1];
rq[j+1]=temp;
}
}
}
int index;
for(i=0;i<num;i++)
{
if(init<rq[i])
{
index=i;
break;
}
}
printf("\nSeek sequence: %d",init);
for(i=index;i<num;i++)
{
seekTime+=abs(rq[i]-init);
init=rq[i];
printf("->%d",rq[i]);
}

//last movement for max size
seekTime+=abs(size-rq[i-1]-1);
init = size-1;
for(i=index-1;i>=0;i--)
{
seekTime+=abs(rq[i]-init);
init = rq[i];
printf("->%d",rq[i]);
}
printf("\n\nTotal seek time:%d\n\n",seekTime);
}


void CSCAN(int rq[],int num,int init,int size)
{
int move,i,j,temp,seekTime=0;
printf("\nCSCAN\n--------------");
for(i=0;i<num;i++)
{
for(j=0;j<num-i-1;j++)
{
if(rq[j]>rq[j+1])
{
int temp;
temp = rq[j];
rq[j]=rq[j+1];
rq[j+1]=temp;
}
}
}

int index;
for(i=0;i<num;i++)
{
if(init<rq[i])
{
index=i;
break;
}
}
printf("\nSeek sequence:%d",init);
for(i=index;i<num;i++)
{
seekTime+=abs(rq[i]-init);
init=rq[i];
printf("->%d",rq[i]);
}

//last movement for max size
seekTime+=abs(size-rq[i-1]-1);
/*movement max to min disk*/
seekTime+=abs(size-1-0);
init=0;
for(i=0;i<index;i++)
{
seekTime+=abs(rq[i]-init);
init = rq[i];
printf("->%d",rq[i]);
}
printf("\n\nTotal seek time:%d\n\n",seekTime);
}



















