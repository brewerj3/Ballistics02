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

extern const double angleOfGunInDegrees; //Angles
extern const double initialVelocity;  //Meters per Second
extern const double massOfShell;  //Kilograms
extern const double forceOfGravity; // Force of Gravity

extern double currentHorizontalDistance; //Distance Shell has currently traveled horizontally
extern double currentHeight; //Current Height of the Shell

extern void updatePosition(); //Updates the position of the shell currently

#endif //UNTITLED1_NEWTONCALCULATION_H