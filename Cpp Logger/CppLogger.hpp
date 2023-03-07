#pragma once

#include <stdio.h>
#include <time.h>
#include <string>
#include <fstream>
#include <iostream>

typedef enum
{
    lOff,
    lError,
    lWarn,
    lInfo,
    lDebug,
} LogLevel;

typedef enum
{
    mFile,
    mConsole,
    mRemote,
} LogMode;

class CppLogger
{
private:
    time_t rawtime;
    struct tm *timeinfo;
    std::string timestamp;
    std::string appId;
    std::ofstream Myfile; /*If not set defualts to log.txt;*/
    int LogNum;
    LogMode LoggerMode;
    LogLevel LoggerLevel;
    LogLevel MsgLevel;
    void gettime();
    std::string convert_enum[5] =
        {"lOff",
         "lError",
         "lWarn",
         "lInfo",
         "lDebug"};

public:
    CppLogger(std::string lAppId, LogLevel lloglevel, LogMode llogmode, std::string lfileName);
    ~CppLogger();
    void SetLogLevel(std::string lAppId, LogLevel llogLevel);
    void SetLogMode(std::string lAppId, LogMode llogMode);
    friend std::ostream &operator<<(CppLogger &logger, const char *Msg);
};
