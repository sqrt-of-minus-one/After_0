    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Log.cpp                     //
////////////////////////////////////////

#include "Log.h"
#include "Constants.h"
#include <ctime>

using std::ios;
using std::tm;
using std::time;
using std::time_t;
using std::endl;

ofstream Log::file;

void Log::log(const string& msg)
{
	time_t* rt = new time_t;
	*rt = time(NULL);
	tm* t = new tm;
	localtime_s(t, rt);

	file.open(LOG + TEXT_EXT, ios::app);
	file << (t->tm_mday < 10 ? "0" : "") << t->tm_mday << "." <<
		(t->tm_mon < 9 ? "0" : "") << t->tm_mon + 1 << "." <<
		t->tm_year - 100 << " " <<
		(t->tm_hour < 10 ? "0" : "") << t->tm_hour << ":" <<
		(t->tm_min < 10 ? "0" : "") << t->tm_min << ":" <<
		(t->tm_sec < 10 ? "0" : "") << t->tm_sec << ": " << msg << endl << endl;
	file.close();

	delete rt;
	delete t;
}

void Log::i(const string& msg)
{
	log(INFO + msg);
}

void Log::w(const string& msg)
{
	log(WARNING + msg);
}

void Log::e(const string& msg)
{
	log(ERROR + msg + REPORT);
}

void Log::clear()
{
	file.open(LOG + TEXT_EXT);
	file.close();
}