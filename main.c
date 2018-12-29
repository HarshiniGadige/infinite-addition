#include <stdio.h>
#include <string.h>
int atoi(char*);

int main() {
    char n1[100], n2[100]; int fd, sd;
    static int total[101];
    printf("Enter two really large numbers\n");
    scanf("%s",n1);
    scanf("%s",n2);
    int i1 = strlen(n1), i2 = strlen(n2), sum = 0, carry = 0, counter = 0;
    while( i1 > 0 || i2 > 0) {
        fd = --i1 >= 0 ? n1[i1]-48 : 0;
        sd = --i2 >= 0 ? n2[i2]-48 : 0;
        sum = fd+sd+carry;
        if(sum > 9) {
            if(sum > 19) {
                carry = 2;
            }
            carry = 1;
        } else {
            carry = 0;
        }
        sum-=carry*10;
        total[counter++] = sum;
    }
    total[counter] = carry;
    int i;
    i = (carry==0) ? counter-1: counter;
    for(; i >= 0; i--) {
        printf("%d",total[i]);
    }
}