F = @(t, y) 2*y;
[t1, y1] = explicitEuler(F, [0 3], 1);
figure(1); hold on;
plot(t1, y1, '-r');
[t45, y45] = ode45(F, [0 3], 1);
plot(t45, y45, 'bo-');
plot(t45, exp(2*t45), 'k--', 'LineWidth', 2);