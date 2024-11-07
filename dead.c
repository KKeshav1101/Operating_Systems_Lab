//deadlock detection
#include<stdio.h>

int main(){
	int n,m,i,j,k;
	n=5;
	m=3;
	int alloc[5][3]={
		{0,1,0},
		{2,0,0},
		{3,0,2},
		{2,1,1},
		{0,0,2}
	};
	int max[5][3]={
		{7,5,3},
		{3,2,2},
		{9,0,2},
		{2,2,2},
		{4,3,3}
	};
	int avl[3]={3,3,2};
	int f[n],ans[n],ind=0;
	int need[n][m];
	for(i=0;i<n;i++){
		f[i]=0;
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			if(f[i]==0){
				int flag=0;
				for(j=0;j<m;j++){
					if(need[i][j]>avl[j]){
						flag=1;
						break;
					}
				}
				if(flag==0){
					ans[ind++]=i;
					f[i]=1;
					for(j=0;j<m;j++){
						avl[j]+=alloc[i][j];
					}
				}
			}
		}
	}
	int flag=0;
	for(i=0;i<n;i++){
		if(f[i]==0){
			flag=1;
			printf("Deadlock detected");
			break;
		}
	}
	if(flag==0){
		printf("No deadlocks detected");
	}
	return 0;
}
