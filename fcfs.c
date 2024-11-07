#include<stdio.h>
#include<math.h>

struct process{
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
	int done;
}processes[10];

int dispatcher(int time,int n){
	int minn=INFINITY;
	int ind=-1;
	for(int i=0;i<n;i++){
		if((processes[i].done==0) && (processes[i].at<=time) && processes[i].at<minn)){
			minn=processes[i].at;
			ind=i;
		}
	}
	return ind;
}

int n;

int main(){
	printf("no");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("process %d\n",i+1);
		printf("arrival time:");
		scanf("%d",&processes[i].at);
		printf("burst time:");
		scanf("%d",&processes[i].bt);
		processes[i].done=0;
	}
	int i=0;
	int curr_time = 0;
	int pid;
	while(i<n){
		pid = dispatcher(curr_time, n);
		processes[pid].ct = curr_time+process[pid].at;
		processes[pid].tat=processes[pid].ct-processes[pid].at;
		processes[pid].wt=processes[pid].tat-processes[pid].bt;
		processes[pid].done=1;
		curr_time += processes[pid].bt;
		i++;
	}
	printf("Process\t AT\t BT\t CT\t TAT\t WT\n");
	for(i=0;i<n;i++){
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i,processes[i].at,processes[i].bt,processes[i].ct,processes[i].tat,processes[i].wt);
	}
	float mean_tat=0;
	float mean_wt=0;
	for(int i=0;i<n;i++){
		mean_tat+=processes[i].tat;
		mean_wt+=processes[i].wt;
	}
	mean_tat/=n;
	mean_wt/=n;
	printf("%f",mean_tat);
	printf("%f",mean_wt);
}
