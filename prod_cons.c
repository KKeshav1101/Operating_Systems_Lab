#include<stdio.h>

int empty=5,full=0,s=1;

void wait(int* s){
	while(*s<=0);
	(*s)--;
}
void signal(int *s){
	(*s)++;
}
void produce(int buffer[]){
	if(empty<=0){
		printf("buffer is full\n");
		return;
	}
	wait(&empty);
	wait(&s);
	printf("ENTER ITEM TO PRODUCE:");
	scanf("%d",&buffer[full]);
	signal(&full);
	signal(&s);
}
void consume(int buffer[]){
	if(full<=0){
		printf("Buffer is empty\n");
		return;
	}
	wait(&full);
	wait(&s);
	printf("%d is consumed\n",buffer[full]);
	signal(&empty);
	signal(&s);
}
int main(){
	int a[5],ch;
	do{
		printf("1.Produce\n2.Consume\nEnter your choice");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				produce(a);
				break;
			case 2:
				consume(a);
				break;
		}
	}while(ch==1 || ch==2);
	return 0;
}
