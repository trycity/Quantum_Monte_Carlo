/**
 *@file EffectiveRangeF.h
 *
 *@author ikhan
 *@brief file depicting interaction term as stated in 1953 Jastrow paper.
 */


#ifndef QMC_EFFECTIVERANGEF_H
#define QMC_EFFECTIVERANGEF_H


namespace QMC
{

class EffectiveRangeF
{
public:
	/**
	 * Effective range interaction term ctor
	 *
	 * @param as The s-wave scattering length
	 */
	explicit EffectiveRangeF(double as);

	/**
	 * destructor
	 */
	~EffectiveRangeF();

	/**
	 * overloaded method call operator
	 *
	 * @param rij The interparticle distance
	 */
	double operator()(double rij)const;

private:
	/// S-Wave scattering length
	double m_as;

}; // EffectiveRangeF

}; // end namespace QMC

#endif // QMC_EFFECTIVERANGEF_H
