%d - deslocamento em Z do link i para link i+1 
% a - deslocamento em X do link i para o link i+1
% alpha - rotacao em X do link i para link i+1
% offset - rotacao em Z

d1 = 1.15

alpha1 = -pi/2
a1 = 0.116
d2 = 0.85
offset1 = 0

alpha2 = 0
a2 = 1.6
d3 = 0
offset2 = -pi/2 

alpha3 = 0
a3 = 1.835
d4 = 0
offset3 = (pi/2)-0.09

alpha4 = 0
a4 = 0.37 
d5 = 0
offset4 = pi/2

alpha5 = 0
a5 = 0
d6 = 0
offset5 = 0

%%%%%%%%% LINKS %%%%%%%%%%
L0 = Link('d', 1.15, 'a', 0, 'alpha', 0, 'qlim', [0 0])
L1 = Link('revolute', 'd', d2, 'a', a1, 'alpha', alpha1, 'offset', offset1)
%L1 = Link([0 d2 a1 alpha1 offset1])
L2 = Link('revolute','d', d3, 'a', a2, 'alpha', 0, 'offset', offset2)
L3 = Link('revolute','d', d4, 'a', a3, 'alpha', 0, 'offset', offset3) 
L4 = Link('revolute','d', d5, 'a', a4, 'alpha', 0, 'offset', offset4)
L5 = Link('revolute','d', d6, 'a', a5, 'alpha', 0, 'offset', offset5)


%bot = SerialLink([L0,L1], 'name', 'manipulador')
%bot.plot([0])

%bot = SerialLink([L0,L1,L2],'name','manipulador')
%bot.plot([0 0 0])

%bot = SerialLink([L0,L1,L2,L3],'name','manipulador')
%bot.plot([0 0 0])

%bot = SerialLink([L0,L1,L2,L3, L4],'name','manipulador')
%bot.plot([0 0 0 0])
qz = [0 0 0 0 0 0]
bot = SerialLink([L0,L1,L2,L3, L4,L5],'name','manipulador')
bot.plot(qz)  %qz vetor de zeros

T0 = bot.fkine(qz)