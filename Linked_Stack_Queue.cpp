// Stack & Queue Program using ChainNode, by Youngwoo Kim, email: rdd0426@gmail.com
// Directory
// Line 7 ~ ? : declaration for classes 
// Line ? ~ ? : main function.
#include <iostream>
#include <iomanip>

using namespace std;

class ChainStack;
class ChainQueue;
class ChainNode {
	friend class ChainStack; // friend ������ ���� Stack���� ChainNode�� ��� ������ ������ �� �ֵ���.
	friend class ChainQueue; // friend ������ ���� Queue���� ChainNode�� ��� ������ ������ �� �ֵ���.
private:
	int data; // ���� ����Ÿ�� ������ ��� ����.
	ChainNode* next; // ���� ��带 ����Ű�� ���� ChainNode ������ �� ����.
public:
	ChainNode(int data = 0,ChainNode* next = 0) { this->next = next, this->data = data; } // ������.
};

class ChainStack {
private:
	ChainNode* top; // ������ ���� �������� ���� ���� �����ϱ� ���� ChainNode �������� ����.
public:
	ChainStack() { top = 0; } // ������ top�� ��� �����͵� ����Ű�� �ʵ��� NULL�� �ش�.
	void Push(const int&); // �����͸� �޾Ƽ� Stack�� ä���ִ� ����Լ�.
	int* Pop(int&); // top�� ����� �����Ϳ� ������ �ش� �����͸� Stack���� ����, ���� Stack�� ����ִٸ� 0�� �ƴ϶�� 1�� ����ϰ� ��.
	void PrintS(); // Stack���� ����Ÿ���� ��� (LIFO��).
};

class ChainQueue {
private:
	ChainNode* front, * rear; // ó���� ���� ����ų top�� rear.
public:
	ChainQueue() { front = rear = 0; } // �����ÿ��� top�� rear�� NULL�� ����.
	void Push(const int&); // Stack�� ���� ���ο� ����Ÿ�� �߰�.
	int* Pop(int&); // Stack�� front�� ����� ����Ÿ�� ����.
	void PrintQ(); // Queue���� ����Ÿ���� ��� (FIFO��)
};

void ChainStack:: Push(const int& x) {
	top = new ChainNode(x, top); // next�� ����Ű�� ���� top -> ���� ó�� ��� -> NULL ����.
}

int* ChainStack::Pop(int& retvalue) { // PPT�� �����Ͽ� ��������ϴ�.
	if (top == NULL) return 0;
	ChainNode* delNode = top;
	retvalue = top->data;
	top = top->next;
	delete delNode;
	return &retvalue;
}

void ChainStack::PrintS() {
	ChainNode* temp = top;
	if (top == 0) cout << "������ ����ֽ��ϴ�." << endl; // top�� ����Ű�� �ּҰ� NULL�̶�� ������ �����.
	else { // ������ ������ ���.
		cout << "Stack(LIFO ��): ";
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << '\n';
	}
}

void ChainQueue::Push(const int& x) {
	if (front == 0) {
		front = rear = new ChainNode(x, 0); // front�� NULL���� �����ٸ� �̴� Queue�� ����ٴ� �ǹ�!.
	}
	else {
		rear=rear->next = new ChainNode(x, 0); // next�� ����Ű�� ���� front -> rear ����.
	}
}

int* ChainQueue::Pop(int& retvalue) {
	if (front == NULL) return 0;
	ChainNode* delNode = front;
	retvalue = front->data;
	front = front->next; // rear�� ���Ѱ��� �ٲ��� �ʿ䰡 ����. �� ������ Push������ Pop������ front�� �̿��� Queue_empty�� �Ǵ��߱� ����.
	delete delNode;
	return &retvalue;
}

void ChainQueue::PrintQ() {
	ChainNode* temp = front;
	if (front == 0)cout << "ť�� ����ֽ��ϴ�." << endl;
	else {
		cout << "Queue(FIFO ��): ";
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
		if (i > 1) return 0; // i�� 2�� �ǰ� �Ǹ� �̴� ��ɾ��� ������ �̻��ϰ� ���޵� ���̹Ƿ� NULL ��ȯ.
		cin >> n[i]; // �Է��� �޾� �ִ´�.
		if (cin.fail()) return 0; // �Է��� ���н� cin.fail()�� 1�� ���� ��ȯ�Ѵ�. �Է��� ���ж�� return 0!
		i++;
	} while (cin.get() != '\n'); // 

	if (n[0] == 1 || n[0] == 2) { // ��ɾ �����̶�� �翬�� �Է����� ����ڷκ��� 2���� ���� �޾Ҿ�� ����?
		if (i == 1) return 0; // i�� 1�̶�� �����ε� ������ ����Ÿ�� ���ٴ� ��!. �׷��Ƿ� return 0!
	}

	return n; // �ܼ��� Input�� ����� �̷������ Ȯ���ϴ� �뵵.
}
void Menual()
{
	cout << left << setw(20) << "1. ���ÿ� ����";
	cout << left << "2. ť�� ����" << endl;
	cout << left << setw(20) << "3. ���ÿ��� ����";
	cout << left << "4. ť���� ����" << endl;
	cout << left << setw(20) << "5. ���� ���� ����";
	cout << left << "6. ť ���� ����" << endl;
	cout << left << "���α׷��� �����Ͻ÷��� 0�� �Է����ּ���!" << endl;
}

int main()
{
	int arr[2]; // index 0���� ������ ���,
	int retvalue;
	ChainQueue myQueue;
	ChainStack myStack;
	

	Menual();

	while (1)
	{
		if (Input(arr)) {
			switch (arr[0]) {
			case 0:
				cout << "���α׷��� �����մϴ�." << endl;
				return 0;
			case 1:
				myStack.Push(arr[1]);
				break;
			case 2:
				myQueue.Push(arr[1]);
				break;
			case 3:
				if(!myStack.Pop(retvalue)) cout << "�� ������ ������δ� ������ �Ұ����մϴ�." << endl;
				break;
			case 4:
				if(!myQueue.Pop(retvalue)) cout << "�� ť�� ������δ� ������ �Ұ����մϴ�." << endl;
				break;
			case 5:
				myStack.PrintS();
				break;
			case 6:
				myQueue.PrintQ();
				break;
			default:
				cout << "�������� �ʴ� ��ɾ��Դϴ�." << endl;
			}
			
		}
		else {
			cout << "�߸��� �Է��Դϴ�." << endl;
			return 1;
		}
	}

	return 0;
	
}

