#include <stdio.h>
#include <stdlib.h>


long max(long n,long m){
    if(n>m){
        return n;
    }
    return m;
}

int main(void){
    long n;
    scanf("%li\n",&n);
    long mat[n][n];
    long mat2[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            scanf("%li",&mat[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        mat2[n-1][i]=mat[n-1][i];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            mat2[i][j]=max(mat2[i+1][j],mat2[i+1][j+1])+mat[i][j];
        }
    }
    printf("%li\n",mat2[0][0]);
    return 0;
}