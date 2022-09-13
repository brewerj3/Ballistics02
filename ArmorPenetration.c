///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  untitled1 - EE 205 - Spr 2022
///
/// @file ArmorPenetration.c
/// @version 1.0
///
/// @author Joshua Brewer <brewerj3@hawaii.edu>
/// @date   10_Sep_2022
///////////////////////////////////////////////////////////////////////////////

#include <math.h>
#include <stdlib.h>

#include "ArmorPenetration.h"
#include "newtonCalculation.h"

double penetration = 0;
double deckPenetration = 0;
double beltPenetration = 0;

double findArmorPenetration(void) {
    penetration = ((0.0004689*pow((massOfShell*2.2), 0.55))/(pow((shellDiameter*39.37), 0.65)))*pow((currentVelocity*3.28084), 1.1);
    deckPenetration = cos(currentShellAngle)*penetration;
    beltPenetration = fabs(sin(currentShellAngle)*penetration);
    return penetration;
}

double findDeckPenetration(void) {
    return deckPenetration;
}

double findBeltPenetration(void) {
    return beltPenetration;
}