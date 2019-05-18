C1 = cell(3, 2);
C1{1, 1} = 'szöveg';
C1{1, 2} = 12;
C1{2, 1} = [8.13, 14.86];
C1{2, 2} = magic(5);
C1{3, 1} = cell(2, 4);
C1{3, 2} = {1, 2, 3, 4, 5};

figure(1);
cellplot(C1);
title('C1 tartalma');

C2 = {'szöveg', 12 ; [8.13, 14.86], magic(5) ; cell(2,4), {1, 2, 3, 4, 5}};
figure(2);
cellplot(C2);
title('C2 tartalma');