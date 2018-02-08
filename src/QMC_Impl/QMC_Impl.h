/**
 * @file QMC_Impl.h
 * @author ikhan
 * 
 * @brief Implementation class for Quantum monte carlo
 */

#ifndef QMC_IMPL_H 
#define QMC_IMPL_H

#include <memory>


namespace QMC
{

class QMC_Impl
{
public:
   /**
    *
    */
   QMC_Impl();
   
   /**
    *
    */
   ~QMC_Impl();
   
   /**
    *
    */
   QMC_Impl(QMC_Impl&&);
   QMC_Impl& operator=(QMC_Impl&&);
   
private:
   ///
   class impl;
   
   ///
   std::unique_ptr<impl> pimpl;   
   

}; // QMC_Impl

}; // end namespace QMC

#endif //  QMC_IMPL_H
