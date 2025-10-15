#include <stdio.h>
int main(){
    char *p = "abc";
    printf("%s",p);
    *p = 'c';
    return 0;
}