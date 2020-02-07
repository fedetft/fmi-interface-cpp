
#include <iostream>
#include "fmi_interface.h"

using namespace std;

int main()
{    
    FmiInterface fmi("FmiTest.Model","../",LogLevel::Normal);
    fmi.printVariables();
    
    //Set initial value of input variables
    fmi.setScalarDouble(fmi.variableIndex("p.i"),-0.001);
    fmi.startSimulation();
    
    double time=0.0;
    const double step=0.01;
    auto vIndex=fmi.variableIndex("v");
    
    for(;time<1.0;time+=step)
    {
        cout<<"v="<<fmi.getScalarDouble(vIndex)<<endl;
        fmi.doStep(time,step);
    }
    cout<<"v="<<fmi.getScalarDouble(vIndex)<<endl;
}
