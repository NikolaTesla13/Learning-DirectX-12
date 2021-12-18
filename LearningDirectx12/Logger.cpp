#include "Logger.h"

namespace Program
{
	Logger::Logger(const LoggerProps& loggerProps) : m_Props(loggerProps) {}

	void Logger::Output(const std::string& message)
	{
		if (m_Props.onlyDebug)
		{
#ifndef _DEBUG
			return;
#endif
		}

		if (m_Props.showTime)
		{
			auto t = std::time(nullptr);
			auto tm = *std::localtime(&t);

			std::ostringstream oss;
			oss << std::put_time(&tm, "%H:%M:%S");

			OutputDebugStringA(("["+oss.str()+"]").c_str());
		}

		if (m_Props.shodID)
		{
			OutputDebugStringA(("[" + m_Props.identificator + "] ").c_str());
		}

		OutputDebugStringA((message + "\n").c_str());
    }
}