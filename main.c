#include <stdio.h>
#include <math.h>

#include "newtonCalculation.h"
#include "ArmorPenetration.h"

int main() {
    while(currentTime < 120000000) {
        if(currentHeight < 0) { // if current height is less than zero the projectile has hit the ground
            printf("Height is less than 0 \n");
            break;
        }
        if(currentVelocity < 0 ) {
            printf("Velocity is less than 0 \n");
            break;
        }
        updatePosition();
    }
    printf("Range: %0.2fm Time: %fs Angle: %0.2f degrees\n",(currentHorizontalDistance), (currentTime/passesPerSecond), (currentShellAngle*(180/3.14159265358979323846)));
    printf("Range: %0.2f Yards \n",(currentHorizontalDistance*1.09361));
    printf("Velocity at Impact:             %5.2f m/s\n",currentVelocity);
    printf("Maximum armor penetration:      %5.2f inches\n",findArmorPenetration());
    printf("Maximum deck armor penetration: %5.2f inches\n",findDeckPenetration());
    printf("Maximum belt armor penetration: %5.2f inches \n",findBeltPenetration());
    return 0;
}
