//// 6. ��ü�� �̵��Ͽ� ��� �����
//// 30x30 ũ���� 2���� �迭�� �����. ���� ��ܿ��� ���� �ϴ����� ���� �� ���� ��θ� ���� �� ȭ�鿡 ����Ѵ�.
//// 1�� ��, 0�� ���, X�� ��ֹ��� ǥ���Ѵ�. ��ֹ��� 4�� �̻� �����Ѵ�.
//// ��ü�� ���� ��ܿ� �����ִ�. �ٸ� ���� * �� ��Ÿ����.
//// ��ü�� �̵��ϸ� �̵��ߴ� ���� ���� �ȴ�. ���� �� ���� �ٸ� ���� 1�� ǥ�õȴ�.
//// ������ Ű���� ����� �����Ѵ�. (Ű���� ��ɾ�� �ٸ� ���� ����ص� ������)
//// w / a / s / d: ��Ÿ�� ��ü�� ��� ���� �� / �Ʒ� / �� / ��� �̵��Ѵ�. ��ֹ����� ������ �� ����. ������ ���� 1�� ǥ�õǰ�, �ٽ� �� ��ġ�� ������
//// + 1 �Ѵ�. �� �� �� ������ ��ġ�� 2, �� �� ������ ��ġ�� 3��, ���ڴ� �������� Ƚ���� ��Ÿ����.
//// enterŰ : ������� ���� �����Ǹ� ���µȴ�. ��ֹ��� ��ġ�� �ٲ��. ��ü�� �ٽ� ���� ��ܿ� �����ִ�.
//// q : ���α׷�����
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
//	// ���� �ʱ�ȭ
//	for (int i = 0; i < 30; i++) {
//		for (int j = 0; j < 30; j++) {
//			board[i][j] = '0';
//		}
//	}
//	board[playerY][playerX] = '1';
//
//	// ��ֹ� ��ġ
//	for (int i = 0; i < 4; i++) {
//		int obsX = rand() % 30;
//		int obsY = rand() % 30;
//		if (board[obsY][obsX] == '0' && !(obsX == playerX && obsY == playerY)) {
//			board[obsY][obsX] = 'X';
//		}
//		else {
//			i--; // �̹� ��ֹ��� �ְų� �÷��̾� ��ġ�� ��� �ٽ� �õ�
//		}
//	}
//
//	while (1) {
//		system("cls");
//
//		// ���� ���
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
//		printf("��ɾ� �Է� (w/a/s/d: �̵�, Enter: ����, q: ����): ");
//		scanf(" %c", &command);
//
//		switch (command)
//		{
//		case 'w': // ���� �̵�
//			if (playerY > 0) {
//				playerY--;
//				if (board[playerY][playerX] == '0') {
//					board[playerY][playerX] = '1';
//				}
//				else if (board[playerY][playerX] >= '1' && board[playerY][playerX] < '9') {
//					board[playerY][playerX]++;
//				}
//				else if (board[playerY][playerX] == 'X') {
//					playerY++; // ��ֹ��� ������ ���� ��ġ�� ���ư�
//				}
//			}
//			break;
//		case 's': // �Ʒ��� �̵�
//			if (playerY < 29) {
//				playerY++;
//				if (board[playerY][playerX] == '0') {
//					board[playerY][playerX] = '1';
//				}
//				else if (board[playerY][playerX] >= '1' && board[playerY][playerX] < '9') {
//					board[playerY][playerX]++;
//				}
//				else if (board[playerY][playerX] == 'X') {
//					playerY--; // ��ֹ��� ������ ���� ��ġ�� ���ư�
//				}
//			}
//			break;
//		case 'a': // �������� �̵�
//			if (playerX > 0) {
//				playerX--;
//				if (board[playerY][playerX] == '0') {
//					board[playerY][playerX] = '1';
//				}
//				else if (board[playerY][playerX] >= '1' && board[playerY][playerX] < '9') {
//					board[playerY][playerX]++;
//				}
//				else if (board[playerY][playerX] == 'X') {
//					playerX++; // ��ֹ��� ������ ���� ��ġ�� ���ư�
//				}
//			}
//			break;
//		case 'd': // ���������� �̵�
//			if (playerX < 29) {
//				playerX++;
//				if (board[playerY][playerX] == '0') {
//					board[playerY][playerX] = '1';
//				}
//				else if (board[playerY][playerX] >= '1' && board[playerY][playerX] < '9') {
//					board[playerY][playerX]++;
//				}
//				else if (board[playerY][playerX] == 'X') {
//					playerX--; // ��ֹ��� ������ ���� ��ġ�� ���ư�
//				}
//			}
//			break;
//		case 'r': // ����
//			playerX = playerY = 0;
//			for (int i = 0; i < 30; i++) {
//				for (int j = 0; j < 30; j++) {
//					board[i][j] = '0';
//				}
//			}
//			// ��ֹ� ���ġ
//			for (int i = 0; i < 4; i++) {
//				int obsX = rand() % 30;
//				int obsY = rand() % 30;
//				if (board[obsY][obsX] == '0' && !(obsX == playerX && obsY == playerY)) {
//					board[obsY][obsX] = 'X';
//				}
//				else {
//					i--; // �̹� ��ֹ��� �ְų� �÷��̾� ��ġ�� ��� �ٽ� �õ�
//				}
//			}
//			break;
//		case 'q': // ����
//			return 0;
//			break;
//		default:
//			printf("�ٽ� �Է�\n");
//			break;
//		}
//	}
//}