#include "stdafx.h"

using namespace std;
class Queue
{
	static const int SIZE = 100;
	string *queue;
	int first, last;
public:
	Queue();
	void push(string task);
	void push_first(string task);
	void out();
	int size();
	void pop();
	void deleteEl(string task);
	bool find(string str);
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
	for (int i = first + 1; i <= last + 1; i++)
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

void Queue::push_first(string task)
{
	if (last + 1 == first || (last + 1 == SIZE && !first))
	{
		cout << "queue is full" << endl;
		return;
	}

	if (last == SIZE) last = 0;
	last++;
	for (int i = 0; i < last; i++)
		queue[last - i] = queue[last - i - 1];
	queue[first + 1] = task;

}

void Queue::pop()
{
	last--;
	if (first == SIZE) first = 0;
	if (first == last)
	{
		cout << "Queue is empty" << endl;
		return;
	}
}

void Queue::deleteEl(string task)
{
	int k = 0;

	for (int i = 0; i <= last; i++)
	{
		if (queue[i] == task)
			k = i;
	}
	queue[k].erase();
	last--;
}

int Queue::size()
{
	int s = 0;
	for (int i = first; i < last; i++)
		s++;
	return s;
}

bool Queue::find(string str)
{
	string *p;
	int len = sizeof(queue);
	p = std::find(queue, queue + len, str);
	if (*p == str) return false;
}

string Queue::back()
{
	return queue[last];
}

string Queue::front()
{
	return queue[first + 1];
};

void info()
{
	cout << "Enter the priority using numbers 1-5\n"
		<< "<...> - exit from queue\n"
		<< "<show> - print current queue\n"
		<< "<exit> - exit from programm\n"
		<< "<total> - print total queue\n"
		<< "<restr> - to restruct queue" << endl;
}

string ReturnString(ifstream &input, int priority)
{
	string str;
	string strings[5];
	for (int i = 0; i < 5; i++)
	{
		getline(input, str);
		strings[i] = str;
	}
	strings[priority - 1][0] = NULL;
	strings[priority - 1][1] = NULL;
	return strings[priority - 1];
}

Queue WriteToQueueFromFile(Queue q, int priority)
{
	ifstream input("in.txt");
	string str = ReturnString(input, priority);
	std::regex regex("[a-zA-Z0-9\\+\\*\\?\\!\\%\\^\\(\\)\\-\\@\\$\\#\\&]+");

	for (std::sregex_token_iterator it(begin(str), end(str), regex), last; it != last; ++it)
		q.push(*it);
	return q;
}

Queue AddElementsToQueue(Queue q, string priority, string task)
{
	while (task != "...")
	{
		cout << "Enter the element in queue of " << priority << " priority: ";
		cin >> task;
		if ((task != "...") && (task != "show"))
			q.push(task);
		else if (task == "show")
			q.out();
		cout << endl;
		if (q.size() == 0)
			cout << "Queue is empty" << endl;
	}
	cout << endl;
	return q;
}

Queue IdentifyNumebrQueue(Queue q1, Queue q2, Queue q3, Queue q4, Queue q5, int num)
{
	Queue QueArr[] = { q1, q2, q3, q4, q5 };
	return QueArr[num - 1];
}

void workWithQueues(Queue q1, Queue q2, Queue q3, Queue q4, Queue q5)
{
	string task;
	string priority;
	string exit;
	info();
	q1 = WriteToQueueFromFile(q1, 1);
	q2 = WriteToQueueFromFile(q2, 2);
	q3 = WriteToQueueFromFile(q3, 3);
	q4 = WriteToQueueFromFile(q4, 4);
	q5 = WriteToQueueFromFile(q5, 5);
	while (exit != "Exit")
	{
		cout << "Enter the priority: ";
		cin >> priority;
		if (priority == "1")
		{
			q1 = AddElementsToQueue(q1, priority, task);
			task = "";
		}
		else if (priority == "2")
		{
			q2 = AddElementsToQueue(q2, priority, task);
			task = "";
		}
		else if (priority == "3")
		{
			q3 = AddElementsToQueue(q3, priority, task);
			task = "";
		}
		else if (priority == "4")
		{
			
			q4 = AddElementsToQueue(q4, priority, task);
			task = "";
		}
		else if (priority == "5")
		{
			q5 = AddElementsToQueue(q5, priority, task);
			task = "";
		}
		else if (priority == "total")
		{
			q5.out();
			q4.out();
			q3.out();
			q2.out();
			q1.out();
			cout << endl;
		}
		else if (priority == "exit")
		{
			exit = "Exit";
			cout << "Program is over" << endl;
		}
		else if (priority == "restr")
		{

			int from;
			int to;
			string task;
			cout << "From queue of priority: ";
			cin >> from;
			cout << "To queue of priority: ";
			cin >> to;
			cout << "Task: ";
			cin >> task;
			Queue QFrom = IdentifyNumebrQueue(q1, q2, q3, q4, q5, from);
			Queue Qto = IdentifyNumebrQueue(q1, q2, q3, q4, q5, to);
			if (QFrom.find(task))
				cout << "this task not found!" << endl;
			else if (from > to)
			{
				Qto.push_first(task);
				QFrom.deleteEl(task);
			}
			else if (from < to)
			{
				Qto.push(task);
				QFrom.deleteEl(task);
			}

			QFrom.out();
			cout << QFrom.size() << endl;
			Qto.out();
			cout << Qto.size() << endl;
			
		}
		else
		{
			cout << "Unknown command" << endl;
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
	workWithQueues(queue1, queue2, queue3, queue4, queue5);
	return 0;
}
