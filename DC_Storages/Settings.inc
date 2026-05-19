[Variables]
@Include1 = #@#style.inc
SkinWidth = (#rightSize# * #scale#)
SkinHeight = (127 * #scale#)
Settings = #CURRENTPATH#Settings.inc
InputSize = (17 * #scale#)

TempX = (#SkinWidth# * 0.07)

BarX = (#SkinWidth# * 0.005)
BarY = (#SkinHeight# * 0.2)
BarW = (#SkinWidth# * 0.9)
BarH = (#SkinHeight# * 0.05) 
 
UsedX = (#SkinWidth# * 0.93)
driveNum =1

disk1 =C:
disk2 =D:
disk3 =E:
disk4 =F:

index1 =1
index2 =2
index3 =3
index4 =4
FeedNum=[NextFeed]

hwInfo = C:\Program Files\HWiNFO64\HWiNFO64.EXE

color25 = 0,0,180
color50 = #hlColor#
color75 = 0,185,185

[driveBar]
X = #BarX#
Y = #BarY#r
W = #BarW#
H = #BarH# 
BarColor = #color25#
SolidColor = #bgColor#
BarOrientation = Horizontal
DynamicVariables = 1

[storage]
AutoScale = 1
NumOfDecimals = 0
Text= %1B

[MeterBG]
Meter = Shape
MeterStyle = styleBG

[drive1]
Hidden = ([MeasureUsed1] = 0)

[drive2]
Hidden = ([MeasureUsed2] = 0)

[drive3]
Hidden = ([MeasureUsed3] = 0)

[drive4]
Hidden = ([MeasureUsed4] = 0)

;==================================================
[MeasureTemp1]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey = SOFTWARE\HWiNFO64\VSB
RegValue = Value#index1#
Substitute="C":"c"

[MeasureUsed1]
Measure=FreeDiskSpace
Drive=#disk1#
InvertMeasure = 1
IgnoreRemovable=0

[MeasureFree1]
Measure=FreeDiskSpace
Drive=#disk1#
IgnoreRemovable=0

[MeasureTotal1]
Measure=FreeDiskSpace
Drive=#disk1#
Total=1
IgnoreRemovable=0

[MeasurePercentUsed1]
Measure=Calc
Formula=( MeasureUsed1 * 100 / ( MeasureTotal1 + 0.000001 ))
MinValue=0
MaxValue=100
UpdateDivider=60
DynamicVariables=1

[MeasurePercentFree1]
Measure=Calc
Formula=( MeasureFree1 * 100 / ( MeasureTotal1 + 0.000001 ))
MinValue=0
MaxValue=100
UpdateDivider=60
DynamicVariables=1

;==================================================
[MeasureTemp2]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey = SOFTWARE\HWiNFO64\VSB
RegValue = Value#index2#
Substitute="C":"c"

[MeasureUsed2]
Measure=FreeDiskSpace
Drive=#disk2#
InvertMeasure = 1
IgnoreRemovable=0

[MeasureFree2]
Measure=FreeDiskSpace
Drive=#disk2#
IgnoreRemovable=0

[MeasureTotal2]
Measure=FreeDiskSpace
Drive=#disk2#
Total=1
IgnoreRemovable=0

[MeasurePercentUsed2]
Measure=Calc
Formula=( MeasureUsed2 * 100 / ( MeasureTotal2 + 0.000001 ))
MinValue=0
MaxValue=100
UpdateDivider=-1
DynamicVariables=1

[MeasurePercentFree2]
Measure=Calc
Formula=( MeasureFree2 * 100 / ( MeasureTotal2 + 0.000001 ))
MinValue=0
MaxValue=100
UpdateDivider=-1
DynamicVariables=1

;==================================================
[MeasureTemp3]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey = SOFTWARE\HWiNFO64\VSB
RegValue = Value#index3#
Substitute="C":"c"

[MeasureUsed3]
Measure=FreeDiskSpace
Drive=#disk3#
InvertMeasure = 1
IgnoreRemovable=0

[MeasureFree3]
Measure=FreeDiskSpace
Drive=#disk3#
IgnoreRemovable=0

[MeasureTotal3]
Measure=FreeDiskSpace
Drive=#disk3#
Total=1
IgnoreRemovable=0

[MeasurePercentUsed3]
Measure=Calc
Formula=( MeasureUsed3 * 100 / ( MeasureTotal3 + 0.000001 ))
MinValue=0
MaxValue=100
UpdateDivider=-1
DynamicVariables=1

[MeasurePercentFree3]
Measure=Calc
Formula=( MeasureFree3 * 100 / ( MeasureTotal3 + 0.000001 ))
MinValue=0
MaxValue=100
UpdateDivider=-1
DynamicVariables=1

;==================================================
[MeasureTemp4]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey = SOFTWARE\HWiNFO64\VSB
RegValue = Value#index4#

[MeasureUsed4]
Measure=FreeDiskSpace
Drive=#disk4#
InvertMeasure = 1
IgnoreRemovable=0

[MeasureFree4]
Measure=FreeDiskSpace
Drive=#disk4#
IgnoreRemovable=0

[MeasureTotal4]
Measure=FreeDiskSpace
Drive=#disk4#
Total=1
IgnoreRemovable=0

[MeasurePercentUsed4]
Measure=Calc
Formula=( MeasureUsed4 * 100 / ( MeasureTotal4 + 0.000001 ))
MinValue=0
MaxValue=100
UpdateDivider=-1
DynamicVariables=1

[MeasurePercentFree4]
Measure=Calc
Formula=( MeasureFree4 * 100 / ( MeasureTotal4 + 0.000001 ))
MinValue=0
MaxValue=100
UpdateDivider=-1
DynamicVariables=1

;=============================
;	SET BAR COLORS
;=============================
[SetBarColor1]
Measure=Calc
IfCondition= MeasurePercentUsed1 < 50
IfTrueAction=[!SetOption MeterBarUsed1 BarColor #color25#][!Redraw]
IfCondition2=MeasurePercentUsed1 >= 50
IfTrueAction2=[!SetOption MeterBarUsed1 BarColor #color50#][!Redraw]
IfCondition3= MeasurePercentUsed1 >= 75
IfTrueAction3=[!SetOption MeterBarUsed1 BarColor #color75#][!Redraw]

[SetBarColor2]
Measure=Calc
IfCondition= MeasurePercentUsed2 < 50
IfTrueAction=[!SetOption MeterBarUsed2 BarColor #color25#][!Redraw]
IfCondition2=MeasurePercentUsed2 >= 50
IfTrueAction2=[!SetOption MeterBarUsed2 BarColor #color50#][!Redraw]
IfCondition3= MeasurePercentUsed2 >= 75
IfTrueAction3=[!SetOption MeterBarUsed2 BarColor #color75#][!Redraw]

[SetBarColor3]
Measure=Calc
IfCondition= MeasurePercentUsed3 < 50
IfTrueAction=[!SetOption MeterBarUsed3 BarColor #color25#][!Redraw]
IfCondition2=MeasurePercentUsed3 >= 50
IfTrueAction2=[!SetOption MeterBarUsed3 BarColor #color50#][!Redraw]
IfCondition3= MeasurePercentUsed3 >= 75
IfTrueAction3=[!SetOption MeterBarUsed3 BarColor #color75#][!Redraw]

[SetBarColor4]
Measure=Calc
IfCondition= MeasurePercentUsed4 < 50
IfTrueAction=[!SetOption MeterBarUsed4 BarColor #color25#][!Redraw]
IfCondition2=MeasurePercentUsed4 >= 50
IfTrueAction2=[!SetOption MeterBarUsed4 BarColor #color50#][!Redraw]
IfCondition3= MeasurePercentUsed4 >= 75
IfTrueAction3=[!SetOption MeterBarUsed4 BarColor #color75#][!Redraw]

;=============================
;	SKIN CHANGE BUTTONS
;=============================
[BoxButton]
Text=c
X = (#SkinWidth# * 0.99)
Y = (#SkinHeight# * 0.2)r
FontFace=Webdings
FontSize=(10 * #scale#)
FontColor=#white#
StringAlign = Right
AntiAlias=1
MouseOverAction = [!SetOption #CURRENTSECTION# FontColor #hlColor#][!Redraw]
MouseLeaveAction = [!SetOption #CURRENTSECTION# FontColor #white#][!Redraw]

[MeterButton1]
Meter=String
MeterStyle = BoxButton | ScrollButton
Y = (#SkinHeight# * 0.2)
LeftMouseDownAction =  [!WriteKeyValue Variables driveNum 1 Settings.inc][!ActivateConfig "#CURRENTCONFIG#" "DC_Storages1.ini"]

[MeterButton2]
Meter=String
MeterStyle = BoxButton | ScrollButton
LeftMouseDownAction =  [!WriteKeyValue Variables driveNum 2 Settings.inc][!ActivateConfig "#CURRENTCONFIG#" "DC_Storages2.ini"]

[MeterButton3]
Meter=String
MeterStyle = BoxButton | ScrollButton
LeftMouseDownAction =  [!WriteKeyValue Variables driveNum 3 Settings.inc][!ActivateConfig "#CURRENTCONFIG#" "DC_Storages3.ini"]

[MeterButton4]
Meter=String
MeterStyle = BoxButton | ScrollButton 
LeftMouseDownAction =  [!WriteKeyValue Variables driveNum 4 Settings.inc][!ActivateConfig "#CURRENTCONFIG#" "DC_Storages4.ini"]

[MeterCurrentButton]
Meter = String
Text=g
X = r
Y = ((#SkinHeight# * 0.2) + (#SkinHeight# * 0.2) * (#drives# - 1))
FontFace=Webdings
FontSize=(10.2 * #scale#)
StringAlign = Right
FontColor=#hlColor#
