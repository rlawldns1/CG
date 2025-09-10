//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdbool.h>
//#include <ctype.h>
//#include <string.h>
//#include <stdlib.h>
//#include <Windows.h>
//
//int main() {
//	char command;
//	char filename[20];
//	bool a = false;
//	bool c = false;
//	bool d = false;
//	bool e = false;
//	bool f = false;
//	bool g = false;
//	bool h = false;
//	int wordcnt = 0;
//	int capitalwordcnt = 0;
//	//파일 이름 입력받기
//	printf("파일 이름 입력 : ");
//	scanf(" %s", &filename);
//
//	FILE* fs;
//	fs = fopen(filename, "r");
//
//	char str[100] = {};
//	for (int i = 0; i < 10; i++) {
//		fgets(str, 100, fs);
//		printf("%s", str);
//	}
//
//	while (1) {
//		printf("Command : ");
//		scanf(" %c", &command);
//
//		switch (command)
//		{
//		case 'a': // 모든 문장 대문자로 변경 - 토글
//			a = !a;
//			rewind(fs);
//			for (int i = 0; i < 10; i++) {
//				if (fgets(str, sizeof(str), fs)) {
//					if (a) {
//						// 대문자로 변환해서 출력
//						for (int j = 0; str[j] != '\0'; j++) {
//							str[j] = toupper(str[j]);
//						}
//						printf("%s", str);
//					}
//					else {
//						// 원래 그대로 출력
//						printf("%s", str);
//					}
//				}
//			}
//			break;
//		case 'b': // 각 줄의 단어 갯수 출력
//			rewind(fs);
//			for (int i = 0; i < 10; i++) {
//				if (!fgets(str, sizeof(str), fs)) break; // 줄 읽기 실패 시 종료
//
//				wordcnt = 0;
//				for (int j = 0; str[j] != '\0'; j++) {
//					if (str[j] == ' ')
//						wordcnt++;
//				}
//				// 단어 수 = 공백 수 + 1 (단, 빈 줄은 0)
//				if (strlen(str) > 1) wordcnt++;
//
//				// 개행 제거
//				str[strcspn(str, "\n")] = '\0';
//
//				printf("%s (단어 수: %d)\n", str, wordcnt);
//			}
//			break;
//		case 'c': // 대문자로 시작된 단어 찾아 다른색으로 출력 및 갯수 출력 - 토글
//			c = !c;
//			rewind(fs);
//			for (int i = 0; i < 10; i++) {
//				if (!fgets(str, sizeof(str), fs)) break; // 줄 읽기 실패 시 종료
//				capitalwordcnt = 0;
//				for (int j = 0; str[j] != '\0'; j++) {
//					if (isupper(str[j]) && (j == 0 || str[j - 1] == ' ')) {
//						capitalwordcnt++;
//						if(c) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
//						int k;
//						for (k = j; str[k] != '\0' && str[k] != ' '; k++) {
//							printf("%c", str[k]);
//						}
//						if (c) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//						j = k - 1;
//					}
//					
//					else {
//						printf("%c", str[j]);
//					}
//				}
//				printf("(대문자 시작 단어 수: %d)\n", capitalwordcnt);
//			}
//			break;
//		case 'd': // 문장 거꾸로 출력 - 토글
//			d = !d;
//			rewind(fs);
//			for (int i = 0; i < 10; i++) {
//				if (fgets(str, sizeof(str), fs)) {
//					if (d) {
//						int len = strlen(str);
//						for (int j = len - 1; j >= 0; j--) {
//							printf("%c", str[j]);
//						}
//					}
//					else {
//						printf("%s", str);
//					}
//				}
//			}
//			printf("\n");
//			break;
//		case 'e': // 모든 공백에 /삽입 - 토글
//			e = !e;
//			rewind(fs);
//			for (int i = 0; i < 10; i++) {
//				if (fgets(str, sizeof(str), fs)) {
//					if (e) {
//						for (int j = 0; str[j] != '\0'; j++) {
//							if (str[j] == ' ')
//								printf("/");
//							else
//								printf("%c", str[j]);
//						}
//					}
//					else {
//						printf("%s", str);
//					}
//				}
//			}
//			break;
//		case 'f': // 공백 기준 모든 단어 거꾸로 출력 - 토글
//			f = !f;
//			rewind(fs);
//			for (int i = 0; i < 10; i++) {
//				if (!fgets(str, sizeof(str), fs)) break;
//
//				for (int j = 0; str[j] != '\0'; ) {
//					
//					if (str[j] == ' ') {
//						printf("%c", str[j]);
//						j++;
//					}
//					else {
//						
//						int s = j;
//						while (str[j] != '\0' && str[j]!=' ') j++;
//						
//						for (int k = j - 1; k >= s; k--) {
//							printf("%c", str[k]);
//						}
//					}
//				}
//			}
//			break;
//		case 'g': // 문장 내부 특정 문자를 다른 문자로 변경 (바꿀 문자, 입력 문자 입력받기) - 토글
//		{
//			g = !g;
//			char oldChar, newChar;
//			printf("바꿀 문자 입력: ");
//			scanf(" %c", &oldChar);
//			printf("입력 문자 입력: ");
//			scanf(" %c", &newChar);
//			rewind(fs);
//			for (int i = 0; i < 10; i++) {
//				if (fgets(str, sizeof(str), fs)) {
//					for (int j = 0; str[j] != '\0'; j++) {
//						if (str[j] == oldChar)
//							printf("%c", newChar);
//						else
//							printf("%c", str[j]);
//					}
//				}
//			}
//		}
//			break;
//		case 'h': // 문장에 숫자 찾아 숫자 뒤 문장을 다음 줄로 넘김 - 토글
//			h = !h;
//			rewind(fs);	
//			for (int i = 0; i < 10; i++) {
//				if (fgets(str, sizeof(str), fs)) {
//					if (h) {
//						for (int j = 0; str[j] != '\0'; j++) {
//							printf("%c", str[j]);
//							if (isdigit(str[j])) {
//								printf("\n");
//							}
//						}
//					}
//					else {
//						printf("%s", str);
//					}
//				}
//			}
//			break;
//		case 'i': // 한 문장을 알파벳의 개수에 따라 정렬하여 문자 출력 - 오름차순-> 내림차순 -> 원래대로 토글형식
//			break;
//		case 'j': // 명령어와 단어를 입력하면 단어를 찾아 다른색으로 출력 및 개수 계산 - 대소문자 구분X
//			rewind(fs);
//			char searchWord[20];
//			printf("찾을 단어 입력: ");
//			scanf(" %s", &searchWord);
//			for (int i = 0; i < 10; i++) {
//				if (!fgets(str, sizeof(str), fs)) break;
//				char tempStr[100];
//				strcpy(tempStr, str);
//				char* token = strtok(tempStr, " \n");
//				int count = 0;
//				while (token != NULL) {
//					if (_stricmp(token, searchWord) == 0) {
//						count++;
//					}
//					token = strtok(NULL, " \n");
//				}
//				for (int j = 0; str[j] != '\0'; j++) {
//					if ((j == 0 || str[j - 1] == ' ' || str[j - 1] == '\n') && _strnicmp(&str[j], searchWord, strlen(searchWord)) == 0 && (str[j + strlen(searchWord)] == ' ' || str[j + strlen(searchWord)] == '\n' || str[j + strlen(searchWord)] == '\0')) {
//						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//						printf("%s", searchWord);
//						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//						j += strlen(searchWord) - 1;
//					}
//					else {
//						printf("%c", str[j]);
//					}
//				}
//				printf("(단어 '%s' 개수: %d)\n", searchWord, count);
//			}
//			break;
//		case 'q': // 프로그램 종료
//			return 0;
//		}
//	}
//}