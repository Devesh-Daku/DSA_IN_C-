# AVL Trees: ---------------------

### Terms:
- Balance Factor ( BF ) = height of left sub tree - height of right sub tree 
- If balance factor ( bf ) = { -1, 0 , 1} // called balanced 
- If |bf| > 1  imbalanced node 
- If |bf| <=1  balanced node 
- If every node is balanced we call tree is balanced
- Generally we don't come across an AVL tree having an imbalance node of |bf| > 2


// Rotation 

        30          20
       /           /  \
      20    >>   10    30 
     /
    10 
called LL imbalanced so rotation can be called as 

LL rotation ,cw rotation ,right rotation...

rotation is always done with three node only

so rr rotation will be on rr imbalance 

    10                20      
      \              /  \ 
       20     >>   10    30 
         \ 
          30 

// LR imbalance 

        30                   30
       /                    /  
      10   >>R rotation    20      >>  L rotation  balanced tree
       \                  /
        20               10 
     

similarly RL rotation : 
