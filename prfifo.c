//Page replacement fifo
#include<stdio.h>
int n,nf;
int isHit(int x,int p[]){
	int hit=0;
	for(int j=0;j<nf;j++){
		if(p[j]==x){
			hit=1;
			break;
		}
	}
	return hit;
}

void disPages(int p[]){
	for(int i=0;i<nf;i++){
		if(p[i]!=9999){
			printf("%d\t",p[i]);
		}
	}
	printf("\n");
}

int main(){
	printf("Enter number of pages");
	scanf("%d",&n);
	printf("Enter page sequence");
	int in[n];
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	printf("Enter no of frames :");
	scanf("%d",&nf);
	int pfc=0;
	int p[nf];
	for(int i=0;i<nf; i++){
		p[i]=9999;
	}
	for(int i=0;i<n;i++){
		printf("For %d:",in[i]);
		int k=0;
		if(isHit(in[i],p)==0){
			for(k=0;k<nf-1;k++){
				p[k]=p[k+1];
			}
			p[k]=in[i];
			pfc++;
			disPages(p);
		}
		else{
			printf("Hit\n");
		}
	}
	disPages(p);
	printf("Page faults: %d\n",pfc);
	return 0;
}
