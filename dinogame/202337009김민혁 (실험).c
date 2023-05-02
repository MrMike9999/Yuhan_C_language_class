#include <stdio.h>
#include "dino_screen_header.h"

/* 게임 루프
 * while문이 계속 반복해서 입력을 받는다.
 * 입력받은 값을 game_state에 저장한다.
 */
int main()

{
	
	int game_state = 1;

	

	while(game_state)
	{
		print_title_screen(); 
		printf("input>");
		scanf("%d", &game_state);
			if(game_state == 2)
			{				
				while(game_state)
				{
					How_to_play_this_game();
					
					return_to_menu();
					scanf("%d", &game_state);
						if(game_state == 1)
							{
								break;
							}
						
				}
		}
			else if(game_state == 1)
		{
			
				while(game_state)
				{
					printf("You can't Run this game now XD\n");
					return_to_menu();
					printf("input>");
					scanf("%d", &game_state);
						if(game_state == 1)
							{
								break;
							}
						
				}
		}
		else if(game_state == 3)
		{
			break;
		}
	}

	return 0;
}


