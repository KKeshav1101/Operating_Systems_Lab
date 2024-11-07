//srtf
#include<stdio.h>
#include<math.h>
#include<stdbool.h>

struct process{
	int at;
	int bt;
	int rt;
	int ct;
	int tat;
	int wt;
	int done;
}processes[10];

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
		processes[i].done=0;
	}
	int i=0;
	int curr_time=0;
	int short_ind;
	int count=0;
	int pid;
	while(true){
		short_ind=-1;
		for(int i=0;i<n;i++){
			if(processes[i].done==0){
				if ((processes[i].at<=curr_time) && (processes[i].rt<processes[short_ind].rt || short_ind==-1)){
					short_ind=i;
				}
			}
		}
		curr_time++;
		if(short_ind!=-1){
			processes[short_ind].rt--;
			if(processes[short_ind].rt==0){
				processes[short_ind].done=1;
				processes[short_ind].ct=curr_time;
				processes[short_ind].tat=processes[short_ind].ct-processes[short_ind].at;
				processes[short_ind].wt=processes[short_ind].tat-processes[short_ind].bt;
				count++;
			}
		}
		if(count==n)
			break;
	}
}
