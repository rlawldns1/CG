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
//	//���� �̸� �Է¹ޱ�
//	printf("���� �̸� �Է� : ");
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
//		case 'a': // ��� ���� �빮�ڷ� ���� - ���
//			a = !a;
//			rewind(fs);
//			for (int i = 0; i < 10; i++) {
//				if (fgets(str, sizeof(str), fs)) {
//					if (a) {
//						// �빮�ڷ� ��ȯ�ؼ� ���
//						for (int j = 0; str[j] != '\0'; j++) {
//							str[j] = toupper(str[j]);
//						}
//						printf("%s", str);
//					}
//					else {
//						// ���� �״�� ���
//						printf("%s", str);
//					}
//				}
//			}
//			break;
//		case 'b': // �� ���� �ܾ� ���� ���
//			rewind(fs);
//			for (int i = 0; i < 10; i++) {
//				if (!fgets(str, sizeof(str), fs)) break; // �� �б� ���� �� ����
//
//				wordcnt = 0;
//				for (int j = 0; str[j] != '\0'; j++) {
//					if (str[j] == ' ')
//						wordcnt++;
//				}
//				// �ܾ� �� = ���� �� + 1 (��, �� ���� 0)
//				if (strlen(str) > 1) wordcnt++;
//
//				// ���� ����
//				str[strcspn(str, "\n")] = '\0';
//
//				printf("%s (�ܾ� ��: %d)\n", str, wordcnt);
//			}
//			break;
//		case 'c': // �빮�ڷ� ���۵� �ܾ� ã�� �ٸ������� ��� �� ���� ��� - ���
//			c = !c;
//			rewind(fs);
//			for (int i = 0; i < 10; i++) {
//				if (!fgets(str, sizeof(str), fs)) break; // �� �б� ���� �� ����
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
//				printf("(�빮�� ���� �ܾ� ��: %d)\n", capitalwordcnt);
//			}
//			break;
//		case 'd': // ���� �Ųٷ� ��� - ���
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
//		case 'e': // ��� ���鿡 /���� - ���
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
//		case 'f': // ���� ���� ��� �ܾ� �Ųٷ� ��� - ���
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
//		case 'g': // ���� ���� Ư�� ���ڸ� �ٸ� ���ڷ� ���� (�ٲ� ����, �Է� ���� �Է¹ޱ�) - ���
//		{
//			g = !g;
//			char oldChar, newChar;
//			printf("�ٲ� ���� �Է�: ");
//			scanf(" %c", &oldChar);
//			printf("�Է� ���� �Է�: ");
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
//		case 'h': // ���忡 ���� ã�� ���� �� ������ ���� �ٷ� �ѱ� - ���
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
//		case 'i': // �� ������ ���ĺ��� ������ ���� �����Ͽ� ���� ��� - ��������-> �������� -> ������� �������
//			break;
//		case 'j': // ��ɾ�� �ܾ �Է��ϸ� �ܾ ã�� �ٸ������� ��� �� ���� ��� - ��ҹ��� ����X
//			rewind(fs);
//			char searchWord[20];
//			printf("ã�� �ܾ� �Է�: ");
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
//				printf("(�ܾ� '%s' ����: %d)\n", searchWord, count);
//			}
//			break;
//		case 'q': // ���α׷� ����
//			return 0;
//		}
//	}
//}