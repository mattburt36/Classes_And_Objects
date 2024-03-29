#include <iostream>
using namespace std;
class Fish
{
public:
	virtual Fish* Clone() = 0;
	virtual void Swim() = 0;
	virtual ~Fish() {};
};

class Tuna : public Fish
{
public: 
	Fish* Clone() override
	{
		return new Tuna(*this);
	}

	void Swim() override final
	{
		cout << "Tuna swims fast in the sea!" << "\n"; 
	}
};

class BluefinTuna final:public Tuna
{
public:
	Fish* Clone() override
	{
		return new BluefinTuna(*this);
	}
};

class Carp final: public Fish
{
	Fish * Clone() override
{
	return new Carp(*this);
}
void Swim() override final
{
	cout << "Carp swims slow in the lake" << "\n";
}
};

int main()
{
	const int ARRAY_SIZE = 4;

	Fish* myFishes[ARRAY_SIZE] = { NULL };
	myFishes[0] = new Tuna();
	myFishes[1] = new Carp();
	myFishes[2] = new BluefinTuna();
	myFishes[3] = new Carp(); 

	Fish* myNewFishes[ARRAY_SIZE];
	for (int index = 0; index < ARRAY_SIZE; ++index)
		myNewFishes[index] = myFishes[index]->Clone(); 


	for (int index = 0; index < ARRAY_SIZE; ++index)
		myNewFishes[index]->Swim(); 

	for (int index = 0; index < ARRAY_SIZE; ++index)

		for (int index = 0; index < ARRAY_SIZE; ++index)
		{
			delete myFishes[index];
			delete myNewFishes[index];
	}

	return 0; 

}