[Variables]
@include = #@#style.inc
SkinWidth = (#rightSize# * #scale#)
SkinHeight = (32 * #scale#)
ToggleKey =F4
ScrollSpeed =10
InputSize = (17 * #scale#)
Settings = #CURRENTPATH#Settings.inc

barStartX =(#SkinWidth# * 0.25)
barX = (#SkinWidth# * 0.019)
barY = (#SkinHeight# * 0.15)
barW = (#SkinWidth# * 0.01)
barH = (#SkinHeight# * 0.7)

[styleVolumeLineBG]
X = #barX#r
Shape = Rectangle 0,#barY#,#barW#,#barH# | Extend MyColor
MyColor = Fill Color #hlColor#

[styleVolumeLine]
X = #barX#r
Shape = Rectangle 0,#barY#,#barW#,#barH# | Extend MyColor
MyColor = Fill Color #txColor#
Hidden = (#CURRENTSECTION# > ([MeasureVolume]))
DynamicVariables = 1