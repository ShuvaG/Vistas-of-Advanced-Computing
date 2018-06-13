%% Short Problems - Shuva Gautam %%
clear all; close all; clc

%% Problem #1 - Scalar Vectors
disp('Problem #1 - Scalar Vectors');
a=10;
disp(['a=',num2str(a)]);
b=2.5*(10^23);
disp(['b=',num2str(b)]);
c=2+3*i;
disp(['c=',num2str(c)]);
d=exp(j*2*pi/3);
disp(['d=',num2str(d)]);


%% Problem #4 - Scalar Equations
disp('Problem #4 - Scalar Equations')
x=1/(1+exp(-(a-15)/6));
disp(['x=',num2str(x)]);
y=(sqrt(a)+b^(1/21))^pi;
disp(['y=',num2str(y)]);
z=(log(real((c+d)*(c-d))*sin(a*pi/3)))/(c*conj(c));
disp(['z=',num2str(z)]);

%% Problem #8 - Plotting Multiple Lines and Colors
disp('Problem #8 - Plotting Multiple Lines and Colors')
figure(8)
t=[0:.01:2*pi];
plot(t,sin(t))
hold on
plot(t,cos(t),'--r')
title('Sin and Cos Function');xlabel('Time (t)');ylabel('Function Value')
legend('Sin(t)','Cos(t)')
hold off
xlim([0 2*pi]);ylim([-1.4 1.4]);

