/**
 * @file QMC_Utilities.cpp
 * @author ikhan
 * 
 * @brief File contains implementation of utility methods used for quantum monte carlo project
 */
 
#include <valarray>
#include <cmath>


#include "QMC_Utilities.h"

namespace QMC
{
namespace UTILS
{

double QMC_Distance(const QMCPoint& aPointA, const QMCPoint& aPointB)
{
   QMCPoint X = aPointA - aPointB;
   std::valarray<double> Y = X*X;

   return std::sqrt(Y.sum());
}

double computeVectorSize(const QMCPoint& aPoint)
{
	std::valarray<double> Y = aPoint*aPoint;

	return std::sqrt(Y.sum());
}

}; // end namespace UTILS
}; // end namespace QMC



