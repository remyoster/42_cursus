#include "Logger.hpp"
#include <iomanip>
#include <fstream>
#include <sstream>
#include <ctime>

Logger::Logger(std::string str) : _filename(str) {}

Logger::~Logger(void) {
	return ;
}

std::string Logger::makeLogEntry(std::string str) {
	std::time_t t = std::time(NULL);
	std::tm *data = std::localtime(&t);
	std::stringstream ss;
	ss << "[";
	ss << data->tm_mday << "/" << data->tm_mon + 1 << "/" << data->tm_year + 1900;
	ss << " " << data->tm_hour << ":" << data->tm_min << ":" << data->tm_sec;
	ss << "]";
	ss << " " << str;
	return ss.str();
}

void	Logger::logToConsole(std::string str) {
	std::cout << str << std::endl;
}

void	Logger::logToFile(std::string str) {
	std::ofstream ofs;
	ofs.open(this->_filename.c_str(), std::ios::app);

	if (ofs.is_open())
		ofs << str << std::endl;
}

void	Logger::log(std::string const &dest, std::string const &message) {
	std::string dests[] = {
		"console",
		"file"
	};
	void (Logger::*fct[])(std::string) = {
		&Logger::logToConsole,
		&Logger::logToFile
	};
	size_t idx = 0;

	while (idx < 2) {
		if (dests[idx].compare(dest) == 0) {
			(this->*fct[idx])(this->makeLogEntry(message));
			return ;
		}
		idx++;
	}
	std::cout << dest << " destination is not a valid dest" << std::endl;
}