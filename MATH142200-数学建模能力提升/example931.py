# -*- coding: utf-8 -*-
"""
Created on Fri Jun 26 21:42:13 2020

@author: Zach
"""



import numpy as np

import matplotlib.pyplot as plt


   
 
t = np.arange(1,16,1)
y = np.array([352, 211, 197, 160, 142, 106, 104,  60,  56,  38,  36,  32,  21,  19, 15])


plt.figure(1)
plt.plot(t,y,'-*') 
plt.show()
#第一个拟合，次数为2
z1 = np.polyfit(t, y, 2)
# 生成多项式对象
y1 = np.poly1d(z1,False, 't')
print(z1)
print(y1)
 
# 第二个拟合，次数为3
z2 = np.polyfit(t, y, 3)
# 生成多项式对象
y2 = np.poly1d(z2,False, 't')
print(z2)
print(y2) 
# 绘制曲线 # 原曲线
plt.plot(t, y, 'b^-', label='Origin Line')
plt.plot(t, y1(t), 'gv--', label='Poly Fitting Line(deg=2)')
plt.plot(t, y2(t), 'r*', label='Poly Fitting Line(deg=3)')
plt.legend()
plt.title('example931')
plt.xlabel('t')
plt.ylabel('y')

plt.show()

def rfunc(y, yhat):
     ybar = np.sum(y)/len(y)
     ssreg = np.sum((yhat - ybar)**2)
     sstot = np.sum((y - ybar)**2)
     r= ssreg/sstot
     print(r)

rfunc(y,y1(t))
rfunc(y,y2(t))

print('t=16,y=%f' %np.polyval(z1,16))
