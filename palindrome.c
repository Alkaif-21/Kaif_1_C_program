#include<stdio.h>
int main(){
    int num,reversed = 0, remainder, original;
    //input the number
    printf("enter the integer: ");
    scanf("%d", &num);
    original = num;// store the original number
    while (num != 0){
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num/=10;
    }
    if (original == reversed){
        printf("%d os a palindrome.\n", original);
        } else {
            printf("%d is not a palindrome.\n", original);
        }
        return 0;
        }
