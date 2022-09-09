[Variables]
@include = #@#style.inc
SkinWidth = (#midsize# * #scale#)
SkinHeight = (480 * #scale#)

;Size of any input text
InputSize = 20
Size = 85
labelX = (#SkinWidth# * 0.05)
startY = (#SkinHeight# * 0.02)
lineYBuffer = (0.09)
boxX = (#SkinWidth# * 0.465)
boxW = (#SkinWidth# * 0.400)
boxH = (#SkinHeight# * 0.08)
inputX = (#SkinWidth# * 0.660)
clrBoxX = (#SkinWidth# * 0.88)
clrBoxW = (#SkinWidth# * 0.1)

[styleLabel]
X = #labelX#
Y = (#lineYBuffer# * #SkinHeight#)r
Text = #CURRENTSECTION#
Group = Editor
Hidden = 1
 
[styleInputText]
X = #inputX#
Y = r
W = #boxW#
Group = Editor
Hidden = 1

[styleInputBox]
X = #boxX#
Y = r
Shape = Rectangle 0,0,#boxW#,#boxH# | Fill Color #bgColor# | StrokeWidth #stroke# | Stroke Color #olColor#
Group = Editor
Hidden = 1

[styleColorBox]
X = #clrBoxX#
Y = r
Group = Editor
Hidden = 1