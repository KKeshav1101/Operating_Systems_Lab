#include<stdio.h>
int main(){
  int ms,ps,nop,np,rempages,i,j,x,y,pa,offset;
  int s[10],fno[10][20];
  printf("Enter the memory size --");
  scanf("%d",&ms);
  printf("Enter the page size --");
  scanf("%d",&ps);
  nop=ms/ps;
  printf("\n The number of pages available in memory are -- %d",nop);
  printf("\n Enter number of processes --");
  scanf("%d",&np);
  rempages=nop;
  for(i=1;i<=np;i++){
    printf("\nEnter number of pages required for p[%d]--",i);
    scanf("%d",&s[i]);
    if(s[i]>rempages){
      printf("Memory is full");
      break;
    }
    rempages=rempages-s[i];
    printf("\nEnter pagetable for p[%d] --",i);
    for(j=0;j<s[i];j++)
      scanf("%d",&fno[i][j]);
  }
  printf("Enter the logical address to find physical adddress");
  printf("Enter process no and pagenumber and offset --");
  scanf("%d %d %d",&x,&y,&offset);
  if(x>np || y>=s[i] || offset>=ps)
    printf("\nInvalid Process or page number or offset");
  else{
    pa=fno[x][y]*ps+offset;
    printf("\nThe physical address is --%d",pa);
  }
  return 0;
}
