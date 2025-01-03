#include <iostream>

// 사용자로부터 5개의 숫자를 입력 받아 배열에 저장하고 이들의 합계와 평균을 계산해서 출력
// 5개의 숫자를 입력 받는 공간은 배열을 활용
// 합과 평균을 구하는 동작은 main 함수에 한번에 작성 X, 각각의 함수를 구현해야 함.

// 1. 오름차순 정렬, 내림차순 정렬 가능해야 함.
// 2. 숫자 1을 입력 받으면 오름차순 정렬, 숫자 2를 입력받으면 내림차순 정렬을 하도록 구현.
// 3. 오름차순 정렬, 내림차순 동작을 각각 함수로 구현.

using namespace std;

// 총합 선언 csum

int csum(const int numbers[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; ++i) // for(초기화; 조건; 증감)
	{
		sum += numbers[i]; // sum = sum + numbers[i], sum에 numbers[i]를 더한 값을 계산, 그 결과를 다시 sum에 저장
	}
	return 0;
}

// 평균 선언 caverage

double caverage(const int numbers[], int size)
{
	int sum = csum(numbers, size);
	
	return static_cast<double>(sum) / size; 
	//static_cast: C++의 명시적 타입 변환 연산자 , sum을 double 타입으로 변환, 변환된 sum을 size 로 나눔.
}


// 오름차순 정렬 함수

void sortAscending(int numbers[], int size)
{
	for (int i = 0; i < size - 1; ++i) // 외부 반복문 i
	{
		for (int j = 0; j < size - 1; ++j) // 내부 반복문 j
		{
			if (numbers[j] > numbers[j + 1])
			{
				int temp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp;
			}
		}
	}
}


// 내림차순 정렬 함수
void sortDescending(int numbers[], int size) 
{
	for (int i = 0; i < size - 1; ++i) 
	{
		for (int j = 0; j < size - i - 1; ++j) 
		{
			if (numbers[j] < numbers[j + 1]) 
			{
				int temp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp;
			}
		}
	}
}


int main() 

{

	const int size = 5; // const 초기화 필수인 변수. 5로 지정.
	
	int numbers[size]; 

	//사용자 입력 - 숫자
	cout << "5개의 숫자를 입력하세요 : \n";
	for (int i = 0; i < size; ++i) 
	{
		cin >> numbers[i];
	}

	//총합, 평균 계산
	int sum = csum(numbers, size); // 총합 
	double average = caverage(numbers, size); // 평균

	cout << "총합 : " << sum << "\n";
	cout << "평균 : " << average << "\n";

	//사용자 선택 - 정렬방식
	cout << "정렬 방식을 선택하세요 (1. 오름차순, 2. 내림차순) : ";
	int choice;
	cin >> choice;

	if (choice == 1) // sortAscending = 오름차순, sortDesending = 내림차순
	{
		sortAscending(numbers, size);
		cout << "오름차순 정렬 결과 : ";
	}
	else if (choice == 2) 
	{
		sortDesending(numbers, size);
		cout << "내림차순 정렬 결과 : ";
	}
	else
	{
		cout << "잘못된 선택입니다" << endl;
		return 1;
	}

	//정렬 결과 출력
	for (int i = 0; i < size; ++i)
	{
		cout << numbers[i] << " ";
		cout << endl;

		return 0;
	}







	return 0;
}
