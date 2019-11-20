/************************************************
Filename:Animation.cpp
Version: 1.0
Author: Andrew Palmer
Assignment Number:0
Assignment Name:Animation Project in C
Course Name: C++
Course Code:CST219
Lab Section Number: 302
Professor's Name: Mariusz Makos
Due Date: 2019/11/09
Submission Date:2019/11/05
List of source files: Animation.cpp
Purpose: Until the User quits the program. It will read a valid response from the keyboard
in order to go through the process of either creating a frame of animation,editing a frame,
displaying all frames or even delete a frame.
**********************************/
#define _CRT_SECURE_NO_WARNINGS
#include <crtdbg.h>
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
using namespace std;
#include "Frame.h"
#include "AudioFrame.h"
#include "VideoFrame.h"
#include "Animation.h"



/***********************************************
Function name:	DeleteFrame
Purpose:		Deletes a frame from the beginning of the
				Animation's frames list.
In parameters:
Out Parameters: None
Version:		1.0
Author:			Andrew Palmer
************************************************/
void Animation::DeleteFrame() {
	if (this->frames.empty()) {
		cout << "No frames to delete" << endl;
	}
	else {
		this->frames.pop_front(); // delete the head of the forward list
		cout << "First frame deleted" << endl;
	}
}

/***********************************************
Function name:	EditFrame
Purpose:		Edits the name of a frame.
In parameters:
Out Parameters: None
Version:		1.0
Author:			Andrew Palmer
************************************************/
void Animation::EditFrame()
{
	int counter = 0; // counter for the list
	int index; // index for the list
	string newName; // a placeholder for editing the Frame name
	int size; // a placeholder for editing the duration
	forward_list<Frame*>::iterator it;

	// count how many frames in the list
	for (auto i = this->frames.begin(); i != this->frames.end(); ++i) {
		counter++;
	}

	if (counter == 0) {
		cout << "There are no Frames in the Animation" << endl;
	}
	else {
		cout << "Edit a Frame in the Animation" << endl;

		//different outputs if there is one or many items in the list
		if (counter == 1) {
			cout << "There are " << counter << " Frame(s) in the list. Please specify the index (<=0) to edit at:";
		}
		else {
			cout << "There are " << counter << " Frame(s) in the list. Please specify the index (from 0 to " << counter - 1 << ") to edit at:";
		}

		while (!(cin >> index)) { // make sure user input is a valid number
			cout << "That is not a number. Please try again: " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the invalid input
		}

		if (index <= counter - 1 && index >= 0) {
			counter = 0;

			for (it = frames.begin(); it != frames.end(); it++) { //loop to the correct index and perform edit actions
				if (counter == index) {
					cout << **it << " What do you wish to replace them with?" << endl;
					cin >> newName;
					while (!(cin >> size)) { // make sure user input is a valid number
						cout << "That is not a number. Please try again: " << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the invalid input
					}
					
				}
				counter++;
			}
		}
		else {
			cout << "The index selected is out of range" << endl; // if index given is out of range
		}
	}
}

/***********************************************
Overloading the >> operator
Purpose:		Defines the new behaviour when passing
				the Animation object to instream.
In parameters:	None
Out Parameters: None
Version:		1.0
Author:			Andrew Palmer
************************************************/
istream& operator>>(istream& in, Animation& animation) {
	string name; // placeholder for the name of the frame being created
	int size = 0; // placeholder for the duration of the frame being created
	char type;

	cout << "Insert a Frame into the Animation " << endl;
	cout << "Please enter the Frame frameName: ";
	cin >> name;
	cout << "Please enter the Frame size(MB): ";
	while (!(cin >> size)) { // make sure user input is a valid number
		cout << "That is not a number. Please try again: " << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the invalid input
	}

	cout << "Please enter the Frame type (AudioFrame = A, VideoFrame = V): ";
	cin >> type;

	if (type == 'A') {
		animation.frames.push_front(AudioFrame(name, size)); // place new frame at the front of the forward list
	}
	else if (type == 'V') {
		animation.frames.push_front(VideoFrame(name, size)); // place new frame at the front of the forward list
	}
	else {
		cout << "There was an error creating frame" << endl;
	}
	
	cout << "Frame " << name << " added at the front of frames" << endl;
	return in;
}

/***********************************************
Overloading the << operator
Purpose:		Defines the new behaviour when passing
				the Animation object to outstream.
In parameters:	None
Out Parameters: None
Version:		1.0
Author:			Andrew Palmer
************************************************/
ostream& operator<<(ostream& out, Animation& animation) {
	int counter = 0; // counter for animation frames list

	out << "	Animation name is " << animation.animationName << endl;
	out << "	Report the Animation" << endl;

	if (animation.frames.empty()) {
		out << "	No frames in the Animation" << endl; //if frames is empty print this
	}
	else {
		for (Frame& frame : animation.frames) {
			out << "	Frame " << counter << ": " << frame << endl; // print every frame object in the list
			counter++;
		}
	}
	return out;
}


