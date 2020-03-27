// Stack using two queues

#include <iostream>
#include <queue>
using namespace std;

class QueueStack{
    private: 
        queue<int> q1;
        queue<int> q2;

    public:
        void push(int B);
        int pop(); 
};

void QueueStack :: push(int x){
    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }
    q1.push(x);
}

int QueueStack :: pop(){
    int val;
    if(q1.empty() && q2.empty())      
        return -1;

    if(!q2.empty()){
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }    
    }
    int len = q1.size();
    while(len > 1){
        q2.push(q1.front());
        q1.pop();
        len--;
    }
    val = q1.front();
    q1.pop();
    return val;
}

int main() {
	int T;
	cin>>T;
	while(T--){

        QueueStack *qs = new QueueStack();
	    int Q;
	    cin>>Q;
        while(Q--){
            int QueryType = 0;
            cin>>QueryType;
            if(QueryType == 1){
                int a;
                cin>>a;
                qs->push(a);
            }
            else if(QueryType == 2)
                cout<<qs->pop()<<" ";
        }
        cout<<"\n";
	}
	return 0;
}