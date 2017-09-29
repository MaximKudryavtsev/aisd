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
//Конструктор
Queue::Queue() {
	queue = new string[SIZE];
	frnt = rear = 0;
}
//Вывод элементов очереди
void Queue::out() {
	for (int i = frnt + 1; i<rear + 1; i++)
		cout << queue[i] << " ";
}
//Помещение элемента в очередь
void Queue::push(string task) {
	if (rear + 1 == frnt || (rear + 1 == SIZE && !frnt)) {
		cout << "очередь полна" << endl;
		return;
	}
	rear++;
	if (rear == SIZE) rear = 0;
	queue[rear] = task;
}
// Извлечение элемента из очереди
void Queue::pop() {
	if (frnt == rear) {
		cout << "очередь пуста" << endl;
		return;
	}
	frnt++;
	if (frnt == SIZE) frnt = 0;
}
//Определение размера очереди
int Queue::size() {
	int s = 0;
	for (int i = frnt; i<rear; i++)
		s++;
	return s;
}
// Последний элемент очереди
string Queue::back() {
	return queue[rear];
}
// Первый элемент очереди
string Queue::front() {
	return queue[frnt + 1];
}

void info()
{
	cout << "Для ввода приоритета используйте цифры 1-5\n"
		<< "... - выход из очереди\n"
		<< "-1 - выход из программы\n"
		<< "-2 - вывод общей очереди" << endl;
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
		
			cout << "Введите приоритет очереди: ";
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
				cout << "Неверное значение!" << endl;
			}
			
			
		
	}
	return 0;
}