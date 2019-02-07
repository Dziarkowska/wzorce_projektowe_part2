#include <iostream>

class Traveller_sub{
public:
    virtual void  hide() = 0;
};

class Traveller_obj : public Traveller_sub{

public:
    virtual void hide(){
        std::cout<<"I'm hiding"<<std::endl;
    }
};

class TravellerProxy : public Traveller_sub{
    Traveller_obj *_obj;
public:
    TravellerProxy() : _obj(nullptr){        
    }

    virtual void hide(){

        if (_obj){
            _obj->hide();
        } 
        else{
            _obj = new Traveller_obj;
            _obj->hide();
        }
    }

};

