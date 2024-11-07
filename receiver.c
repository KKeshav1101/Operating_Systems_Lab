#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msgbuffer{
	long mtype;
	char mtext[100];
};

int main(){
	int mqID;
	ket_t key;
	msgbuffer buffer;
	key=333;
	
	if ((mqID=msgget(key,0666))==-1){
		perror("msgget");
		exit(1);
	}
	
	printf("Queue created");
	
	while(1){
		printf("\n\nWaiting for msg from sender\n\n");
		if(msgrcv(mqID,&buffer,sizeof(buffer.mtext),0,0)==-1){
			perror("msgrcv");
			exit(1);
		}
		printf(buffer.text);
		if(strcmp(buffer.mtext,"bye")==0)
			break;
	}
	msgctl(mqID,IPC_RMID,NULL);
	return 0;
}
