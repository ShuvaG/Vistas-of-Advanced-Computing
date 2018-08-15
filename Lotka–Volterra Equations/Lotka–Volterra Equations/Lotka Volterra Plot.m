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

