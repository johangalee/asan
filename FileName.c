#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <mmsystem.h>

void CursorView(char show)
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

int main()
{
    int rnd1;
    int input;
    int player1 = 100;
    int player2 = 100;
    char name1[100], name2[100];
    int turn = 0;
    int attack1 = 0, attack2 = 0;

    srand(time(NULL));

    printf("뺨 때리기!!\n");
    printf("시작 하려면 엔터, 중지하려면 'q' 입력 : ");
    input = getchar();
    if (input == 'q')
    {
        return 0;;
    }
    system("cls");
    printf("player1의 닉네임을 정해주세요(영어):");
    scanf_s("%s", name1, 100);
    system("cls");
    printf("player2의 닉네임을 정해주세요(영어):");
    scanf_s("%s", name2, 100);

    while (1)
    {
        if (player1 <= 0)
        {
            printf("%s 승리!!", name2);
            return 0;
        }
        else if (player2 <= 0)
        {
            printf("%s 승리!!", name1);
            return 0;
        }
        else
        {
            if (turn % 2 == 0)
            {
                printf("%s의 턴\n", name2);
                printf("\n");
                rnd1 = rand() % 10 + 1;

                player1 = player1 - rnd1;

                printf("%s의 남은 체력 : %d\n", name1, player1);
                printf("계속 하려면 엔터, 중지하려면 'q' 입력 : ");
                input = getchar();
                if (input == 'q')
                {
                    break;
                }
                system("cls"); 
            }
            else
            {
                printf("%s의 턴\n", name1);
                printf("\n");
                rnd1 = rand() % 10 + 1;

                player2 = player2 - rnd1;

                printf("%s의 남은 체력 : %d\n", name2, player2);
                printf("계속 하려면 엔터, 중지하려면 'q' 입력 : ");
                input = getchar();
                if (input == 'q')
                {
                    break;
                }
                system("cls");
            }
            turn++;
        }
    }
    return 0;
}

        
        
            