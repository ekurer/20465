#include<stdio.h>
#include<string.h>
#define SIZE 101

char str[SIZE];
int i=0, strict=1, asc=0, desc=0;

/* a function that takes a string and returns if it's in order */

void f_sequence(char str[]) {
    {
/* the loop compares every character to the one before it
  and grades the variables accordingly */

        for (i = 0; i < (strlen(str) - 1); i++) {
            if (str[i] == str[i + 1]) {
                strict = 0;
            }
            if (str[i] < str[i + 1]) {
                asc = 1;
            }
            if (str[i] > str[i + 1]) {
                desc = 1;
            }
        }
/* 
 * giving the result based on the rates in the for loop
 * if it's both ascending and descending-not in order
 * if there are any matching characters-not strict
 */
        if ((asc+desc)==2){
            printf("The string is *not in order*");}

        else {
            if (strict == 1) {
                if (asc == 1)
                    printf("The string is *strictly ascending*");
                else if (desc == 1)
                    printf("The string is *strictly descending*");
            } else if (strict == 0) {
                if (desc == 1)
                    printf("The string is *descending*");
                else
                    printf("The string is *ascending*");
            }
        }
    }
    printf("\n");
    return;
}

int main() {
    printf("Please enter a String\n");
    scanf("%s",str);
    printf("Your String is: %s \n", str);
    f_sequence(str);

    return 0;
}
