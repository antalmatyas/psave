[x, y] = meshgrid(-15:0.5:15, -15:0.5:15);
r = sqrt(x.^2 + y.^2);
z = sin(r)./r;
C = countour(x, y, z);
figure(1);
surf(x, y, z);
xlabel('x érték');
ylabel('y érték');
zlabel('z érték');

