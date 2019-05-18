[X, Y] = meshgrid(-2:0.1:2, -2:0.1:2);
Z = Y.*exp((-X.^2)-(Y.^2));
figure;
surf(X, Y, Z);
El = 30;
for Az = 0:0.01:18000
   view(Az, El);
   pause(0.001);
end