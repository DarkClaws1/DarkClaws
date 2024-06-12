[Variables]
@Include1 = #@#style.inc
SkinWidth = (#rightSize# * #scale#)
SkinHeight = (#areaH# * 0.208) 
InputSize = (15 * #scale#)
Settings = #CURRENTPATH#Settings.inc
Player=Media Monkey
showBars =0
fftSize=2048
fftAttack=100
fftDecay=60
buttonsY = (#SkinHeight# * 0.65)
buttonsH =(#SkinHeight# * 0.35) 
folderW = (#SkinWidth# * 0.07)
folderH = (#SkinHeight# * 0.1)
rate =25
slow = 25
fast = 16

;barX, where the bars start
bX = (#SkinWidth# * 0.01)

;barT, topmost part of the bars
bT = (#SkinHeight# * 0.19)

;barHeight, the max height of a bar
bH = (#SkinHeight# * 0.51)

;barY, the Y of the BOTTOM of the bars
bY = (#bT# + #bH#)

;all Bars Width, how wide the entire visiualizer is
abW = (#SkinWidth# - (#bX#*2))

;barW, how wide each bar is
bW = ((#aBW# / 20) * 0.8)

;barGap, the space between each bar
bG = ((#abW# / 20) - #bW#)



FolderPath = "D:\Music"
MusicX = 0
MusicHeight = 0

;music bar
[mBar]
MeasureName = Test1
Shape = Line 0, #bY#, 0, (#bY# - (#bH# * [B#CURRENTSECTION#])) | Extend O
O = Fill Color #hlColor# | StrokeWidth #bW# | StrokeColor #hlColor#
X = (#bG# + #bW#)r
DynamicVariables = 1
Hidden = (#showBars# = 0 ? 1 : 0)

