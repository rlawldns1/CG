//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>	
//#include <stdbool.h>
//
//int det(int m1[4][4]) {
//	int d = 0;
//	d += m1[0][0] * (
//		(m1[1][1] * m1[2][2] * m1[3][3] +
//			m1[1][2] * m1[2][3] * m1[3][1] +
//			m1[1][3] * m1[2][1] * m1[3][2])
//		- (m1[1][3] * m1[2][2] * m1[3][1] +
//			m1[1][1] * m1[2][3] * m1[3][2] +
//			m1[1][2] * m1[2][1] * m1[3][3])
//		);
//	d -= m1[0][1] * (
//		(m1[1][0] * m1[2][2] * m1[3][3] +
//			m1[1][2] * m1[2][3] * m1[3][0] +
//			m1[1][3] * m1[2][0] * m1[3][2])
//		- (m1[1][3] * m1[2][2] * m1[3][0] +
//			m1[1][0] * m1[2][3] * m1[3][2] +
//			m1[1][2] * m1[2][0] * m1[3][3])
//		);
//	d += m1[0][2] * (
//		(m1[1][0] * m1[2][1] * m1[3][3] +
//			m1[1][1] * m1[2][3] * m1[3][0] +
//			m1[1][3] * m1[2][0] * m1[3][1])
//		- (m1[1][3] * m1[2][1] * m1[3][0] +
//			m1[1][0] * m1[2][3] * m1[3][1] +
//			m1[1][1] * m1[2][0] * m1[3][3])
//		);
//	d -= m1[0][3] * (
//		(m1[1][0] * m1[2][1] * m1[3][2] +
//			m1[1][1] * m1[2][2] * m1[3][0] +
//			m1[1][2] * m1[2][0] * m1[3][1])
//		- (m1[1][2] * m1[2][1] * m1[3][0] +
//			m1[1][0] * m1[2][2] * m1[3][1] +
//			m1[1][1] * m1[2][0] * m1[3][2])
//		);
//	return d;
//}
//
//int main() {
//	srand(time(NULL));
//	int m1[4][4], m2[4][4];
//	int m3[4][4] = { 0 };
//	int m1minm[4][4], m2minm[4][4];
//	int m1maxm[4][4], m2maxm[4][4];
//	char command; // 명령어
//	bool e = false;
//	bool f = false;
//	int m1min = 0, m2min =0;
//	int m1max = 0, m2max =0;
//	int m1det = 0;
//	int m2det = 0;
//	bool num = false;
//	int sel = 0;
//	//m1 첫번째 행렬, m2 두번째 행렬, m3	결과값 행렬
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++) {
//			m1[i][j] = rand() % 9 + 1;
//			m2[i][j] = rand() % 9 + 1;
//		}
//	}
//
//
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++) {
//			printf("%d ", m1[i][j]);
//		}
//		printf("\t");
//		for (int j = 0; j < 4; j++) {
//			printf("%d ", m2[i][j]);
//		}
//		printf("\n");
//	}
//
//	while (1) {
//		printf("Command : ");
//		scanf(" %c", &command);
//
//		if (command >= '1' && command <= '9') {
//			int v = command - '0';
//			if (num && sel == v) {
//				num = false;
//			}
//			else {
//				num = true;
//				sel = v;
//			}
//
//			for (int i = 0; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {
//					if (!num || m1[i][j] % sel == 0) printf("%d ", m1[i][j]);
//					else                               printf("- ");
//				}
//				printf("\t");
//				for (int j = 0; j < 4; j++) {
//					if (!num || m2[i][j] % sel == 0) printf("%d ", m2[i][j]);
//					else                               printf("- ");
//				}
//				printf("\n");
//			}
//			continue;
//		}
//		switch (command)
//		{
//		case 'm': //행렬 곱셈
//			for (int i = 0; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {
//					m3[i][j] = 0;
//				}
//			}
//
//			for (int i = 0; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {
//					for (int k = 0; k < 4; k++) {
//						m3[i][j] += m1[i][k] * m2[k][j];
//					}
//				}
//			}
//			for (int i = 0; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {
//					printf("%d ", m3[i][j]);
//				}
//				printf("\n");
//			}
//			break;
//		case 'a': // 행렬 덧셈
//			for (int i = 0; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {
//					m3[i][j] = m1[i][j] + m2[i][j];
//				}
//			}
//			for (int i = 0; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {	
//					printf("%d ", m3[i][j]);
//				}
//				printf("\n");
//			}
//			break;
//		case 'd': // 행렬 뺄셈
//			for (int i = 0; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {
//					m3[i][j] = m1[i][j] - m2[i][j];
//				}
//			}
//			for (int i = 0; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {
//					printf("%d ", m3[i][j]);
//				}
//				printf("\n");
//			}
//			break;
//		case 'r': // 행렬식의 값
//			m1det = 0;
//			m2det = 0;
//			m1det = det(m1);
//			m2det = det(m2);
//			
//			printf("%d\t", m1det);
//			printf("%d\n", m2det);
//			break;
//		case 't': // 전치행렬
//			for (int i = 0; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {
//					printf("%d ", m1[j][i]);
//				}
//				printf("\t");
//				for (int j = 0; j < 4; j++) {
//					printf("%d ", m2[j][i]);
//				}
//				printf("\n");
//			}
//			m1det = 0;
//			m2det = 0;
//			m1det = det(m1);
//			m2det = det(m2);
//
//			printf("%d\t", m1det);
//			printf("%d\n", m2det);
//			break;
//		case 'e': // 최소값 빼기
//			e = !e;
//			m1min = m1[0][0];
//			for (int i = 0; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {
//					if (m1min > m1[i][j]) {
//						m1min = m1[i][j];
//					}
//				}
//			}
//			m2min = m2[0][0];
//			for (int i = 0; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {
//					if (m2min > m2[i][j]) {
//						m2min = m2[i][j];
//					}
//				}
//			}
//			if (e) {
//				for (int i = 0; i < 4; i++) {
//					for (int j = 0; j < 4; j++) {
//						printf("%d ", m1[i][j]-m1min);
//					}
//					printf("\t");
//					for (int j = 0; j < 4; j++) {
//						printf("%d ", m2[i][j] - m2min);
//					}
//					printf("\n");
//				}
//			}
//			else {
//				for (int i = 0; i < 4; i++) {
//					for (int j = 0; j < 4; j++) {
//						printf("%d ", m1[i][j]);
//					}
//					printf("\t");
//					for (int j = 0; j < 4; j++) {
//						printf("%d ", m2[i][j]);
//					}
//					printf("\n");
//				}
//			}
//			break;
//		case 'f': // 최대값 더하기
//			f = !f;
//			m1max = m1[0][0];
//			for (int i = 0; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {
//					if (m1max < m1[i][j]) {
//						m1max = m1[i][j];
//					}
//				}
//			}
//			m2max = m2[0][0];
//			for (int i = 0; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {
//					if (m2max < m2[i][j]) {
//						m2max = m2[i][j];
//					}
//				}
//			}
//			if (f) {
//				for (int i = 0; i < 4; i++) {
//					for (int j = 0; j < 4; j++) {
//						printf("%d ", m1[i][j] + m1max);
//					}
//					printf("\t");
//					for (int j = 0; j < 4; j++) {
//						printf("%d ", m2[i][j] + m2max);
//					}
//					printf("\n");
//				}
//			}
//			else {
//				for (int i = 0; i < 4; i++) {
//					for (int j = 0; j < 4; j++) {
//						printf("%d ", m1[i][j]);
//					}
//					printf("\t");
//					for (int j = 0; j < 4; j++) {
//						printf("%d ", m2[i][j]);
//					}
//					printf("\n");
//				}
//			}
//			break;
//		case 's': //재설정
//			for (int i = 0; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {
//					m1[i][j] = rand() % 9 + 1;
//					m2[i][j] = rand() % 9 + 1;
//				}
//			}
//			for (int i = 0; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {
//					printf("%d ", m1[i][j]);
//				}
//				printf("\t");
//				for (int j = 0; j < 4; j++) {
//					printf("%d ", m2[i][j]);
//				}
//				printf("\n");
//			}
//			break;
//		case 'q': // 프로그램 종료
//			return 0;
//		}
//	}
//}
//
