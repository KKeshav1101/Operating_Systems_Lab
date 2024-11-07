#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

#define N 5
#define T 2
#define H 1
#define E 0
#define LEFT (n+4)%N
#define RIGHT (n+1)%N

int state[N];
int philo[N]={0,1,2,3,4};
sem_t mutex,S[N];

void test(int n){
	if(state[n]==H && state[LEFT]!=E && state[RIGHT]!=E){
		state[n]=E;
		sleep(2);
		printf("%d is eating\n",n);
		sem_post(&S[n]);
	}
}

void takefork(int n){
	sem_wait(&mutex);
	state[n]=H;
	printf("%d is hungry\n",n);
	test(n);
	sem_post(&mutex);
	sem_wait(&S[n]);
	sleep(1);
}

void putfork(int n){
	sem_wait(&mutex);
	state[n]=T;
	printf("%d is thinking\n",n);
	test(LEFT);
	test(RIGHT);
	sem_post(&mutex);
}

void *phil(void *n){
	while(1){
		int* i=(int*) n;
		sleep(1);
		takefork(*i);
		sleep(0);
		putfork(*i);
	}
}

int main(){
	pthread_t t[N];
	sem_init(&mutex,0,1);
	for(int i=0;i<N;i++){
		sem_init(&S[i],0,0);
	}
	for(int i=0;i<N;i++){
		pthread_create(&t[i],0,phil,&philo[i]);
	}
	for(int i=0;i<N;i++){
		pthread_join(t[i],0);
	}
}
