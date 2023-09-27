[Variables]

SkinWidth = (#midSize# * #scale#)
SkinHeight = (200 * #scale#)
LEFTSIDE 	= "29.4, 41.2, 14.7, 14.7"
RIGHTSIDE 	= "23.4, 12, 19.4, 4.6, 23.7, 14.7"

;Paths
ImgDir 		= #ROOTCONFIGPATH#\#Main#\Images
ListDir 		= #ROOTCONFIGPATH#\#Main#\List.inc
Settings = #CURRENTPATH#Settings.inc

;PLACEMENT
TitleHeight 	= 	(#SkinHeight# * 0.15)
IconWidth		=	(#SkinWidth#  * 0.25)
IconHeight	=	(#SkinHeight# * 0.85)

;SCROLLING
ScrollDivider	= 9.4
OffsetX		= 0
ScrollMultiplier=-0.96
ScrollLimit	= Min(#SkinWidth#, (#SkinWidth# + #IconWidth# * #Total# * -1))

BufferX = 75
BufferY = 15
BoxW = (#SkinWidth# * 0.25)
BoxH = (#SkinHeight#/3)

;Warning Message info
WBoxGap = 0.08
WBoxWidth = 0.25
WBoxY =  (#SkinHeight# * 0.7)
WBoxW = (#SkinWidth# * #WBoxWidth#)
WBoxH = (#SkinHeight# * 0.25)

[styleProgramIcon]
X=(([SmoothScroll]) + #IconWidth# * (#CURRENTSECTION#-1))
Y=#TitleHeight#
W=#IconWidth#
H=#IconHeight#
SolidColor=#bgColor#
PreserveAspectRatio=1
MouseOverAction  =	[!SetOption "#CURRENTSECTION#" "SolidColor" "#hlColor#"][!SetVariable Select #CURRENTSECTION#][!SetVariable LastSelect #CURRENTSECTION#]
MouseLeaveAction =	[!SetOption "#CURRENTSECTION#" "SolidColor" "#bgColor#"][!SetVariable Select "0"]
LeftMouseUpAction=	["[#dir[#CURRENTSECTION]]"][!DeactivateConfig #CURRENTCONFIG#]
ImageName="#ImgDir#\[#img[#CURRENTSECTION]]"
DynamicVariables=1
Group = Icons


[styleProgramBox]
Shape=Rectangle 0,0,#IconWidth#,#IconHeight#| Fill Color #bgColor#,0 | Stroke Color #olColor# | StrokeWidth #stroke#
X=r
Y=r
Group = Icons
