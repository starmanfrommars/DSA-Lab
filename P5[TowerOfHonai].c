#include<stdio.h>

void tower(int n,char src, char aux, char dest){
    if(n==1){
        printf("Move Disk 1 from pole %c to pole %c\n",src,dest);
        return;
    }
    tower(n-1,src,dest,aux);
    printf("Move Disk %d from pole %c to pole %c\n",n,src,dest);
    tower(n-1,aux,src,dest);
}

void main(){
    int n;
    printf("Enter the number of disks : ");
    scanf("%d",&n);
    printf("Sequence of moves : \n");
    tower(n,'A','B','C');
}
