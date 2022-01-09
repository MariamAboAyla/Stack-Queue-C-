#include <iostream>
using namespace std;

//the class MyList
template <class T>
class MyList{
protected:
    T itsSize;
    T *elems;
    T counter;

public:
    //parametrized constructor
    MyList(T siz){
        counter=0;
        itsSize = siz;
        elems = new T [siz];
        for (T i=0; i<siz; i++){
            elems[i]=0;
        }
    }
    //function that returns the capacity of the array
    T getSize(){return itsSize;}

    //pure virtual functions
    virtual void addElem(T e)=0;
    virtual T getElem()=0;
    virtual bool isEmpty()=0;
    virtual bool isFull()=0;
    virtual void clearItems()=0;

    //destructor of the array
    ~MyList(){
        delete []elems;
    }
};

//The class MyStack
template <class T>
class MyStack : public MyList<T>{
public:
    virtual void addElem(T e);
    virtual T getElem();
    virtual bool isEmpty();
    virtual bool isFull();
    virtual void clearItems()=0;
};
template <class T>
bool MyStack <T>::isEmpty() {
    if(MyStack<T>::elems[0]){return true;}
    return false;
}

template <class T>
bool MyStack<T>::isFull(){
    if(MyStack<T>::elems[MyStack<T>::getSize()]!= nullptr){return true;}
    return false;
}
template <class T>
T MyStack<T>::getElem() {
    T Y = MyStack<T>::elems[(MyStack<T>::counter)-1];
    for (T i=(MyStack<T>::counter)-1; i<(MyStack<T>::getSize()); i++){
        MyStack<T>::elems[i]=MyStack<T>::elems[i+1];
        MyStack<T>::counter--;
    }
    return Y;
}
template <class T>
void MyStack<T>::addElem(T e) {
    MyStack<T>::elems[MyStack<T>::counter]=e;
    MyStack<T>::counter++;
}
template <class T>
void MyStack<T>::clearItems() {
    delete [] (MyStack<T>::elems);
}

// the class MyQueue
template <class T>
class MyQueue: public MyList<T>{
public:
    virtual void addElem(T e);
    virtual T getElem(T x);
    virtual bool isEmpty();
    virtual bool isFull();
    virtual void clearItems()=0;
};
template <class T>
void MyQueue<T>::clearItems() {
    delete [] (MyQueue<T>::elems) ;
}
template <class T>
void MyQueue<T>::addElem(T e) {
    MyQueue<T>::elems[MyQueue<T>::counter]=e;
    MyQueue<T>::counter++;
}
template <class T>
bool MyQueue<T>::isEmpty() {
    if(MyQueue<T>::elems[0]== nullptr){return true;}
    return false;
}
template <class T>
bool MyQueue<T>::isFull() {
    T Y =MyQueue<T>::getSize();
    if(MyQueue<T>::elems[Y]== nullptr){return false;}
    return true;
}
template <class T>
T MyQueue<T>::getElem(T x) {
    T Y = MyQueue<T>::elems[0];
    for (T i=0; i<(MyQueue<T>::counter); i++){
        MyQueue<T>::elems[i]=MyQueue<T>::elems[i+1];
    }
    return Y;
}

// Rectangle class
class Rectangle{
        int length,width;
    public:
        Rectangle(){length=0.0; width=0.0;}
        Rectangle(int l, int w){length=l; width=w;}
        int getLength(){return length;}
        int getWidth(){return width;}
       // int getArea(){return length*width;}
    friend ostream& operator<<(ostream&os,const Rectangle& r){
            os<<"Length="<<r.length<<", Width= "<<r.width<<", Area= "<<r.length*r.width;
            return os;
        }
    };

int main() {
    char choice;
    cout<<"Would you like to use a stack or a queue (S/Q)?"<<"\n";
    cin>>choice;
    long n;
    try {
        cout<<"\nHow many items to store?\n";
        cin>>n;
        if(n<=0){throw 3;}
    }
    catch (int c) {
        cout<<"\nWrong input -> Enter only a positive number!\n";
        cout<<"\nHow many items to store?\n";
        cin>>n;
    }



    return 0;
}
