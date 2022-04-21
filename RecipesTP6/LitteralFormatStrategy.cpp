///////////////////////////////////////////////////////////
//  LitteralFormatStrategy.cpp
//  Implementation of the Class LitteralFormatStrategy
//  Created on:      02-avr.-2022 14:16:27
//  Original author: francois
///////////////////////////////////////////////////////////

#include "LitteralFormatStrategy.h"
#include "TimeFormater.h"

LitteralFormatStrategy LitteralFormatStrategy::instance;


LitteralFormatStrategy::LitteralFormatStrategy()
	: FormatStrategy(LitteralFormat)
{
}

std::string LitteralFormatStrategy::format(int time) const 
{
	// À compléter: décomposer la durée et construire une chaine avec en format litéral

	int day, hour, minute,i = 60 * 60;
	day = time / (24 * i);
	hour = (time % (24 * i)) / (i);
	minute = (time % (i)) / 60;
	time = time % 60;
	std::string value = std::to_string(day) + " jours " + std::to_string(hour) + " heures " + std::to_string(minute) + " minutes " + std::to_string(time) + " secondes ";
	return value;
}