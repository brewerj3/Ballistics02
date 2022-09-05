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
const double forceOfGravity = 9.8*(massOfShell); //Meters per Second per second
const double airDensity = 1.225;
const double dragCoefficiant = 0.1;
const double shellDiameter = 0.4064; //Diameter of Shell in meters
const double shellArea = (0.25)*(3.14159265358979323846)*(shellDiameter*shellDiameter);
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
double yAxisVelocity = 0;
double yAxisAcceleration = 0;

void updatePosition(){
    //Find the force of the air on the shell in
    forceOfAirOnShell = -(((0.5)*dragCoefficiant*airDensity*(currentVelocity*currentVelocity))/passesPerSecond);

    //Find Acceleration in both axis
    xAxisAcceleration = (  ( cos(currentShellAngle)*forceOfAirOnShell) / (massOfShell) )/passesPerSecond; // x-axis acceleration from drag
    yAxisAcceleration = (( (sin(currentShellAngle)*forceOfAirOnShell ) / (massOfShell)) - forceOfGravity)/passesPerSecond; //acceleration from drag and gravity

    xAxisVelocity = (( cos(currentShellAngle)*currentVelocity) )/passesPerSecond; // calculate velocity in the x-axis
    yAxisVelocity = (( sin(currentShellAngle)*currentVelocity) )/passesPerSecond; // calculate velocity in the y-axis


    //Find the next position after one millisecond
    nextHorizontalPosition = currentHorizontalDistance + (xAxisVelocity);
    nextVerticalPosition = currentHeight + (yAxisVelocity);

    //update the velocity with the effects of drag and gravity
    xAxisVelocity = xAxisVelocity-(xAxisAcceleration/passesPerSecond);
    yAxisVelocity = yAxisVelocity-(yAxisAcceleration/passesPerSecond);


    //Update the current velocity
    currentVelocity = ( sqrt( ((nextHorizontalPosition+xAxisVelocity)-currentHorizontalDistance)*((nextHorizontalPosition+xAxisVelocity)-currentHorizontalDistance) + ((nextVerticalPosition-yAxisVelocity)-currentHeight)*((nextVerticalPosition-yAxisVelocity)-currentHeight) )*passesPerSecond ) ;

    //Update the current shell angle. Do this by combining the direction of the velocity with the direction of the acceleration
    printf("Current shell angle before Calculation: %5.4f \n",currentShellAngle);
    currentShellAngle = atan((xAxisVelocity-currentHorizontalDistance) / (yAxisVelocity-currentHeight) ); ///@TODO this does not work properly yet
    printf("Current shell angle after Calculation:  %5.4f \n",currentShellAngle);


    //Update the current positions
    currentHorizontalDistance = nextHorizontalPosition;
    currentHeight = nextVerticalPosition;

    //Update the current time
    currentTime++;
    printf("Time: [%5.i]  | X: [%5.2f]  | Y:  [%5.2f] | Angle  [%5.2f]  | Drag: [%5.2f]  |X-Axis acceleration: [%5.4f]  | Y-Axis acceleration: [%5.4f]  | Current Velocity [%5.2f]\n",currentTime,currentHorizontalDistance,currentHeight,currentShellAngle,forceOfAirOnShell,xAxisAcceleration,yAxisAcceleration,currentVelocity);
}