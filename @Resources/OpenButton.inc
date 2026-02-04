[Variables]
SkinWidth = (#leftSize# * 0.5 * #scale#)
SkinHeight = (#areaH# * 0.15)
TitleSize = (18 * #scale#)

[MeterBG]
Meter = Shape
MeterStyle = styleBG

[MeterBGHighlight]
Meter = Shape
MeterStyle = styleBGHighlight
DynamicVariables = 1

[MeterTitle]
Meter = String
MeterStyle = styleText
X = (#SkinWidth# / 2)
text = #Title#
FontSize = #TitleSize#
StringAlign = Center
DynamicVariables = 1

[MeterIcon]
Meter = Image
ImageName = Icon
X = (#SkinWidth# * 0.25)
Y = (#SkinHeight# * 0.35)
W = (#SkinWidth# * 0.5)
H = (#SkinHeight# * 0.6)
ImageTint = 150,150,150
DynamicVariables = 1
MouseOverAction =  [!SetOption MeterBGHighlight Hidden 0]
MouseLeaveAction = [!SetOption MeterBGHighlight Hidden 1]
LeftMouseDownAction = [!ToggleConfig #ROOTCONFIG#\#Skin# #Skin#.ini][!DeactivateConfig #ROOTCONFIG#\#Close# #Close#.ini]
