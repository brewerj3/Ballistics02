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

const double angleOfGunInDegrees = 20;                 //Angle
const double initialVelocity = 762;                    //Muzzle Velocity in Meters per Second
const double massOfShell = 1225;                       //Kilograms
const double forceOfGravity = -9.8*(massOfShell);      //Meters per Second per second
const double airDensity = 1.225;
const double dragCoefficiant = 0.1774;
const double shellDiameter = (16*0.0254);                                                   //Diameter of Shell in meters
const double shellArea = (3.14159265358979323846)*((shellDiameter/2)*(shellDiameter/2));    //Cross sectional area of Shell
const double passesPerSecond = 1000;

double currentHorizontalDistance = 0;
double currentHeight = 0;
double currentVelocity = initialVelocity;
double forceOfAirOnShell = 0;
double currentShellAngle = angleOfGunInDegrees*(3.14159265358979323846/180);
unsigned currentTime = 0;

double nextHorizontalPosition = 0;
double nextVerticalPosition = 0;
double xAxisVelocity = 0;
double xAxisAcceleration = 0;
double xAxisForce = 0;
double yAxisVelocity = 0;
double yAxisAcceleration = 0;
double yAxisForce = 0;
double deltaY = 0;
double deltaX = 0;

void updatePosition(){
    //Find the force of the air on the shell in one pass
    forceOfAirOnShell = -( ((0.5)*dragCoefficiant*airDensity*shellArea*((currentVelocity)*(currentVelocity)))/passesPerSecond );

    //Find the force in both axis
    xAxisForce = ( cos(currentShellAngle)*forceOfAirOnShell);                                       //This is in one Pass
    yAxisForce = ( sin(currentShellAngle)*forceOfAirOnShell) + (forceOfGravity/passesPerSecond);    //This is in one Pass

    //Find Acceleration in both axis
    xAxisAcceleration = (xAxisForce/massOfShell);                                                       // x-axis acceleration from drag             in one Pass
    yAxisAcceleration = (yAxisForce/massOfShell);                                                       // y-axis acceleration from drag and gravity in one Pass

    //Find change in velocity
    xAxisVelocity = (( cos(currentShellAngle)*currentVelocity) + xAxisAcceleration );               // calculate velocity in the x-axis
    deltaX = (( cos(currentShellAngle)*currentVelocity)/passesPerSecond + xAxisAcceleration );
    yAxisVelocity = (( sin(currentShellAngle)*currentVelocity) + yAxisAcceleration);                // calculate velocity in the y-axis
    deltaY = (( sin(currentShellAngle)*currentVelocity)/passesPerSecond + yAxisAcceleration);


    //Find the next position after one pass
    nextHorizontalPosition = currentHorizontalDistance + (deltaX);
    nextVerticalPosition = currentHeight + (deltaY);

    //Update the current velocity
    currentVelocity = fabs( sqrt( ( (xAxisVelocity)*(xAxisVelocity) + (yAxisVelocity)*(yAxisVelocity) ) )) ;

    //Update the current shell angle. Do this by combining the direction of the velocity with the direction of the acceleration
    //printf("Current shell angle before Calculation: %5.4f \n",currentShellAngle);
    currentShellAngle = atan((yAxisVelocity) / (xAxisVelocity) );
    //printf("Current shell angle after Calculation:  %5.4f \n",currentShellAngle);


    //Update the current positions
    currentHorizontalDistance = nextHorizontalPosition;
    currentHeight = nextVerticalPosition;

    //Update the current time
    currentTime++;
    //printf("Time: [%5f]  | X: [%5.2f]  | Y:  [%5.2f] | Angle  [%5.2f]  | Drag: [%5.4f]  |X-Axis acceleration: [%5.4f]  | Y-Axis acceleration: [%5.4f]  | Current Velocity [%5.4f]\n",(currentTime/passesPerSecond),currentHorizontalDistance,currentHeight,currentShellAngle,forceOfAirOnShell,xAxisAcceleration,yAxisAcceleration,currentVelocity);
}