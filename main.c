#include <stdio.h>
#include "newtonCalculation.h"
int main() {
    printf("Hello, World!\n");
    updatePosition();
    while(1) {
        if(currentHeight < 0) { // if current height is less than zero the projectile has hit the ground
            break;
        }
        updatePosition();
    }
    printf("Range: %f\n",currentHorizontalDistance);
    return 0;
}
