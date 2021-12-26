#include<iostream>
using namespace std;

class MyArray {
    private:
    int total_size;
    int used_size;
    int *ptr;

    public:

    MyArray(int tSize, int uSize){
        total_size =tSize;
        used_size = uSize;
        ptr = (int *) malloc(tSize*sizeof(int));
    }

    void setVal(){
        int n;
        for (int i= 0; i<used_size; i++){
            cout<<"Enter the element: "<<i<<" "<<endl;
            cin>>n;
            ptr[i] = n;

        }
    }

    void show(){
        for (int i= 0; i<used_size; i++){
            cout<<"Element at position "<<i<<" is "<<ptr[i]<<endl;
        }
    }

};



int main(){

    MyArray marks =  MyArray(10, 3);

    marks.setVal();

    marks.show();


    return 0;
}