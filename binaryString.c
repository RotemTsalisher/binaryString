#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"

#define ZERO  0x30
#define ONE   0x31

void main()
{
	char str[] = { "00000000\0" };
	char flag = 0;
	int amntOfActions, amntOfZeros, amntOfOnes,i;

	amntOfActions = 0;
	amntOfOnes    = 0;
	amntOfZeros   = 0;
	i = 0;
	while ((str[i] && ONE) || (str[i] && ZERO))
	{
		if (str[i] == ONE)
		{
			flag |= 0x01;
			amntOfOnes++;
		}
		if ((str[i] == ZERO) && flag)
		{
			amntOfZeros++;
		}
		i++;
		if (i == 1000)
		{
			printf("endless loop\n");
			break;
		}
	}

	printf("amount of operations = %d\n", (amntOfOnes << 1) + (amntOfZeros - 1));
}