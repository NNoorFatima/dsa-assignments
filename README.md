# Assignments

These assignments are done using the concepts of Data Structures such as queue, stack, trees and so on. Descrption regarding each assignments is added below. 


## Assignment -02
Fast University is situated in the heart of Islamabad, with students hailing from different sectors of the city. They employ various modes of transportation for their daily commute, such as the metro,bus, or simply walking. However, due to the nature of the transportation systems, students often need to combine these modes. You can envision the city's locations as a numbered line starting from 1(one). Movement is restricted to forward and backward along this line. The metro is considerably faster than the bus, and the bus is faster than walking. Unfortunately, the metro can only start and stop at designated metro stations, and the bus can only stop at designated bus stops.

To visualize these journeys, a special 3-layered linked list is employed, illustrated as follows:

Metro: 1--------2---------3 5--------6-----------7--------8

Bus: 1--------2 4--------5 7--------8

Walking:1--------2--------3--------4--------5--------6----------7--------8-------9-------10


The bottom layer represents walking, the middle layer represents the bus, and the top layer represents the metro. Each node in the layered linked list contains:
● An integer representing the location
● A reference `next` pointing to the next location within the current mode of transport
● A reference ‘prev’ pointing to the previous location within the current mode of transport.
● A reference `down` taking you down to the SAME location in a slower mode of transport.
● A reference `up` taking you up to the SAME location in a faster mode of transport.

For instance, in the diagram above, node 5 in the metro layer points to node 5 in the bus layer, which in turn points to node 5 in the walking layer. `next` will be set to null if there is no stop at the next location on the current mode of transport, and `down` will be set to null if you are in the walking layer or if the lower layer has no location with the same node id. prev will be set to null if there is no location before the current node in the same layer. You cannot directly go from the metro layer to the walking layer node if there is no bus node.

Create the following functions:
    addNode(int layer, int location_id)
    deleteNode(int layer, int location_id)
    getPath(int start, int end)

The layers and their locations are read from a text file such as 

    6 6 6

    1 2 3 4 9 10

    1 3 4 5 6 9 

    1 3 4 5 7 9

The first line must contain three integers: n, m, and q, representing the number of stations in the first, second, and third layers, respectively.

### Question -2
In this transport system, we consider the cost of traveling between different locations . The primary goal is to compute and manage the cost of traveling between any two locations within the network.Assume that all the nodes exist in all the transport layers.

Input format:

● The first line contains an integer n, representing the total number of locations in the transport network.
● The next three lines contain a series of n-1 integers each, where each line corresponds to a different mode of transportation: metro, bus, and walking respectively. These lines represent the costs associated with traveling from one location to another. The cost of going from one node to the same node on another layer above or below it is 5. going from layer 1-3 or 3-1 will cost 10.
● The i-th integer in each line represents the cost of traveling from the i-th location to the (i+1)-th location using the respective mode of transportation.
● the person can start their journey from any layer on the starting location and end at any layer on the ending location.

Create a function GetMinCost(int start , int end) that returns the minimum cost for going from starting point to the end point.Start is not necessarily less than end.

## Assignment 03

### Question-01

In the land of Wordsmithia, where words danced in the pages of enchanted
dictionaries, a unique challenge arose. The wise sage Lexico faced a task involving
the mystical art of lexicographical order.
Lexico explained, "Lexicographically means arranging things just like the words in a
wizard's dictionary. For instance, consider two magical strings:
String 1: abcdef
String 2: abcdez
String 2 is lexicographically larger than String 1. The magic lies in the first position
where they differ—'z' in String 2 comes after 'f' in String 1. We compare characters
at this first differing position, and 'z' is greater than 'f' by their ASCII values. So,
String 2 is lexicographically larger."
Now, imagine you have a string "s" and a magical number "k." Your quest is to find
the lexicographically maximum possible string after removing k characters.
Let's embark on a couple of adventures:


example 1:
    input s="fzlyoapx", K=2
    output: "zyoapx"

In this enchanting tale, the string
"fzlyoapx" holds a secret. To make it as large as possible, we must remove two
characters. Lexico, with a glint in his eye, identifies the humble 'f' and ‘l’ as the ones. By banishing 'f' and ‘l’ the string transforms into "zyoapx," standing tall as the
lexicographically maximum.


example 2:
    input s="xdycz", K=2
    output: "ycz"

In this mystical journey, we encounter the
string "xdycz" and the challenge of removing two characters. To maximize its
lexicographical greatness, we bid farewell to the first two characters, 'x' and 'd.'
The residue, "ycz," emerges as the triumphant lexicographical zenith.

And remember, any other removals would lead to a smaller lexicographicalstring.
Lexico hints at the use of a magical staff known as the Stack, ensuring a swift
solution with optimal complexity O(n + k). Armed with this knowledge,
adventurers set forth into the realm of strings, ready to maximize their
lexicographical destiny. May the words guide you to victory!
chosen
### Question-02

In the enchanted land of Numerica, where numbers orchestrated a magical
symphony, a new quest unfurled before the adventurers. Digitara, the wise
sorcerer, faced a challenge with the mystical number 'x.' The task was a unique
operation—removing one digit at a time while adhering to specific rules.

The rules of this mystical operation were crystal clear:
• The resulting number must avoid any leading zeroes.
• The outcome must remain a positive integer.
Goal:
The adventurers aimed to unveil the smallest positive integer from 'x' by
applying this operation 'k' times. The magical process unfolded as follows:
• Commence with the original number 'x.'
• Remove one digit, ensuring it follows the rules.
• Repeat this process 'k' times to reveal the smallest possible number.

An example illuminated the adventurers' path: 'x' as 10142, with 'k'set to 2.
• Start with 10142, remove '4' to get 1012.
• Remove another digit, like '2,' to obtain 101.
• The result—the smallest positive integer achievable with 'k' operations—
was 101. Notably, trailing zeroes were forbidden in this mystical arithmetic.
### Question-03

Imagine you are a financial analyst working for an investment firm, and your task
is to identify the most lucrative investment opportunities in a series of daily stock
prices. Each day, the stock prices are recorded, and you are given the flexibility to
choose a sequence of 'k' consecutive days to maximize the profit.
Array of Stock Prices: Think of an array representing the daily stock prices, where
each element signifies the closing price of the stock for a specific day.
[Day 1: $100, Day 2: $110, Day 3: $120, Day 4: $90, Day 5: $130, ...].
Integer 'k': In this financial analysis challenge, 'k' represents the number of
consecutive days you can choose to buy and sell the stock. For instance, if 'k' is 3,
you aim to find the sequence of three consecutive days that would result in the
maximum profit.

Subsequence with the Highest Profit: The subsequence corresponds to selecting
'k' consecutive days with the highest cumulative difference in stock prices. The
objective is to maximize the profit gained from buying and selling stocks during
this period.
Queue Data Structure: Visualize a queue-like approach, where you keep track of
the best 'k' consecutive days while moving through the array of stock prices. The
algorithm dynamically adjusts the queue to include the most profitable 'k' days,
ensuring you capitalize on the optimal trading opportunities.

Optimal Time Complexity: By implementing an algorithm inspired by the problem
statement, you can efficiently analyze the stock prices and identify the 'k'
consecutive days with the maximum profit. The optimal time complexity (O(n + k)
or O(n)) ensures quick decision-making without unnecessary delays.

## Assignment -04

In this assignment, you are assigned the task of designing and implementing a Task
Management System for a project team using Red-Black Trees. Studying Red-Black trees is
also a part of this assignment. There are numerous resources online but the one specific book
you can learn from is Data Structures and Algorithm Analysis in C++ by Mark Allen uploaded in
Google Classroom.
The objective is to create a comprehensive system that efficiently manages tasks assigned to
team members, prioritizes tasks based on their urgency, and offers a wide range of operations
for manipulating and retrieving task information. The assignment aims to provide a practical
solution for project teams to streamline task management, enhance productivity, and maintain
organized records of tasks.

##### Requirements

Add Assignee: users shoudl be able to add new assignees to the system by providing info such as first name, last name, address and DOB

Search Assignee by ID: find assignee by their id

Search Assignee by Name: find assignee by their name

Search Assignee with no tasks Assigned

Shift tasks of one assignee to another

Delete Assignee: assignee with tasks cannot be deleted

Add Task: add new tasks to the system by providing info such as task description, priority level and the assignee id 

Complete Task: tasks should be marked as completed when they are finished

Print task Queue: display all tasks sorted according ot priority level

Find highest priority task

Find task by Assignee

Count total Tasks

Update Task priority: the system should allow to update the priority of a specific tasks without removing it from the queue

Clear Completed tasks

Display all completed tasks

Search for task by priority range

###### Red-Black Tree implementation 

The red-black tree should store task records. Each node in the red-black tree represents a task in the system. The node structure of the task tree includes the following fields:

Task ID: unique id

Description: text description of the tasks

Priority level

Assignee ID

Another tree would be created to store the details of Assignee, which would include:

First Name
Last Name
Address
DOB: in day/month/year format
Assignee ID: auto generated 

Include in order-transversal fucntion of the red-black tree, which would also display the color of each node. Tree is created according to priority of the tasks in task tree and Assignee ID in case of Assignee tree.

