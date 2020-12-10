#ifndef LOGGER_H
# define LOGGER_H

# include <iostream>

class Logger {

public:

	Logger(std::string str);
	~Logger(void);

	void log(std::string const &dest, std::string const &message);

private:

	std::string _filename;

	void	logToConsole(std::string str);
	void	logToFile(std::string str);
	std::string makeLogEntry(std::string str);

};

#endif
