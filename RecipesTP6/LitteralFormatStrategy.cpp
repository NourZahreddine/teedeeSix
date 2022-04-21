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
	// � compl�ter: d�composer la dur�e et construire une chaine avec en format lit�ral

	int jour, heure, minute;
	jour = time / (24 * 60 * 60);
	time = time % (24 * 60 * 60);
	heure = time / (60 * 60);
	time = time % (60 * 60);
	minute = time / 60;
	time = time % 60;
	std::string value = std::to_string(jour) + " jours " + std::to_string(heure) + " heures " + std::to_string(minute) + " minutes " + std::to_string(time) + " secondes ";
	return value;
}