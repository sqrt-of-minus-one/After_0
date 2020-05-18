    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Log.h                       //
////////////////////////////////////////

#pragma once
#include <fstream>
#include <string>

class Log
{
protected:
	static std::ofstream file;
	static void log(const std::string& msg);
public:
	static void i(const std::string& msg);
	static void w(const std::string& msg);
	static void e(const std::string& msg);
	static void clear();
};
