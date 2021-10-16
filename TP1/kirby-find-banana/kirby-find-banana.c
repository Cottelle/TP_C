#include <stdio.h>
#include <kirby.h>




int main(void){
    createWorld();
    setSpeed(7);
    kb_fruit fruit;
    fruit=getFruit();
    while (fruit!=BANANA){
        move();
        while(!isOnFruit()){
            turnLeft();
            turnLeft();
            move();
            turnLeft();
            move();
        }
    fruit =getFruit();
}
    cleanWorld();
    return 0;
}