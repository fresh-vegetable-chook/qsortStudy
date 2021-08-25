#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//只能排序整型
void BubbleSort(int arr[], int sz) {
	int i = 0;
	for (i = 0; i < sz - 1; i++) {
		//一趟冒泡排序
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

//库里的qsort - 可以排序任意类型的数据
void qsort(void* base, size_t num, size_t width, int(*cmp)(const void* e1, const void* e2));//void* 型指针可以接收任意一种类型
	//void型的指针是不能进行解引用的（因为访问几个字节不确定），void型指针不能确定指针的类型
	// 	   void型的指针不能进行+-*/运算
	//base:目标的起始位置
	//num:数组的大小（元素）
	//width:元素字节大小
	//cmp:比较函数，e1>e2时返回大于0的数，e1=e2时返回0，e1<e2时返回小于0的数

int cmp_int(const void* e1, const void* e2) {
	//比较两个整型值的函数
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
	//return ((int)(*(float*)e1 - *(float*)e2));   //这个做法不严谨
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
	//字符串的比较不能直接用>=<来比较，应该用strcmp函数
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
	struct Stu s[5] = { {"张三",20},{"李四",30},{"王五",50},{"草泥马",17},{"猫咪",24} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
	int k = 0;
	for (k = 0; k < sz; k++) {
		printf("%d ", s[k].age);
	}
}

void test4() {
	struct Stu s[5] = { {"张三",20},{"李四",30},{"王五",50},{"草泥马",17},{"猫咪",24} };
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