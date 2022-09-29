1;
pkg load control;
pkg load image;

function draw_cart_pendulum(y, L)
  theta = y(1);
  dist = y(3);
  #disp(dist);
  Len = 14;
  B = 10;
  x1 = dist - L*sin(pi-theta);      ## x-coordinate of pendulum bob
  y1 = L*cos(pi - theta);  ## y coordinate of pendulum bob
  d = 5;               ## diameter of pendulum bob
  hold on;
  clf;
  axis equal;
  rectangle('Position',[((dist)-(Len/2)),0,Len,B],'FaceColor',[0 0 1]);
  rectangle('Position',[(x1-(d/2)),(y1-(d/2)),d,d],'Curvature',1,'FaceColor',[1 0 0]);
  line([dist x1], [B/2 y1], "linestyle", "-", "color", "k");
  line([-40 40], [0 0], "linestyle", "-", "color", "k");
  xlim([-35 35])
  ylim([0 40])
  drawnow
  hold off
endfunction

function dy = inverted_pendulum_dynamics(y, m, M, L, g, u)
  sin_theta = sin(y(1));
  cos_theta = cos(y(1));
  f = 20;
  dy(1,1) = y(2);
  dy(3,1) = y(4);
  dy(4,1) = (-(m*g*cos_theta*sin_theta) + (m*L*sin_theta*((y(2))^2) + f*y(4)) + u)/(M + m*(sin_theta^2));
  dy(2,1) = (-(g*sin_theta) + (dy(4,1)*cos_theta))/L;

endfunction

function [A,B] = inverted_pendulum_AB_matrix(m, M, g, L)
  f = 0.8;
  A = [0 1 0 0; (g+(m*g/M))/L 0 0 -f/(M*L); 0 0 0 1; -m*g/M 0 0 -f/M];
  B = [0; -1/(L*(M)); 0; 1/(M)];
endfunction

function [t,y,K,sys_d] = lqr_inverted_pendulum(m, M, g, L, y_setpoint, y0)
  [A,B] = inverted_pendulum_AB_matrix(m, M, g, L);  ## Initialize A and B matrix
  sys = ss(A,B);
  sys_d = ss(c2d(sys, 0.05));
  #daspect();
  Q = [10000 0 0 0; 0 100 0 0; 0 0 100000 0; 0 0 0 1];                   ## Initialise Q matrix
  R = 0.01;                   ## Initialise R
  K = dlqr(sys_d,Q,R);  ## Calculate K matrix from A,B,Q,R matrices
##K = lqr(A,B,Q,R);
  tspan = 0:0.05:10;       ## Initialise time step
  [t,y] = ode45(@(t,y)inverted_pendulum_dynamics(y, m, M, L, g, -K*(y-y_setpoint)),tspan,y0);
endfunction

function inverted_pendulum_main()
  m = 130;
  M = 280;
  g = 980;
  L = 33.23;
  y_setpoint = [pi; 0; 0; 0];                                  ## Set Point
  y0 = [2.9; 0; 0; 0];  ## Initial condtion
  [t,y,K,sys_d] = lqr_inverted_pendulum(m, M, g, L, y_setpoint, y0);
  #step(sys_d,0.7);
  y_ = repmat(transpose(y_setpoint), 201, 1);
  disp(K);
  disp(y);
  u = -K*(transpose(y-y_));
  disp(max(u/(M+m)));
  #disp([t,y]);
##  plot(t,y(:,1));
##  hold on
##  plot(t,y(:,2),"*");
##  hold off
##  hold on
##  plot(t,y(:,4),"--g");
##  hold off
  for k = 1:length(t)
    draw_cart_pendulum(y(k, :), L);
  endfor
endfunction
