// Stack & Queue Program using ChainNode, by Youngwoo Kim, email: rdd0426@gmail.com
// Directory
// Line 10 ~ 127 : declaration for classes & other functions
// Line 129 ~ til the end : main function.
#include <iostream>
#include <iomanip> // 입출력 형태를 이쁘게 하기위해 setw와 left를 사용할것임.

using namespace std;

class ChainStack;
class ChainQueue;
class ChainNode {
	friend class ChainStack; // friend 선언을 통해 Stack에서 ChainNode의 멤버 변수에 접근할 수 있도록.
	friend class ChainQueue; // friend 선언을 통해 Queue에서 ChainNode의 멤버 변수에 접근할 수 있도록.
private:
	int data; // 정수 데이타를 저장할 멤버 변수.
	ChainNode* next; // 다음 노드를 가르키기 위한 ChainNode 포인터 형 변수.
public:
	ChainNode(int data = 0,ChainNode* next = 0) { this->next = next, this->data = data; } // 생성자.
};

class ChainStack {
private:
	ChainNode* top; // 스택의 제일 마지막에 들어온 값을 저장하기 위한 ChainNode 포인터형 변수.
public:
	ChainStack() { top = 0; } // 생성시 top은 어느 데이터도 가르키지 않도록 NULL을 준다.
	void Push(const int&); // 데이터를 받아서 Stack에 채워넣는 멤버함수.
	int* Pop(int&); // top에 저장된 데이터에 접근해 해당 데이터를 Stack에서 삭제, 만약 Stack이 비어있다면 0을 아니라면 1을 출력하게 함.
	void PrintS(); // Stack내의 데이타들을 출력 (LIFO순).
};

class ChainQueue {
private:
	ChainNode* front, * rear; // 처음과 끝을 가르킬 top과 rear.
public:
	ChainQueue() { front = rear = 0; } // 생성시에는 top과 rear에 NULL을 저장.
	void Push(const int&); // Stack의 끝에 새로운 데이타를 추가.
	int* Pop(int&); // Stack의 front에 저장된 데이타를 빼냄.
	void PrintQ(); // Queue내의 데이타들을 출력 (FIFO순)
};

void ChainStack:: Push(const int& x) {
	top = new ChainNode(x, top); // next가 가르키는 방향 top -> 제일 처음 노드 -> NULL 방향.
}

int* ChainStack::Pop(int& retvalue) { // PPT를 참고하여 만들었습니다.
	if (top == NULL) return 0;
	ChainNode* delNode = top;
	retvalue = top->data;
	top = top->next;
	delete delNode;
	return &retvalue;
}

void ChainStack::PrintS() {
	ChainNode* temp = top;
	if (top == 0) cout << "스택이 비어있습니다." << endl; // top이 가르키는 주소가 NULL이라면 스택이 비었음.
	else { // 스택의 값들을 출력.
		cout << "Stack(LIFO 순): ";
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << '\n';
	}
}

void ChainQueue::Push(const int& x) {
	if (front == 0) {
		front = rear = new ChainNode(x, 0); // front가 NULL값을 가진다면 이는 Queue가 비었다는 의미!.
	}
	else {
		rear=rear->next = new ChainNode(x, 0); // next가 가르키는 방향 front -> rear 방향.
	}
}

int* ChainQueue::Pop(int& retvalue) {
	if (front == NULL) return 0;
	ChainNode* delNode = front;
	retvalue = front->data;
	front = front->next; // rear에 대한것은 바꿔줄 필요가 없다. 그 이유는 Push에서도 Pop에서도 front를 이용해 Queue_empty를 판단했기 때문.
	delete delNode;
	return &retvalue;
}

void ChainQueue::PrintQ() {
	ChainNode* temp = front;
	if (front == 0)cout << "큐가 비어있습니다." << endl;
	else {
		cout << "Queue(FIFO 순): ";
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}

		cout << '\n';
	}
}
int* Input(int* n)
{
	int i = 0;
	do {
		if (i > 1) return 0; // i가 2가 되게 되면 이는 명령어의 개수가 이상하게 전달된 것이므로 NULL 반환.
		cin >> n[i]; // 입력을 받아 넣는다.
		if (cin.fail()) return 0; // 입력의 실패시 cin.fail()이 1의 값을 반환한다. 입력의 실패라면 return 0!
		i++;
	} while (cin.get() != '\n'); // 

	if (n[0] == 1 || n[0] == 2) { // 명령어가 삽입이라면 당연히 입력으로 사용자로부터 2개의 값을 받았어야 겠죠?
		if (i == 1) return 0; // i가 1이라면 삽입인데 삽입할 데이타가 없다는 뜻!. 그러므로 return 0!
	}
	else {
		if (i == 2) return 0; // 다른 명령어는 당연히 뒤에 이상한 데이타가 이어서 나오면 안됩니다.
	}

	return n; // 단순히 Input이 제대로 이루어졌나 확인하는 용도.
}
void Menual()
{
	cout << left << setw(20) << "1. 스택에 삽입";
	cout << left << "2. 큐에 삽입" << endl;
	cout << left << setw(20) << "3. 스택에서 삭제";
	cout << left << "4. 큐에서 삭제" << endl;
	cout << left << setw(20) << "5. 스택 내용 보기";
	cout << left << "6. 큐 내용 보기" << endl;
	cout << left << "프로그램을 종료하시려면 0을 입력해주세요!" << endl;
}

int main()
{
	int arr[2]; // index 0에는 실행할 명령,
	int retvalue;
	ChainQueue myQueue;
	ChainStack myStack;
	

	Menual();

	while (1)
	{
		if (Input(arr)) {
			switch (arr[0]) {
			case 0:
				cout << "프로그램을 종료합니다." << endl;
				return 0;
			case 1:
				myStack.Push(arr[1]);
				break;
			case 2:
				myQueue.Push(arr[1]);
				break;
			case 3:
				if(!myStack.Pop(retvalue)) cout << "빈 스택을 대상으로는 삭제가 불가능합니다." << endl;
				break;
			case 4:
				if(!myQueue.Pop(retvalue)) cout << "빈 큐를 대상으로는 삭제가 불가능합니다." << endl;
				break;
			case 5:
				myStack.PrintS();
				break;
			case 6:
				myQueue.PrintQ();
				break;
			default:
				cout << "잘못된 입력입니다." << endl;
				return 1;
			}
			
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			return 1;
		}
	}

	return 0;
	
}

