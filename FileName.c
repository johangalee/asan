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

    printf("�� ������!!\n");
    printf("���� �Ϸ��� ����, �����Ϸ��� 'q' �Է� : ");
    input = getchar();
    if (input == 'q')
    {
        return 0;;
    }
    system("cls");
    printf("player1�� �г����� �����ּ���(����):");
    scanf_s("%s", name1, 100);
    system("cls");
    printf("player2�� �г����� �����ּ���(����):");
    scanf_s("%s", name2, 100);

    while (1)
    {
        if (player1 <= 0)
        {
            printf("%s �¸�!!", name2);
            return 0;
        }
        else if (player2 <= 0)
        {
            printf("%s �¸�!!", name1);
            return 0;
        }
        else
        {
            if (turn % 2 == 0)
            {
                printf("%s�� ��\n", name2);
                printf("\n");
                rnd1 = rand() % 10 + 1;

                player1 = player1 - rnd1;

                printf("%s�� ���� ü�� : %d\n", name1, player1);
                printf("��� �Ϸ��� ����, �����Ϸ��� 'q' �Է� : ");
                input = getchar();
                if (input == 'q')
                {
                    break;
                }
                system("cls"); 
            }
            else
            {
                printf("%s�� ��\n", name1);
                printf("\n");
                rnd1 = rand() % 10 + 1;

                player2 = player2 - rnd1;

                printf("%s�� ���� ü�� : %d\n", name2, player2);
                printf("��� �Ϸ��� ����, �����Ϸ��� 'q' �Է� : ");
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

        
        
            