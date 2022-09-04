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
#include <math.h>

const double angleOfGunInDegrees = 41; //Angle
const double initialVelocity = 823;  //Meters per Second
const double massOfShell = 1315;  //Kilograms
const double forceOfGravity = 9.8; //Meters per Second per second
const double angleOfGravity = (270*(3.14159265358979323846/180));
const double airDensity = 1.225;
const double dragCoefficiant = 0.1;
const double shellDiameter = 0.4064; //Diameter of Shell in meters
const double shellArea = (0.25)*(3.14159265358979323846)*(shellDiameter*shellDiameter);

double currentHorizontalDistance = 0;
double currentHeight = 0;
double currentVelocity = initialVelocity;
double forceOfAirOnShell = 0;
double currentShellAngle = angleOfGunInDegrees*(3.14159265358979323846/180);
unsigned currentTime = 0;

double nextHorizontalPosition = 0;
double nextVerticalPosition = 0;
double currentHorizontalAcceleration = 0;
double currentVerticalAcceleration = 0;

void updatePosition(){
    //Find the force of the air on the shell
    forceOfAirOnShell = -(0.5)*dragCoefficiant*airDensity*(currentVelocity*currentVelocity);
    //Find the current acceleration of the shell Horizontally
    currentHorizontalAcceleration =( cos(currentShellAngle)*forceOfAirOnShell + cos(angleOfGravity)*massOfShell );
    //Find the current acceleration of the shell Vertically
    currentVerticalAcceleration = ( sin(currentShellAngle)*forceOfAirOnShell + sin(angleOfGravity)*massOfShell );
    //Find the current position after one millisecond and set the position
    currentHorizontalDistance = currentHorizontalDistance + (( cos(currentShellAngle) * currentVelocity )/1000);
    currentHeight = currentHeight + (( sin(currentShellAngle) * currentVelocity)/1000);
    //Find the total acceleration of the Shell in one millisecond

}