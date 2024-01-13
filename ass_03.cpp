#pragma once
//Noor Fatima
//J 
//22i-1036

#include<iostream>
#include <string>
using namespace std;
template <typename T>
#define int_max 123456789

class Node_1
{
	T data;
	T first_element;
	Node_1<T>* next;
public:
	Node_1()
	{
		data = -1;
		first_element = -1;
		next = nullptr;
	}
	void setFirstelement(T a)
	{
		first_element = a;
	}
	T getFirstelement()
	{
		return first_element;
	}
	Node_1(T a, Node_1<T>* b)
	{
		data = a;
		first_element = -1;
		next = b;
	}
	void setData(T d)
	{
		data = d;
	}
	void setNext(Node_1<T>* n)
	{
		next = n;
	}
	T getData()
	{
		return data;
	}
	Node_1<T>* getNext()
	{
		return next;
	}
};
template <typename T>
class Stack
{
public:
	Node_1<T>* top;
	Stack(int ignored = 0)
	{
		top = nullptr;
	}
	bool isEmpty()
	{
		if (top == nullptr)
			return 1;
		return 0;
	}
	void push(const T dataitem)
	{
		if (top == nullptr)
		{
			top = new Node_1<T>(dataitem, nullptr);
			top->setFirstelement(dataitem);
		}
		else
		{
			Node_1<T>* n_node = new Node_1<T>(dataitem, nullptr);
			n_node->setNext(top);
			top = n_node;
		}
	}
	void pop()
	{
		if (isEmpty() == 0)
		{
			Node_1<T>* val = top;
			top = top->getNext();
			delete val;
		}
		else
			throw std::runtime_error("stack is empty");
	}
	void print()
	{
		if (isEmpty() != 1)
		{
			Node_1<T>* cur = top;
			while (cur != nullptr)
			{
				cout << cur->getData() << " ";
				cur = cur->getNext();
			}
		}

	}
	T peek()
	{
		if (isEmpty() != 1)
		{
			return top->getData();
		}
		else
			throw std::runtime_error("stack is empty");
	}
	void clear()
	{
		while (isEmpty() != 1)
		{
			pop();
		}
	}
	~Stack()
	{
		delete top;
	}
	int size()
	{
		int count = 0;
		Node_1<T>* t = top;
		while (t != nullptr)
		{
			count++;
			t = t->getNext();
		}
		return count;
	}
	T bottom()
	{
		return top->getFirstelement();
	}
};


//O(n+k) or more specifically it is O(n) where n is the length of the string as it iterates through the whole string
//QUESTION-1
string largestString(string str, int k)
{
	
	Stack<char> stack;	//stack of type char
	string resultant;
	int i = 0;
	stack.push(str[i]);
	i++;
	while (str[i] != '\0')
	{
		if (stack.isEmpty() != 1 && k > 0 && str[i] > stack.peek())	//if stacck emptry skip or if k<0 skip or if the current character is < top of stack skip
		{
			while (stack.isEmpty() != 1 && k > 0 && str[i] > stack.peek())//if not skipped then pop top and decrement k
			{
				stack.pop();
				k--;
			}
		}
		stack.push(str[i]);	//push in stack 
		i++;
	}
	if (k != 0)	//incase not all characters were removed and more need to be removed 
	{
		while (k != 0 && stack.isEmpty() != 1)
		{
			stack.pop();
			k--;
		}
	}
	while (stack.isEmpty() != 1)	//pop from the stack and add to string
	{
		resultant = stack.peek() + resultant;	//stores in the correct order no need to reverse 
		stack.pop();
	}
	cout << endl<<resultant << endl;
	return resultant;
	//return your resultant string
}


//O(n+k) or more specically O(n)
//QUESTION-2
string solve(string number, int k)
{
	Stack<char> stack;
	int len = 0;
	while (number[len] != '\0')		//finding length of the string
		len++;

	if (k == len || k > len)		//incase len is qual to the number of character to be removed return "0"
		return "0";
	if (k == 0)	//incase no characters required to be removed just return the string 
		return number;
	stack.push(number[0]);
	int d = 0;
	for (int i = 1; i < len; i++)	//works for the length of the string
	{
		char temp = number[i];
		if (stack.isEmpty() != 1 && temp < stack.peek() && k>0)
		{
			while (!stack.isEmpty() && temp < stack.peek() && k>0)
			{
				k--;
				stack.pop();
			}
		}
		if (temp == '0')
			k--;
		stack.push(temp);
	}

	if (k != 0) // if k is not zero, remove them from the top of the stack.
	{
		while (k > 0 && stack.isEmpty() != 1)
		{
			stack.pop();
			k--;
		}
	}

	string result = "";
	while (stack.isEmpty() != 1)
	{
		result = stack.peek() + result;	//using what is left in stack to constructuct the final string
		stack.pop();
	}
	int i = 0;
	int l = 0;
	while (result[l] != '\0')	//lengthi
		l++;
	while (i < l)	//for leading 0
	{
		if (result[i] != '0')
			break;
		i++;
	}

	//if there are leading 
	if (i == l)
	{
		return "0";  // all 0
	}
	string ans = "";

	while (i < l)
	{
		ans += result[i];
		i++;
	}
	cout << endl << ans << endl;
	return ans;

}

class Node
{
	int data;
	Node* next;
public:
	Node()
	{
		data = -1;
		next = nullptr;
	}
	Node(int a, Node* v)
	{
		data = a;
		next = v;
	}
	void setData(int a)
	{
		data = a;
	}
	void setNext(Node* a)
	{
		next = a;
	}
	int getData()
	{
		return data;
	}
	Node* getNext()
	{
		return next;
	}


};

//O(size) where size is the size of the input array
//QUESTION-3
class Queue
{
public:
	Node* front;
	Node* rear;
	Queue()
	{
		front = nullptr;
		rear = nullptr;
	}
	bool is_empty()
	{
		if (front == nullptr && rear == nullptr)
			return 1;
		return 0;

	}
	Queue(Queue& a)
	{
		front = nullptr;
		rear = nullptr;
		if (a.is_empty() != true)
		{
			Node* cur = a.front;
			while (cur->getNext() != nullptr)
			{
				this->enqueue(cur->getData());
				cur = cur->getNext();
			}
			this->enqueue(cur->getData());
		}
	}
	void enqueue(int a)
	{
		Node* n_node = new Node(a, NULL);
		//= new Node(a, nullptr);
		n_node->setData(a);
		n_node->setNext(nullptr);
		if (is_empty() == 1)
		{
			rear = n_node;
			front = n_node;
		}
		else
		{
			rear->setNext(n_node);
			rear = n_node;
		}
	}
	int dequeue()
	{
		//Node<T>* r_node = nullptr;
		int d;
		if (is_empty() == 1)
		{
			cout << "sorry queue is emptt\n";
			return int_max;
		}
		else
		{

			if (front->getNext() != nullptr)
			{
				d = front->getData();
				Node* t = front->getNext();;
				delete front;
				front = t;
			}
			else
			{
				d = front->getData();;
				Node* t = nullptr;
				delete front;
				front = nullptr;;
				rear = nullptr;
			}

			return d;

		}
	}
	int size()
	{
		int count = 0;
		Node* c = front;
		if (c == nullptr)
			return 0;
		while (c->getNext() != nullptr)
		{
			count++;
			c = c->getNext();
		}
		if (c != nullptr)
			count++;
		return count;
	}
	int peek()
	{
		if (is_empty() != 1)
			return front->getData();
	}
	void clear()
	{
		while (front != nullptr)
			dequeue();
	}
	void print(Queue q)
	{
		Node* current = q.front;
		while (current != nullptr)
		{
			cout << current->getData() << " ";
			current = current->getNext();
		}
		cout << endl;
	}
	int Front()
	{
		if (is_empty() != 1)
			return front->getData();;
		return -1;
	}
};

int* maxSubsequence(int nums[], int size, int k)
{
	//Write your solution here you must return a pointer to the array(your resultant array)
	int* resultant = nullptr;
	Queue queue;
	//int size = sizeof(nums) / sizeof(nums[0]);
	for (int i = 0; i < size; i++)
	{
		queue.enqueue(nums[i]);
	}
	int max = 0;
	int p = 0;	//prev
	for (int i = 0; i < k; i++)
		max += nums[i];
	int m = 0; int sum = 0;
	for (int i = 0; i < size; i++)
	{

		if (m < k)		//3,-1,-2,4, 6, -2, 2, 4, 6, -1
		{
			sum += nums[i];
			m++;

		}
		if (m == k)
		{
			if (max < sum)
			{
				max = sum;
				queue.dequeue();
			}
			i = p;
			p = i + 1;
			if (i + k >= size)
				break;
			m = 0;
			sum = 0;
		}
		/*if (i + k >=size)
			break;*/
	}
	//tranversing again to find which
	int s = queue.size();
	resultant = new int[s];
	//	cout << queue.size();
	int n = 0; sum = 0; int prev = 0; bool f = 0;
	int* final = nullptr;
	for (n = 0; n < s; n++)
	{
		resultant[n] = queue.dequeue();
	}
	if (n == k)
		return resultant;
	else
	{
		for (int i = 0; i < n; i++)
		{

			sum += resultant[i];
			if (i - prev == k - 1)
			{
				if (sum != max)
				{
					resultant[prev] = int_max;
					i = prev;
					prev = i + 1;
					sum = 0;
				}
				else if (sum == max)
				{
					f = 1;
					break;
				}
			}
		}
	}

	if (f == 1)
	{
		int l = 0;
		final = new int[k];
		for (int i = 0; i < n; i++)
		{
			if (resultant[i] == int_max)
				continue;
			if (l == k)
				break;
			final[l] = resultant[i];
			l++;
		}
	}
	return final;
}
