function []=gyak8_f83_antma1()
filename = '83.txt';
file_path = ['.\' filename];
fid = fopen(file_path);
data = fscanf(fid, '%f', [1 inf]);
fclose(fid); 
display(data);
t = [data(1) data(2)];
y0 = [data(3), data(4)];
F = @(t, y0) [5*log(y0(2))*y0(1) ; (1-1.2*y0(1))*y0(2)];
[T, Y] = ode45(F, t, y0);
figure(1);
subplot(2, 1, 1);
plot(T, Y(:, 1), '-.m');
hold on;
plot(T, Y(:, 2), '.c');
ylabel('ertek', 'FontWeight', 'bold');
xlabel('ido', 'FontWeight', 'bold');
title('Idobeli lefutasok', 'FontSize', 14);
legend('y1', 'y2', 'Location', 'northeast');
subplot(2, 1, 2);
plot(Y(:, 1), Y(:, 2), '-r', 'LineWidth', 2);
xlabel('y1', 'FontWeight', 'bold');
ylabel('y2', 'FontWeight', 'bold');
title('Fazisportre -- allapotter', 'FontSize', 14);

end