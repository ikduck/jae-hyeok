// **** STL_Vector_v11
#include <iostream>
// 기본적으로 제공하는 기능	
#include <vector>

using namespace std;

int main(void)
{
	// 수업전 설명
	/*
	char; // 256 / -128 ~ 127 // 8비트 연산 컴퓨터 (256 + 256이 한계)-> 애니악(1946)
	short; // 정수 -> 16비트 컴퓨터 -> mac 
	int; // 32비트 컴퓨터(보급형pc) , 16비트 컴퓨터에서는 16비트로 표현해주고 32비트 컴퓨터에서는 32비트로 만들어줌 but 64비트는 안댐
	long; // 8바이트
	
	__int64; // 8바이트 
	
	double; //  

	// int와 double의 표현차이가 있다.

	// auto == var(자바)
	*/

	// 구성관리자 뜻 풀이
	/*
		debug -> 구성할때
		release -> 배포할때
	
		*** debug에서 실행되지만 release에서 실행안될때도있어서 수정해야됨
		전처리기를 사용함

		win32
		x64 - 하나의 데이터를 64비트 기준으로 만듦 (포인터 하나 만드는데 8바이트로 만들어짐.)

		// c로 개발할때는 지우면 안됨 , 지금은 공부중이여서 가능
	*/

	// 포인터에 대한 기본 설명
	/*
	// int* Pointer = 지역변수 (스택) , new int = (힙)
	int* Pointer = new int;

	// char* -> int형을 받을려면 형변환해야함 ,하지만 에러를 발생시킬수 있음
	// 정수 -> 실수로 가거나 할때는 캐스트를 써줘야함
	// 캐스트 -> 크기또한 바뀜()

	// int; int*; 은 서로다르다.
	
	// int; 4바이트 정수형
	// int*; 자료형이 int인 변수의 주소만 가질수 있음
	
	float형이 가진 값을 int*가 가질수는 있지만 소수점 뒷자리가 100% 소실됨

	// 포인터는 선택
	// 원본데이터의 값을 변경하고 싶을때 call by Reference 포인터를 써야함
	// 4바이트 데이터를 4개를 옮길때 call by value는 4번의 복사가 이루어지지만
	// call by reference는 1번의 복사로 4개의 데이터를 옮긺
	// 포인터는 왜 쓰나요? 의 질문은 잘못됨 -> 언제써야하나요 가 맞는 질문임
	*/

	// 헝가리안 표기법 사용(색으로 표현이 안되던 시절에 사용 _포함) = c코딩(1950)의 대세를 따름 (습관)
	// vector = vec

	int MAX = 50;

	// vecNumber의 형태는 vector<int>다
	vector<int> vecNumbers;
	
	// *** 입력
	for(int i =0; i < 10; ++i)
	{
		vecNumbers.push_back(10 * i);
		cout << "Capacity : " << vecNumbers.capacity() << endl;
		cout << "Size : " << vecNumbers.size() << endl << endl;
		
	}

	// 출력 추가 설명
	/*
		float형에서 int형으로 옮기면 소수점 이하 숫자가 소실됨
		vector<int>* iterator도 맞지만
		vector<int>::iterator iter 로 써주는게 맞음
	*/

	// 원소와 반복자
	/*
	// front() 와 back() 은 반복자가 아니고 원소 그자체임
	// *** 가장 앞에 있는 *원소를 반환*
	cout << vecNumbers.front() << endl;
	// *** 가장 뒤에 있는 *원소를 반환*
	cout << vecNumbers.back() << endl;

	// begin() 과 end()는 반복자이다.
	// *** 시작 지점을 가르키는 *반복자*	
	cout << *vecNumbers.begin() << endl;
	// *** 종료 지점을 가르키는 *반복자*
	cout << *vecNumbers.end() << endl;
	*/

	// *** 출력 1 : 직접접근을 할때
	/*
		// 유일하게 배열만 직접접근이 가능하다. * 다른 컨테이너는 직접접근(index접근)이 안됨 *
		int Array[16] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };

		// for (int i = 0; i < 16; ++i)
		//  	Array[i] = { i + 1 };

		// 직접접근이 않기 때문에 iterator로 대신 접근함 (택배기사,카카오톡같이 직접접근이 안되기 때문에 간접적으로 접근해서 출력해줘야함)
		// 배열또한 포인터임. c를 배우는 이유 -> 포인터 <- 데이터 관리
		// google -> go언어만듦
		// 수동형 언어(c,c++) 프로그래머가 변수를 다 관리해야함 if(100개면 100개다!), 자동형 언어
		int* iterator = Array;

		for (int i = 0; i < 16; ++i)
			cout << Array[i] << endl;

		for (int i = 0; i < 16; ++i)
			cout << *(iterator + i) << endl;
			cout << *(iterator++) << endl;
	*/

	// *** 출력 2 
	/*
	for (int i = 0; i < vecNumbers.size(); ++i)
			cout << vecNumbers[i] << endl;
	
	// *** 중요
	for (vector<int>::iterator iter = vecNumbers.begin();
		iter != vecNumbers.end(); ++iter)
		cout << (*iter) << endl;

	for (auto iter = vecNumbers.begin();
			iter != vecNumbers.end(); ++iter)
			cout << (*iter) << endl;
	*/

	// *** 출력 3 
	/*
	// *** 중요
	for (auto iter = vecNumbers.begin(); iter != vecNumbers.end();)
	{
		// 증감 연산자가 조건문에 들어가면 지울때도 값이 증가해서 이상하게 출력됨
		// 지울때는 지우고
		// if((*iter) > MAX) 

		if ((*iter) > 50)
			iter = vecNumbers.erase(iter);

		// 증가할때는 증가하게
		else
			++iter;
	}

	for (auto iter = vecNumbers.begin(); iter != vecNumbers.end(); ++iter)
	{
		cout << (*iter) << endl;
	}

	// 위의 코드를 응용해서 사용할수 있어야함 \
	ex) if 문의 조건이 충돌이라고 생각했을때 충돌이 일어나면 종료시키고 아니면 계속 증가시키는 것처럼 사용할 수도 있음
	*/
	
	// insert 오랜 시간이 걸리지는 않지만 효율적이지 않음
	/*
	1. _where 시작 주소 부터 끝주소까지 복사하고 임시 저장소에 넣음
	1-2. 배열 크기가 작다면 늘림
	2. _where 시작 지점에 값을 넣음
	3. _where 끝 지점에 임시 저장소에 넣은 값을 넣음 
	*/

	return 0;
}

// 이미테이션 게임 추천 영화
/*
	- 코딩하는 사람은 봐야하는 필수 영화임.
	애니악 컴퓨터(최초의 컴퓨터) - 문자를 출력하기 위해 만들어진 컴퓨터
	미국에서 개발해서 -> 영어로사용
*/

// 스택의 구조

// 후위연산 -> 값을 어딘가에 보관후 값이 오르면 가져오는데
// 전위 연산은 그런게 필요없어서 더 빠름
