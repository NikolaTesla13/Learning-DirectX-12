#pragma once

#include "System.h"
#include "Logger.h"

namespace Program
{
	class Timer
	{
	public:

		Timer() = default;

		Timer(std::string title = "")
		{
			LoggerProps loggerProps;
			loggerProps.identificator = title;
			loggerProps.onlyDebug = true;
			loggerProps.shodID = true;
			loggerProps.showTime = true;

			m_Logger = Logger(loggerProps);

			m_Start = std::chrono::high_resolution_clock::now();
		}

		~Timer()
		{
			m_End = std::chrono::high_resolution_clock::now();
			m_Duration = m_End - m_Start;
			double ms = m_Duration.count() * 1000.0f;
			m_Logger.Output("took " + std::to_string(ms) + " miliseconds");
		}

	private:
		Logger m_Logger;
		std::chrono::steady_clock::time_point m_Start, m_End;
		std::chrono::duration<double> m_Duration;
	};
}