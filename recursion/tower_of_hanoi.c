#include <stdio.h>


int counter = 1;
void hanoi(int n,char source,char dest,char aux){
    if (n == 0){
        return;
    }
    hanoi(n-1,source,aux,dest);
    printf("%d. move from %c to %c\n",counter++,source,dest);
    hanoi(n-1,aux,dest,source);
    
}

int main(){
    hanoi(1,'a','c','b');
}

