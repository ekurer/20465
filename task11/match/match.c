#include<stdio.h>
#include <string.h>
#define SIZE 101

char patt[SIZE];
char text[SIZE];
int i,j,s,diff,min,loc;

/* 
 * a function that takes a pattern and a text and returns
 * the location from where the pattern will most match the text
 */

void match(char patt[], char text[]) {
    min=SIZE;
    loc=-1;

    {
/* double for loop that checks the pattern 
 * against every possible substring and compares the characters to each other
 * it will count every difference 
 */
        for (i=0; i<=(strlen(text)-strlen(patt)); i++) {
            diff=0;
            for (j=0,s=i; j<strlen(patt); j++, s++) {
                if(patt[j]!=text[s]){
                    diff++;}
            }

/* when found the minimal difference return the position of where the string starts */

            if(diff<min){
                min=diff;
                loc=i;
            }
        }

        printf("The position with the best match is: %d\n\n",loc);
    }
    return;
}

int main() {
    printf("Please enter a pattern\n");
    scanf("%s",patt);
    printf("Please enter a text\n");
    scanf("%s",text);
    printf("Your pattern is: %s\n",patt);
    printf("Your text is: %s\n",text);
    match(patt,text);
    return 0;
}
