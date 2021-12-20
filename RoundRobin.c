#include<stdio.h>
int main()
{
int at[50],bt[50],ct[50],tat[50],wt[50],process[50],temp[50];
int i,j,n,pos,time_quantum,total=0,x,count=0;
printf("Enter the number of processes :");
scanf("%d",&n);
x=n;

for(i=0;i<n;i++)
{
printf("Enter arrival time of process %d: ",i);
scanf("%d", &at[i]);
printf("Enter burst time of process %d:",i);
scanf("%d", &bt[i]);
temp[i] = bt[i];
}

for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(at[i]>at[j])
{
pos = at[i];
at[i] = at[j];
at[j] = pos;

pos = bt[i];
bt[i] = bt[j];
bt[j] = pos;

pos = process[i];
process[i] = process[j];
process[j] = pos;
}
}
}


printf("Enter time quantum \n");
scanf("%d", &time_quantum);
printf("\n Process ID\tArrival time\tBurst time\tCompletion time\tTurnaround time\t Waiting time\n");

while(x!=0)
{
if(temp[i]<=time_quantum && temp[i]>0)
{
total = total+ temp[i];
temp[i] = 0;
count =1;
}
else if(temp[i]>0)
{
temp[i] -= time_quantum;
total += time_quantum;
}

if(temp[i] == 0 && count==1)
{
x--;
ct[i] = total;
printf("\n%d  \t\t%d  \t\t%d  \t\t%d  \t\t%d   \t\t%d \t",i,at[i],bt[i],ct[i],ct[i]-at[i],ct[i]-at[i]-bt[i]);
count = 0;
}

if(i==n-1)
{
i=0;
}
else if(at[i+1]<= total)
{
i++;
}
else
{
i=0;
}
}

return 0;
}










