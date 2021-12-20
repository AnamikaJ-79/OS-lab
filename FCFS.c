#include<stdio.h>
int main()
{
int n,i,j,at[50],bt[50],process[50],wt[50],tat[50],ct[50]={0},sum=0,temp;

printf("\n Enter the number of process: ");
scanf("%d", &n);
for(i=0;i<n;i++)
{
printf("Enter the arrival time of process %d : ", i);
scanf("%d", &at[i]);
printf("Enter burst time of process %d : ", i);
scanf("%d", &bt[i]);
process[i] = i;
printf("\n");
}

for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
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

for(i=0;i<n;i++)
{
sum += bt[i];
ct[i] = sum;
}

for(i=0;i<n;i++)
{
tat[i] = ct[i] - at[i];
wt[i] = tat[i] - bt[i];
}

printf("\n\nprocess \t Arrival time \t Burst time \t Completion time \t TA time \t Waiting time \n\n");

for(i=0;i<n;i++)
{
printf("\t%d\t\t%d\t\t%d\t\t%d\t\t%d \t\t%d", process[i], at[i], bt[i], ct[i], tat[i], wt[i]);
printf("\n");
}

}
















