/**
 * @file QMC_Typedefs.h
 * @author ikhan
 * 
 * @brief File contains typedefs used for quantum monte carlo project
 */
 
#ifndef QMC_TYPEDEFS_H
#define QMC_TYPEDEFS_H

#include <valarray>

namespace QMC
{
namespace UTILS
{

using QMCPoint = std::valarray<double>;


}; // end namespace UTILS
}; // end namespace QMC


#endif // QMC_TYPEDEFS_H

