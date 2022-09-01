1;
pkg load control;
pkg load image;

function draw_cart_pendulum(y, L)
  theta = y(1);
  dist = y(3);
  Len = 1;
  B = 1;
  x1 = dist - L*sin(pi-theta);      ## x-coordinate of pendulum bob
  y1 = L*cos(pi - theta);  ## y coordinate of pendulum bob
  d = 0.3;               ## diameter of pendulum bob
  hold on;
  clf;
  axis equal;
  rectangle('Position',[((dist)-(Len/2)),0,Len,B],'FaceColor',[0 0 1]);
  rectangle('Position',[(x1-(d/2)),(y1-(d/2)),d,d],'Curvature',1,'FaceColor',[1 0 0]);
  line([dist x1], [B/2 y1], "linestyle", "-", "color", "k");
  line([-5 5], [0 0], "linestyle", "-", "color", "k");
  xlim([-5 5])
  ylim([-5 5])
  drawnow
  hold off
endfunction

function dy = inverted_pendulum_dynamics(y, m, M, L, g, u)
  sin_theta = sin(y(1));
  cos_theta = cos(y(1));
  dy(1,1) = y(2);
  dy(3,1) = y(4);
  dy(4,1) = (-(m*g*cos_theta*sin_theta) - (m*L*sin_theta*((y(2))^2)) + u)/(M + m*(sin_theta^2));
  dy(2,1) = (-(g*sin_theta) + (dy(4,1)*cos_theta))/L;

endfunction

function [A,B] = inverted_pendulum_AB_matrix(m, M, g, L)
  A = [0 1 0 0; (g+(m*g/M))/L 0 0 0; 0 0 0 1; -m*g/M 0 0 0];
  B = [0; -1/(L*(M)); 0; 1/(M)];
endfunction

function [t,y] = lqr_inverted_pendulum(m, M, g, L, y_setpoint, y0)
  [A,B] = inverted_pendulum_AB_matrix(m, M, g, L);               ## Initialize A and B matrix
  Q = [100 0 0 0; 0 40 0 0; 0 0 10 0; 0 0 0 40];                   ## Initialise Q matrix
  R = 0.001;                   ## Initialise R
  K = lqr(A,B,Q,R);                   ## Calculate K matrix from A,B,Q,R matricesclc
  tspan = 0:0.1:10;       ## Initialise time step
  [t,y] = ode45(@(t,y)inverted_pendulum_dynamics(y, m, M, L, g, -K*(y-y_setpoint)),tspan,y0);
endfunction

function inverted_pendulum_main()
  m = 1;
  M = 2;
  g = 9.8;
  L = 3;
  y_setpoint = [pi; 0; 2; 0];                                  ## Set Point
  y0 = [3*pi/4; 0; 1; 0];  ## Initial condtion
  [t,y] = lqr_inverted_pendulum(m, M, g, L, y_setpoint, y0);
  for k = 1:length(t)
    draw_cart_pendulum(y(k, :), L);
  endfor
endfunction
