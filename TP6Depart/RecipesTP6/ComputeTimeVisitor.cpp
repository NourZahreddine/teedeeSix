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
	// À compléter: itérer sur les enfants du composite et appliquer le visiteur à chaque enfant

	for (auto comp = composite.begin(); comp != composite.end(); ++comp)
	{
		ComputeTimeVisitor visitor;
		comp->accept(visitor);
	}

}

void ComputeTimeVisitor::processIngredient(Ingredient& ingredient)
{
	// À compléter: ajouter la durée de préparation de l'ingrédient au temps total de préparation

	int preparationTime = 0;
	for (auto it = ingredient.begin(); it != ingredient.end(); ++it) 
	{
		preparationTime += it->getPreparationTime();
	}


}

void ComputeTimeVisitor::processRecipe(Recipe& recipe)
{
	// À compléter: itérer sur les ingrédients et appliquer le visiteur à chaque enfant
	//              itérer sur chaque étape et appliquer le visiteur à chaque étape
	for (auto ing = recipe.begin(); ing != recipe.end(); ++ing)
	{
		ComputeTimeVisitor visitor;
		ing->accept(visitor);
	}
}

void ComputeTimeVisitor::processSingleStep(SingleStep& step)
{
	// À compléter: ajouter la durée de réalisation de l'étape au temps total de réalisation
	int time = 0;
	for (auto it = step.begin(); it != step.end(); ++it)
	{
		time += it->getRealizationTime();
	}
}
