# Markov model simulation

The repository contains C code for a markov model implementation. 


### Compiling 

Compiled via MAKE call:


```
make 
```

inside the src folder to build the program 'sim'. 


### Usage

the program takes the following command line arguments: 

1. Number of iterations to run the simulations for 
2. The transition probability matrix defining the model

The transition probability matrix is given row-wise such that the matrix: 

$$
\begin{pmatrix}x_{00} & x_{01} \\ x_{10} & x_{11}\end{pmatrix} 
$$
would have the following call:

```
./sim 100000 x_00 x_01 x_10 x_11
```

The same row-wise embedding goes for all probability matrix sizes.


