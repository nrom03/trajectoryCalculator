#ifndef __INPUT_PARSER_H__
#define __INPUT_PARSER_H__

#include <string>

typedef struct trajConfigs trajConfigs;
typedef struct simConfigs simConfigs;

struct trajConfigs
{
	std::string objectName;
	double objectMass;		// km
	double launchVelocity; 	// km/s
	double launcherAngle;   // deg
	double launcherHeight; 	// km
};

struct simConfigs
{
	double initialLat;		 	// deg
	double initialLong; 	 	// deg
	double flightSampleRate;    // s
	int constantWindResistance; // ConstantWindResistance(0->OFF,1->LOW,2->MED,3->HIGH)
};

class inputParser
{
	public:
		inputParser();
		void printInputPath();
		inline void setInputString(const std::string &inputPath) { m_inputString = inputPath; }
		inline void populateTrajConfig(trajConfigs &traj) { traj = m_trajConfig; }
		inline void populateSimConfig(simConfigs &sim) { sim = m_simConfig; }
		void parseInputs();

	private:
		// data could probably be in a protected section, doesn't need to be private
		std::string m_inputString;
		std::string m_trajectoryConfigFile;
		std::string m_simulationConfigFile;

		trajConfigs m_trajConfig;
		simConfigs m_simConfig;
		void trimLine(std::string &line);
		void getTokenValue(const std::string &file, const std::string &token, std::string &target);
		void parseTrajConfig();
		void parseSimConfig();
};

#endif
