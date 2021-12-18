#pragma once

#include "System.h"

namespace Program
{
	struct LoggerProps
	{
		BOOL onlyDebug;
		BOOL showTime;
		BOOL shodID = true;
		std::string identificator;
	};

	class Logger // much safer than log4j :)
	{
	public:
		Logger() {};
		explicit Logger(const LoggerProps& loggerProps);

		void Output(const std::string& message);
		//static void LogTiming(const std::string& identificator);

	private:
		LoggerProps m_Props;
	};
}