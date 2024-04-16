[Variables]
@Include1 = #@#style.inc
SkinWidth = (#rightSize# * #scale#)
SkinHeight = (127 * #scale#)
Settings = #CURRENTPATH#SettingsSmall.inc
InputSize = (17 * #scale#)

Row1 = (#SkinHeight# * 0.0)
;RowOffset is the space between each row:
RowOffset = (#SkinHeight# * 0.25)

TempX = (#SkinWidth# * 0.07)

BarX = (#SkinWidth# * 0.005)
BarY = (#SkinHeight# * 0.2)
BarW = (#SkinWidth# * 0.99)
BarH = (#SkinHeight# * 0.05)
 
FontSize = (17 * #scale#)
UsedX = (#SkinWidth# * 0.93)

disk1 = C:
disk2 =G:

index1 =2
index2 =0

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
UpdateDivider=-1
DynamicVariables=1

[MeasurePercentFree1]
Measure=Calc
Formula=( MeasureFree1 * 100 / ( MeasureTotal1 + 0.000001 ))
MinValue=0
MaxValue=100
UpdateDivider=-1
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


[styleInputSmall]
Text = [#[#CURRENTSECTION]]
FontSize = (#InputSize# * #scale#)
StringAlign = Center
LeftMouseUpAction=[!SetVariable "InputEdit" #CURRENTSECTION#][!SetVariable "InputVar" #CURRENTSECTION#][!CommandMeasure MeasureInputSmall "ExecuteBatch 1"]

[MeasureInputSmall]
Measure=Plugin
Plugin=InputText.dll
FontFace  = #font#
FontColor = #txColor#
FontSize = #InputSize#
X = ([#InputEdit#:X] + #stroke#)
Y = ([#InputEdit#:Y])
W = ([#InputEdit#:W] * 0.97)
H = ([#InputEdit#:H] * 0.97)
SolidColor = #bgColor#
;SolidColor = 0,160,0
ClipString = 1
AntiAlias = 1
StringAlign = Center
DynamicVariables = 1
FocusDismiss=1
Command1=!Execute [!WriteKeyValue Variables #InputVar# "$UserInput$" "SettingsSmall.inc"][!Refresh]
DefaultValue= [#[#InputVar]]
