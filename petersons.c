//Peterson's solution
#include<stdio.h>
#include<pthread.h>

int flag[2];
int turn;
const int MAX=10;
int ans=0;

void lock_init(){
	flag[0]=flag[1]=0;
	turn=0;
}

void lock(int self){
	flag[self]=1;
	turn=1-self;
	while(flag[1-self] && turn==1-self);
}

void unlock(int self){
	flag[self]=0;
}

void *fn(void *s){
	int *self=(int*)s;
	lock(*self);
	printf("Thread %d has locked\n",*self);
	for(int i=0;i<MAX;i++){
		ans++;
	}
	printf("Out of critical section%d\n",ans);
	unlock(*self);
}

int main(){
	pthread_t p1,p2;
	int t0=0,t1=1;
	lock_init();
	pthread_create(&p1,0,fn,(void*)&t0);
	pthread_create(&p2,0,fn,(void*)&t1);
	pthread_join(p1,0);
	pthread_join(p2,0);
	printf("Final ans:%d\n",ans);
	return 0;
}

