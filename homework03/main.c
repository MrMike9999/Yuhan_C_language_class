#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "screen.h"
#include <mmsystem.h>


int main()
{
	char screenBuf[20 * 32 + 1];
	int width = 19;
	int height = 32;
	int isGamePlaying = 1;
	char input[10];
	
	while (isGamePlaying == 1 )
	{
		clearBuffer(screenBuf, width, height);
		setMainScreenToScreenBuffer(screenBuf, width, height);
		printf("%s\ninput>", screenBuf);
		scanf("%s", input);
		if (input[0] == '1' )
		{
			while (isGamePlaying)
			{
				system("cls");
				clearBuffer(screenBuf, width, height);
				setGamePlayScreenToScreenBuffer(screenBuf, width, height); //게임 구현해야함
				printf(screenBuf);
			}
		}
		if (input[0] == '2' )
		{
			while (isGamePlaying)
			{
				system("cls");
				clearBuffer(screenBuf, width, height);
				setHowToPlayToScreenBuffer(screenBuf, width, height);
				printf("%s\ninput>", screenBuf);
				scanf("%s", input);
					if (input[0] == '1' )
					{
						system("cls");
						break;
					}
			}
		}
		if (input[0] == '3' )
		{
			isGamePlaying = 0;
			break;
		}
	}

	return 0;
}