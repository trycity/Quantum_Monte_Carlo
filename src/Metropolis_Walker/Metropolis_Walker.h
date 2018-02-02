/**
 * @file Metropolis_Walker.h
 * @author ikhan
 *
 * @brief File contains template class for metropolis walker
 */

#ifndef QMC_METROPOLIS_WALKER_H
#define QMC_METROPOLIS_WALKER_H

#include <memory>
#include <vector>

#include "QMC_Typedefs.h"
#include "QMC_Config.h"

namespace QMC
{

template<class WfnPhi, class WfnF>
class Metropolis_Walker
{
public:
	/**
	 *
	 */
	Metropolis_Walker(unsigned aNumParticles, unsigned aNumDims, double aParticleRadius,
            const std::vector<double>& aBoxSize, unsigned aMax_Correlation, WfnPhi& phi, WfnF& F, UTILS::Energy_Functional eFunc):
            m_WfnPhi(phi), m_WfnF(F), m_EnergyFunc(eFunc)
	{
      m_ConfigPTR = std::make_unique<QMC_Config>(aNumParticles, aNumDims, aParticleRadius, aBoxSize, aMax_Correlation);
	}

	/**
	 *
	 */
	~Metropolis_Walker()
	{
	   
	}

	/**
	 *
	 */
	void operator()(unsigned nConfigInit, unsigned nConfigRun)
	{
	   UTILS::QMCPoint endPoint;
		std::unique_ptr<unsigned> pNode(new unsigned);
		std::unique_ptr<double> prob_val(new double);

		// move without computing energy
		for(unsigned i{0}; i < nConfigInit; i++)
		{
			m_ConfigPTR->trialMove(pNode, endPoint, prob_val, m_WfnPhi, m_WfnF);
			if(*prob_val > 1.0)
			{
				m_ConfigPTR->move(*pNode, endPoint, false);
			}
		}

      double energy{0.0}, energySqd{0.0};
      
		// move and compute energy
		for(unsigned i{0}; i < nConfigRun; i++)
		{
			m_ConfigPTR->trialMove(pNode, endPoint, prob_val, m_WfnPhi, m_WfnF);
			if(*prob_val > 1.0)
			{
				m_ConfigPTR->move(*pNode, endPoint, true);
			}

			if(m_ConfigPTR->computeEnergyTerms())
			{
				m_EnergyTerms = m_EnergyFunc(m_ConfigPTR->getPoints());
			}
			
			energy += m_EnergyTerms.first();
			energySqd += m_EnergyTerms.second();
		}

	}

private:

	///
	WfnPhi& m_WfnPhi;

	///
	WfnF& m_WfnF;

	/// configuration object
	std::unique_ptr<QMC_Config> m_ConfigPTR;

	/// Energy functional
	UTILS::Energy_Functional& m_EnergyFunc;

	///
	std::pair<double, double> m_EnergyTerms;


}; // Metropolis_Walker

}; // end namespace QMC



#endif // QMC_METROPOLIS_WALKER_H
