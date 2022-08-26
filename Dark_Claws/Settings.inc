[Variables]
@include = #@#style.inc
SkinWidth = (#midsize# * #scale#)
SkinHeight = (480 * #scale#)

;Size of any input text
InputSize = 20
Size = 1
labelX = (#SkinWidth# * 0.05)
startY = (#SkinHeight# * 0.02)
lineYBuffer = (0.09)
boxX = (#SkinWidth# * 0.425)
boxW = (#SkinWidth# * 0.3)
boxH = (#SkinHeight# * 0.08)
inputX = (#SkinWidth# * 0.573)
clrBoxX = (#SkinWidth# * 0.76)
clrBoxW = (#SkinWidth# * 0.2)

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