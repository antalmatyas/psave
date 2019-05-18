function [cellaTomb, abra]=gyak8_f81_(db)
    abra = figure;
    cellaTomb = cell(3, 3);
    t = linspace(0, 2*pi, db);
    cellaTomb{1, 1} = t;
    sin3.x = t;
    sin3.y = sin(3.*sin3.x);
    sin3.nev = 'Sin(3t)';
    
    cos5.x = t;
    cos5.y = cos(5.*cos5.x);
    cos5.nev = 'Cos(5t)';
    
    sico.x = t;
    sico.y = sin(3.*sico.x).*cos(5.*sico.x);
    sico.nev = 'Sin(3t)*Cos(5t)';
  
    cellaTomb{2, 1} = sin3.nev;
    cellaTomb{2, 2} = cos5.nev;
    cellaTomb{2, 3} = sico.nev;
    cellaTomb{3, 1} = sin3.y;
    cellaTomb{3, 2} = cos5.y;
    cellaTomb{3, 3} = sico.y;
    hold on;
    for i = 1:1:3
        subplot(3, 1, i);
        plot(t, cellaTomb{3, i}, '-k');
        title(cellaTomb{2, i}, 'FontWeight', 'bold');
        xlabel('t');
    end
    
end