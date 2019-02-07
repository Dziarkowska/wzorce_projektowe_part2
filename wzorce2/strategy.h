#pragma once
#include<iostream>
#include "person.h"

using namespace std;



class Learning{
  public:
    Learning(){
    };
    ~Learning(){
    };
    virtual void learn() = 0;
};

class Read: public Learning{
  public:
    Read(){
    };
    ~Read(){
    };
    void learn(){
        cout<<"Zdobyles nowa wiedze: Orki, ze wszystkich stworzen na ziemi,  maja najbardziej rozwiniety mozg"<<endl;
    }

};

class Practise: public Learning{
  public:
    Practise(){      
    };
    ~Practise(){      
    };
    void learn(){
        cout<<"Zdobyles nowy skill: rozniecanie ognia"<<endl;
    }
};

class RoleModel
{
  private:
    Learning *learning;      
  public:
    RoleModel(Person *who){
      if ((*who).getName()=="tourist"){
        this->learning = new Read();     
      }
      else if ((*who).getName()=="guide"){
        this->learning = new Practise();     
      }
      else{
        throw "nie ma takiej postaci";
      }
    }
  void teach(){
    this->learning->learn();
  }
};
