    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Log.h                       //
////////////////////////////////////////

#pragma once
#include <fstream>
#include <string>

using std::ofstream;
using std::string;

class Log
{
protected:
	static ofstream file;
	static void log(const string& msg);
public:
	static void i(const string& msg);
	static void w(const string& msg);
	static void e(const string& msg);
	static void clear();
};
