Linear regression
==================

scatter plot
------------

1. Select the two columns of the data (left column x, right y), including the headers
2. Insert, scatter plot
3. Click any of the point on the plot, Click the "+" symbol, click the "trend line", select more options

P 值，0.05， 是一个分界线。 P 越小越好，代表对应这个系数是0的概率越小。

问豆包的问题:
  - 方差分析里的 MS 和 SS 代表什么，如何计算的
  - excel 里的线性回归里的 SS 和 MS
  - p 值如何算

弄懂 t 统计量, p value

弄懂 F 建议和显著性. F 针对整个模型, t 只针对具体某个参数.

ESS 是 explained sum of squared, 也是 SSR, 即 regression sum of squares, 是回归平方和。

SSE 是 residual sum of squared errors 或者 residual sum of squares, 是残差平方和。

ANOVA 是方差分析的意思, analysis of variance

自由度：回归平方和里的自由度，是参数总数减去1。 残差平方和里的自由度是 n - 1 - 自变量个数.

回归均方是回归平方和除以回归平方的自由度。用 MSR 表示. 这个自由度也是自变量的个数。

残差均方是残差平方和除以残差平方的自由度。用 MSE 表示.

F 统计量为 MSR/MSE. 分子是 MSR, 它的自由度是自变量个数，即参数个数减去1。分母是 n-k-1 (k 是自变量个数)

得到 F 的值后，可以根据分子和分母的自由度，去查 F 分布的表。 表里表示 大于 F 的面积, 这个面积就是 F significance,
也是原假设的概率。原假设是所有参数都为0. 所以 F significance 越小，就代表原假设的概率越小。一般的，用 0.05 做阈值。
如果  F significance 小于 0.05, 即原假设的对立面的概率大于 0.95, 即至少有一个参数不为0.

t 统计量里的 P 值，也是原假设成立的概率。越小越好。0.05 是一个阈值。
