 x= dlmread("u_values.txt");
w =0;
for a =1:2000
	figure(1)
	plot(x(a,:))
	xlim([0 100])
	ylim([-2.5 2.5])
	%pause(.25)
end

