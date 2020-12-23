import math
import csv
# formula (1 & 2)
def dx(mc_BlowAir,mc_ExtAir,mc_PadAir,mc_AirCan,mc_AirTop,mc_AirOut,mc_TopOut,cap_CO2Air,cap_CO2Top):
   print("Answers are: ")
   return (mc_BlowAir+mc_ExtAir+ mc_PadAir-mc_AirCan-mc_AirTop-mc_AirOut)/(cap_CO2Air),(mc_AirTop-mc_TopOut)/(cap_CO2Top)

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

# formula (10)
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
    if P>R:
     return M_CH2O*h_CBuf*(P - R)
    else:
        print("Input unaccepted")
        return True

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

#for read csv
with open('MHH.csv','r') as csv_file:
    csv_reader=csv.reader(csv_file)
    
    next(csv_reader) #for ignore the first line
    
    for line in csv_reader:
        print(line)
        ###
        co2Air=(float)(line[0])# 2 tham số truyền vào
        co2Top=(float)(line[1])
        #MC_BlowAir
        mc_BlowAir=MC_BlowAir((float)(line[20]),(float)(line[3]),(float)(line[13]),(float)(line[10]))
        #MC_ExtAir
        mc_ExtAir=MC_ExtAir((float)(line[4]),(float)(line[27]),(float)(line[10]))
        #MC_PadAir
        mc_PadAir=MC_PadAir((float)(line[5]),(float)(line[28]),(float)(line[10]),(float)(line[2]),co2Air)
        #MC_AirTop
        f_Th=f_ThScr((float)(line[6]),(float)(line[14]),(float)(line[17]),(float)(line[18]),(float)(line[30]),(float)(line[31]))

        mc_AirTop=MC_AirTop(f_Th,co2Air,co2Top)
        #MC_AirOut
        eta_insScr=eta_InsScr((float)(line[33]))

        f_leak=f_leakage((float)(line[34]),(float)(line[32]))
        # special_f_VentSide is f_VentRoofSide when A_Roof == 0
        f2_VentSide=f_VentRoofSide((float)(line[15]),(float)(line[10]),(float)(line[7]),(float)(line[8]),0,(float)(line[12]),(float)(line[25]),(float)(line[17]),(float)(line[18]),(float)(line[16]),(float)(line[32]))
        
        f_ventRoofSide=f_VentRoofSide((float)(line[15]),(float)(line[10]),(float)(line[7]),(float)(line[8]),(float)(line[10]),(float)(line[12]),(float)(line[25]),(float)(line[17]),(float)(line[18]),(float)(line[16]),(float)(line[32]))
        
        f_ventSide=f_VentSide(eta_insScr, f2_VentSide, f_leak,(float)(line[6]), f_ventRoofSide,(float)(line[21]),(float)(line[22]))
        
        f_ventForced=f_VentForced(eta_insScr,(float)(line[9]),(float)(line[29]),(float)(line[10]))
        
        mc_AirOut=MC_AirOut(f_ventSide, f_ventForced,co2Air,(float)(line[2]))
        #MC_TopOut
        f2_ventRoof=f2_VentRoof((float)(line[15]),(float)(line[7]),(float)(line[11]),(float)(line[10]),(float)(line[26]),(float)(line[17]),(float)(line[19]),(float)(line[16]),(float)(line[32]))

        f_ventRoof=f_VentRoof((float)(line[6]),f2_ventRoof,f_leak,f_ventRoofSide,eta_insScr,(float)(line[21]),(float)(line[23]),(float)(line[24]))

        mc_TopOut=MC_TopOut(f_ventRoof,co2Top,(float)(line[2]))
        #MC_AirCan
        #calculate p
        f_t=f_T((float)(line[40]),(float)(line[41]),(float)(line[37]),(float)(line[36]))

        P_Max_T1=P_Max_T((float)(line[42]),(float)(line[38]),(float)(line[40]),(float)(line[41]),(float)(line[37]),(float)(line[36]),f_t)

        l=L((float)(line[46]),(float)(line[44]),(float)(line[45]),(float)(line[43]))
        
        P_MLT=float(line[42])

        pmax_LT=Pmax_LT(P_Max_T1,l,P_MLT)
        
        p=P(pmax_LT,co2Air,(float)(line[39]))

        mc_AirCan=MC_AirCan(0.03,p,(float)(line[35]),h_CBuf((float)(line[49]),(float)(line[50])))
        #result
        ans1,ans2=dx(mc_BlowAir,mc_ExtAir,mc_PadAir,mc_AirCan,mc_AirTop,mc_AirOut,mc_TopOut,(float)(line[47]),(float)(line[48]))
        print("[ CO2_Air' ] :",round(ans1,4))
        print("[ CO2_Top' ] :",round(ans2,4))  
