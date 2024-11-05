#ifndef TIMER_H
#define TIMER_H

#include <time.h>
#include <arrays.h>
#include <stdio.h>

void timerSort(void (*sort)(InfoArray infoArray), InfoArray InfoArray, char* funcName);

#endif // TIMER_H