///////////////////////////////////////////////////////////
//  NumericFormatStrategy.cpp
//  Implementation of the Class NumericFormatStrategy
//  Created on:      02-avr.-2022 14:16:27
//  Original author: francois
///////////////////////////////////////////////////////////

#include "NumericFormatStrategy.h"

NumericFormatStrategy NumericFormatStrategy::instance;

NumericFormatStrategy::NumericFormatStrategy()
	: FormatStrategy(NumericFormat)
{
}

std::string NumericFormatStrategy::format(int time) const 
{
	// À compléter: décomposer la durée et construire une chaine avec en format numérique
	int day, hour,minute,i = 60 * 60;
	day = time / (24 * i);
	hour = (time % (24 * i)) / (i);
	minute = (time % (i)) / 60;
	time = time % 60;
	std::string value = std::to_string(day) + ":" + std::to_string(hour)+ ":" + std::to_string(minute) + ":" + std::to_string(time);
	return value;
}