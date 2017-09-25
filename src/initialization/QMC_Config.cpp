/**
 * @file QMC_Config.cpp
 * @author ikhan
 * 
 * @brief Implementation of Configuration class for quantum monte carlo
 */
 
#include <random>
 
#include "QMC_Config.h"
#include "QMC_Utilities.h"
 
 
namespace QMC
{
 
QMC_Config::QMC_Config(unsigned aNumParticles, unsigned aNumDims, double aParticleRadius,
                       const std::valarray<double>& aBoxSize):
                       m_NumParticles(aNumParticles),
                       m_NumDimensions(aNumDims),
                       m_ParticleRadius(aParticleRadius),
                       m_BoxSize(aBoxSize)
{
   // @TODO throw exception if boxsize != number of dimensions
   m_Points.reserve(m_NumParticles);
}


QMC_Config::~QMC_Config()
{
   m_Points.clear();
}


void QMC_Config::initialize()
{
   // random number generator
   std::default_random_engine generator;
   std::uniform_real_distribution<double> distribution(0.0, 1.0);
  
   UTILS::QMCPoint point(m_NumDimensions);
   
   // set coordinates for the first particle
   for(unsigned dim{0}; dim<m_NumDimensions; dim++)
   {
      point[dim] = (distribution(generator) - 0.5)*m_BoxSize[dim];
   }
   
   m_Points.push_back(point);
   
   // set coordinates for remaining particles
   do
   {
      for(unsigned dim{0}; dim<m_NumDimensions; dim++)
      {
         point[dim] = (distribution(generator) - 0.5)*m_BoxSize[dim];
      }
      
      bool acceptPosition{true};
      
      for(auto& pos : m_Points)
      {
         double interParticleDistance = UTILS::QMC_Distance(point, pos);
         
         if(interParticleDistance < m_ParticleRadius)
         {
            acceptPosition = false;
            break;
         }
      }
      
      if(acceptPosition) m_Points.push_back(point);
      
   }while(m_Points.size()<m_NumParticles);
}


void QMC_Config::trialMove(unsigned* pNode, UTILS::QMCPoint& aNewPoint, double* aProb_Val)
{}


void QMC_Config::move(unsigned aNodeNumber, const UTILS::QMCPoint& aNewPoint, bool aComputeEnergyFlag)
{
}

}; // end namespace QMC


