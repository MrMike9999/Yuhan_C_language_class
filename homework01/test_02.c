#include <stdio.h>
#include <string.h>


void gamemenu()
{
    char MapSize[465]; /*가로 15 세로 30*/
    int a = 0 ;

    char tittle1[] = "0JUST0";
    char tittle2[] = "0Rhythm0";
    char tittle3[] = "0Hitting0";

    int tittle1_XY = strlen(tittle1);
    int tittle2_XY = strlen(tittle2);
    int tittle3_XY = strlen(tittle3);
    int tittle1_pos = (16 - tittle1_XY) /2 ;
    int tittle2_pos = (16 - tittle2_XY) /2 ;
    int tittle3_pos = (16 - tittle3_XY) /2 ;

    char menubutton1[] = "0Start0";
    char menubutton2[] = "0How to Play0";
    char menubutton3[] = "0Exit0";

    int menubutton1_XY = strlen(menubutton1);
    int menubutton2_XY = strlen(menubutton2);
    int menubutton3_XY = strlen(menubutton3);
    int menubutton1_pos = (16 - menubutton1_XY) /2 ;
    int menubutton2_pos = (16 - menubutton2_XY) /2 ;
    int menubutton3_pos = (16 - menubutton3_XY) /2 ;

    while (a < 464)
    {
        if ( a % 16 == 15)
        {
            MapSize[a] = '\n';
        }
        else if (a == 0 || a == 14 || a == 448 || a == 462)
        {
            MapSize[a] = '0';
        }
        else if (a % 16 == 0)
        {
            MapSize[a] = '1';
        }
        else if (a % 16 == 14)
        {
            MapSize[a] = '1';
        }
        else if (a / 16 == 0)
        {
            MapSize[a] = '-';
        }
        else if (a / 16 == 28)
        {
            MapSize[a] = '-';
        }
        else if (a / 16 == 19)
        {
            MapSize[a] = '-';
        }
        else if (a / 16 == 2 && a % 16 == tittle1_pos)
        {
            int b;
            for ( b = 0; b < tittle1_XY; b++)
            {
                MapSize[a+b] = tittle1[b];
            }
            a +=  tittle1_XY - 1 ;            
        }
        else if (a / 16 == 4 && a % 16 == tittle2_pos)
        {
            int b;
            for ( b = 0; b < tittle2_XY; b++)
            {
                MapSize[a+b] = tittle2[b];
            } 
            a +=  tittle2_XY - 1 ;          
        }
        else if (a / 16 == 6 && a % 16 == tittle3_pos)
        {
            int b;
            for ( b = 0; b < tittle3_XY; b++)
            {
                MapSize[a+b] = tittle3[b];
            } 
            a +=  tittle3_XY - 1 ;          
        }
        else if (a / 16 == 21 && a % 16 == menubutton1_pos)
        {
            int b;
            for ( b = 0; b < menubutton1_XY; b++)
            {
                MapSize[a+b] = menubutton1[b];
            }
            a +=  menubutton1_XY - 1 ;
           
        }
        else if (a / 16 == 23 && a % 16 == menubutton2_pos)
        {
            int b;
            for ( b = 0; b < menubutton2_XY; b++)
            {
                MapSize[a+b] = menubutton2[b];
            }     
            a +=  menubutton2_XY - 1 ;     
        }
        else if (a / 16 == 25 && a % 16 == menubutton3_pos)
        {
            int b;
            for ( b = 0; b < menubutton3_XY; b++)
            {
                MapSize[a+b] = menubutton3[b];
            }    
            a +=  menubutton3_XY - 1 ;       
        }
        else
        {
            MapSize[a] = ' ';
        }
        a++;
    }
    MapSize[464] = '\0';
    printf("%s\n",MapSize);

}

void how_to_play_menu()
{
    char MapSize[465]; /*가로 15 세로 30*/
    int a = 0 ;
    
    char tittle1[] = "0JUST0";
    char tittle2[] = "0Rhythm0";
    char tittle3[] = "0Hitting0";

    int tittle1_XY = strlen(tittle1);
    int tittle2_XY = strlen(tittle2);
    int tittle3_XY = strlen(tittle3);
    int tittle1_pos = (16 - tittle1_XY) /2 ;
    int tittle2_pos = (16 - tittle2_XY) /2 ;
    int tittle3_pos = (16 - tittle3_XY) /2 ;

    char explain1[] = "press d f j k";
    char explain2[] = "when O ";
    char explain3[] = "overlap";
    char explain4[] = "---line";

    int explain1_XY = strlen(explain1);
    int explain2_XY = strlen(explain2);
    int explain3_XY = strlen(explain3);
    int explain4_XY = strlen(explain4);
    int explain1_pos = (16 - explain1_XY) /2 ;
    int explain2_pos = (16 - explain2_XY) /2 ;
    int explain3_pos = (16 - explain3_XY) /2 ;
    int explain4_pos = (16 - explain4_XY) /2 ;

    while (a < 464)
    {
        if ( a % 16 == 15)
        {
            MapSize[a] = '\n';
        }
        else if (a == 0 || a == 14 || a == 448 || a == 462)
        {
            MapSize[a] = '0';
        }
        else if (a % 16 == 0)
        {
            MapSize[a] = '1';
        }
        else if (a % 16 == 14)
        {
            MapSize[a] = '1';
        }
        else if (a / 16 == 0)
        {
            MapSize[a] = '-';
        }
        else if (a / 16 == 28)
        {
            MapSize[a] = '-';
        }
        else if (a / 16 == 19)
        {
            MapSize[a] = '-';
        }
        else if (a / 16 == 2 && a % 16 == tittle1_pos)
        {
            int b;
            for ( b = 0; b < tittle1_XY; b++)
            {
                MapSize[a+b] = tittle1[b];
            }
            a +=  tittle1_XY - 1 ;            
        }
        else if (a / 16 == 4 && a % 16 == tittle2_pos)
        {
            int b;
            for ( b = 0; b < tittle2_XY; b++)
            {
                MapSize[a+b] = tittle2[b];
            } 
            a +=  tittle2_XY - 1 ;          
        }
        else if (a / 16 == 6 && a % 16 == tittle3_pos)
        {
            int b;
            for ( b = 0; b < tittle3_XY; b++)
            {
                MapSize[a+b] = tittle3[b];
            } 
            a +=  tittle3_XY - 1 ;          
        }
        else if (a / 16 == 20 && a % 16 == explain1_pos)
        {
            int b;
            for ( b = 0; b < explain1_XY; b++)
            {
                MapSize[a+b] = explain1[b];
            }
            a +=  explain1_XY - 1 ;
        }
        else if (a / 16 == 21 && a % 16 == explain2_pos)
        {
            int b;
            for ( b = 0; b < explain2_XY; b++)
            {
                MapSize[a+b] = explain2[b];
            }
            a +=  explain2_XY - 1 ;
        }
        else if (a / 16 == 22 && a % 16 == explain3_pos)
        {
            int b;
            for ( b = 0; b < explain3_XY; b++)
            {
                MapSize[a+b] = explain3[b];
            }
            a +=  explain3_XY - 1 ;
        }
        else if (a / 16 == 23 && a % 16 == explain4_pos)
        {
            int b;
            for ( b = 0; b < explain4_XY; b++)
            {
                MapSize[a+b] = explain4[b];
            }
            a +=  explain4_XY - 1 ;
        }
        else
        {
            MapSize[a] = ' ';
        }
        a++;
    }
    MapSize[464] = '\0';
    printf("%s\n",MapSize);
}


int main()
{
    int game_state = 1;
    while (game_state)
    {
        gamemenu() ;
        printf("press 1,2,3 to choose the menu\n");
        printf(">>>");
        scanf("%d",&game_state);
            if( game_state == 1)
            {
                while (game_state)
                {
                    printf("You can't play it now.\n");
                    printf("Do you want to return to menu?\n");
                    printf("1. Yes 2. No\n");
                    printf(">>>");
                    scanf("%d",&game_state);
                        if (game_state == 1)
                        {
                            break;
                        }
                }
                    
            }
            else if( game_state == 2)
            {
                while (game_state)
                {
                    how_to_play_menu();
                    printf("Do you want to return to menu?\n");
                    printf("1. Yes 2. No\n");
                    printf(">>>");
                    scanf("%d",&game_state);
                        if (game_state == 1)
                        {
                            break;
                        }
                }
            }
            else if ( game_state == 3)
            {
                break;
            }
    }

    return 0;
}
