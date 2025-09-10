// 화면에 30x30크기의 보드를 그린다(30x30의 각 칸에.을 찍어 보드를 표현한다).사용자에게 사각형의 두 개의 좌
// 표값(x1, y1) (x2, y2) 값을 입력 받는다.
// 총 2개의 도형을 그리고, 명령어에 따라 도형을 이동, 확대 / 축소, 한 좌표 측으로의 확대 / 축소하여 그리고 두 도형
// 의 충돌도 체크한다.
// 도형을 이동하다가 두 도형이 겹쳐지게 되면 그 부분을 다른 색으로 표시한다.
// 입력 명령어 :
// x / X : x축 우측 / 좌측으로 한 칸 이동(가장자리에 도달해도 계속 이동하고, 보드 밖으로 나가는 부분은 반대편에 나타난다.)
// y / Y : y축 아래쪽 / 위쪽으로 한 칸 이동(가장자리에 도달해도 계속 이동하고, 보드 밖으로 나가는 부분은 반대편에 나타난다.)
// s / S : x와 y 모두 한 칸 축소 / 확대(범위를 넘어가는 축은 변경 안됨)
// i / I : x축 한 칸 확대 / 축소
// j / J : y축 한 칸 확대 / 축소
// a / A : x축 한 칸 확대, y축 한 칸 축소 / x축 한 칸 축소, y축 한 칸 확대
// b : 사각형의 면적 출력
// 위 명령어를 두 도형에 모두 적용할 수 있도록 두 번째 도형에 대한 명령어를 스스로 설정한다.
// c : 보드칸을 x축, y축 모두 한 칸씩 늘린다.최대 10칸만큼 늘릴 수 있다.
// d : 보드칸을 x축, y축 모두 한 칸씩 줄인다.최대 20칸만큼 줄일 수 있다.도형은 보드칸 내에 있어야 한다.
// r : 모든 것을 리셋 하고 다시 좌표 값을 입력 받는다.
// q : 프로그램 종료
// 보드 크기 변경 가능, 명령어 키보드 변경 가능


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

int boardsize = 30;

typedef struct {
	int x1; // 왼쪽 위 x좌표
	int y1; // 왼쪽 위 y좌표
	int x2; // 오른쪽 아래 x좌표
	int y2; // 오른쪽 아래 y좌표
} Rect;

int main() {
	char board[40][40];
	Rect rect1, rect2;
	char command;
	int selectedRect = 1; // 1 또는 2
	
	
	printf("도형 1의 좌측 상단 좌표 입력 (x1, y1): ");
	scanf("%d %d", &rect1.x1, &rect1.y1);
	printf("도형 1의 우측 하단 좌표 입력 (x2, y2): ");
	scanf("%d %d", &rect1.x2, &rect1.y2);

	printf("도형 2의 좌측 상단 좌표 입력 (x1, y1): ");
	scanf("%d %d", &rect2.x1, &rect2.y1);
	printf("도형 2의 우측 하단 좌표 입력 (x2, y2): ");
	scanf("%d %d", &rect2.x2, &rect2.y2);

	while (1) {	
		// 보드 초기화
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

		system("cls"); // 화면 지우기
		// 보드 출력
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
		
		printf("명령어 입력: ");
		scanf(" %c", &command);

		
		switch (command)
		{	
		case 'x': // x축 우측으로 한 칸 이동
			printf("도형 선택 : ");
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
		
		case 'X': // x축 좌측으로 한 칸 이동
			printf("도형 선택 : ");
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
		case 'y': // y축 아래쪽으로 한 칸 이동
			printf("도형 선택 : ");
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
		
		case 'Y': // y축 위쪽으로 한 칸 이동
			printf("도형 선택 : ");
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
		case 's': // x와 y 모두 한 칸 축소
			printf("도형 선택 : ");
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
		case 'S': // x와 y 모두 한 칸 확대
			printf("도형 선택 : ");
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
		case 'i': // x축 한 칸 확대
			printf("도형 선택 : ");
			scanf(" %d", &selectedRect);
			if (selectedRect == 1)
				rect1.x2 += 1;
			else if (selectedRect == 2)
				rect2.x2 += 1;
			break;
		case 'I': // x축 한 칸 축소
			printf("도형 선택 : ");
			scanf(" %d", &selectedRect);
			if (selectedRect == 1)
				rect1.x2 -= 1;
			else if (selectedRect == 2)
				rect2.x2 -= 1;
			break;
		case 'j': // y축 한 칸 확대
			printf("도형 선택 : ");
			scanf(" %d", &selectedRect);
			if (selectedRect == 1)
				rect1.y2 += 1;
			else if (selectedRect == 2)
				rect2.y2 += 1;
			break;
		case 'J': // y축 한 칸 축소
			printf("도형 선택 : ");
			scanf(" %d", &selectedRect);
			if (selectedRect == 1)
				rect1.y2 -= 1;
			else if (selectedRect == 2)
				rect2.y2 -= 1;
			break;
		case 'a': // x축 한 칸 확대, y축 한 칸 축소
			printf("도형 선택 : ");
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
		case 'A': // x축 한 칸 축소, y축 한 칸 확대
			printf("도형 선택 : ");
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
		case 'b': // 사각형의 면적 출력
			printf("도형 선택 : ");
			scanf(" %d", &selectedRect);
			if (selectedRect == 1) {
				printf("사각형 1의 면적: %d\n", (rect1.x2 - rect1.x1)* (rect1.y2 - rect1.y1));
			}
			else if (selectedRect == 2) {
				printf("사각형 2의 면적: %d\n", (rect2.x2 - rect2.x1) * (rect2.y2 - rect2.y1));
			}
			break;
		case 'c': // 보드칸을 x축, y축 모두 한 칸씩 늘린다.최대 10칸만큼 늘릴 수 있다.
			if (boardsize < 40) {
				boardsize += 1;
			}
			else {
				printf("더 이상 보드를 늘릴 수 없습니다.\n");
				Sleep(1000); // 1초 대기
			}
			break;
		case 'd': // 보드칸을 x축, y축 모두 한 칸씩 줄인다.최대 20칸만큼 줄일 수 있다.도형은 보드칸 내에 있어야 한다.
			if (boardsize <= 20) {
				printf("더 이상 보드를 줄일 수 없습니다.\n");
				Sleep(1000); // 1초 대기
				break;
			}
			if (rect1.x2 > boardsize - 1 || rect1.y2 > boardsize - 1 || rect2.x2 > boardsize - 1 || rect2.y2 > boardsize - 1) {
				printf("도형이 보드 밖으로 나가게 됩니다. 보드를 줄일 수 없습니다.\n");
				Sleep(1000); // 1초 대기
			}
			else {
				boardsize -= 1;
			}
			
			break;
		case 'r': // 모든 것을 리셋 하고 다시 좌표 값을 입력 받는다.
			boardsize = 30;
			rect1.x1 = rect1.y1 = rect1.x2 = rect1.y2 = 0;
			printf("도형 1의 좌측 상단 좌표 입력 (x1, y1): ");
			scanf("%d %d", &rect1.x1, &rect1.y1);
			printf("도형 1의 우측 하단 좌표 입력 (x2, y2): ");
			scanf("%d %d", &rect1.x2, &rect1.y2);
			printf("도형 2의 좌측 상단 좌표 입력 (x1, y1): ");
			scanf("%d %d", &rect2.x1, &rect2.y1);
			printf("도형 2의 우측 하단 좌표 입력 (x2, y2): ");
			scanf("%d %d", &rect2.x2, &rect2.y2);
			break;
		case 'q': // 프로그램 종료
			return 0;
			break;
		default:
			printf("다시 입력해주세요.\n");
			break;
		}
	}

}