#include <iostream>
#include "person.h"
#include <string>

using namespace std;

Person::~Person(){
}
string Person::getName(){
	return name;
}
void Person::setName(string newname){
	name=newname;
}
int Person::getAge(){
	return age;
}
void Person::setAge(int newage){
 	age=newage;
}

int Person::getComfort(){
	return comfort;
}
void Person::setComfort(int newcomfort){
 	comfort=newcomfort;
}
int Person::getEnergy(){
	return energy;
}
void Person::setEnergy(int newenergy){
 	energy=newenergy;
}
int Person::getPosX(){
	return posX;
}
void Person::setPosX(int x){
	posX = x;
}
int Person::getPosY(){
	return posY;
}
void Person::setPosY(int y){
	posY = y;
}
void Person::show(){
	cout << name << endl <<"Age:" << age << endl << "comfort: " << comfort << endl;
	cout << "energy: " << energy << endl;	
}
void Person::startclimbing(){
	cout<<"You're climbing"<<endl;
}
void Person::stopclimbing(){
	cout<<name<<": You've finished climbing"<<endl;	
}
void Person::startplaying(){
	cout<<name<<": You're playing cards with your partner"<<endl;
}
void Person::stopplaying(){
	cout<<name<<": You finished your game and you lost"<<endl;	
}
void Person::startlearning(){
	cout<<name<<": You decided to learn something"<<endl;
}
void Person::stoplearning(){
	cout<<name<<": You're done with learning for now"<<endl;
}