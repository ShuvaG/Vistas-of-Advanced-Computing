x= dlmread("u_values.txt");
w =0;
    for a =1:50
        figure(1)
        plot(x(a,:))
        xlim([0 100])
        pause(.25)
    end
