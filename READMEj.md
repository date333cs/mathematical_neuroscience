# mathematical_neuroscience
Mathematical Neuroscience Course Materials [English](README.md)


    git clone "https://github.com/date333cs/mathematical_neuroscience"


### Associative Memory

- [課題1](./docs/project160415associative.pdf)

- Purpose: reproduce Fig.1 and Fig.2 of Amari & Maginu (1988).

- an example of memory allocation:  [mn_test.c](mn_test.c)
- templates: [mn_asm000.c](mn_asm000.c), [mn_asm001.c](mn_asm002.c), [mn_asm002.c](mn_asm002.c)
- for gnuplot [gp001](gp001)
- data structure (n neurons, m memory patterns, i,j=0,...,n-1, a=0,...,m-1)
 - int x[i] :  current state
 - int ux[i] : next state 
 - double w[i][j] : connection weights
 - int p[a][i] : memory items

### 自己組織化モデル： Kohonen の自己組織化マップ（Self-organizaing MAP）


<img src="https://github.com/date333cs/mathematical_neuroscience/blob/master/result_som_102.png" height="220px" align="left">

- [課題2](./docs/project160513neural_som.pdf)

- 悩ましい選択．両方つくる？

 - とりあえず動作原理を確かめるだけのモデルをつくるか．→ 入力2次元，神経場1次元（もしくは2次元），
  - データ構造：x[a],m[i][a], a=0,1, i=0,1,...,n-1 （n は素子数）

 - あとで利用しやすいものをつくるか．この場合，少し手間がかかる．

 - 初心者にとって，理解しやすいのは？

- templates: [mn_som000.c](mn_som000.c), [mn_som001.c](mn_som001.c),
 - for MNIST [templates](http://www.cs.miyazaki-u.ac.jp/~date/lectures/2015neural/mnist/index.html)


### Boltzmann Machine

- [課題3](./docs/project160610bolzmann.pdf)

+



