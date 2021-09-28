#include <kirby.h>

int main(void) {
  createWorld();
  setSpeed(100);
  while (isOnFruit() || !(bagIsEmpty())){
  if (isOnFruit() && !(bagIsEmpty())) {
      move();
  }
  else if (isOnFruit())
  {
      getFruit();
      move();
  }
  else if (!(bagIsEmpty()))
  {
      putFruit();
      turnLeft();
      turnLeft();
      while (frontIsClear())
      {
          move();
      }
      turnLeft();
      turnLeft();
  }
  }
  cleanWorld();
  return 0;
}