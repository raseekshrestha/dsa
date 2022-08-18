#include <stdio.h>

int sequence(int n){
    if (n==1){
        return 2;
    }
    else{
        printf("n = %d\n",n);
        return 3*sequence(n-1) - (n-1);
    }
    
}

int main(){
    printf("%d",sequence(3));
}