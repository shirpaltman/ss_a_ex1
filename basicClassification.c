    #include "NumClass.h"
    int isPrime(int x){
    int i = 2;

    

    if (x < 1) { //if they say 1 isn't prime change <=
        return 0; 
    }
        for (i = 2; i * i <= x; i++) {
            if(x % i == 0 ) {
                return 0;  
            }
            
        }
        return 1;  
}

    

int isStrong(int x){
    int sum=0;
    int copyX=x;
    if(x==0){
        return 0;
    }
    while (copyX != 0) {
        int digit = copyX % 10; 
        int mul=1;
        copyX=copyX/10;
        for(int i=1;i<=digit;i++){
            mul=mul*i;
        }
        sum=sum+mul;
    } 
     
    if (sum==x){
        return 1;
    }
    return 0;
}

