#include<stdio.h>
int main()
{
	int proc=5;
	float bt[proc],wt[proc],at[proc],tat[proc],ct[proc];
	//int bt[5]={2,3,5,4,6};
	printf("Enter number of processors: ");
	scanf("%d",&proc);
	int i,j;
	printf("Enter Burst Time\n");
	wt[0]=0;
	float w=0;
	for(i=0;i<proc;i++)
	{
		printf("P[%d]  ",i+1);
		scanf("%f",&bt[i]);
	}
	for(i=0;i<proc;i++)
	{
		wt[i+1]=wt[i]+bt[i];
		w=w+wt[i];
	}
	printf("Waiting Time\n");
	for(i=0;i<proc;i++)
	{
		printf("w[%d]  %f\n",i+1,wt[i]);
	}
	ct[0]=bt[0]-1;
	for(i=0;i<proc;i++)
	{
//		printf("%d, %d, %d\n",ct[i+1], ct[i] , bt[i+1]);
		ct[i+1]=ct[i]+bt[i+1];
	}
	printf("Completion Time\n");
	for(i=0;i<proc;i++)
	{
		printf("c[%d]  %f\n",i+1,ct[i]);
	}
	printf("Arrival Time\n");
	for(i=0;i<proc;i++)
	{
		at[i]=wt[i];
		printf("a[%d]  %f\n",i+1,at[i]);
	}
	float a=0;
	for(i=0;i<proc;i++)
	{
		tat[i]=ct[i]-at[i];
		a=a+tat[i];
	}
	printf("Average Waititng Time= %f\n",w/proc);
	printf("Average Turn Around Time= %f\n",a/proc);
}
