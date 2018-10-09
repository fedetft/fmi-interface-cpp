package FmiTest

connector Port
Real i;
end Port;

model Model
input Port p;
Real v;
parameter Real c=1e-3; //1000uF
initial equation
v=1;
equation
p.i=c*der(v);
end Model;

end FmiTest;
