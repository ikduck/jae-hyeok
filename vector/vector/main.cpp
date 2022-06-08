// ***** Vector_v10
#include <iostream>

using namespace std;

// 전역변수 선언
// ** 현재 원소의 개수
int Size = 0;

// ** 최대 수용 개수
int Capacity = 0;

// ** 컨테이너 
int* Vector = nullptr;

// 전방선언 (모르는데 어떻게 가요), 동적할당 및 배열 복사 추가
// *** 컨테이너의 마지막 위치에 값을 추가.
void push_back(const int& _Value);

// *** 컨테이너의 마지막 위치에 있는 값을 삭제.
void pop_back();

// f12(정의로 이동하기) = ctrl + 더블 클릭(예전에는 현재 더블클릭 기능이엿음)

// *** 가장 앞쪽에 있는 원소
int front();

// *** 가장 뒷쪽에 있는 원소
int back();

// *** _where 위치에 데이터 삭제
void erase(const int& _where);

// alt + enter누르면 선언 정의 만들기 간편하게 만들수 있음

// *** _where 위치에 데이터 추가
void insert(const int& _where, const int& _Value);

/*
int* begin();
int end();
*/

int main(void)
{
	// ** 누적 횟수만큼 비효율
	// ** 값 추가
	for (int i = 0; i < 10; ++i)
		push_back(i * 1 + 1);

	// pop_back();
	// push_back(10000);

	// ** 출력
	// cout << "컨테이너의 처음 값: " << front() << endl;
	// cout << "컨테이너의 마지막 값: " << back() << endl << endl;

	// erase(3);

	insert(2, 777);

	// *** 출력
	for (int i = 0; i < Size; ++i)
		cout << "Value: " << Vector[i] << endl;

	cout << "Size : " << Size << endl;
	cout << "Capacity : " << Capacity << endl << endl;

	return 0;
}

// 1. 데이터 추가 (새로운 공간 확장)
// 2. 데이터 제거
// 3. 데이터를 삽입 할 수 있는 공간의 쓰기
// 4. 현재 삽입되어있는 원소의 개수

// 5. 컨테이너의 시작 지점
// 6. 컨테이너의 중간 지점

void push_back(const int& _Value)
{
	// *** 만약 더이상 수용할 수 있는 공간이 없다면...
	if (Capacity <= Size) 
	{
		// 공간 추가
		// *** 현재 수용량(Capacity)이 4보다 작다면 1씩 증가하고.
		// *** 현재 수용량이 4보다 크거나 같다면 1/2 만큼 추가함. 
		Capacity += (Capacity <= 3) ? 1 : Capacity >> 1;

		// 동적할당은 Temp에
		// int* Temp = new int[Capacity];
		// 배열 제일 마지막에 null 값을 넣어줄때
		// *** 임시의 저장소를 생성
		int* Temp = new int[Capacity + 1]; 

		// if 더블 포인터를 사용할려면
		/*
		int** dPoint = &Temp;

		for (int i = 0; i <= Capacity; ++i)
			Vector[i] = NULL;
		*/

		// *** 생성된 공간에 초기화함.
		for (int i = 0; i <= Capacity; ++i)
			Temp[i] = NULL;

		// *** 기존에 있던 값을 복사.
		for (int i = 0; i < Size; ++i)
			Temp[i] = Vector[i];
		
		// *** 기존에 값을 삭제.
		if(Vector)
		{
			delete Vector;
			Vector = nullptr;
		}
	
		// 복사
		// *** 임시의 값(해당 주소)를 복사해옴.
		Temp[Size] = _Value;

		// 값은 Vector에
		// *** 임시 주소값에 복사해둔 값과 
		// *** 추가된 새로운 값을 다시 
		// *** 전역변수로 저장되어 있는 Vector 로 가져옴. 
		Vector = Temp;
	}
	else
		// *** 마지막 위치에 값 추가.
		Vector[Size] = _Value;
		
	// else가 있어서 둘중하나는 무조건 실행되기 때문에 ++Size를 외부로 빼줌
	// *** 현재 원소의 최대값 증가.
	++Size;
	
	// null 추가
	// Vector[Capacity] = NULL;

	// 작동 확인을 위해 만듦
	// cout << "Value : " << _Value << endl;
	// cout << "Size : " << Size << endl;
	// cout << "Capacity : " << Capacity << endl << endl;

	// 나의 답
	/*
	if(Size >= Capacity) 
		Capacity += (Capacity <= 3) ? 1 : Capacity >> 1;
	// 이것만 넣었음 ;;
	*/
}

void pop_back()
{
	// 삭제만 하기 때문에 값을 받아오지않음
	// 지울 필요없고 다음번에 넣을수있게 만들어 주면됨
	// 깨끗하게 지울려고하는 것 부터가 이미 비효율적임
	// *** 현재 원소의 최대값 증가
	--Size;
}

int front()
{
	// *** 0번째 원소 변환
	return Vector[0];
}

int back()
{
	// *** 원소의 최대값 감소
	return Vector[Size - 1];
}

void erase(const int& _where)
{
	// ** 특정 위치에 있는 원소를 삭제하고 정렬

	// *** 원소의 최대값 감소
	--Size;

	// *** 재정렬
	for (int i = _where + (-1); i < Size; ++i)
	{
		Vector[i] = Vector[i + 1];
	}

}

void insert(const int& _where, const int& _Value)
{
	if (Capacity <= Size)
		Capacity += (Capacity <= 3) ? 1 : Capacity >> 1;

		// *** 임시 저장소
		int* Temp = new int[Capacity + 1];

		// *** 전체 초기화
		for (int i = 0; i <= Capacity; ++i)
			Temp[i] = NULL;

		// *** 해당 위치 이전의 값을 복사.
		for (int i = 0; i < _where; ++i)
			Temp[i] = Vector[i];

		// *** 해당 위치에 값 삽입
		Temp[_where] = _Value;
		Size++;

		// *** 해당 위치 이후의 값을 복사
		for (int i = _where + 1; i < Size; ++i)
		{
			Temp[i] = Vector[i - 1]; // 4바이트 int형을 배열로 써서 나옴
		}

		if (Vector)
		{
			delete Vector;
			Vector = nullptr;
		}

		// 값은 Vector에
		Vector = Temp;

	//else
	// 	Vector[Size] = _Value;

	// 똑같은 코드가 두번 반복되면 반드시 줄일 수 있다.
}

/*
void insert(const int& _where,const int& _Value)
{
	++Size;

	for (int i = Size; i > _where + (-1); --i)
	{
		Vector[i + 1] = Vector[i];
	}

	Vector[_where] = _Value;
}
*/



// 코드를 다 바꿔야되서 폐지 list로 넘어가면 더 쉬워짐
/*
int* begin()
{
	// return Vector[0];
	// fornt가 바뀌면 begin도 바뀌게
	return Vector;
}

// 더블 포인터를 사용해야함
int end()
{
	return Vector[Size];
}
*/

// 2022.05.31
/*
// git 새로운것을 덮어씌우지 않고 이전 버전을 지킬려고함	
// 브런치를 나눠서 구역을 나눔 , 경합하는 과정이 힘듦
// Visual studio - IDE 코드 뿐만아니라 많은 편집기능을 포함하고있어 프로그램이 무거움
// Visaul studio Mac - c컴파일할때 GCC라는 것이 필요했었다. 최근에는 모름
// Visaul studio Code - 경량화 되어있음 컴파일러가없어 프로그램이 가볍다 
// 전위 연산이 후위연산보다 더빠름 i++ < ++i 
// 솔루션 탐색기 설정에서 버전바꾸는것 정도는 알아야함
// 오늘 이후로는 git gui를 사용하는데 문제없이 만들것.
// pull 하고 오전 끝 야근 
	*/

// 배열
/*
char str1[2][5] =
{
	{'A','B','C','D','E'},
	{'F','G','H','I','J'}
};

char* str2[2] =
{
	{(char*)"ABCDE"},
	{(char*)"FGHIJ"}
};

for(int i = 0; i < 5; ++i)
	cout << (*str1)[i];
cout << endl;

pritnf_s("%s\n", str2[0]);

cout << str1[1][4] << endl;
cout << str2[1][4] << endl;

// 배열의 장단점에 대하여

1. 장점

2. 단점
	*/

// 2022.06.02
/*
* // 원인이 뭘지 찾아보는 습관을 기르자 (어디가 문제인거지?)

	// *** 1. 왜 되지?
	// *** 2. 왜 안되지?

	// *** 원인분석
	// 에러의 원인을 찾는 것이 힘듦

	// msdn 마이크로 소프트에서 제공하는 사전?
	// 디버그란? 디버그를 사용하는 기술? (ex) 롤 배그는 게임)

	// 변명하는거 별로 안좋아하심 (원래, 집에서는, 등등)
*/

// 2의 보수에 대하여
/*
	컴퓨터가 인식하는 딱 떨어지는 숫자들은 2의 n승 숫자들이다
	리터널 상수일때는 문제가 없음
	컴퓨터가 크기 10의 배열로 만들때

	컴퓨터는 빼기의 기능이 없기 때문에 2의 보수가 사용되는데
	0 0000000 = 0
	0 0000001 = 1
	0 0000010 = 2
	0 0000011 = 3
	0 0000100 = 4
	0 0000101 = 5
	0 0000110 = 6
	0 0000111 = 7
	0 0001000 = 8
	0 0001001 = 9
	0 0001010 = 10
	0 0001011 = 11
	0 0001100 = 12
	0 0001101 = 13
	0 0001110 = 14
	0 0001111 = 15
	0 0010000 = 16
	.
	.
	.
	0 1111111 = 127
	1 0000000

	  00010000 = 16
	- 00000110 = 6
	==============
	(16 - 6 == 16 + (-6))
	
	** 2의 보수 시작
	0 0 0 0 0 1 1 0 = 6
	1 1 1 1 1 1 1 1
	===============
	1 1 1 1 1 0 0 1
	11111001 +  1
	===============
	11111010 = -6
	
	  00010000 = 16
	+ 11111010 = -6
	===============
	1 00001010 앞에 1은 밀려서 사라짐
	 00001010 = 10

	맨앞 숫자는 값의 부호(+,-)

	char n1 = 127;
	n1 += 1;
	printf_s("%d\n", n1);

	//===============
	char n2 = 16;
	n2 -= 6;  // 컴퓨터가 -를 어떻게 연산하겟는가?
	printf_s("%d\n", n2);
	// 사람에게 좋음 (보기 쉬움)

	//===============
	char n3 = 16;
	n3 += -6;  // 답
	printf_s("%d\n", n3);
	// 컴퓨터에게 좋음 2의 보수를 하지않아도됨 (6을 -6으로 안바꿔도됨)

	하지만 변수를 많이사용하는 작업 상 많이 제한됨 (곱하기나 나누기를 할때 더욱 어려워짐)
	정수 계산 특화 cpu - 직렬의 형태
	실수 계산 특화 gpu - 병렬의 형태로 많음(병렬 연산이 빠름)
	더하기의 심화 곱하기 - 빼기의 심화 나누기 나누기는 컴퓨터의 약점
	게임은 특히 나누기가 많이사용됨
	마우스 중앙에 위치하고싶을때 int x = 1920 / 2; int y = 1020 /2 ;
	그러므로 int x = 1920 * 0.5; < int x = 1920 << 1;
	사용하지는 않지만 알고있어야함
	if 특정상수를 줘야할때


	// <<(쉬프트 연산자) 란?  c에서만 사용가능 c#에서는 사용불가능
	char n = 16;
	00010000 = 16

	printf_s("%d", n >> 1);
	00001000 = 8;
	나누기의 기능을 하게됨

	// >>
	곱하기의 기능을 하게됨
*/

#pragma region 2022.06.02 2의 보수 선생님 정리

// *** 양수 표현의 최대값에서 +1을 더하면 어떤값이 나올까
	/*
	char n = 127;
	n += 1;
	printf_s("%d\n", n);
	*/

	// *** + 연산과 - 연산중 무엇이 더 효율 적일까.
	/*
	char n = 16;
	n += -6;
	n -= 6;
	printf_s("%d\n", n);
	*/

	// *** 나누기를 해야 할 때에는 *로 대체할수 있을지 확인해보고
	/*
	int n1 = 1920 / 2;
	int n2 = 1920 * 0.5;

	printf_s("%d\n", n);

	// *** 아래와 같이 쉬프트 연산자로 사용할수 있을지 확인해보자.
	printf_s("%d\n", n >> 1);

	*/
	/*
	 배열의 크기를 10으로 만들었을때 컴퓨터는 10을 넣을수있는 값 16으로 만든다
	 그후 16 - 6을 해줘야하기 때문에 효율이 좋지않다.

	*/

	// *** 
	/*
	const int MAX = 16;
	int Vecter[MAX];

	int length = 10;

	for (int i = 0; i < length; ++i)
	{
		cout << Vecter[i] << endl;
	}
	*/

	// 
	/*
	// ** 배열은 0이 아닌 값으로만 초기화가 가능하다.
	// ** 배열은 상수값으로만 초기화가 가능하다

	// ** 아래와 같이 사용한다면 위 조건은 무시할수 있다.
	(배열은 아니지만 배열처럼 사용할수 있다.)

	// 자료구조를 stack이 아닌 hip으로 만들거임
	int Size = 0;
	int iter = 0;

	int* Vector = new int[Size];

	Vector[iter];
	*/
	// int Vector[0]은 못만듬 [1]은 만들수 있지만 안씀
	// 배열에는 상수만 들어가지만 동적할당에는 값이 0인 변수도 들어감
	// 배열을 만드는 것이 아니라 할당할 구역을 정하는 것 길이가 아니라 크기가됨

	// *** 배열은 아니지만 배열처럼 사용할 수 있다.
	/*
	int Size = 10;
	int iter = 0;
	
	int* Vector = new int[Size];
	
	for (int i = 0; i < Size; ++i)
	{
		Vector[i] = i;
	}
	
	// for (int i = 0; i < Size; ++i)
	// 	cout << Vector[i] << endl;
	
	for (int i = 0; i < 11; ++i)
		cout << Vector[iter++] << endl;
	
	// 크기 값을 오버하면 문제가 생김
	*/

#pragma endregion

// 2022.06.03
/*
// 전역변수 선언
// ** 원소의 개수
int Size = 0;

// ** 최대 수용 개수
int Capacity = 0;

// ** 컨테이너
int* Vector = nullptr;

// 전방선언 (모르는데 어떻게 가요)
void push_back(const int& _Value);

int main(void)
{
	// ** 누적된 횟수 만큼 비효율 (!100 (팩토리얼))
	for (int i = 0; i < 17; ++i)
		push_back(i * 100 + 100);

	for (int i = 0; i < Size; ++i)
		cout << Vector[i] << endl;

	// 배열 생성이 3번 이상이되면 3 += 3/2 - 4.5 가되지만 int형이기 때문에 0.5를 버림처리하여 4개
	// 4 += 4/2 = 6 이런식으로 점점 커진다.
	
	// push_back(100);
	// push_back(200);
	// push_back(300);
	
	//for (int i = 0; i < Size; ++i)
	//	cout << Vector[i] << endl;
	// 새로 만들고 복사하고 추가하기

return 0;
}

void push_back(const int& _Value)
{
	if (Size >= Capacity)
		Capacity += (Capacity <= 3) ? 1 : Capacity >> 1;

	// size와 Capacity 같이 증가하게

	// ** Capacity 만큼 만듦
	int* Temp = new int[Capacity];

	// Size만큼 복사
	for (int i = 0; i < Size; ++i)
		Temp[i] = Vector[i];

	// 벡터가 남는게 있으면 지우고 초기화
	if (Vector)
	{
		delete Vector;
		Vector = nullptr;
	}


	Temp[Size - 1] = _Value;
	++Size;

	Vector = Temp;
	// 원소의 개수는 한번에 한번씩 증가
	//++Size;

	//cout << Capacity << endl;
	/*
	if (Size <= 3)
	{
		++Size;

		// if(Size <= 0 ) 일때
		//Vector = new int[Size];
		//Vector[Size - 1] = _Value;

	}
	else
	{
		Size += Size * 0.5f; // 0.5f에서 f를 붙이면 4바이트를 소모하지만 0.5는 8바이트를 사용함
		// 컴퓨터가 64 비트일때 long 일때와 longlong 일때 (정수일때) 1회 연산하지만
		// 실수는 다르다 실수는 여러번 연산하기 때문에 무조건 적게 사용하는것이 좋다.
	}
	
	
	else
	{

		int* Temp = new int[Size];
		// Vector = new int[Size]; 로 하게되면 현재는 문제가없지만
		// 데이터가 축적되어 오버플로우가 일어나서 갑작스럽게 터지기때문에
		// 문제를 찾기가 굉장히 오래걸리고 힘듦

		for (int i = 0; i < Size - 1; ++i)
			Temp[i] = Vector[i];

		// heap영역에 계속 누적되서 메모리 누수가 일어나서 지워줘야함
		delete Vector;
		Vector = nullptr;

		Temp[Size - 1] = _Value;
		Vector = Temp;
	}
	
}
// c를 배우면 좋다는 것은 메모리 관리를 철저하게 해줘야하기 때문이다.(포인터를 잘다뤄야 메모리관리를 잘할수있음)
*/

// 시간이 없어서 단축키와 동선을 줄이기위해 코드를 줄임

// 네이버 지식백과 검색해보자 

// 스택은 위가 뚫혀있는 구조, 하노이 탑 같은 구조
/*
	call by value 
	값이 변하지않음 다른 함수에서 값을 변경했다고해도
	그 함수가 끝나면 값이 원래대로 돌아옴
	(변수 보존)
	call by &(래퍼런스) 
	주소를 가지고있음
	값을 변경한후 값이 변경되어도 힙영역에 값이 변한채로 유지됨

	& 단항으로 사용했을때는 주소
	&& 이항으로 사용했을때는 and 기능

	const int&

	const를 사용해서 값의 변경을 막음 (const는 건드리지 않는 것이 좋음)
*/

// 학습방법? 프로그래밍 문과형(그냥 암기함) > 이과형(이해하기 전까지 계속해서 연구함) 
// 프로그래밍은 암기하고 넘어가야함
// 시험치듯이 해야함 막히면 넘어가야함 조금 큰 단원으로 넘어가야함
// if 메모리구조 스택 힙 같은건 외워야함
// 나보다 똑똑한 사람이 만들어 놓은거 외워서 사용하자!
// 컴공처럼 기초가 되는 교육을 받는 대학을 가야함 그래야지 스펙업이 가능
// 학점은행제 5~6년 3년에 한번 일자리 변경. 대기업은 학벌중요함

// 연산자 오버로딩

// list 단방향 리스트 , 양방향 리스트 , 
// 요즘은 만들어진 형태로 사용함

// 오버플로우 오버런