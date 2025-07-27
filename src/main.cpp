#include <iostream>
#include <memory>

#include "../include/inputParser.H"
#include "../include/trajectoryCalculator.H"

int main(int argc, char* argv[])
{
	std::string configInput;
	std::unique_ptr<inputParser> Parser (new inputParser);

	if (argc == 1)
	{
		configInput = "../programConfig.cfg";
		std::cout << "Using internal configuration file \"" << configInput << "\"\n";
	}
	else if(argc == 2)
	{
		configInput = argv[1];
		std::cout << "Using custom configuration file \"" << configInput << "\"\n";
	}

	Parser->setInputString(configInput);
	Parser->parseInputs();

	simConfigs sim;
	trajConfigs traj;

	Parser->populateSimConfig(sim);
	Parser->populateTrajConfig(traj);

	// Pass off the simulation info to the trajectory calculator
	std::unique_ptr<trajectoryCalculator> trajCalc (new trajectoryCalculator(sim, traj));
	int executionStatus = trajCalc->run();

}
