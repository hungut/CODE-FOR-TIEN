import math
import csv
# formula (3)
def MC_BlowAir (eta_HeatCO2, U_Blow, P_Blow, A_Flr):
    return (eta_HeatCO2 * U_Blow * P_Blow)/A_Flr

# formula (4)
def MC_ExtAir (U_ExtCO2, phi_ExtCO2, A_Flr):
    return (U_ExtCO2 * phi_ExtCO2) / A_Flr

# formula (5)
def MC_PadAir (U_Pad, phi_Pad, A_Flr, CO2_Out, CO2_Air):
    #toc do cua CO2 qua tam thong gio
    return ((U_Pad * phi_Pad)/A_Flr)*(CO2_Out-CO2_Air)

# formula (6)
def MC_AirTop(f_ThScr,CO2_Air,CO2_Top):  
    return f_ThScr*(CO2_Air-CO2_Top) 

# formula (7)
def f_ThScr(U_ThSrc,K_ThSrc,T_Air,T_Top,p_Air,p_Top):
    p_Mean=(p_Air+p_Top)/2    
    a=U_ThSrc*K_ThSrc*(abs(T_Air-T_Top)**(2/3)) #tham thau qua man
    b=(1-U_ThSrc)*((9.81*(1-U_ThSrc)/(2*p_Mean))*abs(p_Air-p_Top))**(1/2) #khong bi chan qua man
    return a+b

# formula (9)
def MC_AirOut(f_VentSide, f_VentForced, CO2_Air, CO2_Out):
     return (f_VentSide + f_VentForced) * (CO2_Air - CO2_Out)

# formula (A_Flr)
def f_VentRoofSide(C_d, A_Flr, U_Roof, U_Side, A_Roof, A_Side, h_SideRoof, T_Air, T_Out, C_w, v_Wind):
    T_Mean_Air=(T_Air+T_Out)/2
    ratio = C_d / A_Flr
    stack_first_component = ((U_Roof ** 2) * (U_Side ** 2) * (A_Roof ** 2) * (A_Side ** 2)) / ((U_Roof ** 2) * (A_Roof ** 2) + (U_Side ** 2)*(A_Side ** 2))
    stack_second_component = 2 * 9.81 * h_SideRoof * (T_Air - T_Out) / T_Mean_Air
    stack_component = stack_first_component * stack_second_component
    bernoulli_component = (((U_Roof * A_Roof + U_Side * A_Side) / 2) ** 2) * C_w * (v_Wind ** 2)
    result = ratio * math.sqrt(stack_component + bernoulli_component)
    return result

# formula (11)
def eta_InsScr(zeta_InsScr):
    return zeta_InsScr * (2 - zeta_InsScr)

# formula (12)
def f_leakage(c_leakage, v_Wind):
    if v_Wind < 0.25:
        return 0.25 * c_leakage
    else:
        return v_Wind * c_leakage

# formula (13)
# special_f_VentSide is f_VentRoofSide when A_Roof == 0
def f_VentSide(eta_InsScr, special_f_VentSide, f_leakage, U_ThScr, f_VentRoofSide, eta_Side, eta_Side_Thr):
    if eta_Side >= eta_Side_Thr:
        return eta_InsScr * special_f_VentSide + 0.5 * f_leakage
    else:
        return eta_InsScr * (U_ThScr * special_f_VentSide + (1 - U_ThScr) * f_VentRoofSide * eta_Side) + 0.5 * f_leakage

# formula (14)
def f_VentForced(eta_InsScr, U_VentForced, phi_VentForced, A_Flr):
    return eta_InsScr * U_VentForced * phi_VentForced / A_Flr

# formula (15)
def MC_TopOut(f_VentRoof,CO2_Top,CO2_Out): 
    return f_VentRoof*(CO2_Top-CO2_Out)

# formula (16)
def f_VentRoof(U_ThSrc,f2_VentRoof,f_leakage,f_VentRoofSide,eta_InsScr,eta_Side,eta_Roof,eta_Roof_Thr):
        if eta_Roof>=eta_Roof_Thr:
            a=eta_InsScr*f2_VentRoof+0.5*f_leakage
        else:
            a=eta_InsScr*(U_ThSrc*f2_VentRoof+(1-U_ThSrc)*f_VentRoofSide*eta_Side)+0.5*f_leakage
        return a

# formula (17)
def f2_VentRoof(C_d,U_Roof,A_Roof,A_Flr,h_Roof,T_Air,T_Out,C_w,v_Wind):
    T_Mean=(T_Air+T_Out)/2
    a=((C_d*U_Roof*A_Roof)/(2*A_Flr))*((9.81*h_Roof*(T_Air-T_Out))/(2*T_Mean)+C_w*(v_Wind**2))**(1/2) 
    return a         

# formula (18)
def MC_AirCan (M_CH2O, P, R, h_CBuf):
     return M_CH2O*h_CBuf*(P - R)

# formula (19)
def h_CBuf(C_Buf,C_Max_Buf):
    if C_Buf>C_Max_Buf: return 0
    else: return 1 

# formula (22)
def P(Pmax_LT,CO2_Air,Res):
    return CO2_Air/Res
    
# formula (24)
def f_T(T , T_0 , Hd, S):
    tmp1 = (-Hd/8.314)*(1/T_0-1/(Hd/S))
    t1 = 1+pow(math.e, tmp1)
    tmp2 = (-Hd/8.314)*(1/T-1/(Hd/S))
    t2 = 1+pow(math.e, tmp2)
    return t1/t2

# formula (25)
def P_Max_T(k_T0 , Ha , T , T_0  , Hd , S , f_T ):
    t= float((-Ha/8.314)*(1/T - 1/T_0))
    k= float(k_T0*pow(math.e, t))#calculate k(T)
    return k*f_T

# formula (27)
def L(L_0, K, m,LAI):
    L = L_0 * (1-(K * math.exp(-K*LAI)/(1-m)))
    return L

# formula (28)
def k_T( LAI, k_T0,T_0,T,Ha, R):
    k_T = LAI * k_T0 * math.exp(-(Ha/R) * ((1/T)-(1/T_0)))
    return k_T

# formula (29)
def Pmax_LT( Pmax_T,L,P_MLT):
    L_05 = (P_MLT * Pmax_T * L)/(Pmax_T/2) - L
    Pmax_LT = P_MLT * Pmax_T * L / (L + L_05)
    return Pmax_LT

#khai bao bien ngoai tru CO2_Air và CO2_Top
def Input(*args):
    ret=[]
    for arg in args:
        ret.append(float(arg))
    return ret

A,B,CO2_Out,U_Blow,U_ExtCO2,U_Pad,U_ThSrc,U_Roof,U_Side,U_VentForced,A_Flr,A_Roof,A_Side,P_Blow,K_ThSrc,C_d,C_w,T_Air,T_Top,T_Out,eta_HeatCO2,eta_Side,eta_SideThr,eta_Roof,eta_Roof_Thr,h_SideRoof,h_Roof,phi_ExtCO2,phi_Pad,phi_VentForced,p_Air,p_Top,v_Wind,zeta_InsScr,c_leakage,R,S,Hd,Ha,Res,T,T_0,k_T0,LAI,K,m,L_0,cap_CO2Air,cap_CO2Top,C_Buf,C_Max_Buf=Input('0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0')

def dx(CO2_Air,CO2_Top):
        #MC_BlowAir
        mc_BlowAir=MC_BlowAir(eta_HeatCO2,U_Blow,P_Blow,A_Flr)
        #MC_ExtAir
        mc_ExtAir=MC_ExtAir(U_ExtCO2,phi_ExtCO2,A_Flr)
        #MC_PadAir
        mc_PadAir=MC_PadAir(U_Pad,phi_Pad,A_Flr,CO2_Out,CO2_Air)
        #MC_AirTop
        f_Th=f_ThScr(U_ThSrc,K_ThSrc,T_Air,T_Top,p_Air,p_Top)

        mc_AirTop=MC_AirTop(f_Th,CO2_Air,CO2_Top)
        #MC_AirOut
        eta_insScr=eta_InsScr(zeta_InsScr)

        f_leak=f_leakage(c_leakage,v_Wind)
        # special_f_VentSide is f_VentRoofSide when A_Roof == 0
        f2_VentSide=f_VentRoofSide(C_d,A_Flr,U_Roof,U_Side, 0 ,A_Side,h_SideRoof,T_Air,T_Top,C_w,v_Wind)
        
        f_ventRoofSide=f_VentRoofSide(C_d,A_Flr,U_Roof,U_Side,A_Flr,A_Side,h_SideRoof,T_Air,T_Top,C_w,v_Wind)
        
        f_ventSide=f_VentSide(eta_insScr, f2_VentSide, f_leak,U_ThSrc, f_ventRoofSide,eta_Side,eta_SideThr)
        
        f_ventForced=f_VentForced(eta_insScr,U_VentForced,phi_VentForced,A_Flr)
        
        mc_AirOut=MC_AirOut(f_ventSide, f_ventForced,CO2_Air,CO2_Out)
        #MC_TopOut
        f2_ventRoof=f2_VentRoof(C_d,U_Roof,A_Roof,A_Flr,h_Roof,T_Air,T_Out,C_w,v_Wind)

        f_ventRoof=f_VentRoof(U_ThSrc,f2_ventRoof,f_leak,f_ventRoofSide,eta_insScr,eta_Side,eta_Roof,eta_Roof_Thr)

        mc_TopOut=MC_TopOut(f_ventRoof,CO2_Top,CO2_Out)
        #MC_AirCan
        #calculate p
        f_t=f_T(T,T_0,Hd,S)

        P_Max_T1=P_Max_T(k_T0,Ha,T,T_0,Hd,S,f_t)

        l=L(L_0,K,m,LAI)
        
        P_MLT=k_T0

        pmax_LT=Pmax_LT(P_Max_T1,l,P_MLT)
        
        p=P(pmax_LT,CO2_Air,Res)

        mc_AirCan=MC_AirCan(0.03,p,R,h_CBuf(C_Buf,C_Max_Buf))

        return (mc_BlowAir+mc_ExtAir+ mc_PadAir-mc_AirCan-mc_AirTop-mc_AirOut)/(cap_CO2Air),(mc_AirTop-mc_TopOut)/(cap_CO2Top)

#hàm dx chứa 2 CT 1 và 2 có  CO2_Air như y1,CO2_Top như y2
#các biến chỉ phụ thuộc vào t trong bài này thì ta xem nhẹ bởi vì GT ko xem trong thời gian:
#gồm có :MC_BlowAir,MC_ExtAir
#biến phụ thuộc CO2_Air:MC_PadAir,MC_AirCan,MC_AirTop,MC_AirOut
#biến phụ thuộc CO2_Top:MC_AirTop,MC_TopOut
def euler(func,args,CO2_Air0,CO2_Top0,h):
   f1,f2=func(*args) #return the right side of (1) and (2) with parameters are CO2_Air and CO2_Top
   #Step 1:calculate values at the time (t+h) respectively
   P_t=CO2_Air0+h*f1   
   Q_t=CO2_Top0+h*f2
   return P_t,Q_t
def rk4(func,args,CO2_Air0,CO2_Top0,h):     
   k1_1,k1_2=func(*args) #calculate k1 for f1 and f2

   #function f1 recpectively the right side of (1)
   #update values of CO2_Air and CO2_Top at (t+h/2) with k1_1
   P_t1=CO2_Air0+k1_1*(h/2)
   Q_t1=CO2_Top0+k1_1*(h/2)
   
   a=func(P_t1,Q_t1) #for calculate k2_1 with new CO2_Air and CO2_Top
   k2_1=a[0] #get fisrt component
   #update values of CO2_Air and CO2_Top at (t+h/2) with k2_1
   P_t1=CO2_Air0+k2_1*(h/2)
   Q_t1=CO2_Top0+k2_1*(h/2)

   a=func(P_t1,Q_t1) #for calculate k3_1 with new CO2_Air and CO2_Top
   k3_1=a[0] #get fisrt component 
   #update values of CO2_Air and CO2_Top at (t+h) with k3_1
   P_t1=CO2_Air0+k3_1*(h)
   Q_t1=CO2_Top0+k3_1*(h)

   a=func(P_t1,Q_t1) #for calculate k4_1 with new CO2_Air and CO2_Top
   k4_1=a[0]#get fisrt component
   #calculate CO2_Air(t+h)
   P_final=CO2_Air0+(h/6)*(k1_1+2*k2_1+2*k3_1+k4_1)

   #function f2 recpectively the right side of (2)
   #update values of CO2_Air and CO2_Top at (t+h/2) with k1_2
   P_t2=CO2_Air0+k1_2*(h/2) 
   Q_t2=CO2_Top0+k1_2*(h/2)

   a=func(P_t2,Q_t2) #for calculate k2_2 with new CO2_Air and CO2_Top
   k2_2=a[1] #get second component
   #update values of CO2_Air and CO2_Top at (t+h/2) with k2_2
   P_t2=CO2_Air0+k2_2*(h/2)
   Q_t2=CO2_Top0+k2_2*(h/2)

   a=func(P_t2,Q_t2) #for calculate k3_2 with new CO2_Air and CO2_Top
   k3_2=a[1] #get second component
   #update values of CO2_Air and CO2_Top at (t+h) with k3_2
   P_t2=CO2_Air0+k3_2*(h)
   Q_t2=CO2_Top0+k3_2*(h)

   a=func(P_t2,Q_t2) #for calculate k4_2 with new CO2_Air and CO2_Top
   k4_2=a[1] #get second component
   #calculate CO2_Top(t+h)
   Q_final=CO2_Top0+(h/6)*(k1_2+2*k2_2+2*k3_2+k4_2)
   return P_final,Q_final

#for read csv
with open('MHH.csv','r') as csv_file:
    csv_reader=csv.reader(csv_file)
    
    next(csv_reader) #for ignore the first line
    
    for line in csv_reader:
       CO2_Air,CO2_Top,CO2_Out,U_Blow,U_ExtCO2,U_Pad,U_ThSrc,U_Roof,U_Side,U_VentForced,A_Flr,A_Roof,A_Side,P_Blow,K_ThSrc,C_d,C_w,T_Air,T_Top,T_Out,eta_HeatCO2,eta_Side,eta_SideThr,eta_Roof,eta_Roof_Thr,h_SideRoof,h_Roof,phi_ExtCO2,phi_Pad,phi_VentForced,p_Air,p_Top,v_Wind,zeta_InsScr,c_leakage,R,S,Hd,Ha,Res,T,T_0,k_T0,LAI,K,m,L_0,cap_CO2Air,cap_CO2Top,C_Buf,C_Max_Buf=Input(line[0],line[1],line[2],line[3],line[4],line[5],line[6],line[7],line[8],line[9],line[10],line[11],line[12],line[13],line[14],line[15],line[16],line[17],line[18],line[19],line[20],line[21],line[22],line[23],line[24],line[25],line[26],line[27],line[28],line[29],line[30],line[31],line[32],line[33],line[34],line[35],line[36],line[37],line[38],line[39],line[40],line[41],line[42],line[43],line[44],line[45],line[46],line[47],line[48],line[49],line[50])
       print("CO2_Air0 =",CO2_Air,"CO2_Top0 =",CO2_Top,"h =",600)
       ans1,ans2=euler(dx,(CO2_Air,CO2_Top),CO2_Air,CO2_Top,600)#h=0.1
       print("FOR EULER:")
       print("[ CO2_Air(t+h) ] :",round(ans1,4))
       print("[ CO2_Top(t+h) ] :",round(ans2,4)) 
       ans3,ans4=rk4(dx,(CO2_Air,CO2_Top),CO2_Air,CO2_Top,600)
       print("FOR RUNGE-KUTTAR:")
       print("[ CO2_Air(t+h) ] :",round(ans3,4))
       print("[ CO2_Top(t+h) ] :",round(ans4,4))
       print("-----------------------------------------")


