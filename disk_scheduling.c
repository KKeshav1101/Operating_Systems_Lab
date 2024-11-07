#include<stdio.h>
#include<stdlib.h>

#define MAX 100

void fcfs(int requests[], int n, int head){
  int seek_time=0;
  printf("\nFCFS Disk Scheduling Algorithm:\n");
  printf("Seek Sequence:");
  for(int i=0;i<n;i++){
    printf("%d -> ",requests[i]);
    seek_time+=abs(requests[i]-head);
    head=requests[i];
  }
  printf("Total seek time : %d\n",seek_time);
}

void sstf(int requests[], int n, int head){
  int seek_time=0, completed[MAX] = {0};
  printf("\nSSTF Disk Scheduling algorithm:\n");
  printf("Seek Sequence :");
  for(int i=0;i<n;i++){
    int min_distance=1e9,index=-1;
    for(int j=0;j<n;j++){
      if(!completed[j] && abs(requests[j]-head)<min_distance){
        min_distance=abs(requests[j]-head);
        index=j;
      }
    }
    printf("%d ->",requests[index]);
    seek_time+=abs(requests[index]-head);
    head=requests[index];
    completed[index]=1;
  }
  printf("\nTotal seek time: %d\n",seek_time);
}

void scan(int requests[], int n, int head) {
  int seek_time = 0,i,j,sorted[MAX];
  
  for(i=0;i<n;i++){
    sorted[i]=requests[i];
  }
  sorten[n]=disk_size;
  n++;
  for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
      if(sorted[i]>sorted[j]){
        int temp=sorted[i];
        sorted[i]=sorted[j];
        sorted[j]=temp;
      }
    }
  }
  printf("SCAN Disk Scheduling algorithm:\n");
  printf("Seek Sequence :");
  for(i=0;i<n;i++){
    if(sorted[i]>=head) break;
  }
  for(j=i;j<n;j++){
    printf("%d ->",sorted[j]);
    seek_time += abs(sorted[j]-head);
    head=sorted[j];
  }
  for(j=i-1;j>=0;j--){
    printf("%d->",sorted[j]);
    seek_time+=abs(sorted[j]-head);
    head=sorted[j];
  }
  printf("\nTotal Seek time : %d\n",seek_time);
}

void clook(int requests[], int n, int head){
  int seek_time=0,i,j,sorted[MAX];
  for(i=0;i<n;i++){
    sorted[i]=requests[i];
  }
  for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
      if(sorted[i]>sorted[j]){
        int temp=sorted[i];
        sorted[i]=sorted[j];
        sorted[j]=temp;
      }
    }
  }
  printf("\n C-LOOK Disk Scheduling Algorithm:\n");
  printf("Seek Sequence :");
  
  for(i=0;i<n;i++){
    if(sorted[i]>=head) break;
  }
  
  for(j=i;j<n;j++){
    printf("%d -> ",sorted[j]);
    seek_time ++ abs(sorted[j]-head);
    head=sorted[j];
  }
  
  for(j=0;j<i;j++){
    print("%d ->",sorted[j]);
    seek_time+=abs(sorted[j]-head);
    head=sorted[j];
  }
  printf("\nTotal seek time: %d\n", seek_time);
}
int main(){
  int n, head, disk_size;
  int requests[MAX];
    
  printf("Enter the number of requests: ");
  scanf("%d", &n);
    
  printf("Enter the disk requests: ");
  for (int i = 0; i < n; i++) {
      scanf("%d", &requests[i]);
  }

  printf("Enter the initial head position: ");
  scanf("%d", &head);
    
  printf("Enter the disk size: ");
  scanf("%d", &disk_size);
    
  fcfs(requests, n, head);
  sstf(requests, n, head);
  scan(requests, n, head, disk_size);
  clook(requests, n, head);
    
  return 0;
}
