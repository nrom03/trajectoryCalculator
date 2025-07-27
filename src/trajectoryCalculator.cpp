#include <iostream>

#include "../include/trajectoryCalculator.H"

#define TRAJECTORY_DEBUG 1

trajectoryCalculator::trajectoryCalculator(simConfigs &simConfig, trajConfigs &trajConfig, double flightDuration) :
	m_objectName(trajConfig.objectName),
	m_objectMass(trajConfig.objectMass),
	m_launchVelocity(trajConfig.launchVelocity),
	m_launcherHeight(trajConfig.launcherHeight),
	m_launcherAngle(trajConfig.launcherAngle),
	m_initialLat(simConfig.initialLat),
	m_initialLong(simConfig.initialLong),
	m_flightSampleRate(simConfig.flightSampleRate),
	m_flightDuration(flightDuration),
	m_constantWindResistance(simConfig.constantWindResistance),
	m_exitStatusToReturn(0)
{
	#ifdef TRAJECTORY_DEBUG
		std::cout << m_objectName << "\n"
				  << m_objectMass << "\n"
				  << m_launchVelocity << "\n"
				  << m_launcherAngle << "\n"
				  << m_initialLat << "\n"
				  << m_initialLong << "\n"
				  << m_flightSampleRate << "\n"
				  << m_constantWindResistance <<
		std::endl;
	#endif
}

/*
 * This function should manage calculating the deviation from
 * the initial position the object began in
 * Assume a straight line for now, add in an azimuth offset later on
 * It should also write each data point to a file with an associated time
 * Time starts at 0 */
int trajectoryCalculator::run()
{


	return m_exitStatusToReturn;
}

