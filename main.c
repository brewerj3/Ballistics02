#include <stdio.h>
#include <math.h>

#include "newtonCalculation.h"

int main() {
    while(1) {
        if(currentHeight < 0) { // if current height is less than zero the projectile has hit the ground
            printf("Height is less than 0 \n");
            break;
        }
        updatePosition();
    }
    printf("Range: %f Time: %i\n",currentHorizontalDistance, currentTime/1000);
    return 0;
}
