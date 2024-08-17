#include <iostream>
#include "parts.cpp"
class car: public shapes{
  public:
  //some parts of the car
    fuelFilter m_fuelFilter;
    gearBox m_gearBox;
  public:
  //default constructor
    car() : m_fuelFilter(6.0, 11.0, 1.5){
        m_gearBox.theGear.gearInfo(15.0, 22.5, 3.0, 7.85);
        m_gearBox.inputShaft.inputShaftInfo(1.5, 30, 2.7);

        evalSurface();
        evalVolume();
        evalMass();

    }
  //evaluating the total surface, volume and mass
    double evalSurface() override{
        m_surface=0;
        m_surface+= m_fuelFilter.evalSurface();
        m_surface+= m_gearBox.theGear.evalSurface();
        m_surface+= m_gearBox.inputShaft.evalSurface();
        return m_surface;

    }
      double evalVolume() override{
        m_volume=0;
        m_volume+= m_fuelFilter.evalVolume();
        m_volume+= m_gearBox.theGear.evalVolume();
        m_volume+= m_gearBox.inputShaft.evalVolume();
        return m_volume;
    }
    double evalMass() override{
        m_mass=0;
        m_mass+= m_fuelFilter.evalMass();
        m_mass+= m_gearBox.theGear.evalMass();
        m_mass+= m_gearBox.inputShaft.evalMass();
        return m_mass;
    }
    

};
class hatchback: public car{
  //ordinary car with no trunk
};
class sedans: public car{
  
  public:
  trunk m_trunk;
  sedans():m_trunk(76.0, 89.0, 30, 2.7){
    m_surface+= m_trunk.m_surface;
    m_volume+= m_trunk.m_volume;
    m_mass+= m_trunk.m_mass;
    
  }
};