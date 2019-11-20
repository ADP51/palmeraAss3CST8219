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
#include "VideoFrame.h"


void VideoFrame::CalculateFrameResource() {
	cout << "MP3 Lossy Compression" << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << "colours: | 2	| 4    | 8    | 16   | 32   | 64   | 128  | 256" << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << "file size (MB):           | " << size / (COMPRESSION_RATIO*BITDEPTH_FACTOR[0]) << "    | " << size / (COMPRESSION_RATIO * BITDEPTH_FACTOR[1]) << "    | " << size / (COMPRESSION_RATIO * BITDEPTH_FACTOR[2]) << "    | " << size / (COMPRESSION_RATIO * BITDEPTH_FACTOR[3]) << "    | " << size / (COMPRESSION_RATIO * BITDEPTH_FACTOR[4]) << "    | " << size / (COMPRESSION_RATIO * BITDEPTH_FACTOR[5]) << "    | " << size / (COMPRESSION_RATIO * BITDEPTH_FACTOR[6]) << "    | " << size / (COMPRESSION_RATIO * BITDEPTH_FACTOR[7]) << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;
}

ostream& operator<<(ostream& out, VideoFrame& frame) {
	out << "VideoFrame: ";
	return out;
}