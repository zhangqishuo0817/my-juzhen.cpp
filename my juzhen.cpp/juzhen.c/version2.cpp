
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int **data;
} jz;

jz* createjz(int row, int col) {
    jz* myjz = (jz*)malloc(sizeof(jz));
    myjz->row = row;
    myjz->col = col;
    myjz->data = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) {
        myjz->data[i] = (int *)malloc(col * sizeof(int));
        for (int j = 0; j < col; j++) {
            myjz->data[i][j] = 0;
        }
    }
    return myjz;
}

jz* add(jz* m1, jz* m2) {
    if (m1->row != m2->row || m1->col != m2->col) {
        printf("ֻ����ά����ͬ����\n");
        exit(1);
    }
    jz* result = createjz(m1->row, m1->col);
    for (int i = 0; i < m1->row; i++) {
        for (int j = 0; j < m1->col; j++) {
            result->data[i][j] = m1->data[i][j] + m2->data[i][j];
        }
    }
    return result;
}

jz* minus(jz* m1, jz* m2) {
    if (m1->row != m2->row || m1->col != m2->col) {
        printf("ֻ����ά����ͬ����\n");
        exit(1);
    }
    jz* result = createjz(m1->row, m1->col); 
    for (int i = 0; i < m1->row; i++) {
        for (int j = 0; j < m1->col; j++) {
            result->data[i][j] = m1->data[i][j] - m2->data[i][j];
        }
    }
    return result;
}

jz* shucheng(int n, jz* m) {
    jz* result = createjz(m->row, m->col);
    for (int i = 0; i < m->row; i++) {
        for (int j = 0; j < m->col; j++) {
            result->data[i][j] = m->data[i][j] * n;
        }
    }
    return result;
}

jz* multiple(jz* m1, jz* m2) {
    if (m1->col != m2->row) {
        printf("ֻ����һ�������������һ�������������ͬ�����\n");
        exit(1);
    }
    jz* result = createjz(m1->row, m2->col);
    for (int i = 0; i < m1->row; i++) {
        for (int j = 0; j < m2->col; j++) {
            result->data[i][j] = 0; 
            for (int k = 0; k < m1->col; k++) {
                result->data[i][j] += m1->data[i][k] * m2->data[k][j];
            }
        }
    }
    return result;
}

void printjz(jz* m) {
    for (int i = 0; i < m->row; i++) {
        for (int j = 0; j < m->col; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

void freejz(jz* m) {
    for (int i = 0; i < m->row; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

void inputjz(jz* m) {
    printf("��������Ԫ��:\n");
    for (int i = 0; i < m->row; i++) {
        for (int j = 0; j < m->col; j++) {
            printf("Ԫ�� [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &m->data[i][j]);
        }
    }
}
int main() {
    int r1, c1, r2, c2;
    int choice;
    jz* m1, *m2, *result;

    // ��һ������
    printf("�����һ�����������������: ");
    scanf("%d %d", &r1, &c1);
    m1 = createjz(r1, c1);
    inputjz(m1);
    printjz(m1); 

    // �ڶ�������
    printf("����ڶ������������������: ");
    scanf("%d %d", &r2, &c2);
    m2 = createjz(r2, c2);
    inputjz(m2);
    printjz(m2); 

    // �û����� 
    do {
        printf("\nѡ�����:\n");
        printf("1. �ӷ�\n");
        printf("2. ����\n");
        printf("3. ����\n");
        printf("4. �˷�\n");
        printf("5. �˳�\n");
        printf("�������ѡ��: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (r1 == r2 && c1 == c2) {
                    result = add(m1, m2);
                    printjz(result); 
                    freejz(result); 
                } else {
                    printf("ά�Ȳ�ƥ�䡣\n");
                }
                break;
            case 2:
                if (r1 == r2 && c1 == c2) {
                    result = minus(m1, m2);
                    printjz(result); 
                    freejz(result); 
                } else {
                    printf("ά�Ȳ�ƥ��\n");
                }
                break;
            case 3: {
                int n;
                printf("����һ����: ");
                scanf("%d", &n);
                result = shucheng(n, m1);
                printjz(result); 
                freejz(result); 
                break;
            }
            case 4:
                if (r1 == m2->row && c1 == m2->col) { 
                    result = multiple(m1, m2);
                    printjz(result); 
                    freejz(result); 
                } else {
                    printf("ά�Ȳ�ƥ�䡣\n");
                }
                break;
            case 5:
                break;
            default:
                printf("�������������롣\n");
        }
    } while (choice != 5);

    // �ͷž����ڴ�
    freejz(m1);
    freejz(m2);

    return 0;
}
