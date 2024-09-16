#include <stdio.h>
void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
    printf("a,b inside swap = %d,%d\n",a,b);
}
int main() {
    int a=2,b=3;
    swap(a,b);
    printf("a,b inside main = %d,%d\n",a,b);
}