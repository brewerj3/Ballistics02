///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  untitled1 - EE 205 - Spr 2022
///
/// @file newtonCalculation.c
/// @version 1.0
///
/// @author Joshua Brewer <brewerj3@hawaii.edu>
/// @date   03_Sep_2022
///////////////////////////////////////////////////////////////////////////////
#include "newtonCalculation.h"
const double angleOfGunInDegrees = 41; //Angle
const double initialVelocity = 823;  //Meters per Second
const double massOfShell = 1315;  //Kilograms
const double forceOfGravity = 9.8; //Meters per Second per second
const double airDensity = 1.225;
const double dragCoefficiant = 0.1;
const double shellDiameter = 0.4064; //Diameter of Shell in meters
const double shellArea = (0.25)*(3.14159265358979323846)*(shellDiameter*shellDiameter);

double currentHorizontalDistance = 0;
double currentHeight = 0;
double currentVelocity = initialVelocity;
double forceOfAirOnShell = 0;
unsigned currentTime = 0;

double nextHorizontalPosition = 0;
double nextVerticalPosition = 0;

void updatePosition(){
    //Find the force of the air on the shell
    forceOfAirOnShell = -(0.5)*dragCoefficiant*airDensity*(currentVelocity*currentVelocity);

}