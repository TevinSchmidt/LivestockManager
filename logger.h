#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger
{
public:
    void INFO(std::string string, bool toConsole = false, bool toLog = true);
    void DEBUG(std::string string, bool toConsole = false, bool toLog = true);
    void VERBOSE(std::string string, bool toConsole = false, bool toLog = true);

private:

};

#endif // LOGGER_H
