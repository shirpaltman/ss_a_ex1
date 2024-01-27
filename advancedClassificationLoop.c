#include "NumClass.h"
int isArmstrong(int x){
    int length = getLength(x);
    int sum=0;
    int copyX=x;
    while (copyX != 0) {
        int digit = copyX % 10; 
        int mul=1;
        copyX=copyX/10;
        for(int i=1;i<=length;i++){
            mul=mul*digit;
        }
        sum=sum+mul;
    }
    if (sum==x){
        return 1;
    }
    return 0;
       
}



int isPalindrome(int x){
    
    int length = getLength(x);
    int digit = 1;
    for (int i = 1; i < length; i++) {
        digit *= 10;
    }

    while (x != 0) {
        int left = x / digit;
        int right = x % 10;

        if (left != right) {
            return 0; 
        }

        x = x % digit ;
        x =x/10;
        digit =digit/100;
    }

    return 1;
}



int getLength(int x){
    int length=0;
    while(x!=0){
        x=x/10;
        length++;
    }
    return length;
}