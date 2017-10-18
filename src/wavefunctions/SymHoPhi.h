/**
 *@file SymHoPhi.h
 *
 *@author ikhan
 *@brief file depicting symmetric harmonic oscillator Phi (SymHoPhi)
 */

#ifndef QMC_SYMHOPHI_H
#define QMC_SYMHOPHI_H


namespace QMC
{


class SymHoPhi
{
public:
	/**
	 * SymHoPhi ctor
	 *
	 * @param alpha The variational parameter
	 */
	explicit SymHoPhi(double alpha);

	/**
	 * destructor
	 */
	~SymHoPhi();

	/**
	 * overloaded method call operator
	 *
	 * @param ri The position of the particle
	 */
	double operator()(double ri)const;

private:

	/// variational parameter
	double m_Alpha;

}; // end SymHoPhi

}; // end namespace QMC

#endif // QMC_SYMHOPHI_H
