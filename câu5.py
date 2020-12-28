import math
import csv

#MV_CanAir
#function for calculate
def S_r_s(R_Can):
    S_r_s = 1/(1+math.exp(-1*(R_Can-5)))
    return S_r_s
def c_evap3(S_r_s):
    c_evap3 = 1.1*pow(10,-11)*(1-S_r_s)+1.1*pow(10,-11)*S_r_s
    return c_evap3
def c_evap4(S_r_s):
    c_evap4 = 5.2*pow(10,-6)*(1-S_r_s)+5.2*pow(10,-6)*S_r_s
    return c_evap4
    #
def r_s(R_Can, c_evap3, c_evap4, VP_Can,VP_Air ):
    rf_R_Can = (R_Can+4.30)/(R_Can+0.54)
    a = 0.554-200
    rf_VP_Air = 1 + c_evap3*pow(a,2)
    rf_VPcan_VPair = 1 + c_evap4*(VP_Can-VP_Air)
    r_s = 82.0*rf_R_Can*rf_VP_Air*rf_VPcan_VPair
    return r_s
    #
def VEC_CanAir(p_Air,LAI,r_s):
    VEC_CanAir = 2*p_Air*1*pow(10,3)*LAI/(2.45*pow(10,6)*65.8*(275+r_s))
    return VEC_CanAir
def MV_CanAir(VEC_CanAir, VP_Can, VP_Air):
    MV_CanAir= VEC_CanAir*(VP_Can-VP_Air)
    return MV_CanAir 
#MV_PadAir
def MV_PadAir (U_Pad,phi_Pad,A_Flr,eta_Pad, x_Pad, x_Out, h_Elevation):
	f_Pad=U_Pad*phi_Pad/A_Flr
	p_Air = 1.2 *math.exp((9.81 * 28.96 * h_Elevation) / (293.15 * (8.314*(10**3))))
	return p_Air * f_Pad * (eta_Pad * (x_Pad - x_Out) +x_Out)
#MV_FogAir
def MV_FogAir (U_Fog, phi_Fog, A_Flr):
	return U_Fog * phi_Fog / A_Flr
#MV_BlowAir     
def MV_BlowAir (U_Blow, P_Blow, A_Flr):
	return 4.43*(10**(-8)) * U_Blow * P_Blow / A_Flr
#MV_AirThscr
def MV_AirThScr(VP_Air, VP_ThScr, T_Air, T_ThScr, U_ThScr):
    HEC_AirThScr=1.7*U_ThScr*abs(T_Air-T_ThScr)
    if (VP_Air<VP_ThScr): return 0
    else: MV1_AirThScr=6.4*pow(10,-9)*HEC_AirThScr*(VP_Air-VP_ThScr)
    return MV1_AirThScr    
#MV_AirTop
def f_ThScr(U_ThScr,K_ThScr,T_Air,T_Top,p_Air,p_Top):
    p_Mean=(p_Air+p_Top)/2    
    a=U_ThScr*K_ThScr*(abs(T_Air-T_Top)**(2/3)) #tham thau qua man
    b=(1-U_ThScr)*((9.81*(1-U_ThScr)/(2*p_Mean))*abs(p_Air-p_Top))**(1/2) #khong bi chan qua man
    return a+b
def MV_AirTop(f_ThScr, VP_Air, VP_Top, T_Air, T_Top):
    M_Water = 18
    R = 8314
    return (M_Water / R) * f_ThScr * (VP_Air / (T_Air ) - VP_Top / (T_Top ))
#MV_AirOut
#function for calculate 
def f_VentRoofSide(C_d, A_Flr, U_Roof, U_Side, A_Roof, A_Side, h_SideRoof, T_Air, T_Out, C_w, v_Wind):
    T_Mean_Air=(T_Air+T_Out)/2
    ratio = C_d / A_Flr
    stack_first_component = ((U_Roof ** 2) * (U_Side ** 2) * (A_Roof ** 2) * (A_Side ** 2)) / ((U_Roof ** 2) * (A_Roof ** 2) + (U_Side ** 2)*(A_Side ** 2))
    stack_second_component = 2 * 9.81 * h_SideRoof * (T_Air - T_Out) / T_Mean_Air
    stack_component = stack_first_component * stack_second_component
    bernoulli_component = (((U_Roof * A_Roof + U_Side * A_Side) / 2) ** 2) * C_w * (v_Wind ** 2)
    result = ratio * math.sqrt(stack_component + bernoulli_component)
    return result
def eta_InsScr(zeta_InsScr):
    return zeta_InsScr * (2 - zeta_InsScr)
def f_leakage(c_leakage, v_Wind):
    if v_Wind < 0.25:
        return 0.25 * c_leakage
    else:
        return v_Wind * c_leakage
# special_f_VentSide is f_VentRoofSide when A_Roof == 0
def f_VentSide(eta_InsScr, special_f_VentSide, f_leakage, U_ThScr, f_VentRoofSide, eta_Side, eta_Side_Thr):
    if eta_Side >= eta_Side_Thr:
        return eta_InsScr * special_f_VentSide + 0.5 * f_leakage
    else:
        return eta_InsScr * (U_ThScr * special_f_VentSide + (1 - U_ThScr) * f_VentRoofSide * eta_Side) + 0.5 * f_leakage
def f_VentForced(eta_InsScr, U_VentForced, phi_VentForced, A_Flr):
    return eta_InsScr * U_VentForced * phi_VentForced / A_Flr
##
def MV_AirOut(f_VentSide, f_VentForced, VP_Air, VP_Out, T_Air, T_Out):
    M_Water = 18
    R = 8314
    return (M_Water / R) * (f_VentSide + f_VentForced) * (VP_Air / (T_Air ) - VP_Out / (T_Out ))
#MV_AirOut_Pad
def MV_AirOut_Pad(U_Pad, phi_Pad, A_Flr, VP_Air, T_Air):
    M_Water = 18
    R = 8314
    return (U_Pad * phi_Pad / A_Flr) * (M_Water / R) * (VP_Air / (T_Air ))
#MV_AirMech
def HEC_MechAir(U_MechCool, COP_MechCool,P_MechCool,A_Flr,T_Air, T_MechCool, VP_Air, VP_MechCool):
    HEC_MechAir = (U_MechCool*COP_MechCool*P_MechCool/A_Flr)/(T_Air-T_MechCool+6.4*pow(10,-9)*2.45*pow(10,6)*(VP_Air-VP_MechCool))
    return HEC_MechAir
 
def MV_AirMech(VP_Air, VP_MechCool,HEC_MechAir):
    if (VP_Air<VP_MechCool): return 0
    else: MV_AirMech=6.4*pow(10,-9)*HEC_MechAir*(VP_Air-VP_MechCool)
    return MV_AirMech
#MV_TopCov,in
def MV_TopCovin(VP_Top, VP_Covin, T_Top, T_Covin, c_HECin, A_Cov, A_Flr):
    HEC_TopCovin=c_HECin*pow(T_Top-T_Covin,0.33)*(A_Cov/A_Flr)
    if (VP_Top<VP_Covin): return 0
    else: MV1_TopCovin=6.4*pow(10,-9)*HEC_TopCovin*(VP_Top-VP_Covin)
    return MV1_TopCovin
#MV_TopOut 
#fuction for calculate  
def f_VentRoof(U_ThScr,f2_VentRoof,f_leakage,f_VentRoofSide,eta_InsScr,eta_Side,eta_Roof,eta_RoofThr):
        if eta_Roof>=eta_RoofThr:
            a=eta_InsScr*f2_VentRoof+0.5*f_leakage
        else:
            a=eta_InsScr*(U_ThScr*f2_VentRoof+(1-U_ThScr)*f_VentRoofSide*eta_Side)+0.5*f_leakage
        return a
def f2_VentRoof(C_d,U_Roof,A_Roof,A_Flr,h_Roof,T_Air,T_Out,C_w,v_Wind):
    T_Mean=(T_Air+T_Out)/2
    a=((C_d*U_Roof*A_Roof)/(2*A_Flr))*((9.81*h_Roof*(T_Air-T_Out))/(2*T_Mean)+C_w*(v_Wind**2))**(1/2) 
    return a         

def MV_TopOut(VP_Top, VP_Out, T_Top, T_Out, f_VentRoof):
    MV_TopOut1=(18/(8.314*pow(10,3)))*f_VentRoof*(VP_Top/(T_Top)+VP_Out/(T_Out))
    return MV_TopOut1  

#function for input data
def Input(*args):
    ret=[]
    for arg in args:
        ret.append(float(arg))
    return ret
#khai bao bien ngoai tru VP_Air và VP_Top
a,b,VP_Out,VP_Can,VP_MechCool,U_Blow,U_Pad,U_ThScr,U_Roof,U_Side,U_VentForced,U_Fog,U_MechCool,A_Flr,A_Roof,A_Side,A_Cov,P_Blow,P_MechCool,K_ThScr,C_d,C_w,T_Air,T_Top,T_Out,T_ThScr,T_Covin,eta_Side,eta_SideThr,eta_Roof,eta_RoofThr,eta_Pad,h_SideRoof,h_Roof,h_Elevation,phi_Pad,phi_VentForced,phi_Fog,p_Air,p_Top,v_Wind,zeta_InsScr,c_leakage,LAI,cap_VPAir,cap_VPTop,x_Pad,x_Out,VP_ThScr,VP_Covin,VP_MechCool,c_HECin,R_Can,COP_MechCool,T_MechCool=Input('0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0')

# formula differental equations
def dx(VP_Air,VP_Top):
    #MV_CanAir
    S_r_s1=S_r_s(R_Can)
    c_evap3_1=c_evap3(S_r_s1)
    c_evap4_1=c_evap4(S_r_s1)
    r_s1=r_s(R_Can,c_evap3_1,c_evap4_1,VP_Can,VP_Air)
    vec_CanAir=VEC_CanAir(p_Air,LAI,r_s1)
    mv_CanAir=MV_CanAir(vec_CanAir,VP_Can,VP_Air)
    #MV_PadAir
    mv_PadAir=MV_PadAir(U_Pad,phi_Pad,A_Flr,eta_Pad, x_Pad, x_Out, h_Elevation)
    #MV_FogAir
    mv_FogAir=MV_FogAir(U_Fog, phi_Fog, A_Flr)
    #MV_BlowAir     
    mv_BlowAir=MV_BlowAir(U_Blow, P_Blow, A_Flr)
    #MV_AirThscr
    mv_AirThScr=MV_AirThScr(VP_Air, VP_ThScr, T_Air, T_ThScr, U_ThScr)
    #MV_AirTop
    f_Th=f_ThScr(U_ThScr,K_ThScr,T_Air,T_Top,p_Air,p_Top)

    mv_AirTop=MV_AirTop(f_Th, VP_Air, VP_Top, T_Air, T_Top)
    #MV_AirOut
    eta_insScr=eta_InsScr(zeta_InsScr)

    f_leak=f_leakage(c_leakage,v_Wind)
    # special_f_VentSide is f_VentRoofSide when A_Roof == 0
    f2_VentSide=f_VentRoofSide(C_d,A_Flr,U_Roof,U_Side, 0 ,A_Side,h_SideRoof,T_Air,T_Top,C_w,v_Wind)
        
    f_ventRoofSide=f_VentRoofSide(C_d,A_Flr,U_Roof,U_Side,A_Flr,A_Side,h_SideRoof,T_Air,T_Top,C_w,v_Wind)
        
    f_ventSide=f_VentSide(eta_insScr, f2_VentSide, f_leak,U_ThScr, f_ventRoofSide,eta_Side,eta_SideThr)
        
    f_ventForced=f_VentForced(eta_insScr,U_VentForced,phi_VentForced,A_Flr)
        
    mv_AirOut=MV_AirOut(f_ventSide, f_ventForced, VP_Air, VP_Out, T_Air, T_Out)
    #MV_AirOut_Pad
    mv_AirOut_Pad=MV_AirOut_Pad(U_Pad, phi_Pad, A_Flr, VP_Air, T_Air)
    #MV_AirMech
    hec_MechAir=HEC_MechAir(U_MechCool, COP_MechCool,P_MechCool,A_Flr,T_Air, T_MechCool, VP_Air, VP_MechCool)
    mv_AirMech=MV_AirMech(VP_Air, VP_MechCool,hec_MechAir)
    #MV_TopCov,in
    mv_TopCovin=MV_TopCovin(VP_Top, VP_Covin, T_Top, T_Covin, c_HECin, A_Cov, A_Flr)
    #MV_TopOut  
    f2_ventRoof=f2_VentRoof(C_d,U_Roof,A_Roof,A_Flr,h_Roof,T_Air,T_Out,C_w,v_Wind)

    f_ventRoof=f_VentRoof(U_ThScr,f2_ventRoof,f_leak,f_ventRoofSide,eta_insScr,eta_Side,eta_Roof,eta_RoofThr)
    
    mv_TopOut=MV_TopOut(VP_Top, VP_Out, T_Top, T_Out, f_ventRoof) 

    return (mv_CanAir+mv_PadAir+ mv_FogAir+mv_BlowAir-mv_AirThScr-mv_AirTop-mv_AirOut-mv_AirOut_Pad-mv_AirMech)/cap_VPAir,(mv_AirTop-mv_TopCovin-mv_TopOut)/cap_VPTop
# formula for Euler and Runge-Kuttar:
def euler(func,args,VP_Air0,VP_Top0,h):
   f1,f2=func(*args) #return the right side of (1) and (2) with parameters are VP_Air and VP_Top
   #Step 1:calculate values at the time (t+h) respectively
   P_t=VP_Air0+h*f1   
   Q_t=VP_Top0+h*f2
   return P_t,Q_t
def rk4(func,args,VP_Air0,VP_Top0,h):     
   k1_1,k1_2=func(*args) #calculate k1 for f1 and f2

   #function f1 recpectively the right side of (1)
   #update values of VP_Air and VP_Top at (t+h/2) with k1_1
   P_t1=VP_Air0+k1_1*(h/2)
   Q_t1=VP_Top0+k1_1*(h/2)
   
   a=func(P_t1,Q_t1) #for calculate k2_1 with new VP_Air and VP_Top
   k2_1=a[0] #get fisrt component
   #update values of VP_Air and VP_Top at (t+h/2) with k2_1
   P_t1=VP_Air0+k2_1*(h/2)
   Q_t1=VP_Top0+k2_1*(h/2)

   a=func(P_t1,Q_t1) #for calculate k3_1 with new VP_Air and VP_Top
   k3_1=a[0] #get fisrt component 
   #update values of VP_Air and VP_Top at (t+h) with k3_1
   P_t1=VP_Air0+k3_1*(h)
   Q_t1=VP_Top0+k3_1*(h)

   a=func(P_t1,Q_t1) #for calculate k4_1 with new VP_Air and VP_Top
   k4_1=a[0]#get fisrt component
   #calculate VP_Air(t+h)
   P_final=VP_Air0+(h/6)*(k1_1+2*k2_1+2*k3_1+k4_1)

   #function f2 recpectively the right side of (2)
   #update values of VP_Air and VP_Top at (t+h/2) with k1_2
   P_t2=VP_Air0+k1_2*(h/2) 
   Q_t2=VP_Top0+k1_2*(h/2)

   a=func(P_t2,Q_t2) #for calculate k2_2 with new VP_Air and VP_Top
   k2_2=a[1] #get second component
   #update values of VP_Air and VP_Top at (t+h/2) with k2_2
   P_t2=VP_Air0+k2_2*(h/2)
   Q_t2=VP_Top0+k2_2*(h/2)

   a=func(P_t2,Q_t2) #for calculate k3_2 with new VP_Air and VP_Top
   k3_2=a[1] #get second component
   #update values of VP_Air and VP_Top at (t+h) with k3_2
   P_t2=VP_Air0+k3_2*(h)
   Q_t2=VP_Top0+k3_2*(h)

   a=func(P_t2,Q_t2) #for calculate k4_2 with new VP_Air and VP_Top
   k4_2=a[1] #get second component
   #calculate VP_Top(t+h)
   Q_final=VP_Top0+(h/6)*(k1_2+2*k2_2+2*k3_2+k4_2)
   return P_final,Q_final

#for part 3
with open('Data5.csv','r') as csv_file:
    csv_reader=csv.reader(csv_file)
    
    next(csv_reader) #for ignore the first line
    
    for line in csv_reader:
        #print(line)
        VP_Air,VP_Top,VP_Out,VP_Can,VP_MechCool,U_Blow,U_Pad,U_ThScr,U_Roof,U_Side,U_VentForced,U_Fog,U_MechCool,A_Flr,A_Roof,A_Side,A_Cov,P_Blow,P_MechCool,K_ThScr,C_d,C_w,T_Air,T_Top,T_Out,T_ThScr,T_Covin,eta_Side,eta_SideThr,eta_Roof,eta_RoofThr,eta_Pad,h_SideRoof,h_Roof,h_Elevation,phi_Pad,phi_VentForced,phi_Fog,p_Air,p_Top,v_Wind,zeta_InsScr,c_leakage,LAI,cap_VPAir,cap_VPTop,x_Pad,x_Out,VP_ThScr,VP_Covin,VP_MechCool,c_HECin,R_Can,COP_MechCool,T_MechCool=Input(line[0],line[1],line[2],line[3],line[4],line[5],line[6],line[7],line[8],line[9],line[10],line[11],line[12],line[13],line[14],line[15],line[16],line[17],line[18],line[19],line[20],line[21],line[22],line[23],line[24],line[25],line[26],line[27],line[28],line[29],line[30],line[31],line[32],line[33],line[34],line[35],line[36],line[37],line[38],line[39],line[40],line[41],line[42],line[43],line[44],line[45],line[46],line[47],line[48],line[49],line[50],line[51],line[52],line[53],line[54])
        print("VP_Air =",VP_Air,"VP_Top =",VP_Top)
        ans10,ans20=dx(VP_Air,VP_Top)
        print("[ VP_Air' ] :",round(ans10,4))
        print("[ VP_Top' ] :",round(ans20,4))
        print("--------------------------------------------")  
#for part 4
with open('Data5.csv','r') as csv_file:
    csv_reader=csv.reader(csv_file)
    
    next(csv_reader) #for ignore the first line
    
    for line in csv_reader:
       VP_Air,VP_Top,VP_Out,VP_Can,VP_MechCool,U_Blow,U_Pad,U_ThScr,U_Roof,U_Side,U_VentForced,U_Fog,U_MechCool,A_Flr,A_Roof,A_Side,A_Cov,P_Blow,P_MechCool,K_ThScr,C_d,C_w,T_Air,T_Top,T_Out,T_ThScr,T_Covin,eta_Side,eta_SideThr,eta_Roof,eta_RoofThr,eta_Pad,h_SideRoof,h_Roof,h_Elevation,phi_Pad,phi_VentForced,phi_Fog,p_Air,p_Top,v_Wind,zeta_InsScr,c_leakage,LAI,cap_VPAir,cap_VPTop,x_Pad,x_Out,VP_ThScr,VP_Covin,VP_MechCool,c_HECin,R_Can,COP_MechCool,T_MechCool=Input(line[0],line[1],line[2],line[3],line[4],line[5],line[6],line[7],line[8],line[9],line[10],line[11],line[12],line[13],line[14],line[15],line[16],line[17],line[18],line[19],line[20],line[21],line[22],line[23],line[24],line[25],line[26],line[27],line[28],line[29],line[30],line[31],line[32],line[33],line[34],line[35],line[36],line[37],line[38],line[39],line[40],line[41],line[42],line[43],line[44],line[45],line[46],line[47],line[48],line[49],line[50],line[51],line[52],line[53],line[54])
       print("VP_Air0 =",VP_Air,"VP_Top0 =",VP_Top,"h =",0.1)
       ans1,ans2=euler(dx,(VP_Air,VP_Top),VP_Air,VP_Top,0.1)#h=0.1
       print("FOR EULER:")
       print("[ VP_Air(t+h) ] :",round(ans1,4))
       print("[ VP_Top(t+h) ] :",round(ans2,4)) 
       ans3,ans4=rk4(dx,(VP_Air,VP_Top),VP_Air,VP_Top,0.1)
       print("FOR RUNGE-KUTTAR:")
       print("[ VP_Air(t+h) ] :",round(ans3,4))
       print("[ VP_Top(t+h) ] :",round(ans4,4))
       print("-----------------------------------------")        