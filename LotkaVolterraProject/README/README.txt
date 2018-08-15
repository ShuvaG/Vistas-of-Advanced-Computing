This code explores the population dynamic between prey and predators using the Lotka-Volterra Equations.
The list of parameters you can change are:
   -alpha 
   -beta 
   -delta 
   -gamma
   -dt 
   -x[0]
   -y[0]
In addition, you can choose which Lotka-Volterra equation to use: 
   - For regular:
     double fx(double x, double y) { return alpha * x - beta * x * y; }  
     double fy(double x, double y) { return delta * x * y - gamma * y; }
   - For damped:
     double fx(double x, double y) { return alpha*x - lambda * x * x - beta * x * y; }  
     double fy(double x, double y) { return delta * x * y - kappa * y * y - gamma * y; }  
  ** Comment out the version you don't want!
To graph on MATLAB use the following code:
      prey = dlmread("prey.txt");
      predator = dlmread("predator.txt");
      figure(1)
      plot(prey,'LineWidth',2);
      hold on
      plot(predator,'LineWidth',2);
      legend("Prey", "Predator")
      ylabel("Population")
      xlabel("Time")
      figure(2)
      plot(prey, predator,'LineWidth',.1,'Color',[ 0.9100 0.6100 0.1700])
      ylabel("Predator")
      xlabel("Prey")
