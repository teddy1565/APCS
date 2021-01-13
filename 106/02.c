#include<stdio.h>

int main(){
    int R=0,C=0,M=0;
    while(scanf("%d %d %d",&R,&C,&M)!=EOF){
        int Content[10][10];
        int operator[10][10];
        int M_Content[10];
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                scanf("%d",&Content[i][j]);
            }
        }
        for(int i=0;i<M;i++){
            scanf("%d",&M_Content[i]);
        }
        //如果 m = 0 則代表旋轉，m = 1 代表翻轉
        //旋轉時 r-1 c-1開始 翻轉時r-1 0開始
        for(int i=0;i<M;i++){
            for(int i=0,k=R-1;i<R;i++,k--){
                for(int j=0;j<C;j++){
                    operator[i][j] = Content[k][j];
                    Content[k][j]=0;
                }
            }
            for(int i=0;i<R;i++){
                for(int j=0;j<C;j++){
                    Content[i][j] = operator[i][j];
                    operator[i][j] = 0;
                }
            }
            if(M_Content[i]==0){
                for(int i=0;i<C;i++){
                    for(int j=0;j<R;j++){
                        operator[i][j] = Content[j][i];
                        Content[j][i] = 0;
                    }
                }
                R = R^C;
                C = R^C;
                R = R^C;
                for(int i=0;i<R;i++){
                    for(int j=0;j<C;j++){
                        Content[i][j] = operator[i][j];
                        operator[i][j] = 0;
                    }
                }
            }
        }
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                printf("%d ",Content[i][j]);
            }
            printf("\n");
        }
        
    }
   
    return 0;
}