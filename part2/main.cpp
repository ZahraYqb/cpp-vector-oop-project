#include "device.cpp"
int main(){
    std::cout<<"This is just an approximate estimation for few part of a car.\n\n";

    // Creating instances of hatchback and sedan classes.
    hatchback hatchback_one;
    sedans sedan_one;
    //several test cases 
    std::cout<<"the mass of hatchback one is "<<hatchback_one.m_mass<<" grams.\n";
    std::cout<<"the mass of sedan one is "<<sedan_one.m_mass<<" grams.\n\n";

    std::cout<<"the volume of hatchback one is "<<hatchback_one.m_volume<<" cm3.;\n";
    std::cout<<"the volume of sedan one is "<<sedan_one.m_volume<<" cm3;.\n\n";

    std::cout<<"the surface of hatchback one is "<<hatchback_one.m_surface<<" m2.\n";
    std::cout<<"the surface of sedan one is "<<sedan_one.m_surface<<" m2.\n\n";
   


     

}
