#include<stdio.h>

int main(){
    int N=0;
    while(scanf("%d",&N)!=EOF){
        int s[10000],e[10000],total=0;
        for(int i=0;i<N;i++){
            scanf("%d %d",&s[i],&e[i]);
        }
        for(int i=0;i<N-1;i++){
            for(int j=0;j<N;j++){
                if(i==j)continue;
                if(e[i]>s[j]&&s[i]<s[j]&&s[i]<e[j]){
                    s[j] = s[i];
                    s[i]=0;e[i]=0;
                }else if(e[i]>s[j]&&s[i]>s[j]&&s[i]<e[j]){
                    s[i]=0;e[i]=0;
                }else if(e[i]==s[j]){
                    e[i] = e[j];
                    s[j]=0;e[j]=0;
                }
            }
            
        }
        for(int i=0;i<N;i++){
            total+=(e[i]-s[i]);
        }
        printf("%d\n",total);
    }
    return 0;
}