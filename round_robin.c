//rr
#include<stdio.h>
#include<math.h>

struct process{
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
	int arr;
	int rt;
	int done;
}processes[10];

int dispatcher(int time,int n){
	int minn=INFINITY;
	int ind=-1;
	for(int i=0;i<n;i++){
		if((processes[i].done==0) && (processes[i].arr<=time) && (processes[i].arr<=minn) && (processes[i].rt>0)){
			minn=processes[i].arr;
			ind=i;
		}
	}
	return ind
}

int n;

int main(){
	printf("Enter no. of processes:");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Process %d\n",i+1);
		printf("AT:");
		scanf("%d",&processes[i].at);
		printf("BT:");
		scanf("%d",&processes[i].bt);
		processes[i].rt=processes[i].bt;
		processes[i].arr=processes[i].at;
		processes[i].done=0;
	}
	int quant;
	printf("ENter rr time q");
	scanf("%d",&quant);
	int done=0;
	int curr_time=0;
	int pid;
	while(done<n){
		pid=dispatcher(curr_time,n);
		printf("\t\t%d\n",pid);
		if(processes[pid].done!=1){
			if(processes[pid].rt>quant){
				processes[pid].rt-=quant;
				curr_time+=quant;
				process[pid].arr=curr_time;
				printf("\t\tgreater\n");
			}
			else{
				if(processes[pid].rt==quant){
					curr_time+=quant;
					printf("equal");
				}
				else{
					curr_time+=processes[pid].rt;
				}
				processes[pid].rt=0;
				processes[pid].done=1;
				done++;
				processes[pid].ct=curr_time;
				processes[pid].tat=processes[pid].ct-processes[pid].at;
				processes[pid].wt=processes[pid].tat-processes[pid].bt;
			}
		}
	}
	printf("Process\t Arrival Time\t Burst Time\t Completion Time\t TA Time\t Waiting Time\n");
	for(int i=0; i<n;i++){
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, processes[i].at, processes[i].bt, processes[i].ct, processes[i].tat, processes[i].wt);
	}
	float mean_tat = 0;
	float mean_wt = 0;
	for(int i=0; i<n; i++){
		mean_tat+=processes[i].tat;
		mean_wt+=processes[i].wt;
	}
	mean_tat/=n;
	mean_wt/=n;
	printf("Mean TA Time: %f\n", mean_tat);
	printf("Mean Waiting Time: %f\n", mean_wt);
}
