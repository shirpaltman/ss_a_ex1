#include "NumClass.h"
int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    return base * power(base, exponent - 1);
}


int isArmstrongHRec(int x, int length) {
    if (x == 0) {
        return 0;
    }
    int digit = x % 10;
    int mul = power(digit, length);
    return mul + isArmstrongHRec(x / 10, length);
}


int isArmstrong(int x) {
    int length = getLengthRec(x);
    int sum = isArmstrongHRec(x, length);
    return (sum == x);
}


int isPalindromeHRec(int x, int digit) {
    if (x == 0) {
        return 1;
    }

    int left = x / digit;
    int right = x % 10;

    if (left != right) {
        return 0;
    }

    x = (x % digit) / 10;
    digit /= 100;

    return isPalindromeHRec(x, digit);
}


int isPalindrome(int x) {
   
    int length = getLengthRec(x);
    int digit = 1;

    for (int i = 1; i < length; i++) {
        digit *= 10;
    }

    return isPalindromeHRec(x, digit);
}


int getLengthRec(int x){
    if (x==0){
        return 0;
    }
    x=x/10;
    return (1+ getLengthRec(x));
}