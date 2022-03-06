#include <LiquidCrystal.h> 
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
const int S1E=A8;	////////////////L1 
const int S2E=A9;	////////////////L2 
const int S3E=A10;////////////////L3 
const int S4E=A11;////////////////L4

int S11E=0; int S12E=0; int S13E=0; int S14E=0;

int S1Ealert=1; int S2Ealert=1; int S3Ealert=1; int S4Ealert=1;


const	int	L1G=16;	////////////////L1-GREEN
const	int	L1O=15;	////////////////L1-ORANGE
const	int	L1R=14;	////////////////L1-RED

const	int	L2G=17;	////////////////L2-GREEN
const	int	L2O=18;	////////////////L2-ORANGE
const	int	L2R=19;	////////////////L2-RED

const	int	L3G=8;	////////////////L3-GREEN
const	int	L3O=9;	////////////////L3-ORANGE
const	int	L3R=10;	////////////////L3-RED

const	int	L4G=11;	////////////////L4-GREEN
const	int	L4O=12;	////////////////L4-ORANGE
const	int	L4R=13;	////////////////L4-RED
int aa=0; void setup()
{
lcd.begin(16, 2);


pinMode(S1E, INPUT); pinMode(S2E, INPUT); pinMode(S3E, INPUT); pinMode(S4E, INPUT);

pinMode(L1G, OUTPUT); pinMode(L1O, OUTPUT); pinMode(L1R, OUTPUT);

pinMode(L2G, OUTPUT); pinMode(L2O, OUTPUT); pinMode(L2R, OUTPUT);

pinMode(L3G, OUTPUT); pinMode(L3O, OUTPUT); pinMode(L3R, OUTPUT);

pinMode(L4G, OUTPUT); pinMode(L4O, OUTPUT); pinMode(L4R, OUTPUT);

lcd.clear(); lcd.setCursor(0,0); lcd.print("TRAFFIC LIGHT "); lcd.setCursor(0,1); lcd.print(" CONTROL DURING");
 
digitalWrite(L1G, LOW); digitalWrite(L1O, LOW); digitalWrite(L1R, LOW); delay(1000); digitalWrite(L1G, HIGH); digitalWrite(L1O, HIGH); digitalWrite(L1R, HIGH); delay(1000);

digitalWrite(L2G,LOW); digitalWrite(L2O,LOW); digitalWrite(L2R,LOW); delay(1000); digitalWrite(L2G, HIGH); digitalWrite(L2O, HIGH); digitalWrite(L2R, HIGH); delay(1000);

digitalWrite(L3G, LOW); digitalWrite(L3O, LOW); digitalWrite(L3R, LOW); delay(1000);

digitalWrite(L3G, HIGH); digitalWrite(L3O, HIGH); digitalWrite(L3R, HIGH); delay(1000);

digitalWrite(L4G, LOW); digitalWrite(L4O, LOW); digitalWrite(L4R, LOW); delay(1000);
 


digitalWrite(L4G, HIGH); digitalWrite(L4O, HIGH); digitalWrite(L4R, HIGH); delay(1000);

lcd.clear(); lcd.setCursor(0,0); lcd.print("EMERGENCY"); lcd.setCursor(0,1); lcd.print(" VEHICLE PASSING");
delay(3000); lcd.clear(); digitalWrite(L1G, HIGH); digitalWrite(L1O, HIGH); digitalWrite(L1R, HIGH); delay(100);

digitalWrite(L2G, HIGH); digitalWrite(L2O, HIGH); digitalWrite(L2R, HIGH); delay(100);

digitalWrite(L3G, HIGH)
;digitalWrite(L3O, HIGH); digitalWrite(L3R, HIGH); delay(100);

digitalWrite(L4G, HIGH); digitalWrite(L4O, HIGH); digitalWrite(L4R, HIGH);
 
delay(100);


}
void loop()
{
if(aa==0)
{
/// FIRST LANE
digitalWrite(L1R, HIGH); digitalWrite(L1G, LOW); digitalWrite(L2R, LOW); digitalWrite(L3R, LOW); digitalWrite(L4R, LOW); delay(1000);

digitalWrite(L1G, HIGH); digitalWrite(L1O, LOW); delay(500);

digitalWrite(L1O, HIGH); digitalWrite(L1R, LOW);

/// second LANE
digitalWrite(L2R, HIGH); digitalWrite(L2G, LOW); digitalWrite(L1R, LOW); digitalWrite(L3R, LOW);

 digitalWrite(L4R, LOW);delay(1000); digitalWrite(L2G, HIGH); digitalWrite(L2O, LOW);delay(500); digitalWrite(L2O, HIGH); digitalWrite(L2R, LOW);
 
/// third LANE
digitalWrite(L3R, HIGH); digitalWrite(L3G, LOW); digitalWrite(L2R, LOW); digitalWrite(L1R, LOW); digitalWrite(L4R, LOW); delay(1000); digitalWrite(L3G, HIGH); digitalWrite(L3O, LOW); delay(500); digitalWrite(L3O, HIGH); digitalWrite(L3R, LOW);

/// Fourth LANE 
digitalWrite(L4R, HIGH); digitalWrite(L4G, LOW); digitalWrite(L2R, LOW); digitalWrite(L3R, LOW);
digitalWrite(L1R, LOW);delay(1000); digitalWrite(L4G, HIGH); digitalWrite(L4O, LOW); delay(500);
digitalWrite(L4O, HIGH); digitalWrite(L4R, LOW);
}
cheking ambulance

S1Ealert = digitalRead(S1E);
if (S1Ealert == LOW){S11E=0;}else{S11E=1;}
S2Ealert = digitalRead(S2E);
if (S2Ealert == LOW){S12E=0;}else{S12E=1;}
S3Ealert = digitalRead(S3E);
 
if (S3Ealert == LOW){S13E=0;}else{S13E=1;}
S4Ealert = digitalRead(S4E);
if (S4Ealert == LOW){S14E=0;}else{S14E=1;}


NORMAL
NO AMBULANCE
if((S11E==1) & (S12E==1)	& (S13E==1) & (S14E==1))
{lcd.setCursor(0,0);lcd.print("NORMAL	");aa=0;} AMBULANCE
COMING AT FIRST LANE
if((S11E==0) & (S12E==1)	& (S13E==1) & (S14E==1))
{aa=1; lcd.setCursor(0,0);
lcd.print("FIRST LANE	"); digitalWrite(L1R, HIGH); digitalWrite(L1G, LOW); digitalWrite(L2R, LOW); digitalWrite(L3R, LOW); digitalWrite(L4R, LOW); delay(1000); digitalWrite(L1G, HIGH);
}
///AMBULANCE COMING AT SECOND LANE
if((S11E==1) & (S12E==0)	& (S13E==1) & (S14E==1))
{aa=1;
lcd.setCursor(0,0);lcd.print("SECOND LANE	"); digitalWrite(L2R, HIGH);
digitalWrite(L2G, LOW); digitalWrite(L1R, LOW); digitalWrite(L3R, LOW); digitalWrite(L4R, LOW);
 
delay(1000);digitalWrite(L2G, HIGH);
}
///AMBULANCE COMING AT THIRD LANE
if((S11E==1) & (S12E==1)	& (S13E==0) & (S14E==1))
{aa=1;
lcd.setCursor(0,0);lcd.print("THIRD LANE	"); digitalWrite(L3R, HIGH);
digitalWrite(L3G, LOW);digitalWrite(L2R, LOW); digitalWrite(L1R, LOW);digitalWrite(L4R, LOW); delay(1000);digitalWrite(L3G, HIGH);
}
///AMBULANCE COMING AT FOURTH LANE
if((S11E==1) & (S12E==1)	& (S13E==1) & (S14E==0))
{aa=1; lcd.setCursor(0,0);
lcd.print("FOURTH LANE	"); digitalWrite(L4R, HIGH); digitalWrite(L4G, LOW); digitalWrite(L2R, LOW); digitalWrite(L3R, LOW); digitalWrite(L1R, LOW); delay(1000); digitalWrite(L4G, HIGH);
}
///AMBULANCE COMING AT 2 - 3 LINE LANE if((S11E==1) & (S12E==0)	& (S13E==0) & (S14E==1))
{aa=1;
lcd.setCursor(0,0);lcd.print("2-3 LANE	"); digitalWrite(L2R, HIGH);
digitalWrite(L2G, LOW); digitalWrite(L4R, LOW); digitalWrite(L3R, HIGH);
 
digitalWrite(L3G, LOW); digitalWrite(L1R, LOW); delay(1000);digitalWrite(L2G, HIGH); digitalWrite(L3G, HIGH);
}
}
