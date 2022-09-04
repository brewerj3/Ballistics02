///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  untitled1 - EE 205 - Spr 2022
///
/// @file newtonCalculation.h
/// @version 1.0
///
/// @author Joshua Brewer <brewerj3@hawaii.edu>
/// @date   03_Sep_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef UNTITLED1_NEWTONCALCULATION_H
#define UNTITLED1_NEWTONCALCULATION_H

#pragma once
#include <math.h>

const double angleOfGunInDegrees; //Angles
const double initialVelocity;  //Meters per Second
const double massOfShell;  //Kilograms
const double forceOfGravity; // Force of Gravity
const double angleOfGravity;
const double airDensity; //Density of Air
const double dragCoefficiant; // drag coefficient
const double shellDiameter; //Diameter of Shell
const double shellArea; //Area of Shell


double currentHorizontalDistance; //Distance Shell has currently traveled horizontally
double currentHeight; //Current Height of the Shell
double currentVelocity; //Current Shell Velocity
double forceOfAirOnShell; //Current force of air on shell
double currentShellAngle; //Current Angle of shell
unsigned currentTime; //Current time in millisecond

double nextHorizontalPosition;
double nextVerticalPosition;
double currentHorizontalAcceleration;
double currentVerticalAcceleration;

extern void updatePosition(); //Updates the position of the shell currently

#endif //UNTITLED1_NEWTONCALCULATION_H
