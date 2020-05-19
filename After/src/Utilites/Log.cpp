    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Log.cpp                     //
////////////////////////////////////////

#include "Log.h"
#include "Constants.h"
#include <ctime>

std::mutex Log::mtx;
std::ofstream Log::file;
bool Log::debug_mode = false;

void Log::log(std::string msg, const std::string& func_name)
{
	if (debug_mode)
	{
		msg += "\n<" + func_name + ">";
	}

	time_t* rt = new time_t;
	*rt = time(NULL);
	tm* t = new tm;
	localtime_s(t, rt);

	mtx.lock();
	file.open(LOG_FILE + TEXT_EXT, std::ios::app);
	file << (t->tm_mday < 10 ? "0" : "") << t->tm_mday << "." <<
		(t->tm_mon < 9 ? "0" : "") << t->tm_mon + 1 << "." <<
		t->tm_year - 100 << " " <<
		(t->tm_hour < 10 ? "0" : "") << t->tm_hour << ":" <<
		(t->tm_min < 10 ? "0" : "") << t->tm_min << ":" <<
		(t->tm_sec < 10 ? "0" : "") << t->tm_sec << ": " << msg << std::endl << std::endl;
	file.close();
	mtx.unlock();

	delete rt;
	delete t;
}

void Log::d(const std::string& msg, const std::string& func_name)
{
	if (debug_mode)
	{
		log(DEBUG + msg, func_name);
	}
}

void Log::i(const std::string& msg, const std::string& func_name)
{
	log(INFO + msg, func_name);
}

void Log::w(const std::string& msg, const std::string& func_name)
{
	log(WARNING + msg, func_name);
}

void Log::e(const std::string& msg, const std::string& func_name)
{
	log(ERROR + msg + REPORT, func_name);
	std::runtime_error(ERROR + msg);
}

void Log::debugEnable()
{
	debug_mode = true;
	Log_d(D_ENABLE);
}

void Log::debugDisable()
{
	Log_d(D_DISABLE);
	debug_mode = false;
}

void Log::clear()
{
	mtx.lock();
	file.open(LOG_FILE + TEXT_EXT);
	file.close();
	mtx.unlock();
}