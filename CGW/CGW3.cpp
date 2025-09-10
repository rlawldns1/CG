#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef struct point {
    int x; int y; int z;
} point;

void zeropoint(point* p) { p->x = 0; p->y = 0; p->z = 0; }

long long dist(point p) {
    double d = sqrt((double)p.x * p.x + (double)p.y * p.y + (double)p.z * p.z);
    return (long long)d;
}

void printlist(point p[], bool used[]) {
    int filled = 0;
    for (int i = 0; i < 10; i++) if (used[i]) filled++;
    if (filled == 0) { printf("리스트가 비어있습니다.\n"); return; }

    for (int i = 0; i < 10; i++) {
        if (used[i]) printf("%d : (%d, %d, %d)\n", i, p[i].x, p[i].y, p[i].z);
        else        printf("%d : \n", i);
    }
}

int main() {

    point p[10] = { 0 }, backup[10] = { 0 };
    bool  used[10] = { 0 }, used_backup[10] = { 0 };
    int n = 0;
    int sorted = 0;
    char command;

    while (1) {
        printf("Command : ");
        if (scanf(" %c", &command) != 1) break;

        switch (command) {
        case '+': {
            if (n >= 10) { printf("가득 찼습니다.\n"); break; }
            int idx = -1;
            for (int i = 9; i >= 0; i--) if (!used[i]) { idx = i; break; }
            printf("x, y, z 좌표 입력: ");
            scanf("%d %d %d", &p[idx].x, &p[idx].y, &p[idx].z);
            used[idx] = true; n++; sorted = 0;
            printlist(p, used);
        } break;

        case 'e': {
            if (n >= 10) { printf("가득 찼습니다.\n"); break; }
            int idx = -1;
            for (int i = 0; i < 10; i++) if (!used[i]) { idx = i; break; }
            printf("x, y, z 좌표 입력: ");
            scanf("%d %d %d", &p[idx].x, &p[idx].y, &p[idx].z);
            used[idx] = true; n++; sorted = 0;
            printlist(p, used);
        } break;

        case '-': {
            if (n == 0) { printf("비어 있습니다.\n"); break; }
            int idx = -1;
            for (int i = 9; i >= 0; i--) if (used[i]) { idx = i; break; }
            zeropoint(&p[idx]); used[idx] = false; n--; sorted = 0;
            printlist(p, used);
        } break;

        case 'd': {
            if (n == 0) {
                printf("비어 있습니다.\n");
                break;
            }
            int idx = -1;
            for (int i = 0; i < 10; i++) {
                if (used[i]) { idx = i; break; }
            }

            if (idx == -1) {
                printf("비어 있습니다.\n");
                break;
            }

            zeropoint(&p[idx]);
            used[idx] = false;
            n--;
            sorted = 0;
            printlist(p, used);
        } break;


        case 'a':
            printf("점의 개수: %d\n", n);
            break;

        case 'b': {
            point temp = p[0];      // p[0] 임시 저장
            bool temp_used = used[0];

            for (int i = 0; i < 9; i++) {
                p[i] = p[i + 1];
                used[i] = used[i + 1];
            }

            p[9] = temp;           // p[0]을 p[9]로 이동
            used[9] = temp_used;

            sorted = 0;
            printlist(p, used);
            break;
        }

        case 'c':
            for (int i = 0; i < 10; i++) { if (used[i]) zeropoint(&p[i]); used[i] = false; }
            n = 0; sorted = 0; printlist(p, used);
            break;

        case 'f': {
            if (!sorted) {

                for (int i = 0; i < 10; i++) { backup[i] = p[i]; used_backup[i] = used[i]; }


                point tmp[10]; int idxs[10]; int m = 0;
                for (int i = 0; i < 10; i++) if (used[i]) { tmp[m] = p[i]; idxs[m] = i; m++; }


                for (int i = 1; i < m; i++) {
                    point key = tmp[i]; long long k2 = dist(key); int j = i - 1;
                    while (j >= 0 && dist(tmp[j]) > k2) { tmp[j + 1] = tmp[j]; j--; }
                    tmp[j + 1] = key;
                }

                int put = 0;
                for (int i = 0; i < 10; i++) if (used[i]) { p[i] = tmp[put++]; }

                sorted = 1; printf("[정렬 O]\n");
            }
            else {

                for (int i = 0; i < 10; i++) { p[i] = backup[i]; used[i] = used_backup[i]; }

                n = 0; for (int i = 0; i < 10; i++) if (used[i]) n++;
                sorted = 0; printf("[정렬 X]\n");
            }
            printlist(p, used);
        } break;

        case 'q': return 0;

        default: printf("다시 입력\n"); break;
        }
    }
    return 0;
}
