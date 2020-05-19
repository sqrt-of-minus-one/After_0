    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Log.h                       //
////////////////////////////////////////

#pragma once
#include <fstream>
#include <string>
#include <mutex>

#define Log_d(msg) Log::d(msg, __func__)
#define Log_i(msg) Log::i(msg, __func__)
#define Log_w(msg) Log::w(msg, __func__)
#define Log_e(msg) Log::e(msg, __func__)

class Log
{
protected:
	static std::mutex mtx;
	static std::ofstream file;
	static void log(std::string msg, const std::string& func_name);
	static bool debug_mode;
public:
	static void d(const std::string& msg, const std::string& func_name);
	static void i(const std::string& msg, const std::string& func_name);
	static void w(const std::string& msg, const std::string& func_name);
	static void e(const std::string& msg, const std::string& func_name);
	static void debugEnable();
	static void debugDisable();
	static void clear();
};
