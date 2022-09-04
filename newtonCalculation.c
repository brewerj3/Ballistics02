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

#include <stdio.h>
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
double currentYVelocity = 0;
double currentXVelocity = 0;
double a1 = 0;
double totalAcceleration = 0; //total magnitude of acceleration
double angleOfAcceleration = 0; //angle of acceleration of projectile
double xAxis = 0;
double yAxis = 0;

void updatePosition(){
    //Find the force of the air on the shell
    forceOfAirOnShell = -(0.5)*dragCoefficiant*airDensity*(currentVelocity*currentVelocity);

    xAxis = (( cos(currentShellAngle)*forceOfAirOnShell + cos(angleOfGravity)*massOfShell + cos(currentShellAngle)*currentVelocity) ); // adds the effect of drag and gravity in the x axis
    yAxis = (( sin(currentShellAngle)*forceOfAirOnShell + sin(angleOfGravity)*massOfShell + sin(currentShellAngle)*currentVelocity) ); // adds the effect of drag and gravity in the y axis


    //Find the next position after one millisecond
    nextHorizontalPosition = currentHorizontalDistance + (( cos(currentShellAngle) * currentVelocity )/1000);
    nextVerticalPosition = currentHeight + (( sin(currentShellAngle) * currentVelocity)/1000);

    //Update the current shell angle. Do this by combining the direction of the velocity with the direction of the acceleration
    currentYVelocity = sin(currentShellAngle)*currentVelocity-currentVerticalAcceleration;
    currentXVelocity = cos(currentShellAngle)*currentVelocity-currentHorizontalAcceleration;
    totalAcceleration = ((sqrt(currentXVelocity + currentYVelocity))/1000);
    currentShellAngle = atan( (nextVerticalPosition-currentHeight) / (nextHorizontalPosition-currentHorizontalDistance) ); ///@TODO this does not work properly yet

    //Update the current velocity
    currentVelocity = currentVelocity-(sqrt(currentVerticalAcceleration*currentVerticalAcceleration + currentHorizontalAcceleration*currentHorizontalAcceleration))/1000;

    //Update the current positions
    currentHorizontalDistance = nextHorizontalPosition;
    currentHeight = nextVerticalPosition;

    //Update the current time
    currentTime++;
    printf("Time: %5.i X: %5.f Y: %5.f Angle %5.f\n",currentTime,currentHorizontalDistance,currentHeight,currentShellAngle);
}