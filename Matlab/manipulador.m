%d - deslocamento em Z do link i para link i+1 
% a - deslocamento em X do link i para o link i+1
% alpha - rotacao em X do link i para link i+1
% offset - rotacao em Z

L0 = Link('d', 1.15, 'a', 0, 'alpha', 0)
L1 = Link('revolute','d', 0.85, 'a', 0.116, 'alpha', -pi/2)
L2 = Link('revolute','d', 0, 'a', 1.6, 'alpha', 0, 'offset', -pi/2) %offset
L3 = Link('revolute','d', 0, 'a', 1.834, 'alpha', 0, 'offset', pi/2) 
L4 = Link('revolute','d', 0, 'a', 0.37, 'alpha', -pi/2, 'offset', 0)
L5 = Link('revolute','d', 0, 'a', 0, 'alpha', 0, 'offset', 0)

%bot = SerialLink([L1], 'name', 'manipulador')
%bot.plot([0])

%bot = SerialLink([L1,L2],'name','manipulador')
%bot.plot([0 0])

%bot = SerialLink([L1,L2,L3],'name','manipulador')
%bot.plot([0 0 0])

%bot = SerialLink([L1,L2,L3, L4],'name','manipulador')
%bot.plot([0 0 0 0])

%
bot = SerialLink([L0,L1,L2,L3, L4,L5],'name','manipulador')
%
bot.plot([0 0 0 0 0 0])
