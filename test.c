#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//ֻ����������
void BubbleSort(int arr[], int sz) {
	int i = 0;
	for (i = 0; i < sz - 1; i++) {
		//һ��ð������
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


struct Stu {
	char name[20];
	int age;
};

//�����qsort - ���������������͵�����
void qsort(void* base, size_t num, size_t width, int(*cmp)(const void* e1, const void* e2));//void* ��ָ����Խ�������һ������
	//void�͵�ָ���ǲ��ܽ��н����õģ���Ϊ���ʼ����ֽڲ�ȷ������void��ָ�벻��ȷ��ָ�������
	// 	   void�͵�ָ�벻�ܽ���+-*/����
	//base:Ŀ�����ʼλ��
	//num:����Ĵ�С��Ԫ�أ�
	//width:Ԫ���ֽڴ�С
	//cmp:�ȽϺ�����e1>e2ʱ���ش���0������e1=e2ʱ����0��e1<e2ʱ����С��0����

int cmp_int(const void* e1, const void* e2) {
	//�Ƚ���������ֵ�ĺ���
	return *(int*)e1 - *(int*)e2;
}

void test1() {
	int arr[] = { 1,3,5,7,9,2,4,6,8,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	for (i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
}

int cmp_float(const void* e1, const void* e2) {
	//return ((int)(*(float*)e1 - *(float*)e2));   //����������Ͻ�
	if (*(float*)e1 == *(float*)e2) {
		return 0;
	}
	else if (*(float*)e1 > *(float*)e2) {
		return 1;
	}
	else {
		return -1;
	}
}

int cmp_stu_by_age(const void* e1, const void* e2) {
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

int cmp_stu_by_name(const void* e1, const void* e2) {
	//�ַ����ıȽϲ���ֱ����>=<���Ƚϣ�Ӧ����strcmp����
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}

void test2() {
	float f[] = { 9.0,8.0,7.0,4.0,6.0,5.0,12.0 };
	int sz = sizeof(f) / sizeof(f[0]);
	qsort(f, sz, sizeof(f[0]), cmp_float);
	int j = 0;
	for (j = 0; j < sz; j++) {
		printf("%f ", f[j]);
	}
}

void test3() {
	struct Stu s[5] = { {"����",20},{"����",30},{"����",50},{"������",17},{"è��",24} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
	int k = 0;
	for (k = 0; k < sz; k++) {
		printf("%d ", s[k].age);
	}
}

void test4() {
	struct Stu s[5] = { {"����",20},{"����",30},{"����",50},{"������",17},{"è��",24} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
	int k = 0;
	for (k = 0; k < sz; k++) {
		printf("%s ", s[k].name);
	}
}


int main() {
	
	test1();
	printf("\n");
	test2();
	printf("\n");
	test3();
	printf("\n");
	test4();
	
	//BubbleSort(arr, sz);
	return 0;
}