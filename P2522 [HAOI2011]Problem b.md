$$\huge 设n=gcd(x,y),f(n)=[n=k]$$
---
$$\huge{f(n)=\sum_{m|n} g(m)}= \sum_{m|x,m|y}g(m)$$
---
# 现在求得 $g(m)$ 即可求得答案
# 进行莫比乌斯反演
$$\huge f=g*1$$
$$\huge g=f*\mu$$
$$\huge g(n)=\sum_{m|n} f(m)*\mu(\frac{n}{m})$$
$$\huge g(n)=\sum_{m|n} [m=k]*\mu(\frac{n}{m})$$
---
$$\huge \sum_{i=a}^b\sum_{j=c}^df(gcd(i,j))$$
$$\huge \sum_{x=a}^b\sum_{y=c}^d\sum_{m|x,m|y} g(m)$$
$$\huge $$