function T0_1 = T0_1(rob,in2)
%% T0_1 - Forward kinematics for the three link copy arm up to frame 1 of 3. 
% ========================================================================= 
%    
%    T = T0_1(rob,q) 
%    T = rob.T0_1(q) 
%    
%  Description:: 
%    Given a set of joint variables up to joint number 1 the function 
%    computes the pose belonging to that joint with respect to the base frame. 
%    
%  Input:: 
%    q:  1-element vector of generalized coordinates. 
%    Angles have to be given in radians! 
%    
%  Output:: 
%    T:  [4x4] Homogenous transformation matrix relating the pose of joint 1 of 3 
%              for the given joint values to the base frame. 
%    
%  Example:: 
%    --- 
%    
%  Known Bugs:: 
%    --- 
%    
%  TODO:: 
%    --- 
%    
%  References:: 
%    1) Robot Modeling and Control - Spong, Hutchinson, Vidyasagar 
%    2) Modelling and Control of Robot Manipulators - Sciavicco, Siciliano 
%    3) Introduction to Robotics, Mechanics and Control - Craig 
%    4) Modeling, Identification & Control of Robots - Khalil & Dombre 
%    
%  Authors:: 
%    This is an autogenerated function! 
%    Code generator written by: 
%    Joern Malzahn 
%    2012 RST, Technische Universitaet Dortmund, Germany 
%    http://www.rst.e-technik.tu-dortmund.de 
%    
%  See also three link copy.
%    
    
% Copyright (C) 1993-2019, by Peter I. Corke 
% Copyright (C) 2012-2019, by Joern Malzahn 
% 
% This file has been automatically generated with The Robotics Toolbox for Matlab (RTB). 
% 
% RTB and code generated with RTB is free software: you can redistribute it and/or modify 
% it under the terms of the GNU Lesser General Public License as published by 
% the Free Software Foundation, either version 3 of the License, or 
% (at your option) any later version. 
%  
% RTB is distributed in the hope that it will be useful, 
% but WITHOUT ANY WARRANTY; without even the implied warranty of 
% MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
% GNU Lesser General Public License for more details. 
%  
% You should have received a copy of the GNU Leser General Public License 
% along with RTB.  If not, see <http://www.gnu.org/licenses/>. 
% 
% http://www.petercorke.com 
% 
% The code generation module emerged during the work on a project funded by 
% the German Research Foundation (DFG, BE1569/7-1). The authors gratefully  
% acknowledge the financial support. 

%% Bugfix
%  In some versions the symbolic toolbox writes the constant $pi$ in
%  capital letters. This way autogenerated functions might not work properly.
%  To fix this issue a local variable is introduced:
PI = pi;
   




%    This function was generated by the Symbolic Math Toolbox version 7.2.
%    17-May-2019 11:57:15

q1 = in2(:,1);
t2 = cos(q1);
t3 = sin(q1);
T0_1 = reshape([t2,t3,0.0,0.0,-t3,t2,0.0,0.0,0.0,0.0,1.0,0.0,t2,t3,0.0,1.0],[4,4]);