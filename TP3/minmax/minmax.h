#include <stdio.h>

void minmax(int *arr, int length, int *min, int *max){
    int m,M;
    m=arr[0];
    M=arr[0];
    for (int i=0;i<length;i++){
        if (m>arr[i]){
            m=arr[i];
        }
        if (M<arr[i]) {
            M=arr[i];
        
        }

    }
    *min = m;
    *max = M;
    ;
}