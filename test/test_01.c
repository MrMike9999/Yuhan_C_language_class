#include <stdio.h>

int main()
{
	int game_state = 0;
	
	scanf("%d",&game_state);

	if(game_state)
	{
		printf("나는 러쉬를 %d번 뛰었다.",game_state);
	}
	else
	{
		printf("님 진 게 ?");
	}
	return 0;
}