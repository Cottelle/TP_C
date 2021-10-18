#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>



double norme(vector_2D v){
    double k=sqrt(pow(v.x,2)+pow(v.y,2));
    return k;
}

void norm_vect(vector_2D *v){
    if(v->x!=0 || v->y !=0){
    double n;
    n=norme(*v);
    v->x=v->x/n;
    v->y=v->y/n; }
}

void norm_vect_xy(double *x,double *y){
     if(*x!=0 || *y !=0){
    double n =sqrt(pow(*x,2)+pow(*y,2));
    *x=*x/n;
    *y=*y/n;
    }
}