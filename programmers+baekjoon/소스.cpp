#include<iostream>
using namespace std;

int rdsearch(int* myRdyTbl, int* myRdyGrp) {
	int i, rand_num, upperBit, lowerBit;
	rand_num = rand() % 64;//random number generation(64미만의 양의 정수만  생성) 
	//중복이 있으면 안된다
	//생성된 숫자가 기존것과 동일하면 재생성


	//***TASK INSERTION***
	//해당 숫자를 myRdyTbl과 myRdyGrp에 삽입한다
	 //task 10번인 경우, 001010
	 //상위 3개 비트 001 = 1
	cout << rand_num << '\n';
	upperBit = rand_num >> 3;
	lowerBit = rand_num & 0x07;
	cout << upperBit << " " << lowerBit << '\n';
	//중복된 수가 없어야 하므로 먼저 &연산을 한 후, 
	cout << myRdyTbl[lowerBit] << '\n';
	cout << *myRdyGrp << '\n';
	 //기존 RdyGrp에 비트추가하려면 bitwise OR연산 필요  
	//상위3개비트값을 나타내는 >>연산  
	//myRdyGrp |= myMapTbl[upperBit];
	//하위3개비트값을 나타내는 7(111)과의 bitwise AND연산 
	//myRdyTbl[upperBit] |= myMapTbl[lowerBit];

	return rand_num;
}

int main() {
	int myRdyTbl[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };
	int myRdyGrp = 0;
	rdsearch(myRdyTbl, &myRdyGrp);
}