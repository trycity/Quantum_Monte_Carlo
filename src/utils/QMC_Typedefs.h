/**
 * @file QMC_Typedefs.h
 * @author ikhan
 * 
 * @brief File contains typedefs used for quantum monte carlo project
 */
 
#ifndef QMC_TYPEDEFS_H
#define QMC_TYPEDEFS_H

#include <valarray>
#include <functional>
#include <utility>
#include <vector>

namespace QMC
{
namespace UTILS
{

/// alias representing a point in the simulation
using QMCPoint = std::valarray<double>;

/// alias representing energy functional
using Energy_Functional = std::function<std::pair<double, double>(const std::vector<QMCPoint>&)>;


}; // end namespace UTILS
}; // end namespace QMC


#endif // QMC_TYPEDEFS_H

