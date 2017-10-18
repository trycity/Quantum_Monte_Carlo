/**
 *@file SymHoPhi.cpp
 *
 *@author ikhan
 */

#include <cmath>

#include "SymHoPhi.h"

namespace QMC
{

SymHoPhi::SymHoPhi(double alpha):m_Alpha(alpha)
{}

SymHoPhi::~SymHoPhi(){}

double SymHoPhi::operator()(double ri) const
{
	return exp(-m_Alpha*ri*ri);
}

}; // end namespace QMC
