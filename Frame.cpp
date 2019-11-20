/************************************************
Filename:				Frame.cpp
Version:				1.0
Author:					Andrew Palmer
Assignment Number:		2
Assignment Name:		Animation in C++ using Container Classes and Overloaded Operators
Course Name:			C++
Course Code:			CST219
Lab Section Number:		302
Professor's Name:		Mariusz Makos
Due Date:				2019/11/09
Submission Date:		2019/11/05
List of source files:	Frame.h

Purpose:	Class file for the Frame object, defines the constructor and destructor
			as well as the overload of the assignment and output operator.
**********************************/

#include <crtdbg.h>
#include <iostream>
#include <string>
using namespace std;
#include "VideoFrame.h"
#include "AudioFrame.h"
#include "Frame.h"



/***********************************************
Overloading the << operator
Purpose:		Defines the new behaviour when passing
				the Frame object to outstream.
In parameters:	None
Out Parameters: None
Version:		1.0
Author:			Andrew Palmer
************************************************/
ostream& operator<<(ostream& out, Frame& frame) {
	try {
		AudioFrame& audio = dynamic_cast<AudioFrame&>(frame);
		out << audio << " frameName= " << frame.frameName << endl;
	} catch(const bad_cast& e) {}
	
	try {
		VideoFrame& video = dynamic_cast<VideoFrame&>(frame);
		out << video << " frameName= " << frame.frameName << endl;
	}
	catch (const bad_cast & e) {}
	return out;
}
