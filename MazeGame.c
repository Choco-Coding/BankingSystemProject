#include "BankingSystem.h"
#include <stdlib.h>
#include <time.h> // time()함수 포함 라이브러리

#define MAX_SIZE 12
#define XPOS 50
#define YPOS 5

void MazeGame(int ID);                                             //미로 게임 함수
void print_mazeGame(char maze[][MAX_SIZE], int row);               //미로 frame(틀)을 그려주는 함수
int is_block(char maze[][MAX_SIZE], int row, int col);             //미로가 벽인지 판단하는 함수 
int is_finish(char maze[][MAX_SIZE], int i, int j);                //미로 종점인지 판단하는 함수
void complete_exit(int ID);                                        //미로 탈출을 완료한 후 미로 게임 종료 후 은행 메인 화면으로 돌아가는 함수
void move_maze(char maze[][MAX_SIZE], int* row, int* col, int ID); //객체(게임 주인공)을 움직이는 함수

//미로 게임 함수
void MazeGame(int ID)
{
    srand(time(NULL));
    int row = 1, col = 0; //시작 위치 초기화
    int rand_int = 0;

    char maze1[MAX_SIZE][MAX_SIZE] = { { '1','1','1','1','1','1','1','1','1','1','1','1' },  //1번 미로 그리기
                                 { 'x','0','1','1','1','1','1','1','1','1','1','1' },
                                 { '1','0','1','1','0','0','0','1','1','1','1','1' },
                                 { '1','0','0','0','0','1','0','1','1','0','0','0' },
                                 { '1','0','1','0','1','1','0','1','1','0','1','0' },
                                 { '1','1','1','1','1','1','0','0','0','0','1','y' },
                                 { '1','1','1','1','1','1','1','1','0','1','1','1' },
                                 { '1','1','1','1','1','1','1','1','0','0','0','1' },
                                 { '1','1','1','1','1','1','1','1','0','0','0','1' },
                                 { '1','1','1','1','1','1','1','1','1','1','0','0' },
                                 { '1','1','1','1','1','1','1','1','1','1','1','1' },
                                 { '1','1','1','1','1','1','1','1','1','1','1','1' },
    };

    char maze2[MAX_SIZE][MAX_SIZE] = { { '1','1','1','1','1','1','1','1','1','1','1','1' },  //2번 미로 그리기
                                     { 'x','0','1','1','1','1','1','1','1','1','1','1' },
                                     { '1','0','1','1','1','0','0','1','1','1','1','1' },
                                     { '1','0','1','1','1','1','0','1','1','0','0','0' },
                                     { '1','0','1','1','1','1','0','1','1','0','1','0' },
                                     { '1','0','1','1','1','0','0','0','0','0','1','y' },
                                     { '1','0','1','1','1','0','1','1','0','1','1','1' },
                                     { '1','0','0','0','0','0','1','1','0','0','0','1' },
                                     { '1','1','0','1','1','0','1','1','1','1','0','1' },
                                     { '1','1','0','1','0','0','1','1','1','1','0','1' },
                                     { '1','1','0','0','1','1','1','1','1','1','1','1' },
                                     { '1','1','1','1','1','1','1','1','1','1','1','1' },
    };

    char maze3[MAX_SIZE][MAX_SIZE] = { { '1','1','1','1','1','1','1','1','1','1','1','1' },  //3번 미로 그리기
                                     { 'x','1','1','1','1','1','1','1','1','1','1','1' },
                                     { '0','1','1','1','1','1','0','0','1','1','1','1' },
                                     { '0','1','1','1','1','1','0','1','1','0','0','1' },
                                     { '0','0','1','0','0','0','0','1','1','1','0','1' },
                                     { '1','0','1','0','1','1','0','1','1','1','0','y' },
                                     { '1','0','1','0','1','1','0','1','1','0','0','1' },
                                     { '1','0','1','0','1','1','0','0','1','0','1','1' },
                                     { '1','0','0','0','0','1','1','0','1','0','1','1' },
                                     { '1','1','0','1','0','1','1','0','0','0','1','1' },
                                     { '1','0','0','1','0','1','0','0','1','1','1','1' },
                                     { '1','1','1','1','1','1','1','1','1','1','1','1' },
    };

    char maze4[MAX_SIZE][MAX_SIZE] = { { '1','1','1','1','1','1','1','1','1','1','1','1' },  //4번 미로 그리기
                                     { 'x','0','1','1','1','0','0','1','1','1','1','1' },
                                     { '1','0','1','1','1','0','1','1','1','1','1','1' },
                                     { '1','0','0','0','0','0','1','1','0','0','0','1' },
                                     { '1','1','0','1','1','1','1','1','0','1','0','1' },
                                     { '1','1','0','1','1','1','0','0','0','1','0','y' },
                                     { '1','1','0','1','1','1','0','1','0','1','1','1' },
                                     { '1','1','0','1','1','0','0','1','0','1','1','1' },
                                     { '1','0','0','1','1','0','1','1','0','1','1','1' },
                                     { '1','0','1','1','0','0','1','1','1','1','1','1' },
                                     { '1','0','0','0','0','1','1','1','1','1','1','1' },
                                     { '1','1','1','1','1','1','1','1','1','1','1','1' },
    };

    gotoxy(XPOS - 3, YPOS - 2);

    rand_int = rand() % 4; //랜덤 값으로 미로 코드를 저장

    printf("흥미로운 미로 찾기 게임(%d)", rand_int + 1);

    switch (rand_int) //0~3
    {
    case 0:
        //1번 미로 게임 start
        move_maze(maze1, &row, &col, ID);
        break;
    case 1:
        //2번 미로 게임 start
        move_maze(maze2, &row, &col, ID);
        break;
    case 2:
        //3번 미로 게임 start
        move_maze(maze3, &row, &col, ID);
        break;
    case 3:
        //4번 미로 게임 start
        move_maze(maze4, &row, &col, ID);
        break;
    }

    return;
}

//미로 frame(틀)을 그려주는 함수
void print_mazeGame(char maze[][MAX_SIZE], int row) 
{

    for (int i = 0; i < row; i++)
    {
        gotoxy(XPOS, YPOS + i);
        for (int j = 0; j < MAX_SIZE; j++)
        {
            if (maze[i][j] == '1')
                printf("■");
            else if (maze[i][j] == 'y')
                printf("★");
            else if (maze[i][j] == '0')
                printf("□");
            else
                printf("●");
        }
        puts("");
    }
}

//미로가 벽인지 판단하는 함수
int is_block(char maze[][MAX_SIZE], int i, int j)
{
    if (maze[i][j] == '1' || maze[i][j] == 'y') //미로가 벽일 경우, 종점일 경우
        return 1;
    else
        return 0;
}

//미로 종점인지 판단하는 함수
int is_finish(char maze[][MAX_SIZE], int i, int j)
{
    if (maze[i][j] == 'y') //종점일 경우
        return 1;
    else
        return 0;
}

//미로 탈출을 완료한 후 미로 게임 종료 후 은행 메인 화면으로 돌아가는 함수
void complete_exit(int ID) 
{
    PLUS(&user_data[ID], 10000);  //입금 처리 

    //거래 내역 저장
    user_data[ID].list_n++;
    user_data[ID].user_list[user_data[ID].list_n - 1].type = 1;
    user_data[ID].user_list[user_data[ID].list_n - 1].cash = 10000;
    user_data[ID].user_list[user_data[ID].list_n - 1].total = user_data[ID].money;

    system("cls");
    screen();
    gotoxy(10, 5);
    printf("성공! 10000원이 적립되었습니다.");
    gotoxy(11, 9);
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    gotoxy(11, 10);
    printf("┃                         ┃");
    gotoxy(11, 11);
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━┛");
    gotoxy(13, 10);
    printf("통장 잔액 : %d원", user_data[ID].money);
    gotoxy(0, 16);
    printf("2초 후 메인 화면으로 돌아갑니다.");
    Sleep(2000);

    return;
}

//객체(게임 주인공)을 움직이는 함수
void move_maze(char maze[][MAX_SIZE], int* row, int* col, int ID) 
{
    int chr; //키를 받아들이기 위한 변수
    int i, j;

    while (1)
    {
        i = *row; //1
        j = *col; //0

        print_mazeGame(maze, 12);
        chr = GetKey();

        /*0xe0 또는 0의 반환을 확인하고 한 번 더
        chr = GetKey();를 선언하여 방향키를 확인하는 작업
        (이 작업이 없으면, 방향키를 누르는 순간 K, M, H, P가 입력됨
        -> 각각 LEFT, RIGHT, UP, DOWN을 의미하는 75, 77, 72, 80과 충돌)*/
        if (chr == 0 || chr == 0xe0)
        {
            chr = GetKey();
            switch (chr)
            {
            case UP:
                i--;
                if (!(is_block(maze, i, j)))    //블럭이 아닐 경우 객체를 옮길 수 있음
                {
                    maze[*row][j] = '0'; //이전 블록에 0을 삽입 
                    maze[i][j] = 'x';    //방향키를 옮긴 뒤 x를 삽입
                    *row -= 1;
                }
                else if (is_finish(maze, i, j)) //종점일 경우
                {
                    maze[*row][j] = '0';
                    maze[i][j] = 'x';
                    print_mazeGame(maze, 12);
                    complete_exit(ID);
                    return;
                }
                break;

            case DOWN:
                i++;
                if (!(is_block(maze, i, j)))
                {
                    maze[*row][j] = '0';
                    maze[i][j] = 'x';
                    *row += 1;
                }
                else if (is_finish(maze, i, j))
                {
                    maze[*row][j] = '0';
                    maze[i][j] = 'x';
                    print_mazeGame(maze, 12);
                    complete_exit(ID);
                    return;
                }
                break;

            case LEFT:
                j--;
                if (!(is_block(maze, i, j)))
                {
                    maze[i][*col] = '0';
                    maze[i][j] = 'x';
                    *col -= 1;
                }
                else if (is_finish(maze, i, j))
                {
                    maze[i][*col] = '0';
                    maze[i][j] = 'x';
                    print_mazeGame(maze, 12);
                    complete_exit(ID);
                    return;
                }
                break;

            case RIGHT:
                j++;
                if (!(is_block(maze, i, j)))
                {
                    maze[i][*col] = '0';
                    maze[i][j] = 'x';
                    *col += 1;
                }
                else if (is_finish(maze, i, j))
                {
                    maze[i][*col] = '0';
                    maze[i][j] = 'x';
                    print_mazeGame(maze, 12);
                    complete_exit(ID);
                    return;
                }
                break;
            }
        }
    }
}