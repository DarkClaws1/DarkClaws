[Variables]
@Include1 = #@#style.inc
SkinWidth = (#rightSize# * #scale#)
SkinHeight = (127 * #scale#)
Settings = #CURRENTPATH#Settings.inc
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
disk2 = D:
disk3 = X:
disk4 =J:

index1 =3
index2 = 1
index3 = 2
index4 =0

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
