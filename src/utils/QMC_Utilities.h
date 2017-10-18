/**
 * @file QMC_Utilities.h
 * @author ikhan
 * 
 * @brief File contains utility methods used for quantum monte carlo project
 */

#ifndef QMC_UTILITIES_H
#define QMC_UTILITIES_H

#include "QMC_Typedefs.h"

namespace QMC
{
namespace UTILS
{

/**
 * Method computes the distance between two points
 *
 * @param aPointA a QMC point
 * @param aPointB a QMC point
 *
 * @return The distance between two points
 */
double QMC_Distance(const QMCPoint& aPointA, const QMCPoint& aPointB);

/**
 * computes the size of the vector
 */
double computeVectorSize(const QMCPoint& aPoint);

}; // end namespace UTILS

}; // end namespace QMC

#endif // QMC_UTILITIES_H

