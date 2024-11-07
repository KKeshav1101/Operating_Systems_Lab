//io burst
#include<stdio.h>
#include<math.h>

struct process{
	int at;
	int bt1;
	int io;
	int bt2;
	int at2;
	int ct;
	int tat;
	int wt;
	int done;
}processes[10];

int dispatcher(int time,int n,int flag){
	int minn=INFINITY;
	int ind=-1;
	for(int i=0;i<n;i++){
		if(flag==0){
			if((processes[i].done==0) && (processes[i].at<=time) && processes[i].at<minn)){
			minn=processes[i].at;
			ind==i;
		}
		else{
			if((processes[i].done==0 && processes[i].at2<=time) && processes[i].at2<minn)){
				minn=processes[i].at2;
				ind=i;
			}
		}
	}
	return ind;
}

int n;

int main(){
	printf("Enter no. of processes: ");
scanf("%d", &n);
for(int i=0; i<n; i++){
printf("Process %d\n", i+1);
printf("Enter Arrival time: ");
scanf("%d", &processes[i].at);
printf("Enter Burst time 1: ");
scanf("%d", &processes[i].bt1);
printf("Enter I/O Burst time: ");
scanf("%d", &processes[i].io);
printf("Enter Burst time 2: ");
scanf("%d", &processes[i].bt2);
processes[i].done=0;
	int i=0;
	int curr_time=0;
	int pid;
	while(i<n){
		pid=dispatcher(curr_time,n,0);
		if(pid==-1){
			curr_time++;
		}
		else{
			processes[pid].at2=curr_time+processes[pid].bt1+process[pid].io;
			processes[pid[.done=1;
			curr_time+=processes[pid].bt1;
			i++;
		}
	}
	for(int i=0;i<n;i++){
		processes[i].done=0;
	}
	i=0;
	while(i<n){
		pid=dispatcher(curr_time,n,1);
		if(pid==-1){
			curr_time++;
		}
		else{
			processes[pid].ct=curr_time+processes[pid].bt2;
			processes[pid].tat=processes[pid].ct-processes[pid].at;
			processes[pid].wt=processes[pid].tat-processes[pid].bt1-processes[pid].bt2-processes[pid].io;
			processes[pid].done=1;
			curr_time+=processes[pid].bt2;
			i++;
		}
	}
}

}
