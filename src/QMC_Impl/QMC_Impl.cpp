/**
 * @file QMC_Impl.cpp
 * @author ikhan
 * 
 * @brief Implementation of pimpl
 */
 
#include <vector>
#include <map>
#include <thread>

#include "QMC_Impl.h"
#include "Metropolis_Walker.h"


namespace QMC
{

class QMC_Impl::impl
{
public:
   void runSimulation()
   {
   
   }
   
   const std::map<double, double>& getResults() const
   {
      return m_Results;
   }
   
private:
   void simulation_instance()
   {
   
   }
   
   ///
   std::map<double, double> m_Results;

};

QMC_Impl::QMC_Impl():pimpl{std::make_unique<impl>()}
{
   pimpl->runSimulation();
}

QMC_Impl::~QMC_Impl() = default;

QMC_Impl::QMC_Impl(QMC_Impl&&) = default;

QMC_Impl& QMC_Impl::operator=(QMC_Impl&&) = default;

}; // end namespace QMC





