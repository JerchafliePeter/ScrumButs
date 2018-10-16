#pragma once
#ifndef LOCATIONS_H
#define LOCATIONS_H

#include <iostream>
#include <string>
using namespace std;


class Room
{
	string description;
public:
	Room* North;
	Room* South;
	Room* East;
	Room* West;
	// Default constructor. Gives dummy description and set all ptrs to null
	Room()
	{
		North = South = East = West = nullptr;
		description = "STANDIN DESCRIPTION\n";
	}
	// Constructor to give new room a description when declared.
	Room(string d)
	{
		North = South = East = West = nullptr;
		description = d;
	}
	// Can be used to change the description of a room
	void setDescription(string d)
	{
		description = d;
	}
	// reads description of a room.
	void Describe()
	{
		cout << description << endl;
	}

};

void Blocked(int stoppage)
{
	cout << "Blocked by ";
	switch (stoppage)
	{
	case 1:
		cout << "flood.\n";
		break;
	case 2:
		cout << "Chemical Spill.\n";
		break;
	case 3:
		cout << "a large fire!\n";
		break;
	case 4:
		cout << "rubble.\n";
		break;
	case 5:
		cout << "a dead end.";
		break;
	default:
		cout << "something.\n";
		break;
	}
}

// Used to move between rooms
Room* Movement(Room* locale, string direction)
{
	if (direction == "north")
	{
		if (locale->North == nullptr)
		{
			Blocked(4);
			return locale;
		}
		else
		{
			locale = locale->North;
			return locale;
		}
	}
	else if (direction == "east")
	{
		if (locale->East == nullptr)
		{
			Blocked(2);
			return locale;
		}
		else
		{
			locale = locale->East;
			return locale;
		}
	}
	else if (direction == "south")
	{
		if (locale->South == nullptr)
		{
			Blocked(1);
			return locale;
		}
		else
		{
			locale = locale->South;
			return locale;
		}
	}
	else if (direction == "west")
	{
		if (locale->West == nullptr)
		{
			Blocked(3);
			return locale;
		}
		else
		{
			locale = locale->West;
			return locale;
		}
	}
	else
	{
		cout << "Command not recognized...\n";
		return locale;
	}
}


// Used to connect the rooms together
void Connect(Room* room1, string direction, Room* room2)
{
	if (direction[0] == 'n')
	{
		room1->North = room2;
		room2->South = room1;
	}
	else if (direction[0] == 'e')
	{
		room1->East = room2;
		room2->West = room1;
	}
	else if (direction[0] == 's')
	{
		room1->South = room2;
		room2->North = room1;
	}
	else if (direction[0] == 'w')
	{
		room1->West = room2;
		room2->East = room1;
	}
}
#endif