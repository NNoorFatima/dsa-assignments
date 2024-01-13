#pragma once
//#include "gtest/gtest.h"
//Noor Fatima, 22i-1036_J A2
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class Node
{
public:
	int location;
	Node* next;
	Node* prev;
	Node* down;
	Node* up;
	Node(int location_id)
	{
		location = location_id;
		next = NULL;
		prev = NULL;
		down = NULL;
		up = NULL;
	}
};

class Transport_Layer_optimization
{
public:
	int n, m, q;
	Node* head_m;
	Node* head_b;
	Node* head_w;
	Transport_Layer_optimization()
	{
		head_w = head_b = head_m = NULL;
		m = n = q = 0;
	}
	void addNode(int layer, int Location_id)
	{
		Node* n_node = new Node(Location_id);
		Node* current;
		Node* prev;
		//prev and next were managed here as well as new node was added in correct layer
		if (layer == 1)		//n is layer 1 m is laer 2 q is layer 3
		{
			prev = head_m;
			current = head_m;
			if (head_m == nullptr)
				head_m = n_node;
			else
			{
				while (current->next != nullptr)
				{
					if (current->location > n_node->location)
					{
						break;
					}
					prev = current;
					current = current->next;
				}
				if (current->location > n_node->location)
				{
					Node* temp = prev->next;
					prev->next = n_node;
					current->prev = n_node;
					n_node->prev = prev;
					n_node->next = temp;
				}
				else
				{
					current->next = n_node;
					prev = current;
					current = current->next;
					current->prev = prev;
				}
			}
		}
		else if (layer == 2)
		{
			prev = head_b;
			current = head_b;
			if (head_b == nullptr)
				head_b = n_node;
			else
			{
				while (current->next != nullptr)
				{
					if (current->location > n_node->location)
					{
						break;
					}
					prev = current;
					current = current->next;
				}
				if (current->location > n_node->location)
				{
					Node* temp = prev->next;
					prev->next = n_node;
					current->prev = n_node;
					n_node->prev = prev;
					n_node->next = temp;
				}
				else
				{
					current->next = n_node;
					prev = current;
					current = current->next;
					current->prev = prev;
				}

			}
		}
		else if (layer == 3)
		{
			prev = head_w;
			current = head_w;
			if (head_w == nullptr)
				head_w = n_node;
			else
			{
				while (current->next != nullptr)
				{
					if (current->location > n_node->location)
					{
						break;
					}
					prev = current;
					current = current->next;
				}
				if (current->location > n_node->location)
				{
					Node* temp = prev->next;
					prev->next = n_node;
					current->prev = n_node;
					n_node->prev = prev;
					n_node->next = temp;
				}
				else
				{
					current->next = n_node;
					prev = current;
					current = current->next;
					current->prev = prev;
				}
			}
		}
		Node* current_m = head_m;
		Node* current_b = head_b;
		Node* current_w = head_w;
		//checking for up/down pointers for metro and bus 
		if (current_b != nullptr && current_m != nullptr)
		{
			if (current_b->location == current_m->location)
			{
				current_b->up = current_m;
				current_m->down = current_b;
			}
			while (current_b != nullptr && current_m != nullptr)
			{
				if (current_b->location == current_m->location)
				{
					current_b->up = current_m;
					current_m->down = current_b;
					current_b = current_b->next;
				}
				else if (current_b->location > current_m->location)
				{
					current_m = current_m->next;
				}
				else if (current_b->location < current_m->location)
				{
					current_b = current_b->next;
				}

			}
		}
		current_b = head_b;
		//up/down pointers for bus and walking
		if (current_b != nullptr && current_w != nullptr)
		{
			if (current_b->location == current_w->location)
			{
				current_b->down = current_w;
				current_w->up = current_b;
			}
			while (current_b != nullptr && current_w != nullptr)
			{
				if (current_b->location == current_w->location)
				{
					current_b->down = current_w;
					current_w->up = current_b;
					current_w = current_w->next;
				}
				else if (current_w->location > current_b->location)
				{
					current_b = current_b->next;
				}
				else if (current_w->location < current_b->location)
				{
					current_w = current_w->next;
				}
			}
		}


	}
	void DeleteNode(int layer, int location_id)
	{
		Node* current = nullptr;
		Node* prev = nullptr;

		//int count = 1;
	//	cout<<"sf";
		if (layer == 1)
		{
			//cout<<"Sf";
			if (head_m->next == NULL && location_id == head_m->location)
			{
				head_m = NULL;
			}
			else
			{
				prev = head_m;
				current = head_m;
				while (current != NULL)
				{
					if (current->location == location_id)
					{
						prev->next = current->next;
						current->down->up = nullptr;
						current->prev = NULL;
						current->down = NULL;
						current->next->prev = prev;
					}
					prev = current;
					current = current->next;
				}
			}
		}
		else if (layer == 2)
		{
			if (head_b->next == NULL && location_id == head_b->location)
			{
				head_b = NULL;
			}
			else
			{
				prev = head_b;
				current = head_b;
				while (current != NULL)
				{
					if (current->location == location_id)
					{
						prev->next = current->next;
						current->down->up = nullptr;
						current->up->down = nullptr;
						current->prev = nullptr;
						current->down = nullptr;
						current->up = nullptr;
						current->next->prev = prev;
					}
					prev = current;
					current = current->next;
				}
			}
		}
		else if (layer == 3)
		{
			if (head_w->next == NULL && location_id == head_w->location)
			{
				head_w = NULL;
			}
			else
			{
				prev = head_w;
				current = head_w;
				while (current != NULL)
				{
					if (current->location == location_id)
					{
						prev->next = current->next;
						current->prev = nullptr;
						current->up->down = nullptr;
						current->up = nullptr;
						current->next->prev = prev;
					}
					prev = current;
					current = current->next;
				}
			}

		}

	}
	void print()
	{
		//for metr0
		Node* current;
		if (head_m != NULL)
		{
			if (head_m->next == nullptr)
			{
				cout << head_m->location << " ";
			}
			else
			{
				current = head_m;
				while (current != nullptr)
				{
					cout << current->location << " ";
					current = current->next;
				}
			}
			cout << endl;
		}
		//bus
		if (head_b != NULL)
		{
			if (head_b->next == nullptr)
			{
				cout << head_b->location << " ";
			}
			else
			{
				current = head_b;
				while (current != nullptr)
				{
					cout << current->location << " ";
					current = current->next;
				}
			}
			cout << endl;
		}
		//walk
		if (head_w != NULL)
		{
			if (head_w->next == nullptr)
			{
				cout << head_w->location << " ";
			}
			else
			{
				current = head_w;
				while (current != nullptr)
				{
					cout << current->location << " ";
					current = current->next;
				}
			}
			cout << endl;
		}

	}
	string GetPath(int start, int end)
	{
		string path = "";
		int layer = 1;
		Node* current;
		Node* prev_1 = head_m;
		if (start < end)
		{
			current = head_m;
			if (current->location == start)
			{
				path += to_string(current->location) + "-" + to_string(layer) + "";;

				while (current->location != end)
				{
					//moving up
					if (layer != 1 && current->up != nullptr && current->location == current->up->location && prev_1 != current->up)
					{
						layer -= 1;
						path += " -> " + to_string(current->location) + "-" + to_string(layer);
						prev_1 = current;
						current = current->up;
					}
					//moving next
					else if (current->next != nullptr && current->next->location == (current->location) + 1 && prev_1 != current->next)
					{
						path += " -> " + to_string(current->next->location) + "-" + to_string(layer);
						prev_1 = current;
						current = current->next;
					}
					//moving down
					else if (layer != 3 && current->down != nullptr && current->location == current->down->location)
					{
						layer += 1;
						path += " -> " + to_string(current->location) + "-" + to_string(layer);
						prev_1 = current;
						current = current->down;
					}
					//moving previous 
					else if (current->prev != nullptr && (current->location) - 1 == current->prev->location)
					{
						path += " -> " + to_string(current->prev->location) + "-" + to_string(layer);
						prev_1 = current;
						current = current->prev;
					}
				}

				//string a = "";
				//string path_2 = "";
				//while (l != len)
				//{
				//	if (path[l] == ' ' || path[l] == '-' || path[l] == '>')
				//	{
				//		l++; continue;
				//		if (l == len)
				//			break;
				//	}
				//	//at a time read three characters 
				//	while (path[l] != ' ')
				//	{
				//		a += path[l]; l++;
				//		if (l == len)
				//			break;
				//	}
				//	string b = "";
				//	int n_time = 0;
				//	int k = l;
				//	while (k != len)
				//	{
				//		if (path[k] == ' ' || path[k] == '-' || path[k] == '>')
				//		{
				//			k+=4; continue;
				//			if (k == len)
				//				break;
				//		}
				//		//at a time read three characters 
				//		while (path[k] != ' ')
				//		{
				//			b += path[k]; k++;
				//			if (k == len)
				//				break;
				//		}
				//		if (a == b)
				//		{
				//			n_time++;
				//			/*if (n_time == 1)
				//				path_2 +=  " -> ";*/
				//		}
				//		
				//		b = "";
				//	}
				//	if (n_time == 0)
				//		path_2 += a + " -> ";
				//	a = "";
				//}
				// len = 0;
				//while (path_2[len] != '\0')
				//	len++;
				////checking path_2 order
				//int m = 0, i = 0;
				//while (i < len)
				//{
				//	m = 0;
				//	while (m <= len)
				//	{
				//		int l = m + 7;
				//		int t = m + 2 + 7;
				//		int f = m + 2;
				//		if (l > len || t > len || f>len)
				//			break;
				//		if (path_2[m] > path_2[m + 7])
				//		{
				//			if (path_2[m + 2] == path_2[m+2+7])
				//			{
				//				int te = path_2[m];
				//				path_2[m] = path_2[m + 7];
				//				path_2[m + 7] = te;
				//			}
				//		}
				//		m += 7;
				//	}
				//	i += 7;
				//}
				//cout << endl<<"SFS "<< path_2 << endl << endl;
			}
			else
			{
				while (current != nullptr && current->next != nullptr)
				{
					if (start == current->location)
					{
						break;
					}
					current = current->next;
				}
				if (current->next == nullptr && current->location != start)
				{
					current = head_b;
					while (current != nullptr && current->next != nullptr)
					{
						if (start == current->location)
						{
							layer = 2;
							break;
						}
						current = current->next;
					}
					if (current->location == start)
						layer = 2;
				}
				if (current->next == nullptr && current->location != start)
				{
					current = head_w;
					while (current != nullptr && current->next != nullptr)
					{
						if (start == current->location)
						{
							layer = 3;
							break;
						}
						current = current->next;
					}
					if (current->location == start)
						layer = 3;
				}

				path += to_string(current->location) + "-" + to_string(layer) + "";;

				while (current->location != end)
				{
					//moving up
					if (layer != 1 && current->up != nullptr && current->location == current->up->location && prev_1 != current->up)
					{
						layer -= 1;
						path += " -> " + to_string(current->location) + "-" + to_string(layer);
						prev_1 = current;
						current = current->up;
					}
					//moving next
					else if (current->next != nullptr && current->next->location == (current->location) + 1 && prev_1 != current->next)
					{
						path += " -> " + to_string(current->next->location) + "-" + to_string(layer);
						prev_1 = current;
						current = current->next;
					}
					//moving down
					else if (layer != 3 && current->down != nullptr && current->location == current->down->location)
					{
						layer += 1;
						path += " -> " + to_string(current->location) + "-" + to_string(layer);
						prev_1 = current;
						current = current->down;
					}
					//moving previous 
					else if (current->prev != nullptr && (current->location) == current->prev->location + 1)
					{
						path += " -> " + to_string(current->prev->location) + "-" + to_string(layer);
						prev_1 = current;
						current = current->prev;
					}
				}
			}
		}
		else if (start > end)
		{
			current = head_m;
			while (current != nullptr && current->next != nullptr)
			{
				if (start == current->location)
				{
					layer = 1;
					break;
				}
				current = current->next;
			}
			if (current->next == nullptr && current->location != start)
			{
				current = head_b;
				while (current != nullptr && current->next != nullptr)
				{
					if (start == current->location)
					{
						layer = 2;
						break;
					}
					current = current->next;
				}
				if (current->location == start)
					layer = 2;
			}
			if (current->next == nullptr && current->location != start)
			{
				current = head_w;
				while (current != nullptr && current->next != nullptr)
				{
					if (start == current->location)
					{
						layer = 3;
						break;
					}
					current = current->next;
				}
				if (current->location == start)
					layer = 3;
			}

			path += to_string(current->location) + "-" + to_string(layer) + "";
			prev_1 = current;
			while (current->location != end)
			{
				//moving up
				if (layer != 1 && current->up != nullptr && current->location == current->up->location && prev_1 != current->up)
				{
					layer -= 1;
					path += " -> " + to_string(current->location) + "-" + to_string(layer);
					prev_1 = current;
					current = current->up;
				}
				//moving previous
				else if (current->prev != nullptr && (current->location) == current->prev->location + 1 && current->prev != prev_1)
				{
					path += " -> " + to_string(current->prev->location) + "-" + to_string(layer);
					prev_1 = current;
					current = current->prev;
				}
				//moving down
				else if (layer != 3 && current->down != nullptr && current->location == current->down->location)
				{
					layer += 1;
					path += " -> " + to_string(current->location) + "-" + to_string(layer);
					prev_1 = current;
					current = current->down;
				}
				//moving next
				else if (current->next != nullptr && current->next->location == (current->location) + 1)
				{
					path += " -> " + to_string(current->next->location) + "-" + to_string(layer);
					prev_1 = current;
					current = current->next;
				}
			}
		}
		path = remove_path(path);
		return path;
	}
	string remove_path(string path)
	{
		int len = 0;
		bool dup = 0;
		while (path[len] != '\0')		//find length of the path
			len++;
		int i = 0;
		while (i < len)
		{
			string b = "";
			int k = i + 7;;
			while (path[i] != ' ' && path[i] != '\0')	//reads one value such as 1-1 or 2-1
			{
				b += path[i];
				i++;
			}
			while (k < len)
			{
				string a = "";

				if (path[k] == '-' || path[k] == '>' || path[k] == ' ')	//if encounter space or - or null then increments by 4
				{
					k += 4;
				}
				else
				{
					while (path[k] != ' ' && path[k] != '\0')	//works either next space is not found or the value is last (encounter null)
					{
						a += path[k];
						k++;
					}
					if (a == b)	//if a==b means duplicate found
					{
						dup = 1;
						//1-1 ...1-1
						for (int m = i; m < k; m++)	//substitutes # for dups
							path[m] = '#';
						break;
					}
				}
			}
			i += 4;
		}
		if (dup == 1)	//in case duplicate found
		{
			int n_hash = 0;
			i = 0;
			while (i < len)	//finds how many character it needs to remove
			{
				if (path[i] == '#')
					n_hash++;
				i++;
			}
			for (int i = 0; i < len; i++)
			{
				if (path[i] == '#')
				{
					for (int j = i; j < len - n_hash; j++)
					{
						path[j] = path[j + n_hash];
					}
				}
			}
			path.resize(len - n_hash);
		}
		return path;
	}
	void ReadFile(string filename)
	{
		//cout << "SD";
		string data = " ";
		int count = 0;
		fstream myfile;
		myfile.open(filename, ios::in);

		while (getline(myfile, data))
		{
			int i = 0;
			int met = 0;
			int bs = 0;
			int wlk = 0;
			while (data[i] != '\0' && count != 0)
			{
				if (count == 1)
				{
					string a;
					if (data[i] == ' ')
					{
						i++; met++;
						continue;
					}
					else
					{
						while (data[met] != ' ' && data[met] != '\0')
						{
							a += data[met]; met++;
						}
					}
					if (a == "" && data[met] == '\0')
						break;
					if (a == "")
					{
						met++;
						continue;
					}
					int b = stoi(a);
					addNode(1, b);
				}
				else if (count == 2)
				{
					string a;
					if (data[i] == ' ')
					{
						i++;
						if (data[bs] == '\0')
							bs--;
						else
						{
							bs++;
							continue;
						}
					}
					else
					{
						while (data[bs] != ' ' && data[bs] != '\0')
						{
							a += data[bs]; bs++;
						}
					}
					if (a == "" && data[bs] == '\0')
						break;
					if (a == "")
					{
						bs++; continue;
					}
					int b = stoi(a);
					addNode(2, b);
				}
				else if (count == 3)
				{
					string a;
					if (data[wlk] == ' ')
					{
						i++; wlk++;
						continue;
					}
					else
					{
						while (data[wlk] != ' ' && data[wlk] != '\0')
						{
							a += data[wlk]; wlk++;
						}
					}
					if (data[wlk] == '\n')
						break;
					if (a == "" && data[wlk] == '\0')
						break;
					if (a == "")
					{
						wlk++; continue;
					}
					//cout << stoi(a) << endl;
					int b = stoi(a);
					addNode(3, b);
					//print();
				}
				i++;
			}
			int c = 0;
			if (count == 0)
			{
				int l = 0;
				while (c != 3)
				{
					string a;
					while (data[l] != ' ' && data[l] != '\0')
					{
						a += data[l];
						//cout << data[l] << endl;
						l++;
					}
					l += 1;
					//cout << "out\n";
					int b = stoi(a);
					if (c == 0)
						n = b;
					else if (c == 1)
						m = b;
					else if (c == 2)
						q = b;
					c++;
				}
			}
			count++;
		}
		myfile.close();
	}
};


//q2
class way
{
public:
	way* next;
	way* prev;
	int distance;
	int current;
	int previous;
	way()
	{
		distance = 0;
		current = 0;
		previous = 0;
		next = prev = nullptr;

	}
	way(int n)
	{
		distance = 0;
		current = n;
		previous = n - 1;
		next = prev = nullptr;

	}
};
class Transport_Cost_Calculator
{
public:
	way* _way;
	Node* head_m;
	Node* head_b;
	int n;
	Node* head_w;
	Transport_Cost_Calculator()
	{
		_way = nullptr;
		head_m = nullptr;
		head_w = NULL;
		n = 0;
		head_b = nullptr;
	}
	void addNode(int layer, int Location_id)
	{
		Node* n_node = new Node(Location_id);
		Node* current;
		Node* prev;
		//prev and next were managed here as well as new node was added in correct layer
		if (layer == 1)		//n is layer 1 m is laer 2 q is layer 3
		{
			prev = nullptr;
			current = head_m;
			if (head_m == nullptr)
				head_m = n_node;
			else
			{
				while (current->next != nullptr)
				{
					current->prev = prev;
					prev = current;
					current = current->next;
				}
				current->next = n_node;
			}
		}
		else if (layer == 2)
		{
			prev = nullptr;
			current = head_b;
			if (head_b == nullptr)
				head_b = n_node;
			else
			{
				while (current->next != nullptr)
				{
					current->prev = prev;
					prev = current;
					current = current->next;
				}
				current->next = n_node;
			}
		}
		else if (layer == 3)
		{
			prev = nullptr;
			current = head_w;
			if (head_w == nullptr)
				head_w = n_node;
			else
			{
				while (current->next != nullptr)
				{
					current->prev = prev;
					prev = current;
					current = current->next;
				}
				current->next = n_node;
			}
		}
		Node* current_m = head_m;
		Node* current_b = head_b;
		Node* current_w = head_w;
		//checking for up/down pointers for metro and bus 
		if (current_b != nullptr && current_m != nullptr)
		{
			current_b->up = current_m;
			current_m->down = current_b;
			current_b = current_b->next;
			current_m = current_m->next;
		}
		current_b = head_b;
		//up/down pointers for bus and walking
		if (current_b != nullptr && current_w != nullptr)
		{
			current_w->up = current_b;
			current_b->down = current_w;
			current_b = current_b->next;
			current_w = current_w->next;
		}
	}
	void ReadFile(string filename)
	{
		fstream myfile;
		myfile.open(filename, ios::in);
		string data = "";
		int count = 0;
		while (getline(myfile, data))
		{
			int i = 0;
			int met = 0;
			int bs = 0;
			int wlk = 0;
			while (data[i] != '\0' && count != 0)
			{
				if (count == 1)
				{
					string a = "";
					while (data[met] != '\0' && data[met] != ' ')
					{
						a += data[met];
						i++;
						met++;
					}
					if (data[met] == '\0' && a == "")
						break;
					if (a == "")
					{
						met++;
						continue;
					}
					int b = stoi(a);
					addNode(1, b);
				}
				else if (count == 2)
				{
					string a = "";
					while (data[bs] != '\0' && data[bs] != ' ')
					{
						a += data[bs];
						i++;
						bs++;
					}
					if (data[bs] == '\0' && a == "")
						break;
					if (a == "")
					{
						bs++;
						continue;
					}
					int b = stoi(a);
					addNode(2, b);
				}
				else if (count == 3)
				{
					string a = "";
					while (data[wlk] != '\0' && data[wlk] != ' ')
					{
						a += data[wlk];
						i++;
						wlk++;
					}
					if (data[wlk] == '\0' && a == "")
						break;
					if (a == "")
					{
						wlk++;
						continue;
					}
					int b = stoi(a);
					addNode(3, b);
				}
			}
			if (count == 0)
			{
				string a = "";
				while (data[i] != '\0')
				{
					a += data[i];
					i++;
				}
				n = stoi(a);

			}
			count++;
		}
		////////////////////////////
		//cal_distance();
	}
	void print()
	{
		//for metr0
		Node* current;
		if (head_m != NULL)
		{
			if (head_m->next == nullptr)
			{
				cout << head_m->location << " ";
			}
			else
			{
				current = head_m;
				while (current != nullptr)
				{
					cout << current->location << " ";
					current = current->next;
				}
			}
			cout << endl;
		}
		//bus
		if (head_b != NULL)
		{
			if (head_b->next == nullptr)
			{
				cout << head_b->location << " ";
			}
			else
			{
				current = head_b;
				while (current != nullptr)
				{
					cout << current->location << " ";
					current = current->next;
				}
			}
			cout << endl;
		}
		//walk
		if (head_w != NULL)
		{
			if (head_w->next == nullptr)
			{
				cout << head_w->location << " ";
			}
			else
			{
				current = head_w;
				while (current != nullptr)
				{
					cout << current->location << " ";
					current = current->next;
				}
			}
			cout << endl;
		}

	}
	int GetMinCost(int start, int end)
	{
		int cost = 0;
		if (start < end)
		{
			int a = 0, b = 0, c = 0;
			Node* cur_m = head_m;
			Node* cur_b = head_b;
			Node* cur_w = head_w;
			int count = 2;


			while (count != start)
			{
				if (start == 1)
					break;
				cur_m = cur_m->next;
				cur_b = cur_b->next;
				cur_w = cur_w->next;
				count++;
			}
			if (start == 1)
			{
				a = cur_m->location;
				b = cur_b->location;
				c = cur_w->location;
			}
			else
			{
				a = cur_m->location;
				b = cur_b->location;
				c = cur_w->location;
			}

			//chose the least 
			int layer = 0;
			if (a <= b && a <= c)
			{
				layer = 1;
				cost = a;
			}
			else if (b <= a && b <= c)
			{
				cost = b;
				layer = 2;
			}
			else
			{
				cost = c;
				layer = 3;
			}
			if (start + 1 == end)
				return cost;
			count = start;
			int layer_2 = layer;
			cur_m = cur_m->next; cur_b = cur_b->next; cur_w = cur_w->next;
			while (count != end + 1)
			{
				a = cur_m->next->location;
				b = cur_b->next->location;
				c = cur_w->next->location;
				int val = 0;
				if (a <= b && a <= c)
				{
					layer_2 = 1;
					val = a;
				}
				else if (b <= a && b <= c)
				{
					val = b;
					layer_2 = 2;
				}
				else
				{
					val = c;
					layer_2 = 3;
				}
				int val_2 = 0;
				//add values of layer movement such as up and down
				if (layer == (layer_2 + 1) || layer == layer_2 - 1)	//2,1 3,2
				{
					val_2 = val + 5;
				}
				else if (layer == (layer_2 + 2) || layer == layer_2 - 2)// 3,1
				{
					val_2 = val + 10;
				}
				//compare again which is the least value add that to cost 
				if (layer_2 != 1 && layer_2 != 2)
				{
					if (a < val_2 && a <= b)
						cost += a;
					else if (b < val_2 && b <= a)
						cost += b;
				}
				else if (layer_2 != 2 && layer_2 != 3)		//layer is 1
				{
					if (b < val_2 && b <= a)
						cost += b;
					else if (c < val_2 && c <= b)
						cost += c;
				}
				else if (layer_2 != 1 && layer_2 != 3)
				{
					if (a < val_2 && a <= c)
						cost += a;
					else if (c < val_2 && c <= a)
						cost += c;
				}

			}
		}
		return cost;
	}

};


