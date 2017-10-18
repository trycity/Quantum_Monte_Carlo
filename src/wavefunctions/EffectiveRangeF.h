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
	explicit EffectiveRangeF(double as);
	~EffectiveRangeF();

	double operator()(double rij)const;

private:
	/// S-Wave scattering length
	double m_as;

}; // EffectiveRangeF

}; // end namespace QMC

#endif // QMC_EFFECTIVERANGEF_H
