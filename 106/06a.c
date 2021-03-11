#include <stdio.h>
#include <stdlib.h>
int main()
{
    
    int n;
    while(scanf("%d",&n)!=EOF){
        int **node = (int**)malloc(sizeof(int*)*(n-1));
        for(int i=0;i<(n-1);i++){
            node[i] = (int*)malloc(sizeof(int)*2);
            scanf("%d%d",&node[i][0],&node[i][1]);
        }
    }
    printf("Hello World");

    return 0;
}
