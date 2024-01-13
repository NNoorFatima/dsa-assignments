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