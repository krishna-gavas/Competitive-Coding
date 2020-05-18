// Parenthesis Checker

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