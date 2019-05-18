function [t_out, y_out] = explicitEuler(F, tspan, y0)
% Egyszeru differencialegyenelt-megoldo, explicit Euler
% modszer alapjan.
% Csak szemleltetesi celu, ne hasznaljuk kesobb, mert
% pontatlan.
% F: derivaltfuggveny
% tspan: idoskala (elso es utolso pontja)
% y0: kezdeti ertek

felosztas = 200;
h = (tspan(end)-tspan(1))/felosztas;
t_out = zeros(1, felosztas);
y_out = zeros(1, felosztas);
y_out(1) = y0;
t_out(1) = tspan(1);
for i = 2:felosztas+1
   t_out(i) = t_out(i-1)+h;
   ydot = F(t_out(i), y_out(i-1));
   y_out(i) = y_out(i-1) + h*ydot;
    
end

end