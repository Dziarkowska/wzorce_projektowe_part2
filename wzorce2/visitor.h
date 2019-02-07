#include <iostream>

class Person1;

class Map{
public:
    virtual void accept(Person1 *p) = 0;
};

class IceLake : public Map{
public:
    void accept(Person1 *p);
    void crawlthrough(){
        std::cout<<"czolgasz sie przez zamarzniete jezioro"<<std::endl;
    }
};
class Glacier : public Map{
public:
    void accept(Person1 *p);
    void skitour(){
        std::cout<<"wszedles na lodowiec na skitourach"<<std::endl;
    }
};

class Person1{
public:
    virtual void cross(IceLake *iceLake) = 0;
    virtual void reachtop(Glacier *glacier) = 0;

};

class Traper : public Person1 {
    virtual void reachtop(Glacier *glacier){
        glacier->skitour();
    }
    virtual void cross(IceLake *iceLake){
        std::cout<<"You cant cross the lake"<<std::endl;
    }
};

class Traveller : public Person1{
    virtual void cross(IceLake *iceLake){
        iceLake->crawlthrough();
    }
    virtual void reachtop(Glacier *glacier){
        std::cout<<"You cant skitour on Glacier"<<std::endl;
    }
};

void IceLake::accept(Person1 *p){
    p->cross(this);
}

void Glacier::accept(Person1 *p){
    p->reachtop(this);

}
