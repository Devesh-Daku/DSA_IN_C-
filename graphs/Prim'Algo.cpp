// we know that graph is represented as 2d array
// for just graph : let's search only upper triangular 
// 
//  
// look for the minimum value node and or the root node or the starting node / then chose that adjecent node that is minimum to it 
// example matrix :
//   0  1  2  3  4  5  6  7 
// 0 -  -  -  -  
// 1 -  - 25  -  -  -  5  -
// 2 - 25  - 12  -  -  -  - 
// 3 -  - 12  -  8  -  -  -
// 4 -  -  -  8  - 16  - 14
// 5 -  -  -  - 16  - 20 18
// 6 -  5  -  -  - 20  -  -
// 7 -  -  -  - 14 18  -  - 

// so we choose the shortest path and note the two joinig vertices in a 2d array with 2*n dimienstion t
// 0 |  |  |  |  |  |  |  | 
// 1 |  |  |  |  |  |  |  |

// and we will have a new matrix and will note which node is earer to perticular node out of that two 
// 0  1  2  3  4  5  6  7  8  
//   |  |  |  |  |  |  |  |  |

// step 1 chose the shortest edge that is between 1 and 6 with  weight 5 
// setp 2 now mark in new array as , thing are neared to 1 or 6 
// - 0 - - - - 0 -
// 0 1 2 3 4 5 6 7
// now finding out all other elements that are either near to 1 vs nearer to 6 
// so for this 




