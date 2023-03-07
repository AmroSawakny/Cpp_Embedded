#include "CppLogger.hpp"

CppLogger::CppLogger(std::string lAppId, LogLevel lloglevel, LogMode llogmode, std::string lfileName = "")
{
    if (llogmode == mFile)
    {
        if (lfileName == "")
        {
            lfileName = "log.txt";
        }
        Myfile.open(lfileName);
    }
    this->appId = lAppId;
    this->LoggerLevel = lloglevel;
    this->LogNum = 1;
    this->LoggerMode = llogmode;
}

CppLogger::~CppLogger()
{
    Myfile.close();
}

void CppLogger::SetLogLevel(std::string lAppId, LogLevel llogLevel)
{
    this->appId = lAppId;
    this->LoggerLevel = llogLevel;
}

void CppLogger::SetLogMode(std::string lAppId, LogMode llogMode)
{
    this->appId = lAppId;
    this->LoggerMode = llogMode;
}

std::ostream &operator<<(CppLogger &logger, const char *Msg)
{

    logger.gettime();
    switch (logger.LoggerMode)
    {
    case mFile:
        logger.Myfile << logger.timestamp << " | " << logger.appId << " | " << logger.LogNum << " | " << logger.convert_enum[logger.LoggerLevel] << " | " << Msg << std::endl;
        logger.LogNum++;
        return logger.Myfile;
        break;
    case mConsole:
        std::cout << logger.timestamp << " | " << logger.appId << " | " << logger.LogNum << " | " << logger.convert_enum[logger.LoggerLevel] << " | " << Msg << std::endl;
        logger.LogNum++;
        return std::cout;
        break;
    }
}

void CppLogger::gettime()
{
    time(&rawtime);
    CppLogger::timeinfo = localtime(&rawtime);
    this->timestamp = asctime(timeinfo);
    this->timestamp = this->timestamp.substr(0, this->timestamp.size() - 1);
}
