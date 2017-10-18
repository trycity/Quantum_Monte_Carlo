/**
 *@file EffectiveRangeF.cpp
 *
 *@author ikhan
 *
 */

#include "EffectiveRangeF.h"

namespace QMC
{

EffectiveRangeF::EffectiveRangeF(double as):m_as(as)
{}

EffectiveRangeF::~EffectiveRangeF(){}

double EffectiveRangeF::operator()(double rij) const
{
	return (1.0 - m_as/rij);
}

}; // end namespace QMC
