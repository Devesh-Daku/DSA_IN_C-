Tree:

-------------------------------------
0. Terminology ----------------------
    tree consist of nodes and connect with edges 

      top node is call root node 

      distributing nodes are called child of parent node

      every node is parent to its very next decedent 

      siblings are children to same parents 

      set of nodes which are child and their child ... to a node is called decedent of decedent

      all the above node from which the node is parent of are and their parent called ancestors of node 

      degree of node : number of direct children 

      degree of a tree is minimum 3;

      nodes with degree 0 is called : leaf : terminal : external:

      levels : the number of ancestor +1 

      height of a tree level -1 = ancestors 

      number of minimum edges to reach is called height 

      a collection of tree is called forest 

-----------------------------------------
Binary Tree :: --------------------------
-----------------------------------------

// binary tree : 
    
    a tree of degree 2 : called binary tree 
    every node have tow children , 1 children 
    so name to children : left child and right child 
    children  = { 0,1,2 };

// number of binary tree with N node 

// if not defined then called unlabeled node 
    
    N = 3 ;
    T(N) = 5 ;
// N = 4 ;
    
    T(N) = 14;
    T(N) = (2n, n) / n+1 ; 
    2nCn = (2n, n)
    maximum height = n-1 ;
    number of tree with maximum height = pow ( 2 ,n -1 );

    T(N) = Summation{(i=0 to n-1 , j = n-1 to 0) [ T(n-1-i) * T(i)]}


// labeled node : each node is label : 

    so that T(n) = (2n ,n) * n! / n+1;

// Height vs node : 

    height = 1 ;
    min = 2, max =3

    height = 2;
    min  = 3, max = 7 

    height = 3 ;
    min = 4 , max = 14 ;

    min = height + 1 , max = pow(2, height +1) -1

// Nodes vs height 

    nodes = 3;
    min = 1 , max = 2 ;

    nodes = 7 ;
    min = 2 , max = 6 ;

    nodes = 15 ;
    min = 3 , max = 14;

    max = n - 1 ;  ,  min = log(n+1 ) -1 ;


// number of node with deg 0 = deg 2  + 1 ;

// strict binary tree : 
    
    node can't have one child 

    ie. {0,2} is their number of child 

// height vs nodes in strict binary tree 
    
    h =2 ;
    min = 5, max = 7 ,
    h= 3 ;
    min = 7, max = 15,
    h =4 ;
    min = 9 , max = 31,

    min = 2*height +1 ;
    max = pow(2, h+1) -1;

// node vs height 
    
    min height = log2,(n+1) +1 ;
    max height = n-1/2;

// internal and external node in strict binary tree 
    
    internal node +1 = external node 

N-Ary trees 

strict array trees ;

binary tree is 2-ary tree

n-ary tree capacity of child are {0,1,2,...n}

no node having degree more than 3 

so every binary tree is also a 3-ary tree as well as 4-ary tree

similarly 4-ary tree is having maximum degree of 4 so from (0, 1,2,3,4) it can have 

// strict n-ary tree
    
    so have degree = {0,n} only 
 
// height vs node of strict m-array tree 
    
    min = m*height + 1 ; 
    max =( ( pow(m,height +1)-1 ) / (m-1)  )  

// node vs height of m-ary tree n nodes are given  
    
    min Height h = log(m)(n(m-1)+1) - 1 ;
    max Height h = ( n-1 )/m ;

strict m ary tree 
    
    external node = (m-1)*(internal nodes) + 1;



------------
--------------------------------------
1. storing in array ------------------

stored by level then left to right

A,B,C,D,E,F,G;

            A
          /   \
         B     C
       /  \   /  \
      D    E F    G

      Emt Idx L   R
      A   1   2   3
      B   2   4   5
      C   3   6   7
      D   4   -   -
      E   5   -   -
      F   6   -   -
      G   7   -   -

node i (2*i) (2*i+1)
    
    parent index = greatest-Integer-function( child's index / 2 )  ;


---------------------------------------
2. Linked representation --------------

node : lchild , data , rchild ; (similar to doubly linked list node)

look exactly like tree

7 nodes : 7+1 null pointer

// external = internal + 1

// full binary tree : having height h and maximum nodes

// node = pow(2,h+1) -1;

// COMPLETE BINARY TREE : if binary tree is represented in array then there shouldn't be blank spaces in between the element
then it is complete tree : a complete tree can be same as full binary tree but need not be reverse true

            A
          /   \
         B     C
       /  \   /  \
      D    E F    G

if G is missing , F,G both missing , E,F,G all missing : it still be a complete tree

because in array representation there will be no gap between two element

for ex: say E is missing then array representation will be : A B C D _ F G .. so there is a missing gap between D and F

hence not complete binary


// strict binary tree vs complete binary tree

can be strict but not complete

can be strict and complete as well

can be complete but not strict

can be neither strict nor complete :

---
------------------------------------------------
3. Binary Tree Traversal -----------------------
   for linear Traversal is last to first , first to last

but for non linear like tree

preorder Traversal: visit(node) , preorder(leftSubTree) , preorder(RightSubTree)

Inorder           : Inorder(left) , visit(node ) , Inorder (right);

Post Order        : PostOrder(left) , PostOrder(right) , visit (node);

Level Order       : Level by Level :

            A
          /   \
         B     C

in preorder :  A -> B -> C

in Inorder :   B -> A -> C

in PostOrder:  B -> C -> A

in level order:A -> B -> C

            A
          /   \
         B     C
       /  \   /  \
      D    E F    G

pre:  A, ( ), ( );
    
    ( B->D->E ) , ( C->F->G )
    A-B-D-E-C-F-G->

In : ( ), A, ( );
    
    (D->B->E ) ,( F->C->G );
    D-B-E-A-F-C-G->

Post:( ), ( ), A ;
    
    (D->E->B) ,(F->G->C), A
    D-E-B-F-G-C-A->

Level: A ,(B, C), (D ,E ,F ,G);
    
    A->B->C->D->E->F->G
    A-B-C-D-E-F-G->

// Easy method for tree traversal

// Easy Method 1

a. connect a line from lhs of a node to a bottom line then the order generated is similar to preorder

b. connect a line from middle of a node to a bottom line then the order generated is similar to inorder

c. connect a line from rhs of a node to a bottom line then the order generated is similar to inorder

// Easy Method 2

make a small horizontal line on each node

           -A
          /   \
        -B     -C
       /  \   /  \
    -D  -E  -F   -G

    go along the top node by making a line as the line cuts their horizontal line that will be ther order preorder
    then order will be A B D E C F G
    do same thing trace along boundary but making a vertical down cut line
    D-E-B-F-G-C-A->
    do same thing marker is rhs
    A-B-C-D-E-F-G->

// Easy Method 3
   
   All method are similar thing in different way traversal your finger in -> direction will get preorder
   
   // in ^ direction will give in order
   
   // <- will give post order

---
----------------------------------------------------------------------
4. Traversing a binary tree through linked representation ------------

// preorder recursive function
that is
    
    void preorder ( node *t ){
      if( t!=NULL ){
        cout << t->data << " ";
        preorder(t->lft);
        preorder(t->rht);
      }
    }

total number of calls = total nodes + nullNodes + 1 = 2*nodes + 1;

maximum height of stack created is = level + 1; of tree = height + 2;
  
  log(n) < O(height) < n;

---
------------------------------------------------------------
5. Generating tree uniquely from traversals ----------------

we have taken an example st that

with three labeled node with a given preorder we can have multiple trees, there will be five tree we are getting that (with 3 nodes)

have same preorder

so with n node and a given preorder we can have  [ 2n(C)n / (n+1) ] number of trees possible

if only post order given we have same scenario

so if we can have

preorder + Inorder

postorder + Inorder

we can have unique tree if we have any of both

example :

we have preorder and inorder

preorder : 4 7 9 6 3 2 5 8 1

Inorder  : 7 6 9 3 4 5 8 2 1

scan pre oder find each element in Inorder

divide the  inorder array in two half both side the first element in preorder

>> first element 4
>> then inorder array :
>>
>>              4
>>            /   \
>>     7 6 9 3     5 8 2 1
>>

>> second element 7
>> then inorder array :
>>
>>        4
>>      /   \
>>     7     5 8 2 1
>>      \
>>       6 9 3
>> next 9 ... so on we get a tree
>>
>>         4
>>       /   \
>>      7     2
>>      \     / \
>>       9   5   1
>>      / \   \
>>     6   3   8
>>

//so this method is order of n*n
