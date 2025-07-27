Nick Romano
March 27 2025

trajectoryCalculatorR1

Purpose:
	*Take an object configuration file and output a trajectory file
	
Config File:
	*Launch site lat/long
	*Flight sample rate (.25 being increments of .25 seconds rather than 1 second jumps in time iteration)
	*Gravity constant(m/s^2)
	*Constant wind resistance
		- If value is zero model no wind resistance, anything else model it (based off of low/med/high?)
		- Not modeling a shape, just a slowing (linear?) of acceleration
		
Input File:
	*Object Name
	*Object Mass
	*(Optional randomization) Duration of flight(s)
	*(Optional randomization) Maximum altitude(km)
	*(Optional randomization) Maximum range from start(km)
	*(Optional randomization) Initial launch acceleration
	
Output File:
	*ecef file of where the trajectory went from start to finish
