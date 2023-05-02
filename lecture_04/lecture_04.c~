#include <stdio.h>


int main()
{ 
    int game_state = 0;

    printf("주인공의 공격력을 입력하세요!");
    printf("적의 HP는 현재 30 입니다!");
    
    scanf("%d",&game_state);

    if(game_state <30)
    {
        printf("주인공이 적을 공격하여 %d의 데미지를 입혔습니다.\n",30-game_state);
	printf("적의 잔여 HP : %d\n",30-game_state);
	printf("오크는 화나서 당신을 공격했습니다!\n");
        printf("GAME OVER\n");
    }
    else if (game_state>=30)
    {
        printf("적이 죽었습니다! (%d의 데미지로 처치)\n",game_state);
	printf("당신은 오크를 쓰려트렸습니다! (EXP 5획득!)\n");
	printf("Happy End!");
    }
    return 0;
}

