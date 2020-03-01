## Abstract

These are 3 implementations of the Floyd's Algorithm for the shortest path
between all the vertices of a graph.

The input is :
- The number of the vertices (first line)
- The adjacency matrix in order to acknowledge the relationship between
each node.

The first two use recursion in order to compare all the possible ways to reach
a node from another.
The last one uses the iterrative way, that can also keep track of the actual 
path.


## Install
```shell
~$ make # just build the default version of the floyd's algo

~$ make flowar=rec/mem/dp # compile to get the recursive/recursive and memory tracking/iterrative version of the algo

~$ make run # build and run the program (use the "flowar" string to get the build that you want)

~$ make flowar=dp path=yes: Get not only the shortest path but also the actual path between each of the nodes 
```
