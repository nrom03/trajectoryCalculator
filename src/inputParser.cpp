#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <locale>

#include "../include/inputParser.H"

//#define INPUTPARSER_DEBUG

inputParser::inputParser()
{
}

void inputParser::printInputPath()
{
	std::cout << m_inputString << std::endl;
}

void inputParser::trimLine(std::string &line)
{
	if (!line.empty())
	{
		// Clear out spaces
		line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

		// Clear out end of line comments
		size_t idx = line.find('#');

		if (idx != std::string::npos)
		{
			//line.erase(line.find('#'));
			line.erase(idx);
		}
	}
}

void inputParser::getTokenValue(const std::string &file, const std::string &token, std::string &readValue)
{
	std::string line;
	std::ifstream inputFile (file);
	bool tokenFound = false;

	if (inputFile.is_open())
	{
		while (getline(inputFile, line))
		{
			inputParser::trimLine(line);

			if (line.empty() || line.at(0) == '#')
			{
				continue;
			}

			if (line.find(token) != std::string::npos)
			{
				//std::cout << line << "\n" << token << "\n" << line.find(token) << std::endl;
				std::string target = line.substr(line.find('=') + 1);
				readValue = target;
				tokenFound = true;
				break;
			}
		}
	}
	else
	{
		std::cerr << "ERROR: Unable to open file \"" << file << "\"" << std::endl;
	}
	inputFile.close();

	if (tokenFound == false)
	{
		std::cerr << "ERROR: Token \"" << token << "\" not found in file \"" << file << "\"" << std::endl;
	}
}

void inputParser::parseSimConfig()
{
	std::string initialLat;
	std::string initialLong;
	std::string flightSampleRate;
	std::string constantWindResistance;

	getTokenValue(m_simulationConfigFile, "InitialLat", initialLat);
	getTokenValue(m_simulationConfigFile, "InitialLong", initialLong);
	getTokenValue(m_simulationConfigFile, "FlightSampleRate", flightSampleRate);
	getTokenValue(m_simulationConfigFile, "ConstantWindResistance(0->OFF,1->LOW,2->MED,3->HIGH)", constantWindResistance);

	#ifdef INPUTPARSER_DEBUG
		std::cout << initialLat << "\n"
				  << initialLong << "\n"
				  << flightSampleRate << "\n"
				  << constantWindResistance <<
		std::endl;
	#endif

	m_simConfig.initialLat = std::stod(initialLat);
	m_simConfig.initialLong = std::stod(initialLong);
	m_simConfig.flightSampleRate = std::stod(flightSampleRate);
	m_simConfig.constantWindResistance = std::stoi(constantWindResistance);
}

// Might not be a bad idea to have the token be a template that a takes in various types, no need to create one string per parameter here
void inputParser::parseTrajConfig()
{
	std::string objectName;
	std::string objectMass;
	std::string launchVelocity;
	std::string launcherAngle;
	std::string launcherHeight;

	getTokenValue(m_trajectoryConfigFile, "ObjectName", objectName);
	getTokenValue(m_trajectoryConfigFile, "ObjectMass", objectMass);
	getTokenValue(m_trajectoryConfigFile, "LaunchVelocity", launchVelocity);
	getTokenValue(m_trajectoryConfigFile, "LauncherAngle", launcherAngle);
	getTokenValue(m_trajectoryConfigFile, "LauncherHeight", launcherHeight);

	#ifdef INPUTPARSER_DEBUG
		std::cout << objectName << "\n"
				  << objectMass << "\n"
				  << launchVelocity << "\n"
				  << launcherAngle <<
		std::endl;
	#endif

	m_trajConfig.objectName = objectName;
	m_trajConfig.objectMass = std::stod(objectMass);
	m_trajConfig.launchVelocity = std::stod(launchVelocity);
	m_trajConfig.launcherAngle = std::stod(launcherAngle);
	m_trajConfig.launcherHeight = std::stod(launcherHeight);
}

void inputParser::parseInputs()
{
	getTokenValue(m_inputString, "SimConfigFile", m_simulationConfigFile);
	getTokenValue(m_inputString, "TrajectoryParamsFile", m_trajectoryConfigFile);

	std::cout << "Found SimConfigFile = " << m_simulationConfigFile << std::endl;
	std::cout << "Found TrajectoryParamsFile = " << m_trajectoryConfigFile << std::endl;

	// Populate config structs
	parseSimConfig();
	parseTrajConfig();
}
