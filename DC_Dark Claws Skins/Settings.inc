[Variables]
@Include1 = #@#style.inc
SkinWidth = (#scale# * #midSize#)
SkinHeight = (#areaH# *  1)
InputSize = (15 * #scale#)
Settings = #CURRENTPATH#Settings.inc
gapY = (#SkinHeight# * 0.1)
min = -345
max = 0
topY =0
scrollSpeed = 20

[styleSkinButton]
X = (#SkinWidth# * 0.5)
Y = #gapY#r
StringAlign = Center
FontSize= 50 * #scale#
Text = #CURRENTSECTION#
DynamicVariables= 1
LeftMouseUpAction = [!ToggleConfig "DarkClaws\DC_#CURRENTSECTION#" "DC_#CURRENTSECTION#.ini"]
