/**
 * @file Metropolis_Walker.h
 * @author ikhan
 *
 * @brief File contains template class for metropolis walker
 */

#ifndef QMC_METROPOLIS_WALKER_H
#define QMC_METROPOLIS_WALKER_H

#include <memory>

#include "QMC_Typedefs.h"
#include "QMC_Config.h"

namespace QMC
{

template<class wfnPhi, class wfnF>
class Metropolis_Walker
{
public:
	/**
	 *
	 */
	Metropolis_Walker(unsigned aNumParticles, unsigned aNumDims, double aParticleRadius,
            const std::vector<double>& aBoxSize, unsigned aMax_Correlation, WfnPhi& phi, wfnF& F)
	{

	}

	/**
	 *
	 */
	~Metropolis_Walker(){}

	/**
	 *
	 */
	void operator()()
	{
		run();
	}

private:
	/**
	 *
	 */
	void run(){}

	/// The number of particles
	unsigned m_NumParticles;

	/// The number of dimensions
	unsigned m_NumDimensions;

	/// The particle radius
	double m_ParticleRadius;

	/// The box size
	const std::vector<double>& m_BoxSize;

	///
	unsigned m_Max_Correlation;

	///
	wfnPhi& m_WfnPhi;

	///
	wfnF& m_WfnF;


}; // Metropolis_Walker

}; // end namespace QMC



#endif // QMC_METROPOLIS_WALKER_H
