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
#include "Frame.h"
#include "AudioFrame.h"


void AudioFrame::CalculateFrameResource() {
	cout << "MP3 Lossy Compression" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "bitrate (kbits/s):        | " << BITRATE[0] << "    | " << BITRATE[1] << "    | " << BITRATE[2] << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "file size (MB):           | " << size / (COMPRESSION_RATIO[0]) << "    | " << size / (COMPRESSION_RATIO[1]) << "    | " << size / (COMPRESSION_RATIO[1]) << endl;
	cout << "---------------------------------------------------------" << endl;
}

ostream& operator<<(ostream& out, AudioFrame& frame) {
	out << "AudioFrame: ";
	return out;
}