#include <iostream>
#include <string>

class Rope;
class Equipment{
protected:
    Rope* rope;
public: 
    virtual void use() = 0;
};
class Rope{
    public:
        virtual void wrap() = 0;
};
// The Bridge  
class Bridge : public Equipment{   
    public:
        Bridge(Rope* backend)
        {
            rope = backend;
        }
};
class Kill : public Bridge{
    public:
        Kill(Rope* backend) : Bridge(backend){

        }
        void use(){
            std::cout<<"Killer mode on"<<std::endl;
            rope->wrap();
        }
};

class Climb : public Bridge{
    public:
        Climb(Rope* backend) : Bridge(backend){
          }

        void use(){
            std::cout <<"Climbing mode on"<<std::endl;
            rope->wrap();
        }
};

class KillerToy : public Rope{
    public:
        void wrap(){
            std::cout<<"You strangled someone"<<std::endl;
        }
};

class ClimbingRope : public Rope{
    public:
        void wrap(){
            std::cout<<"You're on the top of Mount Everest ;)"<<std::endl;
        }
};

