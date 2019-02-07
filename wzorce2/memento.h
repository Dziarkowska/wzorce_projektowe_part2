#include <iostream>

class Memento {
private:
    string state;

public:
    Memento(string s){
        state = s;
    }
    friend class VisitedPlaces;
};

class VisitedPlaces{
private:
    string city;
public:
    string getCity(){
        return city;
    }

    void setCity(string place) {
        VisitedPlaces::city = place;
    }

    Memento *createMemento(){
        return new Memento(city);
    }
    void reinstateMemento(Memento *mori){
        city = mori->state;
    }
};
