on [x,flag,res,iter] = GaussSeidel(A,b,x0,tol,maxiter)

% Vettore iniziale
x = x0;
flag = 0;
iter = 0;

% Matrici di Gauss-Seidel
M_gs = tril(A);      % M=D-E
N_gs = -triu(A,+1);  % N=F

normb   = norm(b);      % norma del vettore b
residuo = norm(b-A*x);  % residuo iniziale

% salvo tutti i residuo
res = residuo;

% Ciclo iterativo principale
while residuo >= tol && iter<maxiter,
    iter = iter+1;
    x = M_gs\(N_gs*x+b);    % Risolve Mx=Nx+b con \
    residuo = norm(b-A*x);  % calcola il residuo
    res(iter+1) = residuo;  % racoglie il residuo ad ogni iterazione
end

if( residuo<tol )
    flag = 1;                % flag=1 metodo convergente
end
      