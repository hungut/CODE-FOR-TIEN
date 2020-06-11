#ifndef _definition_h_
#include "defs.h"
#define _definition_h_
#endif
int bFlag = -1;
float basedamage;
int number, damage, gil1to5, b, levelO, poison = 0, countpoison = 0, special = 0;
int lionheart = 0, countlionheart = 0, nWin = 0, nLose = 0, Odin = 0, countOdin = 0, DragonKnight = 0, OmegaWeapon = 1;
int ScarletHakama = 0, mythril = 0, special2 = 0, Nguyento = 1, numberNina = 0, numberOdin = 0;
int Paladinshield = 0, Lancelotspear = 0, Guineverehair = 0, Excalibur = 0, Authur = 0, Paladin = 0, Lancelot = 0, Guinevere = 0;
void funcspecial(int HP, int gil, int &special)
{
	if ((HP > 5 && gil > 5) && (HP != gil))
	{
		int sum1 = 0, sum2 = 0;
		for (int i1 = 1; i1 <= HP; i1++)
		{
			if (HP % i1 == 0)
			{
				sum1 += i1;
			}
		}
		for (int i2 = 1; i2 <= gil; i2++)
		{
			if (gil % i2 == 0)
			{
				sum2 += i2;
			}
		}
		if ((sum1 * gil) == (sum2 * HP))
			special = 1;
	}
}
void checkDragonknight(int &HPbandau, int &DragonKnight)
{
	if (HPbandau != 888)
	{
		for (int x = 1; x < HPbandau; x++)
		{
			for (int y = 1; y < HPbandau; y++)
			{
				for (int z = 1; z < HPbandau; z++)
				{
					if ((x + y + z == HPbandau) && (x * x == (y * y + z * z)))
					{
						DragonKnight = 1;
						return;
					}
				}
			}
		}
	}
}
void checkNguyento(int &HPbandau, int &Nguyento)
{
	for (int i1 = 2; i1 <= (float)(HPbandau / 2); i1++)
	{
		if (HPbandau % i1 == 0)
		{
			Nguyento = 0;
		}
	}
}
report *walkthrough(knight &theKnight, castle arrCastle[], int nCastle, int mode, int nPetal)
{
	report *pReturn;
	int a = nCastle, maxHP = theKnight.HP, HPbandau = theKnight.HP, levelbandau = theKnight.level;
	//fighting for the existence of mankind here
	checkNguyento(HPbandau, Nguyento);
	checkDragonknight(HPbandau, DragonKnight);
	while (nPetal > 0)
	{
		if (bFlag == 1)
			break;

		for (int i = 0; i < nCastle; i++)
		{
			if (bFlag != 0 && bFlag != 1)
			{
				castle cc = arrCastle[i];
				if (a < nCastle)
				{

					if (theKnight.level < 10)
					{
						++theKnight.level;
						maxHP = maxHP + 100;
						if ((10 - levelbandau) * 100 + HPbandau <= 999)
						{
							if (maxHP >= (10 - levelbandau) * 100 + HPbandau)
								maxHP = (10 - levelbandau) * 100 + HPbandau;
						}
						else
						{
							if (maxHP >= 999)
								maxHP = 999;
						}
					}
				}
				for (int j = 0; j < cc.nEvent; j++)
				{
					if (bFlag != 0 && bFlag != 1)
					{
						number = cc.arrEvent[j];
						//code cho cac ma
						if (HPbandau == 999)
						{
							Authur = 1;
						}
						if (HPbandau == 888)
						{
							Lancelot = 1;
							Lancelotspear = 1;
						}
						if (HPbandau == 777)
						{
							Guinevere = 1;
							Guineverehair = 1;
						}

						if (Nguyento == 1)
						{
							Paladin = 1;
							Paladinshield = 1;
						}

						if (number == 95)
						{
							if (numberNina > 0)
								--numberNina;
							if (numberOdin > 0)
								--numberOdin;
							--nPetal;
							if (poison == 1)
								--countpoison;
							if (lionheart == 1)
								--countlionheart;
							if (Odin == 1)
								--countOdin;
							if (mode == 0)
								Paladinshield = 1;
							if (mode == 1)
							{
								if (hash(95) > hash(96) && hash(95) > hash(97))
								{
									if (Lancelotspear == 1 && Guineverehair == 1)
										Paladinshield = 1;
								}
								if (hash(95) > hash(96) && hash(95) < hash(97))
								{
									if (Lancelotspear == 1)
										Paladinshield = 1;
								}
								if (hash(95) > hash(97) && hash(95) < hash(96))
								{
									if (Guineverehair == 1)
										Paladinshield = 1;
								}
								if (hash(95) < hash(96) && hash(95) < hash(97))
								{
									Paladinshield = 1;
								}
							}
						}
						if (number == 96)
						{
							if (numberNina > 0)
								--numberNina;
							if (numberOdin > 0)
								--numberOdin;
							--nPetal;
							if (poison == 1)
								--countpoison;
							if (lionheart == 1)
								--countlionheart;
							if (Odin == 1)
								--countOdin;
							if (mode == 0)
								Lancelotspear = 1;
							if (mode == 1)
							{
								if (hash(96) > hash(95) && hash(96) > hash(97))
								{
									if (Paladinshield == 1 && Guineverehair == 1)
										Lancelotspear = 1;
								}
								if (hash(96) > hash(95) && hash(96) < hash(97))
								{
									if (Paladinshield == 1)
										Lancelotspear = 1;
								}
								if (hash(96) > hash(97) && hash(96) < hash(95))
								{
									if (Guineverehair == 1)
										Lancelotspear = 1;
								}
								if (hash(96) < hash(95) && hash(96) < hash(97))
								{
									Lancelotspear = 1;
								}
							}
						}
						if (number == 97)
						{
							if (numberNina > 0)
								--numberNina;
							if (numberOdin > 0)
								--numberOdin;
							--nPetal;
							if (poison == 1)
								--countpoison;
							if (lionheart == 1)
								--countlionheart;
							if (Odin == 1)
								--countOdin;
							if (mode == 0)
								Guineverehair = 1;
							if (mode == 1)
							{
								if (hash(97) > hash(95) && hash(97) > hash(96))
								{
									if (Paladinshield == 1 && Lancelotspear == 1)
										Guineverehair = 1;
								}
								if (hash(97) > hash(95) && hash(97) < hash(96))
								{
									if (Paladinshield == 1)
										Guineverehair = 1;
								}
								if (hash(97) > hash(96) && hash(97) < hash(95))
								{
									if (Lancelotspear == 1)
										Guineverehair = 1;
								}
								if (hash(97) < hash(95) && hash(97) < hash(96))
								{
									Guineverehair = 1;
								}
							}
						}
						///////////////////////////////////////
						if (number == 99)
						{
							if (poison == 1)
							{
								--countpoison;
								theKnight.HP = theKnight.HP / 3;
								if (theKnight.HP < 3)
									theKnight.HP = 1;
							}
							if (Excalibur != 1 && lionheart != 1)
							{
								if (numberNina > 0)
									--numberNina;
								if (numberOdin > 0)
									--numberOdin;
								--nPetal;
								++nLose;
								if (poison == 1)
									--countpoison;
								if (Odin == 1)
									--countOdin;
								if (mythril != 1 && Guinevere != 1)
								{
									theKnight.HP = theKnight.HP / 3;
									if (theKnight.HP < 3)
										theKnight.HP = 1;
								}
							}
							else
							{
								if (numberNina > 0)
									--numberNina;
								if (numberOdin > 0)
									--numberOdin;
								--nPetal;
								++nWin;
								if (lionheart == 1)
									--countlionheart;
								if (Odin == 1)
									--countOdin;
								bFlag = 1;
							}
						}
						///////////////////
						if (number == 98)
						{
							if (numberNina > 0)
								--numberNina;
							if (numberOdin > 0)
								--numberOdin;
							--nPetal;
							if (poison == 1)
								--countpoison;
							if (lionheart == 1)
								--countlionheart;
							if (Odin == 1)
								--countOdin;
							if ((Paladinshield == 1 && Lancelotspear == 1 && Guineverehair == 1) || (Authur == 1))
							{
								Excalibur = 1;
							}
						}

						b = (j + 1) % 10;
						levelO = (j + 1) > 6 ? (b > 5 ? b : 5) : b;
						if (1 <= number && number <= 5)
						{
							switch (number)
							{
							case 1:
							{
								basedamage = 1;
								gil1to5 = 100;
								break;
							}
							case 2:
							{
								basedamage = 1.5;
								gil1to5 = 150;
								break;
							}
							case 3:
							{
								basedamage = 4.5;
								gil1to5 = 450;
								break;
							}
							case 4:
							{
								basedamage = 6.5;
								gil1to5 = 650;
								break;
							}
							case 5:
							{
								basedamage = 8.5;
								gil1to5 = 850;
								break;
							}
							}
							if (numberNina > 0)
								--numberNina;
							if (numberOdin > 0)
								--numberOdin;
							if (poison == 1)
							{
								damage = basedamage * levelO * 10;
								theKnight.HP = theKnight.HP - damage;
							}
							--nPetal;
							if (poison == 1)
								--countpoison;
							if (lionheart == 1)
								--countlionheart;
							if (Odin == 1)
								--countOdin;
							//
							if (theKnight.level >= levelO || lionheart == 1 || Odin == 1 || Authur == 1 || Lancelot == 1 || Paladin == 1)
							{

								if (theKnight.HP <= 0)
								{
									callPhoenix(theKnight, maxHP);
									poison = 0;
									countpoison = 0;
								}

								++nWin;
								theKnight.gil = theKnight.gil + gil1to5;
								if (theKnight.gil >= 999)
									theKnight.gil = 999;
							}
							if (lionheart != 1 && Odin != 1 && Authur != 1 && Lancelot != 1 && Paladin != 1)
							{
								if (theKnight.level < levelO)
								{
									++nLose;
									if (mythril != 1)
									{
										if (number != 2 || Guinevere != 1)
										{
											damage = basedamage * levelO * 10;
											theKnight.HP = theKnight.HP - damage;
											//chua biet thu tu tru
										}
									}
									if (theKnight.HP <= 0)
									{
										callPhoenix(theKnight, maxHP);
										poison = 0;
										countpoison = 0;
									}
								}
							}
						}

						if (number == 6)
						{
							if (numberNina > 0)
								--numberNina;
							if (numberOdin > 0)
								--numberOdin;
							if (poison == 1)
							{
								--nPetal;
								--countpoison;
								if (lionheart == 1)
									--countlionheart;
								if (Odin == 1)
									--countOdin;
							}
							if (poison != 1)
							{
								--nPetal;
								if (lionheart == 1)
									--countlionheart;
								if (Odin == 1)
									--countOdin;
								if (theKnight.level >= levelO || lionheart == 1 || Odin == 1 || Authur == 1 || Lancelot == 1)
								{
									++nWin;
									if (theKnight.level < 10)
									{
										++theKnight.level;
										maxHP = maxHP + 100;
										if ((10 - levelbandau) * 100 + HPbandau <= 999)
										{
											if (maxHP >= (10 - levelbandau) * 100 + HPbandau)
												maxHP = (10 - levelbandau) * 100 + HPbandau;
										}
										else
										{
											if (maxHP >= 999)
												maxHP = 999;
										}
									}
								}
								if (lionheart != 1 && Odin != 1 && Authur != 1 && Lancelot != 1)
								{
									if (theKnight.level < levelO)
									{
										++nLose;
										if (Paladin != 1 && DragonKnight != 1)
										{
											poison = 1;
											countpoison = 5;
											if (theKnight.antidote >= 1)
											{
												theKnight.antidote--;
												poison = 0;
												countpoison = 0;
											}
										}
									}
								}
							}
						}
						if (number == 7)
						{
							if (numberNina > 0)
								--numberNina;
							if (numberOdin > 0)
								--numberOdin;
							--nPetal;
							if (poison == 1)
								--countpoison;
							if (lionheart == 1)
								--countlionheart;
							if (Odin == 1)
								--countOdin;
							if (theKnight.level >= levelO || lionheart == 1 || Odin == 1 || Authur == 1 || Lancelot == 1)
							{
								++nWin;
								theKnight.gil = theKnight.gil * 2;
								if (theKnight.gil >= 999)
									theKnight.gil = 999;
							}
							if (lionheart != 1 && Odin != 1 && Authur != 1 && Lancelot != 1)
							{
								if (theKnight.level < levelO)
								{
									++nLose;
									if (ScarletHakama != 1 && Guinevere != 1)
									{
										theKnight.gil = theKnight.gil / 2;
									}
								}
							}
						}

						if (number == 8)
						{
							funcspecial(theKnight.HP, theKnight.gil, special);
							if (numberOdin > 0)
								--numberOdin;
							--nPetal;
							if (lionheart == 1)
								--countlionheart;
							if (Odin == 1)
								--countOdin;
							if (poison == 1)
								--countpoison;
							if (numberNina == 0)
							{
								numberNina = 7;
								if (special == 1)
								{
									if (poison == 1)
									{
										poison = 0;
										countpoison = 0;
									}
									theKnight.HP = maxHP;
									lionheart = 1;
									countlionheart = 5;
								}
								else
								{
									if (ScarletHakama == 1 || Guinevere == 1 || Paladin == 1)
									{
										if (poison == 1)
										{
											poison = 0;
											countpoison = 0;
										}
										if (Guinevere == 1)
										{
											theKnight.gil += 50;
											if (theKnight.gil >= 999)
												theKnight.gil = 999;
										}
										theKnight.HP = maxHP;
									}
									if (theKnight.gil > 50 && ScarletHakama != 1 && Guinevere != 1 && Paladin != 1)
									{
										if (poison == 1)
										{
											theKnight.gil = theKnight.gil - 50;
											poison = 0;
											countpoison = 0;
										}
										if (theKnight.gil > 0)
										{
											while (theKnight.HP != maxHP && theKnight.gil != 0)
											{
												theKnight.gil = theKnight.gil - 1;
												theKnight.HP = theKnight.HP + 1;
											}
										}
									}
								}
							}
							if (special == 1)
								special = 0;
							if (numberNina > 0)
								--numberNina;
						}
						if (number == 9)
						{
							if (numberNina > 0)
								--numberNina;
							if (numberOdin > 0)
								--numberOdin;

							if (poison == 1)
							{
								poison = 0;
								countpoison = 0;
							}
							if (lionheart == 1)
								--countlionheart;
							if (Odin == 1)
								--countOdin;
							theKnight.HP = maxHP;
							if (ScarletHakama != 1)
							{
								nPetal = nPetal + 5;
								if (nPetal >= 99)
									nPetal = 99;
							}
							else
								nPetal = 99;
							--nPetal;
						}
						if (number == 10)
						{
							if (numberNina > 0)
								--numberNina;
							if (numberOdin > 0)
								--numberOdin;
							--nPetal;
							if (lionheart == 1)
								--countlionheart;
							if (Odin == 1)
								--countOdin;
							if (theKnight.antidote >= 0)
							{
								theKnight.antidote = theKnight.antidote + 1;
								if (theKnight.antidote >= 99)
									theKnight.antidote = 99;
							}
							if (poison == 1 && countpoison == 0)
							{
								poison = 0;
							}
							if (poison == 1 && countpoison != 0)
							{
								poison = 0;
								countpoison = 0;
								theKnight.antidote--;
							}
						}
						if (number == 11)
						{
							if (numberNina > 0)
								--numberNina;
							--nPetal;
							if (lionheart == 1)
								--countlionheart;
							if (poison == 1)
								--countpoison;
							if (numberOdin == 0)
							{
								numberOdin = 7;
								if (Odin == 0)
								{
									Odin = 1;
									countOdin = 5;
								}
							}
							if (numberOdin > 0)
								--numberOdin;
						}
						if (number == 12)
						{
							if (numberNina > 0)
								--numberNina;
							if (numberOdin > 0)
								--numberOdin;
							--nPetal;
							if (lionheart == 1)
								--countlionheart;
							if (Odin == 1)
								--countOdin;
							if (poison == 1)
							{
								poison = 0;
								countpoison = 0;
							}
							if (theKnight.level < 10)
							{
								++theKnight.level;
								maxHP = maxHP + 100;
								if ((10 - levelbandau) * 100 + HPbandau <= 999)
								{
									if (maxHP >= (10 - levelbandau) * 100 + HPbandau)
										maxHP = (10 - levelbandau) * 100 + HPbandau;
								}
								else
								{
									if (maxHP >= 999)
										maxHP = 999;
								}
							}
							theKnight.HP = maxHP;
						}
						if (number == 13)
						{
							if (numberNina > 0)
								--numberNina;
							if (numberOdin > 0)
								--numberOdin;
							--nPetal;
							if (lionheart == 1)
								--countlionheart;
							if (Odin == 1)
								--countOdin;
							if (poison == 1)
								--countpoison;
							if (OmegaWeapon == 1)
							{
								if ((theKnight.level == 10 && Excalibur == 1) || (DragonKnight == 1 && lionheart == 1))
								{
									++nWin;
									if (theKnight.level < 10)
									{
										theKnight.level = 10;
										if ((10 - levelbandau) * 100 + HPbandau <= 999)
										{
											if (maxHP >= (10 - levelbandau) * 100 + HPbandau)
												maxHP = (10 - levelbandau) * 100 + HPbandau;
										}
										else
										{
											if (maxHP >= 999)
												maxHP = 999;
										}
									}
									theKnight.gil = 999;
									OmegaWeapon = 0;
								}
								else
								{
									++nLose;
									if (mythril != 1)
									{
										theKnight.HP = 0;
										callPhoenix(theKnight, maxHP);
										poison = 0;
										countpoison = 0;
									}
								}
							}
						}
						if (number == 14)
						{
							if (numberNina > 0)
								--numberNina;
							if (numberOdin > 0)
								--numberOdin;
							if ((Lancelotspear == 1 && Guineverehair == 1 && Excalibur != 1) || (Authur == 1 && Guineverehair == 1) || (Lancelot == 1 && Guineverehair == 1) || (Guinevere == 1 && Lancelotspear == 1))
							{
								special2 = 1;
							}
							--nPetal;
							if (lionheart == 1)
								--countlionheart;
							if (Odin == 1 && DragonKnight != 1)
								Odin = -1;
							if (Odin == 1 && DragonKnight == 1)
								--countOdin;
							if (poison == 1)
								--countpoison;
							if (special2 == 1)
							{
								mythril = 1;
								++nWin;
							}
							if (special2 != 1)
							{
								if ((theKnight.level >= levelO) || (lionheart == 1) || (Odin == 1 && DragonKnight == 1))
								{
									mythril = 1;
									++nWin;
								}
								if ((theKnight.level < levelO) && (lionheart != 1) && (Odin != 1 || DragonKnight != 1))
								{
									++nLose;
									if (mythril != 1)
									{
										theKnight.HP = 0;
										callPhoenix(theKnight, maxHP);
										poison = 0;
										countpoison = 0;
									}
								}
							}
							if (special2 == 1)
								special2 = 0;
						}
						if (number == 15)
						{
							if (numberNina > 0)
								--numberNina;
							if (numberOdin > 0)
								--numberOdin;
							ScarletHakama = 1;
							--nPetal;
							if (lionheart == 1)
								--countlionheart;
							if (Odin == 1)
								--countOdin;
							if (poison == 1)
								--countpoison;
						}
						if (number == 16)
						{
							if (numberNina > 0)
								--numberNina;
							if (numberOdin > 0)
								--numberOdin;
							--nPetal;
							if (lionheart == 1)
								--countlionheart;
							if (Odin == 1)
								--countOdin;
							if (poison == 1)
								--countpoison;
							if (Lancelot != 1 && DragonKnight != 1)
							{
								if (theKnight.level <= ((j + 1) % 10))
								{
									break;
								}
							}
						}
						//end
						if (countlionheart == 0 && Paladin != 1)
							lionheart = 0;
						if (countpoison == 0)
							poison = 0;
						if (countOdin == 0 && Odin == 1)
							Odin = 0;
						if (Authur != 1)
						{
							if (nPetal == 0 && bFlag != 1)
							{
								bFlag = 0;
							}
						}
					}
				}
				a--;
			}
		}
	}
	pReturn = (bFlag) ? new report : NULL;
	if (Authur == 1 && nPetal < 0)
		nPetal = 0;
	if (pReturn != NULL)
	{
		pReturn->nLose = nLose;
		pReturn->nWin = nWin;
		pReturn->nPetal = nPetal;
	}
	return pReturn;
}