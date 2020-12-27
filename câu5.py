import math
import csv
#hinh thanh ro CT ,tong hop data -->mai

#MV_CanAir
 
#MV_PadAir
def MV_PadAir (U_Pad,phi_Pad,A_Flr,eta_Pad, x_Pad, x_Out,p_Air0, M_Air, h_Elevation):
	f_Pad=U_Pad*phi_Pad/A_Flr
	p_Air = p_Air0 *math.exp((9.81 * M_Air * h_Elevation) / (293.15 * (9.314*(10**3))))
	return p_Air * f_Pad * (eta_Pad * (x_Pad - x_Out) +x_Out)
#MV_FogAir
def MV_FogAir (U_Fog, phi_Fog, A_Flr):
	return U_Fog * phi_Fog / A_Flr
#MV_BlowAir     
def MV_BlowAir (eta_HeatVap, U_Blow, P_Blow, A_Flr):
	return eta_HeatVap * U_Blow * P_Blow / A_Flr
#MV_AirThscr
def MV_AirThScr(VP_Air, VP_ThScr, T_Air, T_ThScr, U_ThScr):
    HEC_AirThScr=1.7*U_ThScr*abs(T_Air-T_ThScr)
    if (VP_Air<VP_ThScr): return 0
    else: MV_AirThScr=6.4*pow(10,-9)*HEC_AirThScr*(VP_Air-VP_ThScr)
    return MV_AirThScr    
#MV_AirTop
def MV_AirTop(f_ThScr, VP_Air, VP_Top, T_Air, T_Top):
    M_Water = 18
    R = 8314
    return (M_Water / R) * f_ThScr * (VP_Air / (T_Air + 273.15) - VP_Top / (T_Top + 273.15))
#MV_AirOut
def MV_AirOut(f_VentSide, f_VentForced, VP_Air, VP_Out, T_Air, T_Out):
    M_Water = 18
    R = 8314
    return (M_Water / R) * (f_VentSide + f_VentForced) * (VP_Air / (T_Air + 273.15) - VP_Out / (T_Out + 273.15))
#MV_AirOut_Pad
def MV_AirOut_Pad(U_Pad, phi_Pad, A_Flr, VP_Air, T_Air):
    M_Water = 18
    R = 8314
    return (U_Pad * phi_Pad / A_Flr) * (M_Water / R) * (VP_Air / (T_Air + 273.15))
#MV_AirMech

#MV_TopCov,in
def MV_TopCovin(VP_Top, VP_Covin, T_Top, T_Covin, c_HECin, A_Cov, A_Flr):
    HEC_TopCovin=c_HECin*pow(T_Top-T_Covin,0.33)*(A_Cov/A_Flr)
    if (VP_Top<VP_Covin): return 0
    else: MV_TopCovin=6.4*pow(10,-9)*HEC_TopCovin*(VP_Top-VP_Covin)
    return MV_TopCovin
#MV_TopOut  
def MV_TopOut(VP_Top, VP_Out, T_Top, T_Out, f_VentRoof):
    MV_TopOut=(18/(8.314*pow(10,3)))*f_VentRoof*(VP_Top/(T_Top+273.15)+VP_Out/(T_Out+273.15))
    return MV_TopOut  

#function for input data
def Input(*args):
    ret=[]
    for arg in args:
        ret.append(float(arg))
    return ret
#khai bao bien ngoai tru VP_Air và VP_Top
#A,B,CO2_Out,U_Blow,U_ExtCO2,U_Pad,U_ThSrc,U_Roof,U_Side,U_VentForced,A_Flr,A_Roof,A_Side,P_Blow,K_ThSrc,C_d,C_w,T_Air,T_Top,T_Out,eta_HeatCO2,eta_Side,eta_SideThr,eta_Roof,eta_Roof_Thr,h_SideRoof,h_Roof,phi_ExtCO2,phi_Pad,phi_VentForced,p_Air,p_Top,v_Wind,zeta_InsScr,c_leakage,R,S,Hd,Ha,Res,T,T_0,k_T0,LAI,K,m,L_0,cap_CO2Air,cap_CO2Top,C_Buf,C_Max_Buf=Input('0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0')

# formula differental equations
def dx(VP_Air,VP_Top):
    #MV_CanAir
 
    #MV_PadAir
    mv_PadAir=MV_PadAir(U_Pad,phi_Pad,A_Flr,eta_Pad, x_Pad, x_Out,p_Air0, M_Air, h_Elevation)
    #MV_FogAir
    mv_FogAir=MV_FogAir(U_Fog, phi_Fog, A_Flr)
	
    #MV_BlowAir     
    mv_BlowAir=MV_BlowAir(eta_HeatVap, U_Blow, P_Blow, A_Flr)
	
    #MV_AirThscr
    mv_AirThScr=MV_AirThScr(VP_Air, VP_ThScr, T_Air, T_ThScr, U_ThScr)
    
    #MV_AirTop
    mv_AirTop=MV_AirTop(f_ThScr, VP_Air, VP_Top, T_Air, T_Top)
    
    #MV_AirOut
    mv_AirOut=MV_AirOut(f_VentSide, f_VentForced, VP_Air, VP_Out, T_Air, T_Out)
    
    #MV_AirOut_Pad
    mv_AirOut_Pad=MV_AirOut_Pad(U_Pad, phi_Pad, A_Flr, VP_Air, T_Air)
    
    #MV_AirMech

    #MV_TopCov,in
    mv_TopCovin=MV_TopCovin(VP_Top, VP_Covin, T_Top, T_Covin, c_HECin, A_Cov, A_Flr)
    
    #MV_TopOut  
    mv_TopOut=MV_TopOut(VP_Top, VP_Out, T_Top, T_Out, f_VentRoof) 

    return (mv_CanAir+mv_PadAir+ mv_FogAir+mv_BlowAir-mv_AirThScr-mv_AirTop-mv_AirOut-mv_AirOut_Pad-mv_AirMech)/cap_VPAir,(mv_AirTop-mv_TopCovin-mv_TopOut)/cap_VPTop

#for read csv
with open('MHH.csv','r') as csv_file:
    csv_reader=csv.reader(csv_file)
    
    next(csv_reader) #for ignore the first line
    
    for line in csv_reader:
        print(line)
        ###
        #CO2_Air,CO2_Top,CO2_Out,U_Blow,U_ExtCO2,U_Pad,U_ThSrc,U_Roof,U_Side,U_VentForced,A_Flr,A_Roof,A_Side,P_Blow,K_ThSrc,C_d,C_w,T_Air,T_Top,T_Out,eta_HeatCO2,eta_Side,eta_SideThr,eta_Roof,eta_Roof_Thr,h_SideRoof,h_Roof,phi_ExtCO2,phi_Pad,phi_VentForced,p_Air,p_Top,v_Wind,zeta_InsScr,c_leakage,R,S,Hd,Ha,Res,T,T_0,k_T0,LAI,K,m,L_0,cap_CO2Air,cap_CO2Top,C_Buf,C_Max_Buf=Input(line[0],line[1],line[2],line[3],line[4],line[5],line[6],line[7],line[8],line[9],line[10],line[11],line[12],line[13],line[14],line[15],line[16],line[17],line[18],line[19],line[20],line[21],line[22],line[23],line[24],line[25],line[26],line[27],line[28],line[29],line[30],line[31],line[32],line[33],line[34],line[35],line[36],line[37],line[38],line[39],line[40],line[41],line[42],line[43],line[44],line[45],line[46],line[47],line[48],line[49],line[50])
        print("VP_Air =",VP_Air,"VP_Top =",VP_Top)
        ans1,ans2=dx(VP_Air,VP_Top)
        print("[ VP_Air' ] :",round(ans1,4))
        print("[ VP_Top' ] :",round(ans2,4))
        print("--------------------------------------------")  