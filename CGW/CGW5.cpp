// ȭ�鿡 30x30ũ���� ���带 �׸���(30x30�� �� ĭ��.�� ��� ���带 ǥ���Ѵ�).����ڿ��� �簢���� �� ���� ��
// ǥ��(x1, y1) (x2, y2) ���� �Է� �޴´�.
// �� 2���� ������ �׸���, ��ɾ ���� ������ �̵�, Ȯ�� / ���, �� ��ǥ �������� Ȯ�� / ����Ͽ� �׸��� �� ����
// �� �浹�� üũ�Ѵ�.
// ������ �̵��ϴٰ� �� ������ �������� �Ǹ� �� �κ��� �ٸ� ������ ǥ���Ѵ�.
// �Է� ��ɾ� :
// x / X : x�� ���� / �������� �� ĭ �̵�(�����ڸ��� �����ص� ��� �̵��ϰ�, ���� ������ ������ �κ��� �ݴ��� ��Ÿ����.)
// y / Y : y�� �Ʒ��� / �������� �� ĭ �̵�(�����ڸ��� �����ص� ��� �̵��ϰ�, ���� ������ ������ �κ��� �ݴ��� ��Ÿ����.)
// s / S : x�� y ��� �� ĭ ��� / Ȯ��(������ �Ѿ�� ���� ���� �ȵ�)
// i / I : x�� �� ĭ Ȯ�� / ���
// j / J : y�� �� ĭ Ȯ�� / ���
// a / A : x�� �� ĭ Ȯ��, y�� �� ĭ ��� / x�� �� ĭ ���, y�� �� ĭ Ȯ��
// b : �簢���� ���� ���
// �� ��ɾ �� ������ ��� ������ �� �ֵ��� �� ��° ������ ���� ��ɾ ������ �����Ѵ�.
// c : ����ĭ�� x��, y�� ��� �� ĭ�� �ø���.�ִ� 10ĭ��ŭ �ø� �� �ִ�.
// d : ����ĭ�� x��, y�� ��� �� ĭ�� ���δ�.�ִ� 20ĭ��ŭ ���� �� �ִ�.������ ����ĭ ���� �־�� �Ѵ�.
// r : ��� ���� ���� �ϰ� �ٽ� ��ǥ ���� �Է� �޴´�.
// q : ���α׷� ����
// ���� ũ�� ���� ����, ��ɾ� Ű���� ���� ����


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

int boardsize = 30;

typedef struct {
	int x1; // ���� �� x��ǥ
	int y1; // ���� �� y��ǥ
	int x2; // ������ �Ʒ� x��ǥ
	int y2; // ������ �Ʒ� y��ǥ
} Rect;

int main() {
	char board[40][40];
	Rect rect1, rect2;
	char command;
	int selectedRect = 1; // 1 �Ǵ� 2
	
	
	printf("���� 1�� ���� ��� ��ǥ �Է� (x1, y1): ");
	scanf("%d %d", &rect1.x1, &rect1.y1);
	printf("���� 1�� ���� �ϴ� ��ǥ �Է� (x2, y2): ");
	scanf("%d %d", &rect1.x2, &rect1.y2);

	printf("���� 2�� ���� ��� ��ǥ �Է� (x1, y1): ");
	scanf("%d %d", &rect2.x1, &rect2.y1);
	printf("���� 2�� ���� �ϴ� ��ǥ �Է� (x2, y2): ");
	scanf("%d %d", &rect2.x2, &rect2.y2);

	while (1) {	
		// ���� �ʱ�ȭ
		for (int i = 0; i < boardsize; i++) {
			for (int j = 0; j < boardsize; j++) {
				board[i][j] = '.';
			}
		}

		for (int i = rect1.x1; i < rect1.x2; i++) {
			int xi = ((i % boardsize) + boardsize) % boardsize;
			for (int j = rect1.y1; j < rect1.y2; j++) {
				int yj = ((j % boardsize) + boardsize) % boardsize;
				board[yj][xi] = '1';
			}
		}

		for (int i = rect2.x1; i < rect2.x2; i++) {
			int xi = ((i % boardsize) + boardsize) % boardsize;
			for (int j = rect2.y1; j < rect2.y2; j++) {
				int yj = ((j % boardsize) + boardsize) % boardsize;
				if (board[yj][xi] == '1') board[yj][xi] = '#';
				else if (board[yj][xi] == '.') board[yj][xi] = '2';
			}
		}

		system("cls"); // ȭ�� �����
		// ���� ���
		for (int i = 0; i < boardsize; i++) {
			for (int j = 0; j < boardsize; j++) {
				if (board[i][j] == '#') {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				}
				else{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				printf("%c ", board[i][j]);
			}
			printf("\n");
		}
		
		printf("��ɾ� �Է�: ");
		scanf(" %c", &command);

		
		switch (command)
		{	
		case 'x': // x�� �������� �� ĭ �̵�
			printf("���� ���� : ");
			scanf(" %d", &selectedRect);
			if (selectedRect == 1) {
				rect1.x1 += 1;
				rect1.x2 += 1;
			}
			else if (selectedRect == 2) {
				rect2.x1 += 1;
				rect2.x2 += 1;
			}
			break;
		
		case 'X': // x�� �������� �� ĭ �̵�
			printf("���� ���� : ");
			scanf(" %d", &selectedRect);
			if (selectedRect == 1) {
				rect1.x1 -= 1;
				rect1.x2 -= 1;
			}
			else if (selectedRect == 2) {
				rect2.x1 -= 1;
				rect2.x2 -= 1;
			}
			break;
		case 'y': // y�� �Ʒ������� �� ĭ �̵�
			printf("���� ���� : ");
			scanf(" %d", &selectedRect);
			if (selectedRect == 1) {
				rect1.y1 += 1;
				rect1.y2 += 1;
			}
			else if (selectedRect == 2) {
				rect2.y1 += 1;
				rect2.y2 += 1;
			}
			break;
		
		case 'Y': // y�� �������� �� ĭ �̵�
			printf("���� ���� : ");
			scanf(" %d", &selectedRect);
			if (selectedRect == 1) {
				rect1.y1 -= 1;
				rect1.y2 -= 1;
			}
			else if (selectedRect == 2) {
				rect2.y1 -= 1;
				rect2.y2 -= 1;
			}
			break;
		case 's': // x�� y ��� �� ĭ ���
			printf("���� ���� : ");
			scanf(" %d", &selectedRect);
			if (selectedRect == 1) {
				rect1.x2 -= 1;
				rect1.y2 -= 1;
			}
			else if (selectedRect == 2) {
				rect2.x2 -= 1;
				rect2.y2 -= 1;
			}
			break;
		case 'S': // x�� y ��� �� ĭ Ȯ��
			printf("���� ���� : ");
			scanf(" %d", &selectedRect);
			if (selectedRect == 1) {
				rect1.x2 += 1;
				rect1.y2 += 1;
			}
			else if (selectedRect == 2) {
				rect2.x2 += 1;
				rect2.y2 += 1;
			}
			break;
		case 'i': // x�� �� ĭ Ȯ��
			printf("���� ���� : ");
			scanf(" %d", &selectedRect);
			if (selectedRect == 1)
				rect1.x2 += 1;
			else if (selectedRect == 2)
				rect2.x2 += 1;
			break;
		case 'I': // x�� �� ĭ ���
			printf("���� ���� : ");
			scanf(" %d", &selectedRect);
			if (selectedRect == 1)
				rect1.x2 -= 1;
			else if (selectedRect == 2)
				rect2.x2 -= 1;
			break;
		case 'j': // y�� �� ĭ Ȯ��
			printf("���� ���� : ");
			scanf(" %d", &selectedRect);
			if (selectedRect == 1)
				rect1.y2 += 1;
			else if (selectedRect == 2)
				rect2.y2 += 1;
			break;
		case 'J': // y�� �� ĭ ���
			printf("���� ���� : ");
			scanf(" %d", &selectedRect);
			if (selectedRect == 1)
				rect1.y2 -= 1;
			else if (selectedRect == 2)
				rect2.y2 -= 1;
			break;
		case 'a': // x�� �� ĭ Ȯ��, y�� �� ĭ ���
			printf("���� ���� : ");
			scanf(" %d", &selectedRect);
			if (selectedRect == 1) {
				rect1.x2 += 1;
				rect1.y2 -= 1;
			}
			else if (selectedRect == 2) {
				rect2.x2 += 1;
				rect2.y2 -= 1;
			}
			break;
		case 'A': // x�� �� ĭ ���, y�� �� ĭ Ȯ��
			printf("���� ���� : ");
			scanf(" %d", &selectedRect);
			if (selectedRect == 1) {
				rect1.x2 -= 1;
				rect1.y2 += 1;
			}
			else if (selectedRect == 2) {
				rect2.x2 -= 1;
				rect2.y2 += 1;
			}
			break;
		case 'b': // �簢���� ���� ���
			printf("���� ���� : ");
			scanf(" %d", &selectedRect);
			if (selectedRect == 1) {
				printf("�簢�� 1�� ����: %d\n", (rect1.x2 - rect1.x1)* (rect1.y2 - rect1.y1));
			}
			else if (selectedRect == 2) {
				printf("�簢�� 2�� ����: %d\n", (rect2.x2 - rect2.x1) * (rect2.y2 - rect2.y1));
			}
			break;
		case 'c': // ����ĭ�� x��, y�� ��� �� ĭ�� �ø���.�ִ� 10ĭ��ŭ �ø� �� �ִ�.
			if (boardsize < 40) {
				boardsize += 1;
			}
			else {
				printf("�� �̻� ���带 �ø� �� �����ϴ�.\n");
				Sleep(1000); // 1�� ���
			}
			break;
		case 'd': // ����ĭ�� x��, y�� ��� �� ĭ�� ���δ�.�ִ� 20ĭ��ŭ ���� �� �ִ�.������ ����ĭ ���� �־�� �Ѵ�.
			if (boardsize <= 20) {
				printf("�� �̻� ���带 ���� �� �����ϴ�.\n");
				Sleep(1000); // 1�� ���
				break;
			}
			if (rect1.x2 > boardsize - 1 || rect1.y2 > boardsize - 1 || rect2.x2 > boardsize - 1 || rect2.y2 > boardsize - 1) {
				printf("������ ���� ������ ������ �˴ϴ�. ���带 ���� �� �����ϴ�.\n");
				Sleep(1000); // 1�� ���
			}
			else {
				boardsize -= 1;
			}
			
			break;
		case 'r': // ��� ���� ���� �ϰ� �ٽ� ��ǥ ���� �Է� �޴´�.
			boardsize = 30;
			rect1.x1 = rect1.y1 = rect1.x2 = rect1.y2 = 0;
			printf("���� 1�� ���� ��� ��ǥ �Է� (x1, y1): ");
			scanf("%d %d", &rect1.x1, &rect1.y1);
			printf("���� 1�� ���� �ϴ� ��ǥ �Է� (x2, y2): ");
			scanf("%d %d", &rect1.x2, &rect1.y2);
			printf("���� 2�� ���� ��� ��ǥ �Է� (x1, y1): ");
			scanf("%d %d", &rect2.x1, &rect2.y1);
			printf("���� 2�� ���� �ϴ� ��ǥ �Է� (x2, y2): ");
			scanf("%d %d", &rect2.x2, &rect2.y2);
			break;
		case 'q': // ���α׷� ����
			return 0;
			break;
		default:
			printf("�ٽ� �Է����ּ���.\n");
			break;
		}
	}

}