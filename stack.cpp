#include<iostream>
#include<string>
#include<exception>
#include<list>

using namespace std;

//A simple exception class
class E : public std::exception{
private:  
    E(){}
    const char *msg;
public:  
    explicit E(const char *s) throw(): msg(s){}
    const char * what() const throw() {return msg;}

};

//fixed size LIFO stack template
template <typename T> 
class Stack {
private: 
    static const int defaultSize=10;
    static const int maxSize=100;
    int _size;
    int _top;
    T *stackPtr;
public:
    explicit Stack(int s= defaultSize);
    ~Stack() {delete[] stackPtr;}
    T & push(const T &);
    T & pop();
    bool isEmpty() const {return _top<0;}
    bool isFull() const {return _top>=_size-1;}
    int top() const {return _top;}
    int size() const {return _size;}
};

template <typename T>
Stack<T>::Stack(int s){
    if(s>maxSize || s<1) throw E("Invaild size of stack");
    else _size=s;
    stackPtr =new T[_size];
    _top=-1;
}
template <typename T>
T & Stack<T>::push(const T & x){
    if(isFull()) throw E("Stack is Full");
    return stackPtr[++_top]=x;
}
template <typename T>
T & Stack<T>::pop(){
    if(isEmpty()) throw E("Stack is Empty");
    return stackPtr[_top--];
}

int main(){
    try{
        Stack<int> si(5);
        cout<<"si size : "<<si.size()<<endl;
        cout<<"si top :"<<si.top()<<endl;

        for ( int i : { 1, 2, 3, 4, 5 } ) {
            si.push(i);
        }

        cout<<"si top after pushes: "<<si.top()<<endl;
        cout<<"si is "<<( si.isFull() ?"":"not" )<<"full"<<endl;

        while(!si.isEmpty()) {
            cout << "popped " << si.pop() << endl;
        }

    }catch(E & e){
        cout<<"Stack Error "<<e.what()<<endl;
    }

    try {
        Stack<string> ss(5);
        
        cout << "ss size: " << ss.size() << endl;
        cout << "ss top: " << ss.top() << endl;
        
        for ( const char * s : { "one", "two", "three", "four", "five" } ) {
            ss.push(s);
        }
        
        cout << "ss top after pushes: " << ss.top() << endl;
        cout << "ss is " << ( ss.isFull() ? "" : "not " ) << "full" << endl;
        
        while(!ss.isEmpty()) {
            cout << "popped " << ss.pop() << endl;
        }
    } catch (E & e) {
        cout << "Stack error: " << e.what() << endl;
    }

    return 0;
}
