#include <stdio.h>
#include <math.h>
#include <stdlib.h>


char getxy(int d,int x,int y,char *str){
    return str[y*(d+1)+x-1];
}
void changexy(int d, int x,int y,char new,char *str){
    str[y*(d+1)+x-1]=new;
}

char *disk(int d){
    char *str=malloc(d*(d+1));
    if (str==NULL){
        free(str);
        return NULL;
    }
    for(int y=0;y<d;y++){
        changexy(d,d,y,'\n',str);
    }
    for(int y=0;y<d;y++){
        for(int x=0;x<d;x++){
            if(((d/2.0-0.5) - x)*((d/2.0-0.5) - x) + ((d/2.0-0.5) - y)*((d/2.0-0.5) - y) < d*d/4.0){
                changexy(d,x,y,'#',str);
            }
            else{
                changexy(d,x,y,' ',str);
            }
        }
    }
    return str;
}

char *disk_text(char *str){
    return str;
}