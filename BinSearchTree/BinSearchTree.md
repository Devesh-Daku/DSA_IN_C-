 **Binary Search Tree -------------------**
============================================

- No duplicate element in bin search tree.  
- So inorder will be in a sorted order.  
- Generally represented using linked representation.  
- Search Tree is named such that- 
    
- say we have to find x in the tree so,   
    >if x > node->data : look x in right child(continue..)  
    >if x < node->data : look x in left child (continue..)   
    >if x = node->data : you found the x , search complete.     
    >if we reached a leaf node where still not matches x then means x don't exist in tree. 

time taken for search in bin search tree having n nodes is :: Log(n)

---------------------------------
## 1. Searching  ----------------

### Recursive.

    Node* RSearch(int key , Node * p = root) {
        if(p==NULL) return NULL;
        else if(key>p->data) RSearch(p->rht); 
        else if(key<p->data) RSearch(p->lft);  
        else (key==p->data) return p;
    }
### Iterative 

    Node* ISearch( int key , Node * p = root) {
        while(p){
            if( key == p->data) return p;
            else if ( key < p->data ) p= p->lft;
            else p= p->rht; 
        }
        return NULL;
    }
-------------------------------------------
## 2. Inserting ---------------------------

> Search for key : if key found we can't insert it again.  
> If not found then we will do insertion where we terminated while searching.  
> Create a new node insert key in it and attached where the null node ended while searching . 

>>Iteratively Inserting  

    void Inserting( int key , Node * p = root) {
        // Note : this function will add new keys at end of some node only , 
        // it will not break a node and adjust according to it : 
        Node *tail ;
        int left  = -1;
        while(p){
            if( key == p->data) { cout << already present << endl : return ;}
            else if ( key < p->data ) { tail = p ; p= p->lft; left = 1;}
            else { tail = p ; p= p->rht; left = 0;}
        }
        p = new Node(key) ;
        if(left) tail->lft = p;
        else tail->rht = p;

        or 
        if( p->data > tail->data ) tail->lft = p ;
        else tail->rht = p ;

    }

>> Recursively Inserting

    Node* RInserting(Node * p = root , int key ){
        if(p=NULL){
            Node *t = new Node ( key );
            return t;
        }
        else if (key < p->data ) p->lft = RInserting(p->lft, key);
        else if (key > p->data ) p->rht = RInserting(p->rht, key);
        else return p;
    }
    
- crating a bin search tree takes n*Log(n) order of time 

---------------------------------------------
## 3. deletion of a node in tree ------------

#### Terminology
- Inorder successor  : Left-Child's right-most-child (ie go left first then right... until u reach a node where no more right is possible ).  
- Inorder predecessor: Right-Child's left-most-child (ie go right first then left... until u reach a node where no more left is possible ).  
- that left's-right-most is called inorder predecessor.  
- that right's-left-most is called inorder successor.  

 In other words in Inorder traversal te element just before that node is Inorder predecessor and just after is Inorder successor.

            A
          /   \
         B     C
       /  \   /  \
      D    E F    G

 E is A's inorder predecessor, F is A's inorder successor  

            A
          /   \
         B     C
       /      /  \
      D      F    G

 B is A's inorder predecessor, F is A's inorder successor

#### Deletion
If node is leaf : search it and when found delete it and make it as null.  
If node is head or intermediate then : replace it with either Inorder.  Predecessor or Inorder successor delete that successor and proceed with same procedure as head of that node.  
if any intermediate node is to be deleted then do the same procedure assuming that node to be a head of below tree.  
height of tree is order of log(n).  
so time for searching is maximum is log(n).  

#### for generating  binary search tree only preorder or postorder is sufficient 
- we can sort the preorder or postorder to get inorder .
- so we can have both preorder + inorder or postorder + inorder which is sufficient case for generating any binary tree 


// generating binary search tree by just using preorder 
1. take a stack 
2. you have a preorder given 
3. take the first element make it as a root ( let's say we are on root node rn) 
4. then take next element : compare it with current node if grater then go lft else go rht and add the new node there ( now we are on new node and store the last node in stack )
5. then take next element : compare it with if grater , compare with parent node : try to find appropriate position for that node 

here is the code : 

        //Generating bst from preorder array 
        void BinSearchTree :: Create_from_preorder(int pre[] , int n){
            // lecture number 309
            stack<Node*> stk;
            Node *t ,*p;
            int i=0;
            root = new Node(pre[i++]);
            p = root ;
            while (i<n){

                if(pre[i] < p->data) {
                    t = new Node(pre[i++]);
                    p->lft = t;
                    stk.push(p);
                    p=t;
                }
                else if( !stk.empty() && (pre[i] > stk.top()->data) ){     
                    p = stk.top();
                    stk.pop();
                }
                else{
                    t = new Node(pre[i++]);
                    p->rht = t;
                    p=t;
                }

            }
        }



**DrawBack of Binary Search Tree BST**
1. For same set of keys there are multiple bst with different heights .
2. BST generated from a tree will be highly dependent on order of keys given. 
3. The height of BST generated lies in the range of [ Log2(n) to  n-1 ].

### That's why we need a height controlled binary search tree 
    - solution is AVL trees 