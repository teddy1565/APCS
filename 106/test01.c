#include<stdio.h>
//test traverse speed
//n*(n-1)
int main(){
    for(int i=1;i<100000;i++){ //n
        //printf("%d\n",i);
        for(int j=0;j<i;j++){ //n-1
            //printf("%d\t",j);
        }
        //printf("\n");
    }
    return 0;
}