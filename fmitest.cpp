
#include <iostream>
#include "fmi_interface.h"

using namespace std;

int main()
{
    // Load the model
    FmiInterface fmi("FmiTest.Model","../",LogLevel::Normal);
    fmi.printVariables();
    
    // Get indices of variables so as not to handle strings at each simulation step
    auto vIndex=fmi.variableIndex("v");
    auto iIndex=fmi.variableIndex("i");
    
    // Start simulation
    fmi.startSimulation();
    
    // Do simulations
    const double step=0.01; //[s]
    const double stop=1.0; //[s]
    cout<<"v i\n";
    for(double time=0.0;time<stop;time+=step)
    {
        // Apply a 1V step at t=0.1s
        double v=time<0.1 ? 0.0 : 1.0;
        
        fmi.setScalarDouble(vIndex,v);
        double i=fmi.getScalarDouble(iIndex);
        cout<<v<<" "<<i<<"\n";
        
        fmi.doStep(time,step);
    }
}
