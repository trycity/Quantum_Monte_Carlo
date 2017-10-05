/**
 * @file QMC_Config.h
 * @author ikhan
 * 
 * @brief Configuration class for quantum monte carlo
 */

#ifndef QMC_CONFIG_H 
#define QMC_CONFIG_H 

#include <vector>
#include <valarray>
#include <utility>

#include "QMC_Typedefs.h"

namespace QMC
{

/**
 * @brief QMC_Config class used to create initial phase space for monte carlo calculation
 */
class QMC_Config
{
public:
	/**
	 * QMC_Config ctor
	 *
	 * @param aNumParticles The number of particles in the simulation
	 * @param aNumDims The dimension of space
	 * @param aParticleRadius The particle radius
	 * @param aBoxSize The box size of the phase space
	 * @param aMax_Correlation The max correlation particle number in order to computer energy
	 *
	 */
	QMC_Config(unsigned aNumParticles, unsigned aNumDims,
			double aParticleRadius, const std::valarray<double>& aBoxSize, unsigned aMax_Correlation);

	/**
	 * Destroys a QMC_Config object
	 */
	~QMC_Config();

	/**
	 * Performs a trial move of a node from some initial point to an endPoint
	 *
	 * @param pNode A pointer to the chosen node
	 * @param aNewPoint The new position of the node
	 * @param aProb_Val A pointer to the probability value
	 */
	void trialMove(unsigned* pNode, UTILS::QMCPoint& aNewPoint, double* aProb_Val);

	/**
	 * Performs a move of a node from some initial point to an new point
	 *
	 * @param aNodeNumber The node chosen to be moved
	 * @param aNewPoint The new position of the node
	 * @param aComputeEnergyFlag Flag determines if energy terms are to be computed
	 */
	void move(unsigned aNodeNumber, const UTILS::QMCPoint& aNewPoint, bool aComputeEnergyFlag);

	/**
	 * Computes the energy of the system
	 *
	 * @return The energy and the energy sqd values
	 */
	//std::pair<double, double> computeEnergyTerms();

private:
	/**
	 * creates the initial configuration of the monte carlo simulation
	 */
	void initialize();

	/**
	 * Computes the energy terms
	 */
	void computeEnergyTerms();

	/// The number of particles
	unsigned m_NumParticles;

	/// The number of dimensions
	unsigned m_NumDimensions;

	/// The particle radius
	double m_ParticleRadius;

	/// The box size
	const std::valarray<double>& m_BoxSize;

	/// The coordinates of the particle positions
	std::vector<UTILS::QMCPoint> m_Points;

	/// Flag determines if energy terms are to be computed
	bool m_EnergyComputed { false };

	/// The max correlation term for energy computation
	unsigned m_MaxCorrelation;

	/// pair holds energy term and energy sqd term
	std::pair<double, double> m_EnergyTerms;

}; // end QMC_Config

}; // end namespace QMC

#endif // QMC_CONFIG_H 
