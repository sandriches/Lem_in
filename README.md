# Lem_in
Lem_in pathfinding algorithm project. This is similar to a 'max flow' problem, but, in classic Codam style, with several constraints.

LEM_IN is a project where the input given is a map consisting of:
1. Number of ants (0 < ants < INT_MAX)
2. List of rooms, followed by co-ordinates
3. List of links of rooms

The 'START' and 'END' rooms are indicated by comments above the selected rooms.

For example, a map like look as follows:

```
3
Room1 1 3
Room2 3 5
##start
Room3 2 1
Room4 9 2
##end
Room5 3 7
Room1-Room5
Room2-Room4
Room1-Room3
```
In the above map, the start room is Room3 and the end room is Room5.

All the ants start in the START room. The objective is to get all the ants from START to END going through the rooms using the FEWEST LINES POSSIBLE.
A 'LINE' is consider one movement of ants. All ants are allowed to move once per line, however the rooms can only ever have 1 ant in at once. This means collisions must be avoided.

The output is printed as follows:
L[ant number]-[room_number].

The solution for the above map would be:
```
L1-Room1
L2-Room1  L1-Room5
L3-Room1  L2-Room5
L3-Room5
```
----------------------
The solution used incorporates Dinic's algorithm, removing augmenting paths using BREADTH FIRST SEARCH until the max flow is found.
The input is read into a hash table so as to increase effiency, and the ants are only moved once the correct solution has been found.

----------------------
To test the project:
1. Make
2. Use the given generator to produce a map (or write one yourself into a file). Use ./generator --help to see available types.
EG: ./generator --big > map.txt
3. Run the project like so:
./lem_in < map.txt


More information on the project can be found in the PDF.
