//有序线性表的归并算法
#include "9.291.c"
void Merge(List L1, List L2,List L3) {
	int i, j, k;//i循环L1，j循环L2
	i = j = k = 0;
	while (i < L1.length && j < L2.length) {
		if (L1.data[i] < L2.data[j]) {
			L3.data[k] = L1.data[i];
			L3.length++;
			i++, k++;
		}
		else {
			L3.data[k] = L2.data[j];
			L3.length++;
			j++, k++;
		}
	}
	while (i < L1.length) {
		L3.data[k++] = L1.data[i++];
		L3.length++;
	}
	while (j < L2.length) {
		L3.data[k++] = L2.data[j++];
		L3.length++;
	}
}

void Insert(List L4, int x) {
	int i, j;//i,j用来遍历L4
	i = 0;
	while (L4.data[i] <= x && i < L4.length) {
		i++;
	}
	for (j = L4.length -1;j > i; j--) {
		L4.data[j+1] = L4.data[j];
	}
	L4.data[j] = x;
	L4.length++;
}
void Shiftleft(List L5, int p) {
	int num;//中间值
	int i;//遍历L5
	for (i = 0; i <= p; i++) {
		if (i + p <= L5.length) {
			num = L5.data[i];
			L5.data[i] = L5.data[i + p];
			L5.data[i + p] = num;
		}
		else {
			num = L5.data[i];
			L5.data[i] = L5.data[i + p - L5.length];
			L5.data[i + p] = num;
		}
	}
}