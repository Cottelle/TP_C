#include <stdio.h>
#include <tps.h>

int main(void){
    tps_createWindow("Damier",800,800);
    int b=0;
    while(tps_isRunning()){
        tps_setColor(0,0,0);
        for(int i=0;i<8;i=i+1){
            
            for(int j=b;j<8;j=j+2){
                tps_fillRect(i*100,j*100,100,100);

            }
            b=(b+1)%2;
            }
        tps_render();
    }
    tps_closeWindow();
}