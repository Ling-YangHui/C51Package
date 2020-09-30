# C51Package

Copyright 2020 - ? @YangHui

Last release on 2020.06.05

* Version 1.1.0

*************************************

## Brief Introduction

* This Package includes C51Package.h and C51Package.c, which is designed for CPU with 8051 core.
    
>including STC89/90, STC8.
    
* The functions of SerialInitiation, CounterInitiation, TimerInitiation, SerialSend, Delay are included in this package.

*************************************

## Details

* Timer: Timer2

* Counter: Timer0

* SerialCounter: Timer1

*************************************

## Update Version 1.1.0

* Building a cache which recieve data from UART Serial

* Support functions of SerialRead, SerialAvailable, SerialFlush, SerialCopy
| Name | Functions |
| ---- | ---- |
|int8 SerialRead() | Get one character from the head of cache queue.|
| int8 SerialAvailable() | Check whether the cache queue is empty. |
| void SerialFlush() | Empty the cache queue. |
| void SerialCopy(int8 *) | Copy the cache queue. |

*************************************

## Future Plans

1. INT0/INT1 interrupt initiation
    
    > Version 1.1.1
