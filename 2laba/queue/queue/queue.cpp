<<<<<<< HEAD
п»ї#include "stdafx.h"

using namespace std;
class Queue 
{
	static const int SIZE = 100;
	string *queue;
	int first, last;
=======
#include "stdafx.h"

using namespace std;
class Queue {
	static const int SIZE = 100;
	string *queue;
	int frnt, rear;
>>>>>>> origin/master
public:
	Queue();
	void push(string task);
	void out();
	int size();
	void pop();
<<<<<<< HEAD
	void find(string str);
	string front();
	string back();
};

Queue::Queue()
{
	queue = new string[SIZE];
	first = last = 0;
}

void Queue::out()
{
	for (int i = first + 1; i<last + 1; i++)
		cout << queue[i] << " ";
}

void Queue::push(string task)
{
	if (last + 1 == first || (last + 1 == SIZE && !first))
	{
		cout << "queue is full" << endl;
		return;
	}
	last++;
	if (last == SIZE) last = 0;
	queue[last] = task;
}

void Queue::pop()
{
	if (first == last)
	{
		cout << "queue is empty" << endl;
		return;
	}
	first++;
	if (first == SIZE) first = 0;
}

int Queue::size() 
{
	int s = 0;
	for (int i = first; i<last; i++)
		s++;
	return s;
}

void Queue::find(string str)
{
	string *p;
	int len = sizeof(queue);
	p = std::find(queue, queue + len, str);
	if (*p == str)
	{
		cout << "Found!" << endl;
	}
	else
	{
		cout << "Not found" << endl;
	}
	
}

string Queue::back() 
{
	return queue[last];
}

string Queue::front() 
{
	return queue[first + 1];
=======
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
>>>>>>> origin/master
}

void info()
{
<<<<<<< HEAD
	cout << "Enter the priority using numbers 1-5\n"
		<< "... - exit from queue\n"
		<< "-1 - exit from programm\n"
		<< "-2 - print total queue" << endl;
}

void WriteToQueueFromFile(Queue q, ifstream &input)
{
	int priority;
	string str;
	getline(input, str);
	input >> str;
	q.push(str);
	q.out();
}

void workWithQueues(Queue q1, Queue q2, Queue q3, Queue q4, Queue q5)
{
	string task;
=======
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
>>>>>>> origin/master
	int priority;
	string exit;
	info();
	while (exit != "Exit")
	{
<<<<<<< HEAD

		cout << "Enter the priority: ";
		cin >> priority;

		switch (priority)
		{
		case 1:
			while (task != "...")
			{
				cout << "Enter the element in queue of " << priority << " priority: ";
				cin >> task;
				if (task != "...")
					q1.push(task);
			}
			q1.out();
			cout << endl;
			task = "";
			break;
		case 2:
			while (task != "...")
			{
				cout << "Enter the element in queue of " << priority << " priority: ";
				cin >> task;
				if (task != "...")
					q2.push(task);
			}
			q2.out();
			cout << endl;
			task = "";
			break;
		case 3:
			while (task != "...")
			{
				cout << "Enter the element in queue of " << priority << " priority: ";
				cin >> task;
				if (task != "...")
					q3.push(task);
			}
			q3.out();
			cout << endl;
			task = "";
			break;
		case 4:
			while (task != "...")
			{
				cout << "Enter the element in queue of " << priority << " priority: ";
				cin >> task;
				if (task != "...")
					q4.push(task);
			}
			q4.out();
			cout << endl;
			task = "";
			break;
		case 5:
			while (task != "...")
			{
				cout << "Enter the element in queue of " << priority << " priority: ";
				cin >> task;
				if (task != "...")
					q5.push(task);
			}
			q5.out();
			cout << endl;
			task = "";
			break;
		case -1:
			exit = "Exit";
			cout << "Program is over" << endl;
			break;
		case -2:
			q5.out();
			q4.out();
			q3.out();
			q2.out();
			q1.out();
			cout << endl;
			break;
		default:
			cout << "Incorrect input!" << endl;
			break;
		}
	}
}


int main() {
	Queue queue1;
	Queue queue2;
	Queue queue3;
	Queue queue4;
	Queue queue5;
	system("chcp 1251");
	system("cls");
	//workWithQueues(queue1, queue2, queue3, queue4, queue5);
	ifstream input("in.txt");
	WriteToQueueFromFile(queue1, input);
=======
		
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
>>>>>>> origin/master
	return 0;
}