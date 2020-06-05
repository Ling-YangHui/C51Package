/**************************************

 * C51Package.h

 * <Copyright 2020-? @YangHui>
 * This is a C51Package, including serial initiation, timer initiation and counter initiation. Delay functions and serial functions are also included.

 * Version 1.1.0

**************************************/ 

#ifndef _C51PACKAGE_H_
    #define _C51PACKAGE_H_
    #include <REG52.H>
    #include <STDIO.H>
    #include <STRING.H>
    #define int8 unsigned char
    #define int16 unsigned int
    #define MAXLEN 64
    sfr T2MOD = 0xC9;

    void SerialSet(int16); //Using Timer 1
    void TimerSet(int16); //Using Timer 2
    void CountSet(); //Using Timer 0
    void BeginTimer();
    void StopTimer();
    void BeginCount();
    void StopCount();
    void SendChar(int8);
    void SendString(int8 *);
    void SendStringLn(int8 *);
    void DelayMs(int16);
    void Delay20us();
    void Delay50us();
    void SerialBegin();
    void SerialStop();
#endif