x = dlmread("x_value.txt");
y = dlmread("y_value.txt");
z = dlmread("z_value.txt");

a = [ -4.39227 1 0 0 0.372587; 1 -4.39227 1 0 -0.468884;0 1 -4.39227 1 -0.468884; 0 0 1 -4.39227 -1.31035];
rref(a)
surf(x,y,z)

