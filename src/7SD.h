#ifndef H_7SD
#define H_7SD

// 8_7_X_6_5 
// o######o
// #oooooo#
// #oooooo#
// o######o
// #oooooo#
// #oooooo#
// o######o
// 1_2_X_3_4
class Display
{
private:
    void displayZero(void);
    void displayOne(void);
    void displayTwo(void);
    void displayThree(void);
    void displayFour(void);
    void displayFive(void);
    void displaySix(void);
    void displaySeven(void);
    void displayEight(void);
    void displayNine(void);
    int a,b,c,d,e,f,g,DP;
    int current = 0;
public:
    
    Display(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, int pin7, int pin8);
    ~Display();
    void displayInit(void);
    void displayOff(void);
    int displayDot(int state); 
    int displayNumber(int number);
    void countIncrement(void);
    void countDecrement(void);

};



#endif