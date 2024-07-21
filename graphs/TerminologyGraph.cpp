collection of vertices and edges : 
very similar to state space model in digital electronics 
G = (V ,E ) : V ; vertices set , E : Edges set|
if edges are given on arrows then called directed graph
arrow coming out from a vertices is called "incident from"
arrow pointing on a vertices is called "incident to"
pair of edges between same vertices : called parallel edges
number of edges incoming to a vertices is called indegree of vertices 
number of edges outgoing from a vertices is called outdegree of vertices
edges on same vertices : called self loop 
two vertices connected by same edge called self loop
without self loop , parallel loop called simple Digraph
non directed edges graph  : called as graph : 
ther is no indegree or outdegree : only degree for the non-directed graph
the graph with directed arrow is called Digraph ( is a type of graph )

Non-connected graph : 
there are more than one non connected component called non-connected graph : 
only if two component have a single connection and no other connection between two component the the component called connected componnent 
if there exist such vertices upon their removal graph divides into components called articulation point : 

Strongly Connected graph : 
if there exist such graph from any vertices you can reach  any other vertices of the graph :
another word : there exist a path between any two vertices : 

PATH : 
Directed acyclic graph : DAG

we have to represent two things : 
1. matrix : fo size n*n ; while n is number of vertices 
 that matrix store 1 in between  the node's value 

for example the graph is 
    1---2
    |\  |
    | \ |
    |  \|
    4---3
     \ /
      5

adjacency matrix : 

A = {{ 0 1 1 1 0 },
     { 1 0 1 0 0 },
     { 1 1 0 1 1 },
     { 1 0 1 0 1 },
     { 0 0 1 1 0 }};
     
adjacency List :



weighted graph : weight is given to edge  
for example the graph is
      9 
    1---2
    |\  |
   6|4\5|
    | 8\|
    4---3
    2\ /7
      5

cost adjacency matrix :
A = {{ 0 9 4 6 0 },
     { 9 0 5 0 0 },
     { 4 5 0 8 7 },
     { 6 0 8 0 2 },
     { 0 0 7 2 0 }};

cost adjacency array : 
A = {
    1->{2,9}->{3,4}->{4,6}
    2->{1,9}->{3,5}
    3->{1,4}->{2,5}->{4,8}->{5,7}
    4->{1,6}->{3,8}->{5,2}
    5->{4,2}->{3,7}
}

another way of representation : compact list 
size of compact list is ( n + e*e )
{ index : 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7, 8 , 9 , 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}
{ fillin: / , 7 , 10, 12, 16, 19, / , 2 , 3 , 4 , 1 , 3 , 1 , 2 , 4 , 5 , 1 , 3 , 5 , 3 , 4 }
                        adjacent of   1           2       3               4           5

adjacency matrix for digraph 
say a digraph 
    1--->2 
    |*  |
    | \ |
    !  \!
    4-->3
    ! , > are arrow head 
is 
A = {{0 1 0 1}
     {0 0 1 0}
     {1 0 0 0}
     {0 0 1 0}}
    so we can get outdegree by summing in row , and outdegree as a sum of column 
