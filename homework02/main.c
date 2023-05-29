#include <stdio.h>
#include <stdlib.h>
#include "screen.h"

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
				clearBuffer(screenBuf, width, height);
				setGameOverToScreenBuffer(screenBuf, width, height);
				printf("%s\ninput>", screenBuf);
				scanf("%s", input);
					if (input[0] == '1' )
					{
						break;
					}
			}
		}
		if (input[0] == '2' )
		{
			while (isGamePlaying)
			{
				clearBuffer(screenBuf, width, height);
				setHowToPlayToScreenBuffer(screenBuf, width, height);
				printf("%s\ninput>", screenBuf);
				scanf("%s", input);
					if (input[0] == '1' )
					{
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