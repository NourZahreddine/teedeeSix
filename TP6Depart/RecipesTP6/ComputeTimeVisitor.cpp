///////////////////////////////////////////////////////////
//  ComputeTimeVisitor.cpp
//  Implementation of the Class ComputeTimeVisitor
//  Created on:      02-avr.-2022 14:16:25
//  Original author: francois
///////////////////////////////////////////////////////////

#include "ComputeTimeVisitor.h"
#include "CompositeStep.h"
#include "Ingredient.h"
#include "Recipe.h"
#include "SingleStep.h"

ComputeTimeVisitor::ComputeTimeVisitor()
	: m_preparationTime(0), m_realizationTime(0)
{
}

void ComputeTimeVisitor::processCompositeStep(CompositeStep& composite)
{
	// � compl�ter: it�rer sur les enfants du composite et appliquer le visiteur � chaque enfant

	for (auto comp = composite.begin(); comp != composite.end(); ++comp)
	{
		ComputeTimeVisitor visitor;
		comp->accept(visitor);
	}

}

void ComputeTimeVisitor::processIngredient(Ingredient& ingredient)
{
	// � compl�ter: ajouter la dur�e de pr�paration de l'ingr�dient au temps total de pr�paration

	int preparationTime = 0;
	for (auto it = ingredient.begin(); it != ingredient.end(); ++it) 
	{
		preparationTime += it->getPreparationTime();
	}


}

void ComputeTimeVisitor::processRecipe(Recipe& recipe)
{
	// � compl�ter: it�rer sur les ingr�dients et appliquer le visiteur � chaque enfant
	//              it�rer sur chaque �tape et appliquer le visiteur � chaque �tape
	for (auto ing = recipe.begin(); ing != recipe.end(); ++ing)
	{
		ComputeTimeVisitor visitor;
		ing->accept(visitor);
	}
}

void ComputeTimeVisitor::processSingleStep(SingleStep& step)
{
	// � compl�ter: ajouter la dur�e de r�alisation de l'�tape au temps total de r�alisation
	int time = 0;
	for (auto it = step.begin(); it != step.end(); ++it)
	{
		time += it->getRealizationTime();
	}
}
