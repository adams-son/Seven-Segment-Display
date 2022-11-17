/*! \mainpage Seven Segment Display
 *
 * 
 * - \subpage lib7SD.cpp "AAA"
 *
 *
 */ 
/**
 * @file lib7SD.cpp
 * testing 1 2 1 2 
 */

#include "7SD.h"

#ifdef PLATFORMIO
#include <Arduino.h>
#endif

Display::Display(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, int pin7, int pin8)
{
    e = pin1; 
    d = pin2; 
    c = pin3; 
    DP = pin4;
    b = pin5; 
    a = pin6;
    f = pin7; 
    g = pin8; 
}

void Display::displayInit(){
    pinMode(g, OUTPUT);
    pinMode(f, OUTPUT);
    pinMode(a, OUTPUT);
    pinMode(b, OUTPUT);
    pinMode(DP, OUTPUT);
    pinMode(c, OUTPUT);
    pinMode(d, OUTPUT);
    pinMode(e, OUTPUT); 
}

Display::~Display()
{
}

void Display::countDecrement(){
    current--;
    if(current <= 0) current = 9;
    displayNumber(current);
}

void Display::countIncrement(){
    current++;
    if(current >= 9) current = 0;
    displayNumber(current);
}

int Display::displayNumber(int number ){
    
    if (number > 9 || number < 0){ return 1; }
    current = number;

    switch (number)
    {
    case 0:
        displayZero();
        break;
    case 1:
        displayOne();
        break;
    case 2:
        displayTwo();
        break;
    case 3:
        displayThree();
        break;
    case 4:
        displayFour();
        break;
    case 5:
        displayFive();
        break;
    case 6:
        displaySix();
        break;
    case 7:
        displaySeven();
        break;
    case 8:
        displayEight();
        break;
    default:
        displayNine();
        break;
    }

    return 0;
}

void Display::displayOff(){
    digitalWrite(a,LOW);
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
}

int Display::displayDot(int state){
    if (state > 1 || state < 0){ return 1; }

    if(state == 1){
        digitalWrite(DP,HIGH);
    }else{
        digitalWrite(DP,LOW);
    }

    return 0;
}

void Display::displayZero(){
    displayOff();
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
}

void Display::displayOne(){
    displayOff();
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    
}
void Display::displayTwo(){
    displayOff();
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(d,HIGH);
}
void Display::displayThree(){
    displayOff();
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
}
void Display::displayFour(){
    displayOff();
    digitalWrite(f,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(c,HIGH);
}
void Display::displayFive(){
    displayOff();
    digitalWrite(a,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
}
void Display::displaySix(){
    displayOff();
    digitalWrite(a,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
}
void Display::displaySeven(){
    displayOff();
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
}
void Display::displayEight(){
    displayOff();
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
}
void Display::displayNine(){
    displayOff();
    digitalWrite(a,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(c,HIGH);
}