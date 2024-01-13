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