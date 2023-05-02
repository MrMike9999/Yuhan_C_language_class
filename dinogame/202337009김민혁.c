#include <stdio.h>

int print_title_screen()
{
	printf("############################\n");
	printf("##                        ##\n");
	printf("##      Dino    Game      ##\n");
	printf("##          V.0.1         ##\n");
	printf("##                        ##\n");
	printf("##    1.Game start        ##\n");
	printf("##                        ##\n");
	printf("##    2.How to play       ##\n");
	printf("##                        ##\n");
	printf("##    3.Exit this shit    ##\n");
	printf("##                        ##\n");
	printf("############################\n");

	return 0;
}

int How_to_play_this_game()
{
	printf("############################\n");
	printf("##                        ##\n");
	printf("##  How 2 play this shit  ##\n");
	printf("##                        ##\n");
	printf("##Just press space 2 play ##\n");
	printf("##                        ##\n");
	printf("############################\n");
	
	
	return 0;
}

int return_to_menu()
{
	printf("Do you want to return to menu?\n");
	printf("1.yes/2.no\n");

	return 0;
}

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


