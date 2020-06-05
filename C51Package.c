/**************************************

 * C51Package.c

 * <Copyright 2020-? @YangHui>
 * This is a C51Package, including serial initiation, timer initiation and counter initiation. Delay functions and serial functions are also included.

 * Version 1.1.0

**************************************/     
#include "C51Package.h"

static SerialCache[MAXLEN];
static int8 Head = 0,Rear = MAXLEN - 1,Count = 0;

void SerialSet(int16 Rate) //Using Timer 1
{
    
    TMOD |= 0x20;
    TH1 = 256 - 57600 / Rate;
    TL1 = TH1;
    PCON |= 0x80;
    SCON = 0x50;
    TR1 = 0;
    ES = 1;
    EA = 1;
}
void TimerSet(int16 Time) //Using Timer 2
{
    EA = 1;
    ET2 = 1;
    RCAP2H = (0xFFFF - Time * 1000) / 256;
    RCAP2L = (0xFFFF - Time * 1000) % 256;
    T2CON = 0;
    T2MOD = 0;
    TR2 = 0;
}
void CountSet() //Using Timer 0
{
    TH0 = 0;
    TL0 = 0;
    TMOD |= 0x05;
    TR0 = 0;
}
void BeginTimer()
{
    TR2 = 1;
}
void StopTimer()
{
    TR2 = 0;
}
void BeginCount()
{
    TR0 = 1;
}
void StopCount()
{
    TR0 = 0;
}
void SendChar(int8 send)
{
    ES = 0;
    SBUF = send;
    while(TI == 0);
    TI = 0;
    ES = 1;
}
void SendString(int8 *str)
{
    while (*str)
        SendChar(*str ++);
    return;
}
void SendStringLn(int8 *str)
{
    SendString(str);
    SendChar('\r');
    SendChar('\n');
}
void DelayMs(int16 Delay) //Problem
{
    int16 i;
    int8 j;
    for (i = Delay;i > 0;i --)
        for (j = 250;j > 0;j --);
}
void Delay20us()
{
    int8 i;
    i = 5;
    i ++;
    while(-- i);
}
void Delay50us()
{
    int8 i;
    i = 19;
    i ++;
    while(-- i);
}
void SerialStop()
{
    TR1 = 0;
}
void SerialBegin()
{
    TR1 = 1;
}
int8 SerialAvailable()
{
    return Count;
}
int8 SerialRead()
{
    int8 c = SerialCache[Head ++];
    Head %= MAXLEN;
    return c;
}
void SerialFlush()
{
    Head = Count = 0;
    Rear = MAXLEN - 1;
}
void SerialCopy(int8 *str)
{
    int8 i,j = 0;
    if (Head <= Rear)
        for (i = Head;i <= Rear;i ++)
            str[j] = SerialCache[i];
    else if (Head > Rear)
    {
        for (i = Head;i <= 64;i ++)
            str[j] = SerialCache[i];
        for (i = 0;i <= Rear;i ++)
            str[j] = SerialCache[i];
    }
    str[j] = '\0';
}
void main()
{
    SerialSet(9600);
    SerialBegin();
    while(1)
    {
        SendStringLn("Hello world");
        DelayMs(1000);
    }
}