// 4. ī�� ¦ ���߱� ���� �����
// 5x5 ũ���� ���� ���带 �����. ���� ĭ�� * ��ǥ���Ѵ�. (�ٸ� ����� �����ص� ������)
// 12���� �ٸ� �ҹ��ڸ� ���� 2���� ���忡 �������� ��ġ�Ѵ�. ������ �� ���� ��Ŀ�� ��� ī��͵� ��ġ�ȴ�.
// ���� ���ʿ� a b c d e, ������ 1 2 3 4 5�� ǥ���Ͽ� ĭ�� ��ġ�� �� �� �ְ��Ѵ�.
// 2���� ���ڸ� �����Ѵ�. ���� Ű�� ġ�� ���õ� ĭ�� ���ڰ� ��������.
// �� ���ڰ� ������ �� ĭ���� ���ڰ� �빮�ڷ� ����Ǿ� ��� �׷�����, ���ڰ� �ٸ��� �ٽ� ��������. ������ ���� �����Ѵ�.
// Ư�� Ƚ����ŭ ������ �� �ְ� �ϰ�, ������ �����Ͽ� ����Ѵ�. (Ƚ��, �������������ڰ����ϱ�)
// ������ 2�� �߿� ��Ŀ�� ������ ������ �� ���� ī�尡 ������.
// ��ɾ�:
// r : ������ �����ϰ� �ٽ� �����Ѵ�.
// h : ����ĭ�� ��� ���ڵ��� ��� �����ְ� �ٽ� ������� ����Ѵ�.  (��ƮŰ)
// q : ���α׷� ����
// ����ĭ ���� ���
// ����� ��ȣ�� �Է� �޾� �����ϱ�

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

    // ī�� �غ� �� ����
    for (int i = 0; i < 12; i++) {
        cards[i * 2] = 'a' + i;
        cards[i * 2 + 1] = 'a' + i;
    }
    cards[24] = '@';
    for (int i = 24; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = cards[i]; cards[i] = cards[j]; cards[j] = temp;
    }

    // ����/���� ��ġ
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
        case 'a': { // ī�� ����
            printf("��� �� �Է� (��: 1a): ");
            if (scanf(" %c%c", &row, &col) != 2) break;
            col = (char)tolower(col);

            int opened = 0;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (row == '1' + i && col == 'a' + j) {
                        if (board[i][j] == '*') {
                            // ������
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
                printf("�߸��� ��ġ�̰ų� �̹� ������ ĭ�Դϴ�.\n");
                Sleep(1000);
                break;
            }

            if (opencnt == 2) {
                // ��� �����ֱ�
                system("cls");
                printBoard(board);
                Sleep(1000);

                char a = answer[first_i][first_j];
                char b = answer[second_i][second_j];
                int match = (a == b) || (a == '@') || (b == '@');

                if (match) {
                    // ��Ŀ�� �������� �� ĭ ��� ��빮���� �빮�ڷ� ����
                    char base = (a == '@') ? b : a;
                    char fixed = (char)toupper((unsigned char)base);
                    board[first_i][first_j] = fixed;
                    board[second_i][second_j] = fixed;

                    matchedPairs++;
                    if (matchedPairs == 12) {
                        system("cls");
                        printBoard(board);
                        printf("��� ¦�� ���߼̽��ϴ�. ���� ����!\n");
                        return 0;
                    }
                }
                else {
                    // ����ġ: �ٽ� ����
                    board[first_i][first_j] = '*';
                    board[second_i][second_j] = '*';
                }

                // �� ����
                opencnt = 0;
                first_i = first_j = -1;
                second_i = second_j = -1;
            }
            break;
        }
        case 'r': { // ���� ����
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
        case 'h': { // ��Ʈ(2�� ����)
            system("cls");
            printBoard(answer);
            Sleep(2000);
            break;
        }
        case 'q':
            return 0;
        default:
            printf("�ٽ� �Է�\n");
            Sleep(600);
            break;
        }
    }
}
