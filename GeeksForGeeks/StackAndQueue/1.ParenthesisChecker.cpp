// Parenthesis Checker

// Question:
// Given an expression string exp. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
// For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and 'not balanced' for exp = “[(])”

// Input:
// The first line of input contains an integer T denoting the number of test cases.  Each test case consists of a 
// string of expression, in a separate line.

// Output:
// Print 'balanced' without quotes if the pair of parenthesis is balanced else print 'not balanced' in a separate line.

// Example:
// Input:
// 3
// {([])}
// ()
// ([]

// Output:
// balanced
// balanced
// not balanced

// Solution:
// call checkParenthesis(str): create a stack s and store string length into len. 
// for i=0 to len: 
//     if(str[i] is '(' or '{' or '[') push it to stack 
//     else if(str[i] is ')' or '}' or ']' ): if s is empty return false 
//         else if (s.top() != '(' && str[i] == ')') or (s.top() != '{' && str[i] == '}') or (s.top() != '[' && str[i] == ']') return false else s.pop(). 
// if stack is empty return true else false 

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool checkParenthesis(string str){
    stack <char> s;
    int len = str.length();

    for(int i=0;i<len;i++){
            if(str[i] == '(' || str[i] == '{' || str[i] == '[')
                s.push(str[i]);
            else if(str[i] == ')' || str[i] == '}' || str[i] == ']'){
                if( s.empty())
                    return false;
                else if(s.top() != '(' && str[i] == ')')
                    return false;
                else if(s.top() != '{' && str[i] == '}')
                    return false;
                else if(s.top() != '[' && str[i] == ']')
                    return false;
                else
                    s.pop();
            }
    }
    if( s.empty())
        return true;
    else 
        return false;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    string str;       
        cin>>str;
        
        if(checkParenthesis(str))
            cout<<"balanced\n";
        else 
            cout<<"not balanced\n";
        
	}
	return 0;
}