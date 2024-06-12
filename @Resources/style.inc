[Variables]
scale 	=1

leftPercent = 27.5
midPercent = 45.0
rightPercent = 27.5

leftSize	= (#WORKAREAWIDTH# * (#leftPercent#/100))
midSize	= (#WORKAREAWIDTH# * (#midPercent#/100))
rightSize	= (#WORKAREAWIDTH# * (#rightPercent#/100))

areaH = (#WORKAREAHEIGHT# * #scale#)

;LEFTSIDE = "29.4, 41.2, 14.7, 14.7"
;RIGHTSIDE = "23.4, 12, 19.4, 4.6, 23.7, 14.7"

leftSide	= 0
rightSide = 1005	
maxHeight = 680 
font 	= Choco cooky
stroke 	= 3
openEdit = F9


;background color
	bgColor =0,0,0
;outline color
	olColor =150,150,150 	
;highlight color
	hlColor =0,4,255 		
;text color
	txColor =170,170,170
;click color
	clColor = 0,255,255
;white
	white = 255,255,255
;Clear
	clear = 255,255,255,0


[styleBG]
Shape = Rectangle 0,0,#CURRENTCONFIGWIDTH#,#CURRENTCONFIGHEIGHT# | Fill Color #bgColor# | StrokeWidth #stroke# | Stroke Color #olColor#

[styleBG2]
Shape = Rectangle 0,0,#SkinWidth#,#SkinHeight# | Fill Color #bgColor# | StrokeWidth #stroke# | Stroke Color #olColor#

[styleBGHighlight]
Shape = Rectangle 0,0,#CURRENTCONFIGWIDTH#,#CURRENTCONFIGHEIGHT# | Fill Color #bgColor# | StrokeWidth #stroke# | Stroke Color #hlColor#
Hidden = 1

;This meter does NOT work, it is only used for copying and pasting
[styleBox]
Meter = Shape
Shape = Rectangle X,Y,W,H | Fill Color #bgColor# | StrokeWidth #stroke# | Stroke Color #olColor#


[styleText]
FontSize = (22 * #scale#)
FontFace= #font#
FontColor = #txColor#
AntiAlias= 1

[styleButtonLabel]
Meter = string
FontFace=#font#
FontSize=15
StringStyle=Normal
AntiAlias=1
FontColor= #txColor#
StringAlign = Center

[styleInput]
Text = [#[#CURRENTSECTION]]
FontSize = (#InputSize# * #scale#)
StringAlign = Center
LeftMouseUpAction=[!SetVariable "InputEdit" #CURRENTSECTION#][!SetVariable "InputVar" #CURRENTSECTION#][!CommandMeasure MeasureInput "ExecuteBatch 1"]

[MeasureInput]
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
Command1=!Execute [!WriteKeyValue Variables #InputVar# "$UserInput$" "Settings.inc"][!Refresh]
DefaultValue= [#[#InputVar]]

[textHighlight]
MouseOverAction  =[!SetOption #CURRENTSECTION# FontColor #hlColor#]
MouseLeaveAction =[!SetOption #CURRENTSECTION# FontColor #txColor#]
DynamicVariables = 1

[imageHighlight]
MouseOverAction = [!SetOption #CURRENTSECTION# ImageTint #hlColor#]
MouseLeaveAction = [!SetOption #CURRENTSECTION# ImageTint #white#]

[MeasureConfig]
Measure = String
String = #CURRENTCONFIG#
RegExpSubstitute=1
Substitute="DarkClaws\\":""

[CloseSettings]
FontSize=20
FontWeight = 700
StringAlign=Right
Text = "X"
LeftMouseUpAction= [!ActivateConfig #CURRENTCONFIG# "[MeasureConfig].ini"]
DynamicVariables=1

[Settings]
W=(#SkinWidth# * 0.05)
ImageTint = #txColor#
ImageName=#@#/Icons/Settings
LeftMouseDownAction = [!SetOption #CURRENTSECTION# ImageTint #clColor#]
LeftMouseUpAction=!Execute  [!ActivateConfig "#CURRENTCONFIG#" "Editor.ini"]
MouseOverAction =  [!SetOption #CURRENTSECTION# ImageTint #hlColor#]
MouseLeaveAction = [!SetOption #CURRENTSECTION# ImageTint #txColor#]
PreserveAspectRatio = 1

[Bordered]
FontColor = #bgColor#
StringEffect = Border
FontEffectColor = #white#
FontWeight =950
LeftMouseDownAction = [!SetOption #CURRENTSECTION# FontColor #clColor#]
MouseOverAction  =[!SetOption #CURRENTSECTION# FontColor #hlColor#]
MouseLeaveAction =[!SetOption #CURRENTSECTION# FontColor #bgColor#]
LeftMouseUpAction =[!SetOption #CURRENTSECTION# FontColor #bgColor#]


[StyleWhiteText]
FontColor=#SolidWhite#

[StyleBlackText]
FontColor=#SolidBlack#

[StyleErrorText]
FontColor=#SolidRed#

[StyleWindowsColorText]
FontColor=#WindowsColorText#
Group=WindowsTextColorGroup

[StyleLeftAlign]
StringAlign=Left

[StyleRightAlign]
StringAlign=Right

[StyleCenterAlign]
StringAlign=Center

[StyleBigText]
H=100
AntiAlias=1
FontFace=Segoe UI Light
FontSize=50
FontColor=#SolidWhite#
StringAlign=Left
ClipString=1

[StyleVolumeBarSense]
X=0R
Y=0r
W=2
H=#BackgroundHeight#
Hidden=1
SolidColor=#Transparent#
Group=Sense
UpdateDivider=-1


[StyleHDOff]
X=1R
Y=0r
W=22
H=22
Hidden=1
SolidColor=#TransparentWhite3#
AntiAlias=1
Group=HDSelect
FontFace=Segoe UI
FontSize=12
FontColor=#TransparentWhite3#
StringAlign=Center
ClipString=1
UpdateDivider=-1

;=======================================
; NumberMeasures
;=======================================
[Tlest]
Measure = Calc
Formula = 120