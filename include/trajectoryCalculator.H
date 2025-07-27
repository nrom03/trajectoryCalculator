#ifndef __TRAJECTORY_CALCULATOR_H__
#define __TRAJECTORY_CALCULATOR_H__

#include <vector>

#include "inputParser.H" // For config info structs

class trajectoryCalculator
{
	public:
		trajectoryCalculator(simConfigs &simConfig, trajConfigs &trajConfig, double m_flightDuration);
		int run();
	private:
		std::string m_objectName;
		double m_objectMass;			// kg
		double m_launchVelocity;		// km/s
		double m_launcherHeight;		// km - height from center of the earth
		double m_launcherAngle;			// deg
		double m_initialLat;	 		// deg
		double m_initialLong; 	 		// deg
		double m_flightSampleRate;    	// sec
		double m_flightDuration;		// sec
		int m_constantWindResistance; 	// ConstantWindResistance(0->OFF,1->LOW,2->MED,3->HIGH)
		int m_exitStatusToReturn;			// Exit status that needs to get returned to main

		/*typedef struct apogeeData
		{
			double apogee; 				// km
			double timeToApogee;		// sec

			// Default values to 0
			apogeeData():
				apogee(0.0),
				timeToApogee(0.0)
				{}
		};

		apogeeData m_apogeeData;


		inline apogeeData* getApogeeData() { return &m_apogeeData; }*/

		typedef struct trajectoryData
		{
			double trajLat;
			double trajLong;
			double trajRange;
			double currentTime;
			double currentVel;
			double currentAcc;

			// Default values to 0
			trajectoryData():
				trajLat(0.0),
				trajLong(0.0),
				trajRange(0.0),
				currentTime(0.0),
				currentVel(0.0),
				currentAcc(0.0)
				{}
		};

		trajectoryData m_trajDataStruct;
		std::vector<trajectoryData> m_trajDataVec;

		inline trajectoryData* getCurrentTrajectoryData(int time) { return &m_trajDataVec.at(time); }
		inline std::vector<trajectoryData>* getTrajectoryDataVec() {return &m_trajDataVec; }
};

#endif
