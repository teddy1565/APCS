#include<stdio.h>

int main(){
    int R=0,C=0,M=0;
    while(scanf("%d %d %d",&R,&C,&M)!=EOF){
        int Content[10][10];
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
        int C_type=0,R_type=0,flip=0;
        for(int i=0;i<M;i++){
            if(M_Content[i]==1){
                R_type = R_type+1%2;
            }else{
                C_type = C_type+1%2;
                R_type = R_type+1%2;
                flip = flip+1%4;
            }
        }
        printf("\n");
        if(R_type){
            if(C_type&&flip==2){
                
            }else if((!C_type)&&flip==2){
                
            }else if(C_type&&flip==0){

            }else if((!C_type)&&flip==0){

            }
        }else{
            if(C_type&&flip==2){
                
            }else if((!C_type)&&flip==2){
                
            }else if(C_type&&flip==0){

            }else if((!C_type)&&flip==0){
                
            }
        }
    }
   
    return 0;
}