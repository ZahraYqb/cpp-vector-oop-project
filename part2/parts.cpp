//this program tries to model a car, using inheritance, polymorphism and composition.
#include <iostream>
#include <math.h>

class shapes{
    public:
    double  m_density, m_volume, m_surface, m_height, m_mass;
    //default constructor
    shapes (){
        m_density=0;
        m_volume=0; 
        m_surface=0;
        m_height=0;
        m_mass=0;
    }
    //virtual functions for evaluating surface, volume and mass of each component:
    virtual double evalSurface(){
        return m_surface;
    }
    virtual double evalVolume(){
        m_volume= m_surface * m_height;
        return m_volume;
    }
    virtual double evalMass(){
        return m_density * m_volume;
    }
    
};
//child classes as different components:
class cylindrical_component: public shapes{
    public:
    double m_radius;
    double pi= M_PI;

    public:
    cylindrical_component (double radius=0, double height=0, double density=0){
        m_radius= radius;
        m_height= height; 
        m_density= density;
    }
    double evalSurface() override{
        m_surface= M_PI * pow(m_radius, 2);
        return m_surface;
    }
};
class fuelFilter: public cylindrical_component{
    public:
     fuelFilter(double radius = 0, double height = 0, double density=0) : cylindrical_component(radius, height,density) {}
};
class gear: public shapes{
    public:
    double innerRadius,outerRadius;
    public:
    void gearInfo(double i_radius, double o_radius,double height,double density=0){
        innerRadius= i_radius; 
        outerRadius= o_radius;
        m_height= height;
        m_density= density;
    }
    double evalSurface() override{
        m_surface= M_PI * (pow(outerRadius, 2) - pow(innerRadius, 2));
        return m_surface;
    }
};
class gear_inputShaft: public cylindrical_component{
    public:
    void inputShaftInfo(double radius=0, double height=0, double density=0){cylindrical_component(radius, height, density); }
};
class gearBox: public shapes{
    public:
    gear theGear;
    gear_inputShaft inputShaft;
    
};
class trunk: public shapes{
    double m_length;
    double m_width;
    public:
    trunk (double length=0, double width=0, double height=0, double density=0): 
    m_length(length), m_width(width) {
        m_height= height;
        m_density= density;
        evalSurface();
        evalVolume();
        evalMass();

    }
    double evalSurface()override{
        m_surface=0;
        m_surface= (2* m_width* m_length) + (2*m_length*m_height) + (2*m_width*m_height);
        return m_surface;
    }
    double evalVolume()override{
        m_volume=0;
        m_volume= m_width* m_length* m_height;
        return m_volume;
    }
    double evalMass()override{
        m_mass=0;
        //0.8 is the sheet thickness used for the trunk.
        m_mass= ((0.8* m_length* m_height)+(2* 0.8* m_width* m_height)+(2* 0.8* m_length* m_width))* m_density;
        return m_mass;
        }

    
};

