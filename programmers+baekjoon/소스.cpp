#include<iostream>
using namespace std;

int rdsearch(int* myRdyTbl, int* myRdyGrp) {
	int i, rand_num, upperBit, lowerBit;
	rand_num = rand() % 64;//random number generation(64�̸��� ���� ������  ����) 
	//�ߺ��� ������ �ȵȴ�
	//������ ���ڰ� �����Ͱ� �����ϸ� �����


	//***TASK INSERTION***
	//�ش� ���ڸ� myRdyTbl�� myRdyGrp�� �����Ѵ�
	 //task 10���� ���, 001010
	 //���� 3�� ��Ʈ 001 = 1
	cout << rand_num << '\n';
	upperBit = rand_num >> 3;
	lowerBit = rand_num & 0x07;
	cout << upperBit << " " << lowerBit << '\n';
	//�ߺ��� ���� ����� �ϹǷ� ���� &������ �� ��, 
	cout << myRdyTbl[lowerBit] << '\n';
	cout << *myRdyGrp << '\n';
	 //���� RdyGrp�� ��Ʈ�߰��Ϸ��� bitwise OR���� �ʿ�  
	//����3����Ʈ���� ��Ÿ���� >>����  
	//myRdyGrp |= myMapTbl[upperBit];
	//����3����Ʈ���� ��Ÿ���� 7(111)���� bitwise AND���� 
	//myRdyTbl[upperBit] |= myMapTbl[lowerBit];

	return rand_num;
}

int main() {
	int myRdyTbl[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };
	int myRdyGrp = 0;
	rdsearch(myRdyTbl, &myRdyGrp);
}