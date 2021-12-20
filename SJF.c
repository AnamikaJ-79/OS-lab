#include<stdio.h>
int main()
{
int at[50],bt[50],tat[50],ct[50],wt[50],process[50];
int i,j,n,temp,current_time=0,start_time,complete=0,count;
printf("Enter number of process \n");
scanf("%d", &n);
for(i=0;i<n;i++)
{
printf("Enter arrival time of process %d : ",i);
scanf("%d", &at[i]);
printf("Enter burst time of process %d : ",i);
scanf("%d", &bt[i]);
process[i]= i;
printf("\n");
}

for(i=0;i<n-1;i++)
{
for(j= i+1;j<n;j++)
{
if(at[i]>at[j])
{
temp = at[i];
at[i] = at[j];
at[j] = temp;

temp = bt[i];
bt[i] = bt[j];
bt[j] = temp;

temp = process[i];
process[i] = process[j];
process[j] = temp;
}
}
}

printf("\n\nProcess \tArrival time \tBurst time \tCompletion time \tTurnaround time \tWaiting time\n");
while(complete<n)
{
count = 0;
for(i = complete;i<n;i++)
{
if(at[i]<=current_time)
{
count++;
}
else
{
break;
}
}



if(count>1)
{
for(i=complete;i<(complete + count-1);i++)
{
for(j=i+1;j<complete+count;j++)
{
if(bt[i]>bt[j])
{
temp = at[i];
at[i] = at[j];
at[j] = temp;

temp = bt[i];
bt[i] = bt[j];
bt[j] = temp;

temp = process[i];
process[i] = process[j];
process[j] = temp;

}
}
}
}

start_time = current_time;
ct[complete] = start_time + bt[complete];
tat[complete] = ct[complete] -at[complete];
wt[complete] = tat[complete] - bt[complete];
current_time = ct[complete];
printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",process[complete],at[complete],bt[complete],ct[complete],tat[complete],wt[complete]);
printf("\n");
complete++;
}

return 0;
}




















