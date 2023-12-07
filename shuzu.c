#include <stdio.h>
int main(){
    int a[5] = { 1, 2, 3, 4, 5};
    int * ptr = a;
    printf("%d\n",*(ptr+5));
}