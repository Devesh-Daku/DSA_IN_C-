**Dynamic Programming :
	Dp :** recursion + storage  :

example we are taking a 0/1 knapsack recursive :
	wt[] = { 1,3,4,5}
	val[] = { 1,4,5,7}
	W = 7kg

1. How to identify :

   if we got options to choose to do a task and we have some optimal condition

   a. choices ( yes we have choices  to fill W(7)  so that val is maximized )

   b. optimal ( min ,max ,greatest ,lowest ...)

2. Start with recursions :

   a. Choice Diagram
    item weight <= W : ( may be we can put it in or may be we can't )
    item weight > W : ( we can't put that item in knapsack)

   b. Writing Function
    int Knapsack( int wt[] , int val[] , int W , int n){
        // base condition
        // choice diagram

   }
