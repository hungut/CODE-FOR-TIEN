
# %%
import matplotlib.pyplot as plt
x=[5,10,50,85,100]
y1=[535.0683,627.1366,1363.683,2008.1611,2284.366]#Euler CO2_Air
y2=[533.7867,622.0576,1245.5861,1686.7253,1850.2336]#Runge-Kuttar CO2_Air
y3=[435.1534,450.3069,571.5344,677.6085,723.0688]#Euler CO2Top
y4=[434.842,449.0782,543.8884,604.0888,624.5459]#Runge-Kuttar CO2_Top
plt.plot(x,y1,linestyle='dashed',marker='D',label='CO2_Air(E)')
plt.plot(x,y2,linestyle='dashed',marker='D',label='CO2_Air(R)')
plt.plot(x,y3,linestyle='dashed',marker='D',label='CO2_Top(E)')
plt.plot(x,y4,linestyle='dashed',marker='D',label='CO2_Top(R)')
plt.title('Line graph for Euler and Runge-Kuttar')
plt.xlabel('Time(s)')
plt.ylabel('The rate change of CO2 concentration(mg.m^-3.s^-1)')
plt.legend()
plt.show()  
# %%
