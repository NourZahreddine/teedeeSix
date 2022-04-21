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
	// À compléter: décomposer la durée en nombre de jours, heures, minutes et secondes
	//              retourner le résultat de la décomposition dans un objet time_decomposition

	time_decomposition timeDecomposition;
	timeDecomposition.days = time / (24 * 60 * 60);
	timeDecomposition.hours = (time % (24 * 60 * 60)) / (60 * 60);
	timeDecomposition.minutes = (time % (60 * 60)) / 60;
	timeDecomposition.seconds = (time % (60 * 60)) % 60;

	return time_decomposition(timeDecomposition);
}

void FormatStrategy::registerFormatStrategy(std::string id, const FormatStrategy* strategy)
{
	// À compléter: insérer la stratégie dans le registre des stratégies de la classe TimeFormater
	TimeFormater::getInstance().registerFormatStrategy(id, strategy);
}
