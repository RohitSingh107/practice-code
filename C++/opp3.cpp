#include<iostream>
using namespace std;

class Shop{

    private:
        int itemId[100];
        int itemPrice[100];
        int counter;

    public:
        void initCounter(void){ counter = 0;} 
        void setPrice(void){
            cout<<"Enter Id of your item: "<<endl;
            cin>>itemId[counter];
            cout<<"Enter price of your item no: "<<counter+1<<endl;
            cin>>itemPrice[counter];
            counter++;
        }

        void displayPrice(void){
            for (int i = 0; i<counter; i++){
                cout<<"The Price of item with id "<<itemId[i]<<" is "<<itemPrice[i]<<endl;
            }
        }
};


int main(){
    

    Shop dukaan;
    dukaan.initCounter();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.displayPrice();






    return 0;
}