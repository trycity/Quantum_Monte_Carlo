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
                       const std::vector<double>& aBoxSize, unsigned aMax_Correlation):
                       m_NumParticles(aNumParticles),
                       m_NumDimensions(aNumDims),
                       m_ParticleRadius(aParticleRadius),
                       m_BoxSize(aBoxSize),
					   m_MaxCorrelation(aMax_Correlation)
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


void QMC_Config::trialMove(std::unique_ptr<unsigned>& pNode, UTILS::QMCPoint& aNewPoint,
		std::unique_ptr<double>& aProb_Val,
		std::function<double(double)> aWfnPhi,
		std::function<double(double)> aWfnF)
{
   // select the particle in preparation for moving
   unsigned pNumber = *pNode;
   
   // compute its distance to the other particles
   std::vector<double> interParticleDistances(m_NumParticles-1);
   
   for(unsigned i{0}; i<pNumber; ++i)
   {
      interParticleDistances[i] = UTILS::QMC_Distance(m_Points[pNumber], m_Points[i]);
   }
   
   for(unsigned i{pNumber+1}; i<m_NumParticles; ++i)
   {
      interParticleDistances[i] = UTILS::QMC_Distance(m_Points[pNumber], m_Points[i]);
   }
   
   // random number generator
   std::default_random_engine generator;
   std::uniform_real_distribution<double> distribution(0.0, 1.0);
   
   // make a trial move and recompute distances to other particles
   aNewPoint.resize(m_NumDimensions);
   std::vector<double> interParticleDistancesTrial(m_NumParticles-1);
   bool acceptPosition{true};
   
   do
   {
      for(unsigned dim{0}; dim<m_NumDimensions; dim++)
      {
         aNewPoint[dim] = (distribution(generator) - 0.5)*m_BoxSize[dim];
      }
      
      for(unsigned i{0}; i<pNumber; ++i)
      {
         interParticleDistancesTrial[i] = UTILS::QMC_Distance(m_Points[pNumber], m_Points[i]);
         if(interParticleDistancesTrial[i] < m_ParticleRadius)
         {
            acceptPosition = false;
            break;
         }
      }
   
      for(unsigned i{pNumber+1}; i<m_NumParticles; ++i)
      {
         interParticleDistancesTrial[i] = UTILS::QMC_Distance(m_Points[pNumber], m_Points[i]);
         if(interParticleDistancesTrial[i] < m_ParticleRadius)
         {
            acceptPosition = false;
            break;
         }
      }
      
   }while(!acceptPosition);   

   //compute weight
   double weight = 1.0;

   double riTrial = UTILS::computeVectorSize(aNewPoint);
   double ri = UTILS::computeVectorSize(m_Points[pNumber]);

   weight *= aWfnPhi(riTrial) / aWfnPhi(ri);
   for(unsigned i{0}; i < m_NumParticles; ++i)
   {
	   weight *= aWfnF(interParticleDistancesTrial[i]) / aWfnF(interParticleDistances[i]);
   }

   *aProb_Val = weight*weight;
}


void QMC_Config::move(unsigned aNodeNumber, const UTILS::QMCPoint& aNewPoint, bool aComputeEnergyFlag)
{
   m_Points[aNodeNumber] = aNewPoint;

   // determine if energy is to be computed
   m_EnergyComputed = aComputeEnergyFlag && (aNodeNumber < m_MaxCorrelation);
}

bool QMC_Config::computeEnergyTerms() const
{
	return m_EnergyComputed;
}


}; // end namespace QMC



