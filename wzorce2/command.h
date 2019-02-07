#include <iostream>

using namespace std;

class Command 
{
public:
	virtual void execute()=0;
};

class Level{
public:
	Level(){
	}

	void levelUp(){
		cout<<"You moved to the next level"<<endl;
	}

	void previouslevel(){
		cout<<"You were send back to the previous level"<<endl;
	}
};

class LevelUp: public Command{
public:
	LevelUp(Level& level):theLevel(level){
	}

	virtual void execute(){
		theLevel.levelUp();
	}
private:
	Level& theLevel;
};

class PreviousLevel: public Command{
public:   
	PreviousLevel(Level& level) :theLevel(level){
	}
	virtual void execute(){
		theLevel.previouslevel();
	}
private:
	Level& theLevel;
};

class MapI{
public:
	MapI(Command& upCmd, Command& prevCmd)
	:upCommand(upCmd),prevCommand(prevCmd){
	}

	void up(){
		upCommand.execute();
	}

	void prev(){
		prevCommand.execute();
	}
private:
	Command& upCommand;
	Command& prevCommand;
};

