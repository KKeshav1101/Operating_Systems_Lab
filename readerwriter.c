//solution to reader-writer problem
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<sched.h>

sem_t rLock,wLock;
int SharedData;
int rc;

void *reader(void *arg){
	while(1){
		sleep(1);
		int id=*(int*)arg;
		sem_wait(&rLock);
		rc++;
		if(rc==1)
			sem_wait(&wLock);
		sem_post(&rLock);
		printf("Reader id:%d\t Data: %d\n",id,SharedData);
		printf("No of readers rn:%d\n",rc);
		sem_wait(&rLock);
		rc--;
		if(rc==0)
			sem_post(&wLock);
		sem_post(&rLock);
	}
}

int getNext(){
	static int n=100;
	return n++;
}

void* writer(void* args){
	while(1){
		sem_wait(&wLock);
		printf("Writer is writing...No of readers rn: %d\n",rc);
		SharedData=getNext();
		sem_post(&wLock);
		sleep(1);
	}
}

int main(){
	pthread_t readers[5],writers;
	sem_init(&rLock,0,1);
	sem_init(&wLock,0,1);
	int k;
	for(int i=0;i<5;i++){
		k=i+1;
		pthread_create(&readers[i],0,reader,(void*)&k);
	}
	pthread_create(&writers,0,writer,0);
	for(int i=0;i<5;i++){
		pthread_join(readers[i],0);
	}
	pthread_join(writers,0);
	sem_destroy(&rLock);
	sem_destroy(&wLock);
}

