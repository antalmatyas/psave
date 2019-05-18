function ydot=rugoegyenlet(t, y, m, D, C, F)
 % Masodrendu diffegyenlet megoldasa:
% szetszedjuk ket elsorendure
 % Az allapotvektor y=[y1;y2] alaku,
 % ahol y1=kiteres, y2=sebesseg:
 % Az allapotvektor derivaltjai
 ydot = zeros(2,1);
 % ahol ydot(1) maga a sebesseg
ydot(1)=y(2);
 % es ydot(2) pedig a gyorsulasra
% rendezett egyenlet
ydot(2)=-D/m*y(1)-C/m*y(2)+F/m;
end