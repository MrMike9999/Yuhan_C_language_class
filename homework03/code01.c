#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <mmsystem.h>
#include <time.h>


int width = 19;
int height = 32;
int clearBuffer(char* screenBuf, int width, int height)
{
	int garo = 0;	/* 가로 index i*/
	int sero = 0;  /* 세로 index j*/
	
	while (sero < height)
	{
		while (garo < width + 1) /* 개행문자때문에 + 1*/
		{
			if (garo == width)
				screenBuf[garo + (sero * (width + 1))] = '\n';
			else
			{
				if (garo == 0 || garo == 1 || garo == (width - 1) || garo == (width - 2) || sero == 0 || sero == (height - 1))
					screenBuf[garo + (sero * (width + 1))] = '#';
				else
					screenBuf[garo + (sero * (width + 1))] = ' ';
			}
			garo = garo + 1;
		}
		garo = 0;
		sero = sero + 1;
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
    writeStringToBuffer(screenBuf,"0UKKA0",5,7);
	writeStringToBuffer(screenBuf,"0Random0",4,8);
	writeStringToBuffer(screenBuf,"0MAKER0",3,9);
	writeStringToBuffer(screenBuf,"0GAME!!!0",5,10);
	writeStringToBuffer(screenBuf,"1.Start",5,11);
	writeStringToBuffer(screenBuf,"2.How to Play",4,12);
	writeStringToBuffer(screenBuf,"3.Exit",5,13);

}
int setGameOverToScreenBuffer(char* screenBuf, int width, int height)
{
    clearBuffer(screenBuf,19,30);
    writeStringToBuffer(screenBuf,"Your Life is 0", 3,5);
    writeStringToBuffer(screenBuf,"Game Over", 4,6);
    writeStringToBuffer(screenBuf,"press 1", 4,7);
    writeStringToBuffer(screenBuf,"To Play again", 4,8);
}
int setHowToPlayToScreenBuffer(char* screenBuf, int width, int height)
{
    clearBuffer(screenBuf,19,30);
    writeStringToBuffer(screenBuf,"press 'd,g,j'", 3,5);
    writeStringToBuffer(screenBuf,"three times" ,2,6);
	writeStringToBuffer(screenBuf,"when O" ,3,7);
	writeStringToBuffer(screenBuf,"overlap",3,8);
	writeStringToBuffer(screenBuf,"---line" ,3,9);
	writeStringToBuffer(screenBuf,"-------O-------" ,2,14);
	writeStringToBuffer(screenBuf,"Like this" ,2,15);
	writeStringToBuffer(screenBuf,"if you want to" ,3,17);
	writeStringToBuffer(screenBuf,"go back to menu" ,2,18);
	writeStringToBuffer(screenBuf,"press '1' " ,3,19);
}


int setGamePlayScreenToScreenBuffer(char* screenBuf, int width, int height)
{
    int notePositionD = width =6; // 노트 가로 초기 위치
    int notePositionG = width =9; // 노트 가로 초기 위치
    int notePositionJ = width =12; // 노트 가로 초기 위치
    int life = 5; // 일단 라이프 5으로 설정
    int noteStartPositionD = 3; // 노트 세로 초기 위치
    int noteStartPositionG = 6; // 노트 세로 초기 위치
    int noteStartPositionJ = 9; // 노트 세로 초기 위치
    int score = 0; // 일단 임시로 스코어 0 설정해놨고 나중에 다른곳에서 스코어 넣어야 할 때, 지우기
    char d;
    char j;
    char g;
    char input[10];
    srand(time(NULL));
    

    while (life > 0)
    {
        clearBuffer(screenBuf, 19, 30);
        writeStringToBuffer(screenBuf, "---------------", 2, 22);
        writeStringToBuffer(screenBuf, "---------------", 2, 23);
        writeStringToBuffer(screenBuf, "---------------", 2, 24);

		writeStringToBuffer(screenBuf, "Life : ", 2, 26);
		sprintf(lifeString, "%d", life);
		writeStringToBuffer(screenBuf, lifeString, 10, 26);

        writeStringToBuffer(screenBuf, "Score : ", 2, 27);
        sprintf(scoreString, "%d", score);
        writeStringToBuffer(screenBuf, scoreString, 10, 27);

        writeStringToBuffer(screenBuf, "JUDGE : ", 2, 28);

        writeStringToBuffer(screenBuf, "O", notePositionD, noteStartPositionD); // 노트 위치에 'O' 출력
        writeStringToBuffer(screenBuf, "O", notePositionG, noteStartPositionG); // 노트 위치에 'O' 출력
        writeStringToBuffer(screenBuf, "O", notePositionJ, noteStartPositionJ); // 노트 위치에 'O' 출력
        Sleep(200); // 잠시 딜레이
        noteStartPositionD++; // 노트 위치 업데이트
        noteStartPositionG++; // 노트 위치 업데이트
        noteStartPositionJ++; // 노트 위치 업데이트
        if (kbhit())
        {
            d = getch();
            g = getch();
            j = getch();
            if (d == 'd' && noteStartPositionD == 22 || noteStartPositionD == 23 || noteStartPositionD == 24) // 'd' 키를 누르면 노트 히트 처리 + 히트사운드 출력
            {
                PlaySound(TEXT("hitSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
                writeStringToBuffer(screenBuf, "HIT!", 12, 28);
                score++;
                noteStartPositionD = rand() % 10 + 10;
            }
            else if (g == 'g' && noteStartPositionG == 22 || noteStartPositionG == 23 || noteStartPositionG == 24) // 'g' 키를 누르면 노트 히트 처리 + 히트사운드 출력
            {
                PlaySound(TEXT("hitSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
                writeStringToBuffer(screenBuf, "HIT!", 12, 28);
                score++;
                noteStartPositionG = rand() % 10 + 10;
            }
            else if (j == 'j' && noteStartPositionJ == 22 || noteStartPositionJ == 23 || noteStartPositionJ == 24) // 'j' 키를 누르면 노트 히트 처리 + 히트사운드 출력
            {
                PlaySound(TEXT("hitSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
                writeStringToBuffer(screenBuf, "HIT!", 12, 28);
                score++;
                noteStartPositionJ = rand() % 10 + 10;
            }
            else if (d != 'd' || noteStartPositionD == 22 || noteStartPositionD == 23 || noteStartPositionD == 24) // 'd' 키를 잘못 누르면 노트 미스 처리 + 미스사운드 출력
            {
                PlaySound(TEXT("missSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
                writeStringToBuffer(screenBuf, "Miss!", 12, 28);
                life--;
                noteStartPositionD = rand() % 10 + 10;
            }
            else if (g != 'g' || noteStartPositionG == 22 || noteStartPositionG == 23 || noteStartPositionG == 24) // 'g' 키를 잘못 누르면 노트 미스 처리 + 미스사운드 출력
            {
                PlaySound(TEXT("missSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
                writeStringToBuffer(screenBuf, "Miss!", 12, 28);
                life--;
                noteStartPositionG = rand() % 10 + 10;
            }
            else if (j != 'j' || noteStartPositionJ == 22 || noteStartPositionJ == 23 || noteStartPositionJ == 24) // 'j' 키를 잘못 누르면 노트 미스 처리 + 미스사운드 출력
            {
                PlaySound(TEXT("missSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
                writeStringToBuffer(screenBuf, "Miss!", 12, 28);
                life--;
                noteStartPositionJ = rand() % 10 + 10;
            }
        }
        if (noteStartPositionD >= height - 1) // 노트가 화면 밖으로 벗어나면 목숨 - 랑 랜덤 재배치 + 미스사운드 출력
        {
            PlaySound(TEXT("missSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
            life--;
            noteStartPositionD = rand() % 19 + 2;
        }
        if (noteStartPositionG >= height - 1) // 노트가 화면 밖으로 벗어나면 목숨 - 랑 랜덤 재배치 + 미스사운드 출력
        {
            PlaySound(TEXT("missSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
            life--;
            noteStartPositionG = rand() % 19 + 2;
        }
        if (noteStartPositionJ >= height - 1) // 노트가 화면 밖으로 벗어나면 목숨 - 랑 랜덤 재배치 + 미스사운드 출력
        {
            PlaySound(TEXT("missSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
            life--;
            noteStartPositionJ = rand() % 19 + 2;
        }
        
        
        system("cls");   // 화면 출력
        printf(screenBuf);
		if (life == 0)
		{
			system("cls");
			setGameOverToScreenBuffer(screenBuf, width, height);
			writeStringToBuffer(screenBuf, "Score : ", 2, 27);
        	sprintf(scoreString, "%d", score);
        	writeStringToBuffer(screenBuf, scoreString, 10, 27);
			printf("%s\ninput>", screenBuf);
			scanf("%s", input);
				if (input[0] == '1')
				{
					system("cls");
					break;
				}
		}
    }
}

