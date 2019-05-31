%d - deslocamento em Z do link i para link i+1 
% a - deslocamento em X do link i para o link i+1
% alpha - rotacao em X do link i para link i+1
% offset - rotacao em Z

d0 = 1.15

alpha1 = 0
a1 = 0.116
d1 = 0.85
offset1 = 0

alpha2 = -pi/2
a2 = 1.6
d2 = 0
offset2 = 0%-pi/2

alpha3 = 0
a3 = 1.864
d3 = 0
offset3 = 0%(pi/2) - 0.09

alpha4 = 0
a4 = 1.37
d4 = 0
offset4 = 0

alpha5 = pi/2
a5 = 0
d5 = 0
offset5 = 0

%%%%%%%%% LINKS %%%%%%%%%%
% Link([ thi di ai alphai ], opção)
L0 = Link('d', d0, 'a', 0, 'alpha', 0, 'qlim', [0 0], 'standard')
L1 = Link('revolute', 'd', d1, 'a', a1, 'alpha', alpha2, 'offset', offset1)
%L2 = Link([alpha2 a2 0 d2 0], 'standard')
L2 = Link('revolute','d', d2, 'a', a2, 'alpha', alpha3, 'offset', offset2, 'standard')
L3 = Link('revolute','d', d3, 'a', a3, 'alpha', alpha4, 'offset', offset3, 'standard') 
L4 = Link('revolute','d', d4, 'a', a4, 'alpha', alpha5, 'offset', offset4)
L5 = Link('revolute','d', d5, 'a', a5, 'alpha', 0, 'offset', offset5)
%L6 = Revolute('d', 0, 'a', 0, 'alpha', -pi/2) 

%Grupo 8
%L1 = Link('d', 0, 'a', 400, 'alpha', -pi/2, 'qlim', [0 0])
%L2 = Link('revolute', 'd', 0, 'a', 400, 'alpha', 0, 'offset', offset1)

qz = [0 0 0 0 0 0]

bot = SerialLink([L0 L1 L2 L3 L4 L5], 'name', 'manipulador')
bot.plot([qz])

%bot = SerialLink([L0,L1,L2],'name','manipulador')
%bot.plot([0 0 0])

%bot = SerialLink([L0,L1,L2,L3],'name','manipulador')
%bot.plot([0 0 0])

% bot = SerialLink([L0,L1,L2,L3, L4],'name','manipulador')
% bot.plot([0 0 0 0 0])

%bot = SerialLink([L0,L1,L2,L3, L4],'name','manipulador')
%bot.plot(qz)  %qz vetor de zeros

T0 = bot.fkine(qz)