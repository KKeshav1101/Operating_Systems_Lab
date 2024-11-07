//sender.c
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
	key_t key;
	msgbuffer buffer;
	key=333;
	if ((mqID=msgget(key,0666|IPC_CREAT))==-1){
		perror("msgget");
		exit(1);
	}
	printf("\nMessage Queue Created...");
	while(1){
		printf("\nENter msg :");
		gets(buffer.mtext);
		buffer.mtype=1;
		if(msgsnd(mqID,&buffer,sizeof(buffer.mtext),0)==-1){
			perror("msgsend");
		}
		if (strcmp(buffer.mtext,"bye")==0){
			break;
		}
	}
}
