//Optimal
#include<stdio.h>
int n, nf;

int isHit(int x, int p[]){
    int hit=0;
    for(int i=0; i<nf; i++){
        if(x==p[i]){
            hit=1;
            break;
        }
    }
    return hit;
}

void disPages(int p[]){
    for(int i=0; i<nf; i++){
        if(p[i]!=9999){
            printf("%d\t", p[i]);
        }
    }
    printf("\n");
}

int main(){
    printf("Enter no of pages: ");
    scanf("%d", &n);
    printf("Enter page sequence: ");
    int in[n];
    for(int i=0; i<n; i++){
        scanf("%d", &in[i]);
    }
    printf("Enter no of frames: ");
    scanf("%d", &nf);
    int pfc = nf;
    int p[nf];
    int y = 0;
    for(int i=0; i<nf; i++){
        p[i]=in[y++];
    }
    for(int i=nf; i<n; i++){
        printf("For %d: ", in[i]);
        if(isHit(in[i], p)==0){
            int farthest=-1;
            int rep=-1;
            int j;
            for(j=0; j<nf; j++){
                int ind=-1;
                for(int k=i+1; k<n; k++){
                    if(p[j]==in[k]){
                        ind=k;
                        break;
                    }
                }
                if(ind==-1){
                    rep=j;
                    break;
                }
                if(farthest<ind){
                    farthest=ind;
                    rep = j;
                }
            }
            p[rep]=in[i];
            pfc++;
            disPages(p);
        }
        else{
            printf("Hit\n");
        }
    }
    disPages(p);
    printf("Page faults: %d\n", pfc);
}
