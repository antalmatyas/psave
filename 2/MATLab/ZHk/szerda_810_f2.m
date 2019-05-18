function [fig1, m3_v_r, m3_megtett_ut, m3_szov, m4_v_r, m4_a, m4_a_alulmint, P, f_m4_a, m4_a_kozelit] = szerda_810_f2(muslincaRecords, t)
    fig1 = figure;
    m3Records = squeeze(muslincaRecords(:, 3, :));
    m3_v_r = sqrt(((m3Records(1, :)).^2)+((m3Records(2, :)).^2)+(m3Records(3, :).^2));
    m3_megtett_ut = trapz(m3_v_r, t);
    m3_szov = sprintf('A 3. muslinca altal megtett ut nagysaga: %4.4f centimeter.', m3_megtett_ut);
    m4Records = squeeze(muslincaRecords(:, 4, :));
    m4_v_r = sqrt(((m4Records(1, :)).^2)+((m4Records(2, :)).^2)+(m4Records(3, :).^2));
    m4_a = diff(m4_v_r) ./ diff(t);
    felb = 1:25:300;
    m4_a_alulmint = m4_a(felb);
    t_alulmint = t(felb);
    P = polyfit(t_alulmint, m4_a_alulmint, 5);
    f_m4_a = @(x_tart) polyval(P, x_tart);
    m4_a_kozelit = polyval(P, t);
    tplot = t(1:(length(t)-1));
    plot(tplot, m4_a, 'c*');
    grid on;
    hold on;
    plot(t_alulmint, m4_a_alulmint, 'or');
    plot(t, m4_a_kozelit, '--r');
    xlabel('ido [s]', 'FontSize', 12);
    ylabel('gyorsulas [cm/s^2]', 'FontSize', 12);
    title('4. muslinca gyorsulasanak alakulasa', 'FontSize', 14, 'FontWeight', 'bold');
    legend('gyorsulas(m4-a)', 'gyorsulas alulmint. (m4-a-alulmint)', 'illesztett polinom kiertekelve', 'Location', 'northwest');
end
