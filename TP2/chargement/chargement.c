#include <stdio.h>
int progressBar(int n) {
    printf("[");
    int i=0;
    while(i<n && i<10){
        i++;
        printf("=");
    }
    while(i<10){
        i++;
        printf(" ");

    }
    printf("] \n");
    return 0;
}
int main(void) {
    int n;
    scanf("%i",&n);
    progressBar(n);
  

    return 0;
}