// 4. 카드 짝 맞추기 게임 만들기
// 5x5 크기의 격자 보드를 만든다. 격자 칸을 * 로표시한다. (다른 방법을 적용해도 무방함)
// 12개의 다른 소문자를 각각 2개씩 보드에 무작위로 배치한다. 나머지 한 개는 조커로 어느 카드와도 매치된다.
// 보드 위쪽에 a b c d e, 좌측에 1 2 3 4 5를 표시하여 칸의 위치를 알 수 있게한다.
// 2개의 격자를 선택한다. 엔터 키를 치면 선택된 칸의 문자가 보여진다.
// 두 문자가 같으면 그 칸에는 문자가 대문자로 변경되어 계속 그려지고, 문자가 다르면 다시 가려진다. 문자의 색상 변경한다.
// 특정 횟수만큼 진행할 수 있게 하고, 점수를 배점하여 출력한다. (횟수, 점수배점은각자결정하기)
// 선택한 2개 중에 조커가 있으면 나머지 한 개의 카드가 열린다.
// 명령어:
// r : 게임을 리셋하고 다시 시작한다.
// h : 보드칸의 모든 문자들을 잠시 보여주고 다시 원래대로 출력한다.  (힌트키)
// q : 프로그램 종료
// 보드칸 선택 방법
// 행렬의 번호를 입력 받아 선택하기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <ctype.h>

void printBoard(char board[5][5]) {
    printf("  a b c d e\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 5; j++) {
            if (board[i][j] == 'a' || board[i][j] == 'A') {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			}
			else if (board[i][j] == 'b' || board[i][j] == 'B') {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			}
			else if (board[i][j] == 'c' || board[i][j] == 'C') {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			}
			else if (board[i][j] == 'd' || board[i][j] == 'D') {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
			}
			else if (board[i][j] == 'e' || board[i][j] == 'E') {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			}
			else if (board[i][j] == 'f' || board[i][j] == 'F') {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			}
			else if (board[i][j] == 'g' || board[i][j] == 'G') {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			}
			else if (board[i][j] == 'h' || board[i][j] == 'H') {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			}
			else if (board[i][j] == 'i' || board[i][j] == 'I') {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			}
			else if (board[i][j] == 'j' || board[i][j] == 'J') {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			}
			else if (board[i][j] == 'k' || board[i][j] == 'K') {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			}
			else if (board[i][j] == 'l' || board[i][j] == 'L') {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			}
            printf("%c ", board[i][j]);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }
        printf("\n");
    }
}

int main() {
    srand((unsigned)time(NULL));
    char board[5][5] = { 0 };
    char answer[5][5] = { 0 };
    char cards[25];
    char row, col;
    char command;
    int opencnt = 0;
    int first_i = -1, first_j = -1;
    int second_i = -1, second_j = -1;
    int matchedPairs = 0;

    // 카드 준비 및 셔플
    for (int i = 0; i < 12; i++) {
        cards[i * 2] = 'a' + i;
        cards[i * 2 + 1] = 'a' + i;
    }
    cards[24] = '@';
    for (int i = 24; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = cards[i]; cards[i] = cards[j]; cards[j] = temp;
    }

    // 보드/정답 배치
    int index = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            answer[i][j] = cards[index++];
            board[i][j] = '*';
        }
    }

    while (1) {
        system("cls");
        printBoard(board);
        printf("Command : ");
        if (scanf(" %c", &command) != 1) continue;

        switch (command)
        {
        case 'a': { // 카드 선택
            printf("행과 열 입력 (예: 1a): ");
            if (scanf(" %c%c", &row, &col) != 2) break;
            col = (char)tolower(col);

            int opened = 0;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (row == '1' + i && col == 'a' + j) {
                        if (board[i][j] == '*') {
                            // 뒤집기
                            board[i][j] = answer[i][j];
                            if (opencnt == 0) { first_i = i; first_j = j; }
                            else if (opencnt == 1) { second_i = i; second_j = j; }
                            opencnt++;
                            opened = 1;
                        }
                    }
                }
            }

            if (!opened) {
                printf("잘못된 위치이거나 이미 공개된 칸입니다.\n");
                Sleep(1000);
                break;
            }

            if (opencnt == 2) {
                // 잠깐 보여주기
                system("cls");
                printBoard(board);
                Sleep(1000);

                char a = answer[first_i][first_j];
                char b = answer[second_i][second_j];
                int match = (a == b) || (a == '@') || (b == '@');

                if (match) {
                    // 조커가 섞였으면 두 칸 모두 상대문자의 대문자로 고정
                    char base = (a == '@') ? b : a;
                    char fixed = (char)toupper((unsigned char)base);
                    board[first_i][first_j] = fixed;
                    board[second_i][second_j] = fixed;

                    matchedPairs++;
                    if (matchedPairs == 12) {
                        system("cls");
                        printBoard(board);
                        printf("모든 짝을 맞추셨습니다. 게임 종료!\n");
                        return 0;
                    }
                }
                else {
                    // 불일치: 다시 가림
                    board[first_i][first_j] = '*';
                    board[second_i][second_j] = '*';
                }

                // 턴 리셋
                opencnt = 0;
                first_i = first_j = -1;
                second_i = second_j = -1;
            }
            break;
        }
        case 'r': { // 게임 리셋
            for (int i = 0; i < 12; i++) {
                cards[i * 2] = 'a' + i;
                cards[i * 2 + 1] = 'a' + i;
            }
            cards[24] = '@';
            for (int i = 24; i > 0; i--) {
                int j = rand() % (i + 1);
                char temp = cards[i]; cards[i] = cards[j]; cards[j] = temp;
            }
            int idx = 0;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    answer[i][j] = cards[idx++];
                    board[i][j] = '*';
                }
            }
            opencnt = 0;
            first_i = first_j = -1;
            second_i = second_j = -1;
            matchedPairs = 0;
            break;
        }
        case 'h': { // 힌트(2초 공개)
            system("cls");
            printBoard(answer);
            Sleep(2000);
            break;
        }
        case 'q':
            return 0;
        default:
            printf("다시 입력\n");
            Sleep(600);
            break;
        }
    }
}
