#include<stdio.h>
#include<stdlib.h>

int last(int **data,int n,int target){
    for(int i=0;i<(n-1);i++){
        if(data[i][0]==target)return last(data,n,data[i][1]);
    }
    return target;
}

int first(int **data,int n,int start,int counter){
    
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int **data = (int**)malloc(sizeof(int*)*(n-1));
        for(int i=0;i<(n-1);i++){
            data[i] = (int*)malloc(sizeof(int)*2);
            scanf("%d%d",&data[i][0],&data[i][1]);
        }
        printf("%d\n",last(data,n,data[0][0]));
        int counter=0;
        printf("%d\n",first(data,n,4,counter));
    }
    return 0;
}