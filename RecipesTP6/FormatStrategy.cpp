///////////////////////////////////////////////////////////
//  FormatStrategy.cpp
//  Implementation of the Class FormatStrategy
//  Created on:      02-avr.-2022 14:16:26
//  Original author: francois
///////////////////////////////////////////////////////////

#include "FormatStrategy.h"
#include "TimeFormater.h"

FormatStrategy::FormatStrategy(std::string id)
{
	registerFormatStrategy(id, this);
}

FormatStrategy::time_decomposition FormatStrategy::decomposeTime(int time) const
{
	// � compl�ter: d�composer la dur�e en nombre de jours, heures, minutes et secondes
	//              retourner le r�sultat de la d�composition dans un objet time_decomposition

	time_decomposition timeDecomposition;
	timeDecomposition.days = time / (24 * 60 * 60);
	timeDecomposition.hours = (time % (24 * 60 * 60)) / (60 * 60);
	timeDecomposition.minutes = (time % (60 * 60)) / 60;
	timeDecomposition.seconds = (time % (60 * 60)) % 60;

	return time_decomposition(timeDecomposition);
}

void FormatStrategy::registerFormatStrategy(std::string id, const FormatStrategy* strategy)
{
	// � compl�ter: ins�rer la strat�gie dans le registre des strat�gies de la classe TimeFormater
	TimeFormater::getInstance().registerFormatStrategy(id, strategy);
}
