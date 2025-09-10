//// 6. 객체를 이동하여 경로 만들기
//// 30x30 크기의 2차원 배열을 만든다. 좌측 상단에서 우측 하단으로 가는 한 줄의 경로를 만든 후 화면에 출력한다.
//// 1은 길, 0은 배경, X는 장애물로 표시한다. 장애물은 4개 이상 설정한다.
//// 객체가 좌측 상단에 놓여있다. 다른 색의 * 로 나타낸다.
//// 객체를 이동하면 이동했던 곳은 길이 된다. 길이 된 곳은 다른 색의 1로 표시된다.
//// 다음의 키보드 명령을 수행한다. (키보드 명령어는 다른 것을 사용해도 무관함)
//// w / a / s / d: 나타난 객체를 경로 따라 위 / 아래 / 좌 / 우로 이동한다. 장애물들은 지나갈 수 없다. 지나간 곳은 1로 표시되고, 다시 그 위치를 지나면
//// + 1 한다. 즉 두 번 지나간 위치는 2, 세 번 지나간 위치는 3…, 숫자는 지나갔던 횟수를 나타낸다.
//// enter키 : 만들어진 길이 삭제되며 리셋된다. 장애물의 위치도 바뀐다. 객체는 다시 좌측 상단에 놓여있다.
//// q : 프로그램종료
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <Windows.h>
//
//int main() {
//	srand(time(NULL));
//	char board[30][30];
//	int playerX = 0, playerY = 0;
//	char command;
//
//	// 보드 초기화
//	for (int i = 0; i < 30; i++) {
//		for (int j = 0; j < 30; j++) {
//			board[i][j] = '0';
//		}
//	}
//	board[playerY][playerX] = '1';
//
//	// 장애물 배치
//	for (int i = 0; i < 4; i++) {
//		int obsX = rand() % 30;
//		int obsY = rand() % 30;
//		if (board[obsY][obsX] == '0' && !(obsX == playerX && obsY == playerY)) {
//			board[obsY][obsX] = 'X';
//		}
//		else {
//			i--; // 이미 장애물이 있거나 플레이어 위치인 경우 다시 시도
//		}
//	}
//
//	while (1) {
//		system("cls");
//
//		// 보드 출력
//		for (int i = 0; i < 30; i++) {
//			for (int j = 0; j < 30; j++) {
//				if (i == playerY && j == playerX) {
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
//					printf("* ");
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//				}
//				else {
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//					printf("%c ", board[i][j]);
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//				}
//			}
//			printf("\n");
//		}
//		printf("명령어 입력 (w/a/s/d: 이동, Enter: 리셋, q: 종료): ");
//		scanf(" %c", &command);
//
//		switch (command)
//		{
//		case 'w': // 위로 이동
//			if (playerY > 0) {
//				playerY--;
//				if (board[playerY][playerX] == '0') {
//					board[playerY][playerX] = '1';
//				}
//				else if (board[playerY][playerX] >= '1' && board[playerY][playerX] < '9') {
//					board[playerY][playerX]++;
//				}
//				else if (board[playerY][playerX] == 'X') {
//					playerY++; // 장애물이 있으면 원래 위치로 돌아감
//				}
//			}
//			break;
//		case 's': // 아래로 이동
//			if (playerY < 29) {
//				playerY++;
//				if (board[playerY][playerX] == '0') {
//					board[playerY][playerX] = '1';
//				}
//				else if (board[playerY][playerX] >= '1' && board[playerY][playerX] < '9') {
//					board[playerY][playerX]++;
//				}
//				else if (board[playerY][playerX] == 'X') {
//					playerY--; // 장애물이 있으면 원래 위치로 돌아감
//				}
//			}
//			break;
//		case 'a': // 왼쪽으로 이동
//			if (playerX > 0) {
//				playerX--;
//				if (board[playerY][playerX] == '0') {
//					board[playerY][playerX] = '1';
//				}
//				else if (board[playerY][playerX] >= '1' && board[playerY][playerX] < '9') {
//					board[playerY][playerX]++;
//				}
//				else if (board[playerY][playerX] == 'X') {
//					playerX++; // 장애물이 있으면 원래 위치로 돌아감
//				}
//			}
//			break;
//		case 'd': // 오른쪽으로 이동
//			if (playerX < 29) {
//				playerX++;
//				if (board[playerY][playerX] == '0') {
//					board[playerY][playerX] = '1';
//				}
//				else if (board[playerY][playerX] >= '1' && board[playerY][playerX] < '9') {
//					board[playerY][playerX]++;
//				}
//				else if (board[playerY][playerX] == 'X') {
//					playerX--; // 장애물이 있으면 원래 위치로 돌아감
//				}
//			}
//			break;
//		case 'r': // 리셋
//			playerX = playerY = 0;
//			for (int i = 0; i < 30; i++) {
//				for (int j = 0; j < 30; j++) {
//					board[i][j] = '0';
//				}
//			}
//			// 장애물 재배치
//			for (int i = 0; i < 4; i++) {
//				int obsX = rand() % 30;
//				int obsY = rand() % 30;
//				if (board[obsY][obsX] == '0' && !(obsX == playerX && obsY == playerY)) {
//					board[obsY][obsX] = 'X';
//				}
//				else {
//					i--; // 이미 장애물이 있거나 플레이어 위치인 경우 다시 시도
//				}
//			}
//			break;
//		case 'q': // 종료
//			return 0;
//			break;
//		default:
//			printf("다시 입력\n");
//			break;
//		}
//	}
//}