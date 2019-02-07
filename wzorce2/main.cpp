#include<iostream>
#include<string>
#include "bridge.h"
#include "visitor.h"
#include "strategy.h"
#include "person.h"
#include "responsibilitychain.h"
#include "command.h"
#include "proxy.h"
#include "memento.h"

using namespace std;
int main()
{
    
    //bridge
    Equipment *useCase = 0;
    Rope *climbingRope = new ClimbingRope;
    Rope *killerToy = new KillerToy;
    useCase = new Kill(killerToy);
    useCase->use();
    useCase = new Climb(climbingRope);
    useCase->use();
    cout<<"-------------"<<endl;


    //visitor
    Map *lake = new IceLake();
    Map *glacier = new Glacier();
    Person1 *person1 = new Traveller();
    Person1 *person2 = new Traper();
    lake->accept(person1);
    glacier->accept(person2);
    cout<<"-------------"<<endl;


    //observer
    Person *tourist = new Person("tourist");
    Person *guide = new Person("guide");
    RoleModel *t = new RoleModel(tourist);
    RoleModel *g = new RoleModel(guide);
    t->teach();
    g->teach();
    cout<<"-------------"<<endl;


    //chain of responsibility
    Shoes *flipflops = new FlipFlops(0,38);
    Shoes *trapers = new TreckingShoes(10,38);
    Shoes *flipflops_bad = new FlipFlops(10,38);
    flipflops->setNextShoes(trapers);
    flipflops->request("summer",38);
    flipflops->request("winter",38);
    trapers->request("winter",38);
    trapers->request("autumn",37);
    delete flipflops, flipflops_bad, trapers;
    cout<<"-------------"<<endl;

    //command
    Level level;
    LevelUp levup(level);
    PreviousLevel prevlev(level);
    MapI mapI(levup,prevlev);
    mapI.up();
    mapI.prev();
    cout<<"-------------"<<endl;


    //proxy
    TravellerProxy travellerproxy;
    travellerproxy.hide();
    cout<<"-------------"<<endl;



    //memento
    VisitedPlaces places;
    places.setCity("Rejkavik");
    Memento *memento = places.createMemento();
    cout<<"Visited city: "<<places.getCity()<<endl;

    places.setCity("Tromso");
    cout<<"Next visited city: "<<places.getCity()<<endl;

    places.reinstateMemento(memento);
    cout<<"Previously visited city: "<<places.getCity()<<endl;


    return 0;
}
