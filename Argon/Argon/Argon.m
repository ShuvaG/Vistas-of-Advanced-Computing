temp = dlmread("Temperature.txt");
p_energy = dlmread("PotentialEnergy.txt");
k_energy = dlmread("KineticEnergy.txt");
t_energy = dlmread("TotalEnergy.txt");
time = dlmread("Time.txt");
figure(1)
plot(time,k_energy);
subplot(4,1,1)
plot(time, p_energy);
title ("Potential Energy");
subplot(4,1,2)
plot(time, k_energy);
title ("Kinetic Energy");
subplot(4,1,3)
plot(time, t_energy);
title ("Total Energy");
subplot(4,1,4);
plot(time, temp);
title("Temperature");
