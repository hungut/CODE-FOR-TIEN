import math
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

# formula (630)
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
#CO2_Out(2),U_Blow(3),U_ExtCO2(4),U_Pad(5),U_ThSrc(6),U_Roof(7),U_Side(8),U_VentForced(9),A_Flr(630),A_Roof(11),A_Side(12),P_Blow(13),K_ThSrc(14),C_d(0.65),C_w(16),T_Air(17),T_Top(18),T_Out(19),eta_HeatCO2(20),eta_Side(21),eta_SideThr(22),eta_Roof(23),eta_Roof_Thr(24),h_SideRoof(25),h_Roof(26),phi_ExtCO2(27),phi_Pad(28),phi_VentForced(29),p_Air(30),p_Top(31),v_Wind(32),zeta_InsScr(33),c_leakage(34),R(35),S(36),Hd(37),Ha(38),Res(39),T(40),T_0(41),k_T0(42),LAI(43),K(44),m(45),L_0(46),cap_CO2Air(47),cap_CO2Top(48),C_Buf(49),C_Max_Buf(50)

def dx(CO2_Air,CO2_Top):
        mc_BlowAir=MC_BlowAir(57,0.6,500000,630)

        mc_ExtAir=MC_ExtAir(0.6,13900,630)

        mc_PadAir=MC_PadAir(0.6,15.1,630,407,CO2_Air)
        ###
        f_Th=f_ThScr(0.6,6,276.5,301.28,4.1,7.2)
        mc_AirTop=MC_AirTop(f_Th,CO2_Air,CO2_Top)
        ###
        eta_insScr=eta_InsScr(0.33)

        f_leak=f_leakage(1,3)

        f2_VentSide=f_VentRoofSide(0.65,630,0.8,0.8,0,56.7,3,276.5,301.28,0.07,3)
        
        f_ventRoofSide=f_VentRoofSide(0.65,630,0.8,0.8,630,56.7,3,276.5,301.28,0.07,3)
        
        f_ventSide=f_VentSide(eta_insScr, f2_VentSide, f_leak,0.8, f_ventRoofSide,409,511)
        
        f_ventForced=f_VentForced(eta_insScr,0.8,14,630)
        
        mc_AirOut=MC_AirOut(f_ventSide, f_ventForced,CO2_Air,407)
        ###
        f2_ventRoof=f2_VentRoof(0.65,0.8,11,630,0.5,276.5,301.28,0.07,3)

        f_ventRoof=f_VentRoof(0.8,f2_ventRoof,f_leak,f_ventRoofSide,eta_insScr,409,0.8,0.9)

        mc_TopOut=MC_TopOut(f_ventRoof,CO2_Top,407)
        ###
        #calculate p
        f_t=f_T(290,298,220000,710)

        P_Max_T1=P_Max_T(1,37000,290,298,220000,710,f_t)

        l=L(315,0.7,0.1,1.5)
        
        P_MLT=1

        pmax_LT=Pmax_LT(P_Max_T1,l,P_MLT)
        
        p=P(pmax_LT,CO2_Air,2.5)

        mc_AirCan=MC_AirCan(0.03,p,0.75,h_CBuf(10000,20000))

        return (mc_BlowAir+mc_ExtAir+ mc_PadAir-mc_AirCan-mc_AirTop-mc_AirOut)/(300),(mc_AirTop-mc_TopOut)/(200)

#hàm dx chứa 2 CT 1 và 2 có  CO2_Air như y1,CO2_Top như y2
#các biến chỉ phụ thuộc vào t trong bài này thì ta xem nhẹ bởi vì GT ko xem trong thời gian:
#gồm có :MC_BlowAir,MC_ExtAir
#biến phụ thuộc CO2_Air:MC_PadAir,MC_AirCan,MC_AirTop,MC_AirOut
#biến phụ thuộc CO2_Top:MC_AirTop,MC_TopOut
def euler(func,args,CO2_Air0,CO2_Top0,h):
   #h is the number of steps we must finish
   t=h#delta_t(t)=h 
   f1,f2=func(*args)#return the right side of (1) and (2) with parameter are CO2_Air and CO2_Top
   #Step 1: CO2_Air=CO2_Air0;CO2_Top=CO2_Top0
   P_t=CO2_Air0+t*f1   
   Q_t=CO2_Top0+t*f2
   return P_t,Q_t
def rk4(func,args,CO2_Air0,CO2_Top0,h):     
   t=h
   k1_1,k1_2=func(*args)#caculate k1 cho f1 và f2
   #function f1
   P_t1=CO2_Air0+k1_1*(h/2)#with k1(f1)
   Q_t1=CO2_Top0+k1_1*(h/2)
   
   a=func(P_t1,Q_t1) 
   k2_1=a[0]#get fisrt component
   P_t1=CO2_Air0+k2_1*(h/2)
   Q_t1=CO2_Top0+k2_1*(h/2)

   a=func(P_t1,Q_t1)
   k3_1=a[0]#get fisrt component 
   P_t1=CO2_Air0+k3_1*(h)
   Q_t1=CO2_Top0+k3_1*(h)

   a=func(P_t1,Q_t1) 
   k4_1=a[0]#get fisrt component
   P_final=CO2_Air0+(t/6)*(k1_1+2*k2_1+2*k3_1+k4_1)
   #function f2
   P_t2=CO2_Air0+k1_2*(h/2) #with k1(f2)
   Q_t2=CO2_Top0+k1_2*(h/2)

   a=func(P_t2,Q_t2) 
   k2_2=a[1] #get second component
   P_t2=CO2_Air0+k2_2*(h/2)
   Q_t2=CO2_Top0+k2_2*(h/2)

   a=func(P_t2,Q_t2) 
   k3_2=a[1] #get second component
   P_t2=CO2_Air0+k3_2*(h)
   Q_t2=CO2_Top0+k3_2*(h)

   a=func(P_t2,Q_t2) 
   k4_2=a[1] #get second component
   Q_final=CO2_Top0+(t/6)*(k1_2+2*k2_2+2*k3_2+k4_2)
   return P_final,Q_final
  
ans1,ans2=euler(dx,(427,417),427,417,0.1)    
ans3,ans4=rk4(dx,(427,417),427,417,0.1)
print("FOR EULER:")
print("[ CO2_Air(t+h) ] :",round(ans1,4))
print("[ CO2_Top(t+h) ] :",round(ans2,4)) 
print("FOR RUNGE-KUTTAR:")
print("[ CO2_Air(t+h) ] :",round(ans3,4))
print("[ CO2_Top(t+h) ] :",round(ans4,4)) 