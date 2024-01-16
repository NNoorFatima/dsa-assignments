#pragma once
#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>
int ID = 1;
using namespace std;

class TNode
{
public:
	int taskID;
	string description;
	int priority;
	string ass_ID;
	TNode* left;
	TNode* right;
	TNode* parent;
	string color;
	bool complete;
	TNode()
	{
		left = right = parent = nullptr;
	}
	TNode(int id, string d, int p, string a_id)
	{
		complete = 0;
		taskID = id;
		left = right = parent = nullptr;
		description = d;
		ass_ID = a_id;
		priority = p;
		color = "red";
	}

};

class ANode
{
public:
	string ass_ID = "0";
	string first_name;
	string last_name;
	string address;
	string DOB;
	ANode* left;
	ANode* parent;
	string color;
	ANode* right;
	ANode()
	{
		left = right = parent = nullptr;

	}
	ANode(string f, string l, string a, string d)
	{
		color = "red";
		DOB = d;
		address = a;
		last_name = l;
		first_name = f;
		ass_ID = generateID();
		parent = left = right = nullptr;

	}
	string generateID()
	{
		ostringstream o;
		o << "A" << setfill('0') << setw(3) << ID;
		ID++;
		return o.str();
	}
};

template <class T>
class Node
{
public:
	T data;
	Node* next;
	

};

//
template <class T>
class Queue
{
public:
	Node<T>* front;
	Node<T>* rear;
	Queue()
	{
		rear=front = nullptr;
		 
	}
	bool empty()
	{
		if (front == nullptr)
		{
			return 1;
		}
		return 0;
	}
	void push(T item)
	{
		Node<T>* curr = front;
		Node<T>* n_node = new Node<T>();	///new item
		n_node->next = nullptr;
		n_node->data = item;

		if (curr == nullptr)
		{
			front = new Node<T>();
			front->next = nullptr;
			front->data = item;
			return;	//return if valeu added 
		}
	
		while (curr->next != nullptr)	//tranverse to find where is tail and isert at tail 
		{
			curr = curr->next;
		}
		curr->next = n_node;
		rear = curr->next;
	}
	T pop()
	{
		Node<T>* t = new Node<T>();
		t = front;
		front = t->next;	//change value of front make it point to the next value in list
		return t->data;
	}
	T Front()
	{
		Node<T>* node =front;
		if (node == nullptr)
		{
			return T();
		}
		return node->data;
	}
	int size()
	{
		int count = 0;
		Node<T>* cur = front;
		while (cur->next != nullptr)
		{
			count++;
			cur = cur->next;
		}
		count++;
		return count;
	}
	void clear()
	{
		while (front != nullptr)
			pop();
	}
};





class taskManagementSystem
{
public:
	TNode* tasks;
	ANode* assignee;
	taskManagementSystem()	///constructor
	{
		tasks = nullptr;
		assignee = nullptr;
		ID = 1;
	}
	void inorderTransversal(TNode* root)
	{
		if (root != nullptr)
		{
			inorderTransversal(root->left);		//go to left
			cout << root->taskID << " " << root->color << endl;		//print taskid and color
			inorderTransversal(root->right);		//go to right
		}
	}
	void inorderTransversal(ANode* root)
	{
		if (root != nullptr)
		{
			inorderTransversal(root->left);
			cout << root->ass_ID << " " << root->color << endl;
			inorderTransversal(root->right);
		}
	}
	void inorder()
	{
		inorderTransversal(tasks);
		inorderTransversal(assignee);
	}
//tasks
	void addTask(int id, string d, int p, string a_id)
	{
		TNode* n_node = new TNode(id, d, p, a_id);
		TNode* parent = nullptr;
		if (tasks == nullptr)	//add to root if null and make its color balck 
		{
			tasks = n_node;
			n_node->color = "black";
			n_node->parent = nullptr;
		}
		else
		{
			TNode* cur = tasks;	//using current to transverse through the tree
			while (1)
			{
				if (n_node->priority <= cur->priority && cur->left == nullptr)	//insert to left and break 
				{
					cur->left = n_node;
					n_node->parent = cur;
					break;
				}
				else if (n_node->priority < cur->priority)	//move to left if value is lesss
				{
					parent = cur;
					cur = cur->left;
				}
				else if (n_node->priority >= cur->priority && cur->right == nullptr) //insert t right and break 
				{
					cur->right = n_node;
					n_node->parent = cur;	
					break;
				}
				else if (n_node->priority > cur->priority)
				{
					parent = cur;		//mveo to right 
					cur = cur->right;
				}
			}
			fix(n_node);	//ensure properties are ebing followed
		}
	}
	void leftrotate(TNode* t)
	{
		TNode* K2 = t->right;	//this will become the new mid node 
		t->right = K2->left;	
		//K2->left = t;
		if (K2->left != nullptr)
		{
			K2->left->parent = t;
		}
		K2->parent = t->parent;
		if (t->parent == nullptr)
		{
			tasks = K2;
		}
		else if (t == t->parent->left)
		{
			t->parent->left = K2;
		}
		else
		{
			t->parent->right = K2;
		}

		K2->left = t;
		t->parent = K2;
		//height wali cheezain 

	}
	void rightrotate(TNode* k1)
	{
		TNode* k2 = k1->left;		// the new mid node 
		k1->left = k2->right;

		if (k2->right != nullptr)
		{
			k2->right->parent = k1;
		}
		k2->parent = k1->parent;
		if (k1->parent == nullptr)
		{
			tasks = k2;
		}
		else if (k1 == k1->parent->left)
		{
			k1->parent->left = k2;
		}
		else
		{
			k1->parent->right = k2;
		}
		k2->right = k1;
		k1->parent = k2;
		//height wali cheezain
	}
	
	void fix(TNode* z)
	{
		
		/*TNode* par = z->parent;
		TNode* grandpa = z->parent->parent;*/
		while (z->parent != nullptr && z->parent->color == "red")
		{
			if (z->parent == z->parent->parent->left)	//in case it is the z's parent is the left child
			{
				TNode* uncle = z->parent->parent->right;		//uncle
				if (uncle != nullptr && uncle->color == "red")
				{
					// Case 1: Red uncle
					z->parent->color = "black";		//left and right of grandpa
					uncle->color = "black";		//right
					z->parent->parent->color = "red";	//grandfather
					z = z->parent->parent;
				}
				else
				{
					if (z == z->parent->right)// if z is the right child 
					{
						//  if it is true for case 2 then a LR rotation is hapenning 
						z = z->parent;
						leftrotate(z);
					}
					// 
					z->parent->color = "black";
					z->parent->parent->color = "red";
					rightrotate(z->parent->parent);
				}
			}
			else
			{
				
				TNode* uncle = z->parent->parent->left;
				if (uncle != nullptr && uncle->color == "red")
				{
					//
					z->parent->color = "black";//change parent and uncle color to black 
					uncle->color = "black";		
					z->parent->parent->color = "red";
					z = z->parent->parent;
				}
				else
				{
					if (z == z->parent->left)	//if this condition is fulfilled then RL rotation
					{
						// Case 2 
						z = z->parent;
						rightrotate(z);
					}
					// 
					z->parent->color = "black";
					z->parent->parent->color = "red";
					leftrotate(z->parent->parent);
				}
			}
			if (z == tasks)
				break;
		}
		tasks->color = "black";	//root shoudl always be black

	}
	//used
	void countTotalTasks(std::ostream& out)
	{
		//put all tasks in a queue
		//return the queue and the queue size is the total number of tasks
		Queue<TNode*> tk;
		inorder(tasks, tk);	//storing all tasks nodes in queue
		int size = tk.size();
		out<< "Total Tasks in the System: "<<size<<'\n';
	}
	void searchTasksByPriorityRange(int i, int j, std::ostream& out)
	{
		
		//out << "Tasks within Priority Range (1 to 2):\n";
		if (tasks == nullptr)	//incase no nodes
			return;
		else
		{
			out << "Tasks within Priority Range (" << i << " to " << j << "):\n";	//
			TNode* cur = tasks;
			//find the priority i in tasks
			while (cur->priority != i)	//reach staring prioroty 
			{
				if (i < cur->priority)
					cur = cur->left;
				else if (i > cur->priority)
					cur = cur->right;
				if (i == cur->priority)
				{
					ANode* node = searchbyID(cur->ass_ID);
					out << "Task ID: " << cur->taskID << ", Description: " << cur->description << ", Priority: "
						<< cur->priority << ", Assignee: " << node->first_name << " (" << cur->ass_ID << ")\n";
					break;
				}
			}
			cur = tasks;
			while (1)
			{
				if (j < cur->priority)
				{
					if(cur->priority>i)
					{
						ANode* node = searchbyID(cur->ass_ID);
						out << "Task ID: " << cur->taskID << ", Description: " << cur->description << ", Priority: "
							<< cur->priority << ", Assignee: " << node->first_name << " (" << cur->ass_ID << ")\n";
					}
					cur = cur->left;
				}
				else if (j > cur->priority)
				{
					if(cur->priority>i)
					{
						ANode* node = searchbyID(cur->ass_ID);
						out << "Task ID: " << cur->taskID << ", Description: " << cur->description << ", Priority: "
							<< cur->priority << ", Assignee: " << node->first_name << " (" << cur->ass_ID << ")\n";
					}
					cur = cur->right;
				}
				if (j == cur->priority)
				{
					ANode* node = searchbyID(cur->ass_ID);
					out << "Task ID: " << cur->taskID << ", Description: " << cur->description << ", Priority: "
						<< cur->priority << ", Assignee: " << node->first_name << " (" << cur->ass_ID << ")\n";
					break;
				}
			}
		}
		
	}
	//used
	void ShiftTask(string a1, string a2)
	{
		if (tasks == nullptr)  //incase no tasks 
			return;
		else
		{
			TNode* a1_node = nullptr;
			TNode* a2_node = nullptr;
			Queue<TNode*> rk;
			bool f1 = 0, f2 = 0;
			inorder(tasks, rk);	//stores all elements of the tasks in rk queue
			while (rk.empty() != 1)
			{
				if (a1_node == nullptr && rk.Front()->ass_ID == a1)
				{
					f1 = 1;	//when ass id 1 is found
					rk.pop();
				}
				else if (a2_node == nullptr && rk.Front()->ass_ID == a2)
				{
					f2 = 1;	//when ass id 2 is found
					rk.pop();
				}
				else
					rk.pop();	//otherwise keeping popping till queue is not empty 
				if (f1 == 1 && f2 == 1)
					break;	//in case both string id are foudn break from loop 
			}
			if(f1==1&&f2==1)		//call helper fucntion 
				shift(tasks, a1_node, a2_node, a1, a2);	//call shift tasks
			//shift(tasks,a1_node, a2_node);
			
		}
	}
	void shift(TNode*& t,TNode* p, TNode* q,string a,string b)	//helper fucniton 
	{
		if (t == nullptr)	//no tasks the return null
			return ;
		if (p != nullptr && q != nullptr)	//incase both nodes are found 
		{
			return;	//here nodes are the ones jinke tasks shift hone hain 
		}
		else
		{
			if (p==nullptr && t->ass_ID == a)
			{
				p = t;	//if ass id 1 is found move that node to p
				t->ass_ID = b;		//also chnage the assignee performing hte tasks 
			}
			else if (q == nullptr && t->ass_ID == b)
			{
				q = t;		//if ass id 2 is found mov that to node q
				//t->ass_ID = a;
			}	
			 shift(t->left, p, q, a, b);	//recursive call to left
			 shift(t->right, p, q, a, b);	//calll to right
		}
	}
	void printTaskQueue(std::ostream& out)
	{
		inorder(tasks, out);	//helper function
	}
	void inorder(TNode* t, std::ostream& out)
	{
		if (t == nullptr)	//if null return 
			return;
		inorder(t->left, out);	//mov to left
		ANode* node = searchbyID(t->ass_ID);
		if (t->complete == 0)	//print only tasks whicch are still not done 
		{
			out << "Task ID: " << t->taskID << ", Description: " << t->description << ", Priority: " << t->priority
				<< ", Assignee: " << node->first_name << " (" << t->ass_ID << ")\n";
		}
		inorder(t->right, out);	//recursive call to right 
	}

	//used
	void findHighestPriorityTask(std::ostream& out)
	{
		//store values of red black tree in a queue
		//search for the lowest priority value
		Queue<TNode*> tk;
		inorder(tasks, tk);	//storing value in queue
		TNode* cur = tk.Front();
		tk.pop();
		while (tk.empty() != 1)//loop till queue is empty 
		{
			if (cur->priority >= tk.Front()->priority)
			{
				cur = tk.Front();
				tk.pop();
			}
			else
				tk.pop();	//leep popping
		}
		ANode* node = searchbyID(cur->ass_ID);
		out << "Highest Priority Task: "
			<< "Task ID: " << cur->taskID
			<< ", Description: " << cur->description
			<< ", Priority: " << cur->priority
			<< ", Assignee: " << node->first_name << " (" << cur->ass_ID << ")\n";
		inorder(tasks, tk);
		while (tk.empty() != 1)	//this is in case more than two nodes have same priority 
		{
			if (tk.Front()->priority == cur->priority && cur->taskID!=tk.Front()->taskID)
			{
				TNode* n = tk.Front();
				tk.pop();
				ANode* node = searchbyID(n->ass_ID);
				out << "Highest Priority Task: "
					<< "Task ID: " << n->taskID
					<< ", Description: " << n->description
					<< ", Priority: " << n->priority
					<< ", Assignee: " << node->first_name << " (" << n->ass_ID << ")\n";
			}
			else
				tk.pop();
		}
		
	}
	void updateTaskPriority(int id, int n)
	{
		if (tasks == nullptr)
			return;
		else
		{
			TNode* temp = nullptr;
			findTask(id, tasks, temp);
			string description = temp->description;
			string aid = temp->ass_ID;
			
			if (temp != nullptr)		//means it was previously in the tasks list
			{
				deleteTask(id);	//delete it 
				addTask(id, description, n, aid);	//create a new tasks with same description and ass_id as before just with different priority 
			}
		}
	}
	void findTask(int id, TNode* t,TNode* &temp)
	{
		if(t!=nullptr)	//
		{
			findTask(id, t->left,temp);	//recursive left
			if (t->taskID == id)
			{
				temp = t;
				
			}
			findTask(id, t->right,temp);	//recursive right
		}

	}
	

	void property_1(TNode*& t)	//root is black
	{
		if (t->color == "black")
			return;
		t->color = "black";
	}
	//used
	void property_2(TNode*& t)	//leaf nodes are red as their null are considered as black
	{
		Queue<TNode*> tk;
		inorder(tasks, tk);
		bool found = 0;
		TNode* arr = new TNode[tk.size()];
		int size = tk.size();
		for (int i = 0; i < size; i++)
		{
			TNode *t = tk.Front();
			tk.pop();
			arr[i].ass_ID = t->ass_ID;
			arr[i].taskID = t->taskID;
			arr[i].priority = t->priority;
			arr[i].description = t->description; 
			arr[i].complete = t->complete;
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				if (arr[j].priority > arr[j + 1].priority)
				{
					TNode temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
					found = 1;
				}
			}
		}
		if (found == 1)
		{
			taskManagementSystem n;
			//TNode* new_tasks = nullptr;
			for (int i =size-1 ; i>=0; i--)
			{
				n.addTask(arr[i].taskID, arr[i].description, arr[i].priority, arr[i].ass_ID);
			}
			tasks = nullptr;
			tasks = n.tasks;
		}
	}
	//used
	void findTasksByAssignee(string id, std::ostream& out)
	{
		if (tasks != nullptr)
		{
			Queue<TNode*> tk;
			ANode* a = searchbyID(id);		//get assignee details 

			out << "Tasks Assigned to \"" << a->first_name << " (" << a->ass_ID << ")"<<"\"" << ":\n";
			//out << "Tasks Assigned to \"Wusqa (A001)\":\n";
			inorder(tasks, tk);	//store all tasks in queu 
			while (tk.empty() != 1)
			{
				TNode* n = tk.Front();

				tk.pop();
				if (n->ass_ID == id)	//onve the id is equal to cur ass id store its details in output 
				{
					ANode* a = searchbyID(id);
					out << "Task ID: " << n->taskID
						<< ", Description: " << n->description
						<< ", Priority: " << n->priority
						<< ", Assignee: " << a->first_name << " (" << n->ass_ID << ")\n";
				}
			}
		}

	}
	void completeTask(int id)
	{
		if (tasks != nullptr)
		{
			completeTask_help(tasks, id);//helper
		}
	}
	void completeTask_help(TNode* &t, int id)
	{
		if (t == nullptr)
			return;
		else
		{
			completeTask_help(t->left, id);	//recursice left 
			if (t->taskID == id)	//if id found mark as complete
			{
				t->complete = 1;
				return;
			}
			completeTask_help(t->right, id);	//recursive right 
		}
	}
	//used
	void displayCompletedTasks(std::ostream& out)
	{
		if (tasks != nullptr)	//makes sure tasks list is not empty 
		{
			out << "Completed Tasks:\n";
			Queue<TNode*> tk;
			inorder(tasks, tk);	//store in queue 
			while (tk.empty() != 1)	//loops till queue is not empty
			{
				TNode* n = tk.Front();
				tk.pop();
				if (n->complete == 1)	//onlu if tasks is complete sotre details in O/P
				{
					ANode* a = searchbyID(n->ass_ID);
					out << "Task ID: " << n->taskID
						<< ", Description: " << n->description
						<< ", Priority: " << n->priority
						<< ", Assignee: " << a->first_name << " (" << n->ass_ID << ")\n";
				}
			}
		}
	}
	void PrintTreeInorder(std::ostream& out)
	{
		inordercolor(tasks, out);
	}
	void inordercolor(TNode* t, std::ostream& out)
	{
		if (t != nullptr)
		{
			inordercolor(t->left, out);
			out << t->taskID << " (" << t->color << ")\n";
			inordercolor(t->right, out);
		}
	}
	void deleteTask(int id)
	{
		taskdelete(tasks, id);
	}
	void taskdelete(TNode* t, int id)
	{
		if (t == nullptr)
			return;
		else
		{
			taskdelete(t->left, id);
			if (t->taskID == id)		//deletion only happens if tasks is in the tasks lit
			{
				deletion(t);	//helper
				if (tasks->color == "red")		//ensure root is black
					tasks->color = "black";
				return;
			}
			taskdelete(t->right, id);
		}
	}
	void deletion(TNode* &nodedelete)
	{
		TNode* a;
		TNode* b;
		if (nodedelete->left == nullptr || nodedelete->right == nullptr)	//handles case of one child
		{
			if (nodedelete->right == nullptr)	//handles case of no child 
				b = nodedelete;
			b = nodedelete;
		}
		else
		{
			b = nodedelete->left;			//handles case when two child
			//try to find the immediate value before the node you wwanted tp delete
			while (b->right != nullptr)
				b = b->right;	//predecessor
		}
		if (b->right != nullptr)	//finding the value of a 
		{
			a = b->right;
		}
		else
		{
			a = b->left;
		}
		if (a != nullptr)		//changing the link between three nodes and their parents 
		{
			a->parent = b->parent;
		}
		if (b->parent == nullptr) //root
		{
			tasks = a;				//assign value of deleted node's child as its replacement 
		}
		else if (b->parent->right == b) //in case it is right child of parent
		{
			b->parent->right = a;		//assign value of deleted node's child as its replacement 
		}
		else							//in case it is left child of parent
		{
			b->parent->left = a;		//assign value of deleted node's child as its replacement 
		}

		if (nodedelete != b)	//fri two children 
		{
			//copy contents of the value to delte
			nodedelete->ass_ID = b->ass_ID;	//replacing with values of predecessor 
			nodedelete->taskID = b->taskID;
			nodedelete->color = b->color;
			nodedelete->priority = b->priority;
			nodedelete->complete = b->complete;
			nodedelete->description = b->description;
		}
		if (b->color == "black")
		{
			deletefix_task(a, b);	//in case color 
			delete b;
		}
		else if (b->color == "red")
		{
			delete b;	//handles case of one child or no child 
		}
	}
	void deletefix_task(TNode* x, TNode* y)
	{
		if (x != tasks)		
		{
			while (x == nullptr || x->color == "black")	//loop swhile black or nullptr
			{
				if (x != nullptr && x == x->parent->left)	//left child 
				{
					TNode* uncle = x->parent->right;//uncle
					if (uncle->color == "red")	//checking ccolor of uncle and perform rotation accordingly 
					{
						x->parent->right->color = "black";
						x->parent->color = "red";
						leftrotate(x->parent);
					}
					else//if uncle is black 
					{
						if (uncle->left == nullptr || uncle->left->color == "black")
						{
							if (uncle != nullptr)	//means this is leaf node so must be red as nil nodes are balck 
								uncle->color = "red";
							x = x->parent;
						}
						else
						{
							uncle->color = "red";		//ensuring two red are not on after another 
							uncle->left->color = "black";
							rightrotate(uncle);	//for balanc e
						}
					}
				}
				else if (x != nullptr && x->parent->right == x)		//case of right child 
				{
					TNode* uncle = x->parent->left;//uncle
					if (uncle->color == "red")
					{
						 
						x->parent->color = "black";	//parent is black children are red in case of leaf nodes
						x->parent->left->color = "red";//uncle color
						rightrotate(x->parent);
					}
					else if (uncle->color == "black")
					{
						if (uncle->right->color == "black" || uncle->right == nullptr)
						{
							if (uncle != nullptr)	//case fo leaf node
								uncle->color = "red";
							x->parent->color = "black";	//else not leaf then make blakc 
							leftrotate(x->parent);
						}
						else if (uncle->right->color == "red" && uncle->right != nullptr)
						{
							uncle->color = x->parent->color;
							x->parent->color = "black";
							uncle->right->color = "black";
							leftrotate(x->parent);
						}
					}
				}
				else if (x == nullptr)
				{
					if (y->parent->left == x)
					{
						leftrotate(y->parent);
						if (y->parent->parent->color == "red")
						{
							y->parent->parent->color = "black";
						}
						y->parent->right->color = "red";
					}
					else if (y->parent->right == x)
					{
						rightrotate(y->parent);
						if (y->parent->parent->color == "red")
						{
							y->parent->parent->color = "black";
						}
						y->parent->left->color = "red";
					}
					break;
				}
				x = x->parent;
			}
		}
		if (x != nullptr)
			x->color = "black";
	}



	//assignee
	void addAssignee(string f, string l, string a, string d)
	{
		ANode* n_node = new ANode(f, l, a, d);
		ANode* parent = nullptr;
		if (assignee == nullptr)		//add to root 
		{
			assignee = n_node;
			n_node->color = "black";
			n_node->parent = nullptr;
		}
		else
		{
			ANode* cur = assignee;	//cur used to transverse through the tree
			while (1)
			{
				if (n_node->ass_ID < cur->ass_ID && cur->left == nullptr)//bst adding
				{
					cur->left = n_node;
					n_node->parent = cur;
					break;
				}
				else if (n_node->ass_ID < cur->ass_ID)
				{
					parent = cur;
					cur = cur->left;
				}
				else if (n_node->ass_ID > cur->ass_ID && cur->right == nullptr)
				{
					cur->right = n_node;
					n_node->parent = cur;
					break;
				}
				else if (n_node->ass_ID > cur->ass_ID)
				{
					parent = cur;
					cur = cur->right;
				}
			}
			//if(parent->color=="red")
			fix(n_node);
		}
	}
	void leftrotate(ANode* t)
	{
		ANode* K2 = t->right;	//assign node ka rigth child to k2
		t->right = K2->left;	//right of k2 left is now t->right
		if (K2->left != nullptr)
			K2->left->parent = t;

		K2->parent = t->parent;

		if (t->parent == nullptr)
			assignee = K2;
		else if (t == t->parent->left)
			t->parent->left = K2;
		else
			t->parent->right = K2;

		K2->left = t;
		t->parent = K2;
		//height wali cheezain 

	}
	void rightrotate(ANode* k1)
	{
		ANode* k2 = k1->left;
		k1->left = k2->right;

		if (k2->right != nullptr)
			k2->right->parent = k1;

		k2->parent = k1->parent;

		if (k1->parent == nullptr)
			assignee = k2;
		else if (k1 == k1->parent->left)
			k1->parent->left = k2;
		else //if right child
			k1->parent->right = k2;
		k2->right = k1;
		k1->parent = k2;
		//height wali cheezain
	}
	void fix(ANode* z)
	{
		
		/*ANode* par = z->parent;
		ANode* grandpa = z->parent->parent;*/
		while (z->parent != nullptr && z->parent->color == "red") 
		{
			if (z->parent == z->parent->parent->left)	//in case of left child 
			{
				ANode* uncle = z->parent->parent->right;		//uncle

				if (uncle != nullptr && uncle->color == "red") 
				{
					// Case 1: Red uncle
					z->parent->color = "black";		//left and right of grandpa
					uncle->color = "black";
					z->parent->parent->color = "red";
					z = z->parent->parent;
				}
				else 
				{
					if (z == z->parent->right) 
					{
						//  if case 2 is true then a LR rotation is hapenning
						z = z->parent;
						leftrotate(z);
					}

					//  case of left heavy so we perform rugth rotation 
					z->parent->color = "black";
					z->parent->parent->color = "red";
					rightrotate(z->parent->parent);
				}
			}
			else
			{
				// same case for the right subtree
				ANode* uncle = z->parent->parent->left;

				if (uncle != nullptr && uncle->color == "red") 
				{
					// Case 1 
					z->parent->color = "black";
					uncle->color = "black";
					z->parent->parent->color = "red";
					z = z->parent->parent;
				}
				else 
				{
					if (z == z->parent->left) 
					{
						// Case 2 if true for this case then a RL rotation is hapennign 
						z = z->parent;
						rightrotate(z);
					}

					// Case 3 case of right heavy
					z->parent->color = "black";
					z->parent->parent->color = "red";
					leftrotate(z->parent->parent);	//left rotate grandpa
				}
			}
		}
		assignee->color = "black";	//make sure root is back 

	}
	void displaybyID(std::ostream& out, string id)
	{
		ANode* a1 = searchbyID(id);
		if (a1 != nullptr)
		{
			out << "Name: " << a1->first_name << " " << a1->last_name << ", "
				<< "Address: " << a1->address << ", "
				<< "DOB: " << a1->DOB << ", "
				<< "Assignee ID: " << a1->ass_ID << '\n';
		}
		else
		{
			out << "Assignee not found\n";
		}
		
	}
	ANode* searchbyID(string id)
	{
		ANode* ass_1 = nullptr;
		if (assignee == nullptr)
			return nullptr;
		else
		{
			ANode* cur = assignee;
			while (cur!=nullptr)
			{
				if (id == cur->ass_ID)
				{
					ass_1 = cur;
					return ass_1;
				}
				else if (id < cur->ass_ID)
				{
					cur = cur->left;
				}
				else if (id > cur->ass_ID)
				{
					cur = cur->right;
				}
			}
		}
		return nullptr;
		
	}
	//used
	void displaybyname(std::ostream& out, string fi, string la)
	{
		if (assignee != nullptr)
		{
			Queue<ANode*> as ;
			as.push(assignee);
			while (as.empty() != 1)
			{
				ANode* temp = as.Front();
				as.pop();
				if (temp->first_name == fi && temp->last_name == la)
				{
					out << "Name: " << temp->first_name << " " << temp->last_name << ", "
						<< "Address: " << temp->address << ", "
						<< "DOB: " << temp->DOB << ", "
						<< "Assignee ID: " << temp->ass_ID << '\n';
					if (temp->left != nullptr)
						as.push(temp->left);
					if (temp->right != nullptr)
						as.push(temp->right);
				}
				else
				{
					if (temp->left != nullptr)
						as.push(temp->left);
					if (temp->right != nullptr)
						as.push(temp->right);
				}
			}		
		}
	}
	//used
	void AssigneeWithNoTask(std::ostream& out)
	{
		//move all tasks in the queue of tk
		Queue<TNode*> tk;
		if (tasks == nullptr && assignee != nullptr)	//incase non of the assignee have been assigned tasks
		{
			ANode* cur = assignee;
			Queue<ANode*> ak;
			ak.push(cur);
			while (cur != nullptr)
			{
				ANode* temp = ak.Front();
				ak.pop();
				out << "Name: " << temp->first_name << " " << temp->last_name << ", "
					<< "Address: " << temp->address << ", "
					<< "DOB: " << temp->DOB << ", "
					<< "Assignee ID: " << temp->ass_ID << '\n';
				if (temp->left != nullptr)
					ak.push(temp->left);
				if (temp->right != nullptr)
					ak.push(temp->right);
			}
		}
		else
		{
			//tk =
			inorder(tasks, tk);	//storing all tasks in a queue
			int size = tk.size();		//findign the size of the tasks queue
			ANode* cur = assignee;
			//storing all the ass_id from the tasks queue in a string array
			string *ar = new string[size];	//arr that stores the ass_ID which are present in the tasks queue
			int i = 0;
			while (tk.empty() != 1)	//stroing in array
			{	
				TNode* t = tk.Front();
				tk.pop();
				ar[i] = t->ass_ID;
				i++;
			}
			//store all the assignee in a queue
			Queue<ANode*> ak;
			inorder(assignee, ak);		//storing all assignees in the ak queue
			int a_size = ak.size();
			for (int i = 0; i < a_size; i++)
			{
				bool found = 0;
				for (int j = 0; j < size; j++)
				{
					if(ar[j]==ak.Front()->ass_ID)
					{
						found = 1;
						ak.pop();
						break;
					}
				}
				if (found == 0)
				{
					ANode* nd = ak.Front();
					ak.pop();
					out << "Name: " << nd->first_name << " " << nd->last_name << ", "
						<< "Address: " << nd->address << ", "
						<< "DOB: " << nd->DOB << ", "
						<< "Assignee ID: " << nd->ass_ID << '\n';
				}
			}
		}	
	}
	//used
	void inorder(ANode* t, Queue<ANode*>& ak)
	{
		if (t == nullptr)
			return;
		else
		{
			inorder(t->left, ak);
			ak.push(t);
			inorder(t->right, ak);
		}
		return;
	}
	void inorder(TNode* t,Queue<TNode*>& tk)
	{
		if (t == nullptr)
			return;
		else
		{
			inorder(t->left,tk);
			tk.push(t);
			inorder(t->right, tk);	
		}
		return;
	}
	
	void DeleteAssignee(string id)
	{
		//now check if this assignee has tasks assigned or not
		//create a queue and store whole tasks tree in it 
		// pop if id is not same till queue is empty
		// if in queue value found then return from funcrion seedhi seedhi baat
		Queue<TNode*> tk;
		inorder(tasks, tk);
		while (tk.empty() != 1)
		{
			if (tk.Front()->ass_ID == id)
				return;
			else
				tk.pop();
		}
		//finding the node inthe assignee tree
		if (assignee != nullptr)
		{
			ANode* cur = assignee;
			while (cur != nullptr)
			{
				if (cur->ass_ID == id)
				{
					deleteassigneenode(cur);
					if (assignee->color == "red")//root must be black
						assignee->color = "black";
					return;
				}
				else if (id < cur->ass_ID)
				{
					cur = cur->left;
				}
				else if (id > cur->ass_ID)
				{
					cur = cur->right;
				}
				
			}
		}

	}
	void deleteassigneenode(ANode*& nodedelete)
	{
		ANode* a; 
		ANode* b; 
		if (nodedelete->left == nullptr || nodedelete->right==nullptr)	//handles case of one child
		{
			if (nodedelete->right == nullptr)	//handles case of no child 
				b = nodedelete;
			b = nodedelete;
		}
		else	
		{
			b = nodedelete->left;			//handles case when two child
			//try to find the immediate value before the node you wwanted tp delete
			while (b->right != nullptr)
				b = b->right;	//predecessor
		}
		if (b->right != nullptr)//finding value of a 
		{
			a = b->right;
		}
		else
		{
			a = b->left;
		}
		if (a != nullptr)	//creatign  link between predessors parents and child
		{
			a->parent = b->parent;
		}
		if (b->parent == nullptr) //root
		{
			assignee = a;				//assign value of deleted node's child as its replacement 
		}
		else if (b->parent->right == b) //in case it is right child of parent
		{
			b->parent->right = a;		//assign value of deleted node's child as its replacement 
		}
		else							//in case it is left child of parent
		{
			b->parent->left = a;		//assign value of deleted node's child as its replacement 
		}

		if (nodedelete!=b)	//fri two children 
		{
			//copy contents of the value to delte
			nodedelete->ass_ID = b->ass_ID;	//replacing with values of predecessor 
			nodedelete->address = b->address;
			nodedelete->color = b->color;
			nodedelete->DOB = b->DOB;
			nodedelete->first_name = b->first_name;
			nodedelete->last_name = b->last_name;
		}
		if (b->color == "black")
		{
			deletefix(a, b);	//colro fix
			delete b;
		}
		else if(b->color=="red")
		{
			delete b;	//handles case of one child or no child 
		}
	}
	void deletefix(ANode* x, ANode* y)
	{
		if (x != assignee)
		{
			while (x == nullptr || x->color == "black")
			{
				if (x!=nullptr && x == x->parent->left)		//case of left child 
				{
					ANode* uncle = x->parent->right;//uncle
					if (uncle->color == "red")
					{
						x->parent->right->color = "black";
						x->parent->color = "red";
						leftrotate(x->parent);
					}
					else
					{
						if (uncle->left == nullptr || uncle->left->color == "black")
						{
							if (uncle != nullptr)	//if uncle is leaf node color must be red 
								uncle->color = "red";
							x = x->parent;
						}
						else
						{
							uncle->color = "red";
							uncle->left->color = "black";
							rightrotate(uncle);
						}
					}
				}	
				else if(x!=nullptr && x->parent->right==x)	//case of rihgt child 
				{
					ANode* uncle = x->parent->left;//uncle
					if (uncle->color == "red")
					{
						x->parent->left->color = "red";
						x->parent->color = "black";
						rightrotate(x->parent);
					}
					else if(uncle->color=="black")
					{
						if ( uncle->right->color == "black" || uncle->right == nullptr )
						{
							if (uncle!= nullptr)		//if unclue is leaf node color must be red and nil nodes are black 
								uncle->color = "red";
							x->parent->color = "black";
							leftrotate(x->parent);
						}
						else if(uncle->right->color=="red" && uncle->right!=nullptr)	
						{
							uncle->color = x->parent->color;	//chnage uncle color ro its parents 
							x->parent->color = "black";
							uncle->right->color = "black";
							leftrotate(x->parent);
						}
					}
				}
				else if (x == nullptr)
				{
					if (y->parent->left == x)
					{
						leftrotate(y->parent);
						if (y->parent->parent->color == "red")
						{
							y->parent->parent->color = "black";
						}
						y->parent->right->color = "red";
					}
					else if (y->parent->right == x)
					{
						rightrotate(y->parent);
						if (y->parent->parent->color == "red")
						{
							y->parent->parent->color = "black";
						}
						//else if (y->parent->left->color == "black");
						y->parent->left->color = "red";
					}
					break;
				}
				x = x->parent;
			}
		}
		if (x != nullptr)
			x->color = "black";		///
	}
	void DisplayAssignee(std::ostream& out)
	{
		inorder(assignee, out);
	}
	void inorder(ANode* t, std::ostream& out)
	{
		if (t == nullptr)
			return;
		else
		{
			inorder(t->left, out);
			out << "Name: " << t->first_name << " " << t->last_name << ", "
				<< "Address: " << t->address << ", "
				<< "DOB: " << t->DOB << ", "
				<< "Assignee ID: " << t->ass_ID << '\n';
			inorder(t->right, out);
		}
	}
	void AssigneeInOrder(std::ostream& output)
	{
		colororder(assignee, output);
	}
	void colororder(ANode* a, std::ostream& o)
	{
		if (a == nullptr)
			return;
		else
		{ 
			colororder(a->left, o);
			o << a->ass_ID
				<< " (" << a->color << ")\n";
			colororder(a->right, o);
		}
	}
};