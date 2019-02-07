#include <iostream>

using namespace std;

class Shoes{
    protected:
        Shoes *next;
    public:
        Shoes(){ 
            next = NULL; 
        }
        ~Shoes(){
        }
        virtual void request(string seasone, int s1) = 0;
        void setNextShoes(Shoes *nexttype){
            next = nexttype;
        }
};

class FlipFlops : public Shoes{
    private:
        int warmth;
        int size;  
        //Shoes *next = new TreckingShoes(warmth, size);      

    public:
        FlipFlops(int w, int s) {
            warmth = w;
            size = s;

        }
        ~FlipFlops(){
        }
        void request(string seasone, int s1){
            if(seasone == "summer" && warmth == 0 && size == s1){
                cout<<"Dostajesz klapki na lato, przydatnosc: "<<warmth<<endl;
            } else if(next != NULL){
                //cout<<"tutaj"<<endl;
                next->request(seasone,s1);
            } else {
                cout<<"Sorry but there is no type of shoes matching your requests"<<endl;
            }
        }
};        
class TreckingShoes : public Shoes{
private:
    int warmth;
    int size;
public:
    TreckingShoes(int w, int s){
        warmth = w;
        size = s;
    }
    ~TreckingShoes(){

    }
    void request(string seasone, int s1){
            if(seasone == "winter" && warmth > 0 && size == s1){
                cout<<"Dostajesz buty na zime, przydatnosc: "<<warmth<<endl;
            } else if(next != NULL){
                next->request(seasone,s1);
            } else {
                cout<<"Sorry but there is no type of shoes matching your requests"<<endl;
            }
        }

};
