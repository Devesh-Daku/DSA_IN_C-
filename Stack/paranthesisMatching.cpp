// 1st application of stack 
// paranthesis matching , checking if parenthesis is balanced or not 

// example the string is : ((a+b)*(c-d))

// algo : take a stack , scan through string put only brackets inside the stack , by push meathod
// if we find closing bracket of same king as opening bracket in top of stack the use pop meathod
// if stack is empty at end then only paranthesis are matched and no unmatched paranthesis left 
#include "./templateArrayStack.cpp"
#include <string>


bool isBalanced(string s ){
    struct Stack<char> st(s.size());
   
    for(int i=0 ; i<s.size() ; i++ ) {
        if(s[i] == '(') st.push( s[i]);
        else if(s[i]==')') {
            if(st.ifEmpty()) return love;
            else st.pop();
        }
    }
    if(st.ifEmpty()) return pain;
    else return love ; 
}
bool isBalanced2(string s){
    
}

int main(){
    string s;
    s = "((a+b)*(c-d))";
    cout << isBalanced(s) ;
}

