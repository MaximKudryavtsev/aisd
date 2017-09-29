#include "stdafx.h"

using namespace std;
class Queue {
	static const int SIZE = 100;
	string *queue;
	int frnt, rear;
public:
	Queue();
	void push(string task);
	void out();
	int size();
	void pop();
	string front();
	string back();
};
//�����������
Queue::Queue() {
	queue = new string[SIZE];
	frnt = rear = 0;
}
//����� ��������� �������
void Queue::out() {
	for (int i = frnt + 1; i<rear + 1; i++)
		cout << queue[i] << " ";
}
//��������� �������� � �������
void Queue::push(string task) {
	if (rear + 1 == frnt || (rear + 1 == SIZE && !frnt)) {
		cout << "������� �����" << endl;
		return;
	}
	rear++;
	if (rear == SIZE) rear = 0;
	queue[rear] = task;
}
// ���������� �������� �� �������
void Queue::pop() {
	if (frnt == rear) {
		cout << "������� �����" << endl;
		return;
	}
	frnt++;
	if (frnt == SIZE) frnt = 0;
}
//����������� ������� �������
int Queue::size() {
	int s = 0;
	for (int i = frnt; i<rear; i++)
		s++;
	return s;
}
// ��������� ������� �������
string Queue::back() {
	return queue[rear];
}
// ������ ������� �������
string Queue::front() {
	return queue[frnt + 1];
}

void info()
{
	cout << "��� ����� ���������� ����������� ����� 1-5\n"
		<< "... - ����� �� �������\n"
		<< "-1 - ����� �� ���������\n"
		<< "-2 - ����� ����� �������" << endl;
}

int main() {
	Queue queue1;
	Queue queue2;
	Queue queue3;
	Queue queue4;
	Queue queue5;
	string task;
	system("chcp 1251");
	system("cls");
	int priority;
	string exit;
	info();
	while (exit != "Exit")
	{
		
			cout << "������� ��������� �������: ";
			cin >> priority;

			switch (priority)
			{
			case 1:
				while (task != "...")
				{
					cin >> task;
					if (task != "...")
						queue1.push(task);
				}
				queue1.out();
				cout << endl;
				task = "";
				break;
			case 2:
				while (task != "...")
				{
					cin >> task;
					if (task != "...")
						queue2.push(task);
				}
				queue2.out();
				cout << endl;
				task = "";
				break;
			case 3:
				while (task != "...")
				{
					cin >> task;
					if (task != "...")
						queue3.push(task);
				}
				queue3.out();
				cout << endl;
				task = "";
				break;
			case 4:
				while (task != "...")
				{
					cin >> task;
					if (task != "...")
						queue4.push(task);
				}
				queue4.out();
				cout << endl;
				task = "";
				break;
			case 5:
				while (task != "...")
				{
					cin >> task;
					if (task != "...")
						queue5.push(task);
				}
				queue5.out();
				cout << endl;
				task = "";
				break;
			case -1:
				exit = "Exit";
				break;
			case -2:
				queue5.out();
				queue4.out();
				queue3.out();
				queue2.out();
				queue1.out();
				cout << endl;
				break;
			default:
				cout << "�������� ��������!" << endl;
			}
			
			
		
	}
	return 0;
}