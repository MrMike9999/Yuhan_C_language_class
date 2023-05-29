#include <string.h>
#include <stdio.h>
int width = 19;
int height = 32;
int clearBuffer(char* screenBuf, int width, int height)
{
	int i = 0;	/* 가로 index */
	int j = 0;  /* 세로 index */
	
	while (j < height)
	{
		while (i < width + 1) /* 개행문자때문에 + 1*/
		{
			if (i == width)
				screenBuf[i + (j * (width + 1))] = '\n';
			else
			{
				if (i == 0 || i == 1 || i == (width - 1) || i == (width - 2) || j == 0 || j == (height - 1))
					screenBuf[i + (j * (width + 1))] = '#';
				else
					screenBuf[i + (j * (width + 1))] = ' ';
			}
			i = i + 1;
		}
		i = 0;
		j = j + 1;
	}
	screenBuf[height * (width + 1) - 1] = '\0';
}

/* 수업시간에 배운 x,y에 스트링을 쓰는 함수를 짜면 됨. */
int writeStringToBuffer(char* screenBuf , const char* string, int x, int y)
{
    int i = 0;
    while (string[i] != '\0')
    {
        screenBuf[ x + i + ( y * ( width + 1 ))] = string[i];
        i++;
    }
    return 0;
}

/* 타이틀 화면 그리는 버퍼랑 게임오버, 게임설명 등등 이런식으로 만들면 보기 편하겠죠? */
int setMainScreenToScreenBuffer(char* screenBuf, int width, int height)
{
	clearBuffer(screenBuf,19,30);
    writeStringToBuffer(screenBuf,"0JUST0",5,8);
	writeStringToBuffer(screenBuf,"0Rhythm0",5,9);
	writeStringToBuffer(screenBuf,"0Hitting0",5,10);
	writeStringToBuffer(screenBuf,"1.Start",5,11);
	writeStringToBuffer(screenBuf,"2.How to Play",4,12);
	writeStringToBuffer(screenBuf,"3.Exit",5,13);
}
int setGameOverToScreenBuffer(char* screenBuf, int width, int height)
{
    clearBuffer(screenBuf,19,30);
    writeStringToBuffer(screenBuf,"Your Life is 0", 3,5);
    writeStringToBuffer(screenBuf,"Game 0Ver", 4,6);
    writeStringToBuffer(screenBuf,"press 1", 5,7);
    writeStringToBuffer(screenBuf,"To go menu", 6,8);
}
int setHowToPlayToScreenBuffer(char* screenBuf, int width, int height)
{
    clearBuffer(screenBuf,19,30);
    writeStringToBuffer(screenBuf,"press d f j k", 3,5);
	writeStringToBuffer(screenBuf,"when O" ,3,6);
	writeStringToBuffer(screenBuf,"overlap",3,7);
	writeStringToBuffer(screenBuf,"---line" ,3,8);
	writeStringToBuffer(screenBuf,"-------0-------" ,2,14);
	writeStringToBuffer(screenBuf,"Like this" ,2,15);
	writeStringToBuffer(screenBuf,"if you want to" ,3,17);
	writeStringToBuffer(screenBuf,"go back to menu" ,2,18);
	writeStringToBuffer(screenBuf,"press '1' " ,3,19);
}