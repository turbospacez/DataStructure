/*
д������
1. α����/���״��� д�� ���й��ܵ�ʵ������
2. �����еĹ��ܾ���ʵ��
3. �ڳ������������ݲ��Թ���
*/

#include <stdio.h>
#include <stdlib.h> // malloc ����
#include <stdbool.h> // ��������

// ��Ϊstruct Arr����������
struct Arr {
    int* pBase; // �����е�һ��Ԫ�ص�ַ, ����ָ��
    int len; // ���鳤��
    int current; // ��ǰ����Ԫ�ظ���
};


/*
1.��ʼ������
2.ʹ�ú����ṩ��Щ�����Լ�����������
3.�ú���ʵ�ֵĹ���

*/

void init_arr(struct Arr* pArr, int length); // ��ʼ������
bool append_arr(struct Arr* pArr, int val); // β��׷��Ԫ��
bool insert_arr(struct Arr* pArr, int pos, int val); // ָ��λ�����Ԫ��
bool delete_arr(struct Arr* pArr, int pos, int* pVal); // ɾ��Ԫ��, ������ɾ��ֵ
bool is_empty(struct Arr* pArr); // �жϿ�
bool is_full(struct Arr* pArr); // �ж���
void sort_arr(struct Arr* pArr); // ��������
void show_arr(); // ��ӡ����Ԫ��
void invers_arr(struct Arr* pArr); // ��������

int main(void) {
    struct Arr arr;
    int val;

    init_arr(&arr, 6); // ��arr�ĵ�ַ���� init_arr ����
    //show_arr(&arr);

    /*
    ˳�����Ԫ��
    append_arr(&arr, 1);
    append_arr(&arr, 2);
    append_arr(&arr, 3);
    append_arr(&arr, 4);
    append_arr(&arr, 5);
    insert_arr(&arr, 1, 0);
    //show_arr(&arr);
    */

    //����Ԫ��
    //invers_arr(&arr);

    /*
    //pVal���ڴ��pArrԪ�ص�ַ�� &val=*pArr
    if (delete_arr(&arr, 1, &val)) {
        printf("ɾ���ɹ�! ɾ����Ԫ��Ϊ:%d\n", val);
    } else {
        printf("ɾ��ʧ��!\n");
    }
    */

    //show_arr(&arr);

    /*
    if (append_arr(&arr, 7)) {
        printf("׷�ӳɹ�!\n");
    } else {
        printf("׷��ʧ��Ŷ.\n");
    }
    */

    append_arr(&arr, 87);
    append_arr(&arr, 45);
    append_arr(&arr, 3);
    append_arr(&arr, 122);
    append_arr(&arr, 537);
    append_arr(&arr, 486);
    show_arr(&arr);

    sort_arr(&arr);
    show_arr(&arr);



    return 0;
}

// ͨ��Arr* ���� &arr �����ĵ�ַ
// ��ʼ�����麯��
init_arr(struct Arr* pArr, int length) {
    // ָ�� pArr ָ��ṹ�������pBase��Ա
    // ��malloc��̬������ڴ�ռ�
    pArr->pBase = (int*)malloc(sizeof(int) * length);

    // pBase Ϊ�ڴ�ռ��е�һ��������ַ, ���ڱ����������, intռ��4���ֽ�, int*length����ռ�õľ����ֽ���
    // �����̬�ڴ����ʧ��, malloc�����Ὣ NULL ֵ����pBase ��Ҫ���pBaseֵ�Ƿ�ΪNULL
    if (NULL == pArr->pBase) {
        printf("��̬�ڴ����ʧ��!\n");
        exit(-1); // ��ֹ��������
    } else {
        pArr->len = length;
        pArr->current = 0;
    }
    return;
}

_Bool is_empty(struct Arr* pArr) {
    if (0 == pArr->current) {
        return true;
    } else {
        return false;
    }
}

//�жϵ�ǰ�����Ƿ����
_Bool is_full(struct Arr* pArr) {
    //�жϽṹ��pArr��ǰԪ�ظ����Ƿ��ͬ�����鳤��
    if(pArr->current == pArr->len) {
        return true;
    } else {
        return false;
    }
}


void show_arr (struct Arr* pArr) {
    // pArr�Ƕ���ָ��, ��ʱpArr�Ĳ�������pArr��ַ, ��Ϊ��show_arr��������Ĳ���, ���Բ���Ҫ����κη���
    if( is_empty(pArr)) {
        printf("����Ϊ��!\n");
    } else {
        for(int i=0; i<pArr->current; ++i) {
            //pArrΪ�ṹ��, ��������. Ҫ��ӡ�������Ҫ�õ�ַ�������е�����
            printf("%d ", pArr->pBase[i]);

        }
        printf("\n");
    }
}

//׷��������Ԫ��
_Bool append_arr(struct Arr* pArr, int val) {
    //���ж������Ƿ����
    if(is_full(pArr)) {
        // ��������false
        return false;
    } else {
        // û����, ��val��ֵ׷�ӵ�����pArr��
        //�����0��ʼ����, current�ͱ�ʾ��ǰ��Ҫ�����λ��
        pArr->pBase[pArr->current] = val;
        //׷�����ֺ�, Ҫ���ִ����ݵı���+1��ʾ�����һ������
        pArr->current++;
        return true;
    }

}

_Bool insert_arr(struct Arr* pArr, int pos, int pVal) {
    int i;

    //�ж������Ƿ���
    if (is_full(pArr))
        return false;

    // ��֤����Ĳ�������Ԥ��, ���������ж�
    // �������ݵ�λ��pos�������1, pos����ֵ���ܴ��ڵ�ǰ����Ԫ�ظ���+1
    if (pos<1 || pos>pArr->current+1)
        return false;

    // i��ֵΪ��ǰ�����ļ�һ, ��Ϊ�±��0��ʼ
    // ��Ϊ�±��0��ʼ��, ��Ҫ�ƶ���ֵ��pos-1, �������±�ֵ���ϵ�
    // ����˵һ��6λ����, ���±�Ϊ012345, ����λ��, ���Ҫ��pos=3������һ��Ԫ��, ���㵽�����±����3-1Ϊ2

    // i�����е�ǰ���һ��Ԫ�ص��±�, i�����Ϸ�ֵ, ���ѭ���ǴӺ���ǰ�ƶ���
    for(i=pArr->current-1; i>=pos-1; --i) {
        pArr->pBase[i+1] = pArr->pBase[i];
    }

    // ��val��ֵ����Ҫ�����λ��, ��Ϊ�±��0��ʼ����Ҫ-1
    pArr->pBase[pos-1] = pVal;

    // �����һ����Ԫ��, ��ǰcurrent�±�+1
    (pArr->current)++;
}

_Bool delete_arr(struct Arr* pArr, int pos, int* pVal) {
    int i;
    if(is_empty(pArr))
        return false;
    //�ж�����ǿպ��ж�����ɾ��Ԫ��λ�ò���С��1ͬʱ���ڵ�ǰֵ
    if (pos<1 || pos>pArr->current)
        return false;

    // ��Ҫɾ����ֵ����pVal���ڴ�ӡ
    *pVal = pArr->pBase[pos-1];
    // i����Ҫɾ����λ��, iС�ڵ�ǰԪ�ظ���, i����������λ���±��ֵ��ǰ�ƶ�
    for(i=pos; i<pArr->current; i++) {
        // ���±���ǰ�ƶ�һλ
        pArr->pBase[i-1] = pArr->pBase[i];
    }

    // ɾ���󽫵�ǰ����������-1
    pArr->current--;
    return true;
}

invers_arr(struct Arr* pArr) {
    int i = 0;
    int j = pArr->current-1;
    int temp;
    struct Arr arr;

    while (i<j) {
        /*
        ��������ֵ����ͨ������������ֵtemp���н���
        temp = i
        i = j
        j = temp
        */
        temp = pArr->pBase[i];
        pArr->pBase[i] = pArr->pBase[j];
        pArr->pBase[j] = temp;

        ++i; // �������±��0��ʼ����ƶ�һλ
        --j; // �������±�����һλ��ǰ�ƶ�һλ

        //��ӡ��ǰpArr����Ԫ��
        //show_arr(pArr);
    }

    return;
}

// N2��ð������
void sort_arr(struct Arr* pArr) {
    int i, j, temp;

    for(i=0; i<pArr->current-1;i++) {
        for(j=i+1; j<pArr->current; ++j) {
            if(pArr->pBase[i] > pArr->pBase[j]) {
                temp = pArr->pBase[i];
                pArr->pBase[i] = pArr->pBase[j];
                pArr->pBase[j] = temp;
            }
        }
    }
}
