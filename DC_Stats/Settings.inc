[Variables]
@Include1 = #@#style.inc
SkinWidth = (#rightSize# * #scale#)
SkinHeight = (#areaH# * 0.208)
Settings = #CURRENTPATH#Settings.inc
InputSize = (16 * #scale#)
BarScale = 0
Box1X = 0
Box1Y = 0
Box2X =(#SkinWidth# * 0.5)
Box2Y = 0
Box3X = 0
Box3Y =  (#SkinHeight# * 0.5)
Box4X =  (#SkinWidth# * 0.5)
Box4Y =  (#SKinHeight# * 0.5)

left = 0
right = (#SkinWidth# * 0.5)
top = 0
bottom  = (#SkinHeight# * 0.5)

; BOX POSITIONS
WifiX = #left#
WifiY = #top#
SpeedX = #right#
SpeedY = #top#
GPUX = #right#
GPUY = #bottom#
CPUX = #left#
CPUY = #bottom#

;User input variables
tempLow =30
tempHigh =70
clrLow =0,0,180
clrMed =0,0,255
clrHgh =0,255,255

[Box]
Shape = Rectangle 0,0, #BoxW#, #BoxH# | Fill Color #bgColor# | StrokeWidth #stroke# | Stroke Color #olColor#

[Hist]
W=(#BoxW# - (#stroke#/2))
H=(#BoxH#*#GraphScale#)
GraphStart = Left
AntiAlias=1
AutoScale=!
Flip=0

[HistLine]
X=r
Y=r
W= (#BoxW# - (#stroke#/2))
H=(#BoxH#*#GraphScale#)
GraphStart = Left
LineWidth=1
LineColor = #clColor#
Antialias=1
AutoScale - 1
Flip=0