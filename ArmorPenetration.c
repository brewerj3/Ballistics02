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

#include "ArmorPenetration.h"
#include "newtonCalculation.h"

double findArmorPenetration() {
    penetration = (0.0004689*pow(massOfShell, 0.88)*pow(currentVelocity, 1.1))/(pow(shellDiameter, 0.65));
}