[Rainmeter]
Update=1000
SkinWidth = #SkinWidth#
SkinHeight = #SkinHeight#
RightMouseUpAction = [!SkinCustomMenu]
ContextTitle = Refresh
ContextAction = [!Refresh]
ContextTitle2=More Actions...
ContextAction2=[!SkinMenu]
ContextTitle3=---
ContextAction3=[]
ContextTitle4 = ---
ContextAction4 = []
;ContextTitle4= Making a New Skin
;ContextAction4 = [!ActivateConfig "DarkClaws\Notes" "EX_MakeNewSkin.ini"]
ContextTitle5= Hide and Show Meters
ContextAction5 = [!ActivateConfig "DarkClaws\Notes" "EX_HideShow.ini"]
ContextTitle6= Mouse Actions
ContextAction6 = [!ActivateConfig "DarkClaws\Notes" "EX_MouseActions.ini"]
ContextTitle7= Variables
ContextAction7 = [!ActivateConfig "DarkClaws\Notes" "EX_Variables.ini"]
ContextTitle8= to type down for information incase or something
ContextAction8 = [!ActivateConfig "DarkClaws\Notes" "EX_Notes_Meters.ini"]
ContextTitle9= Changing Meters
ContextAction9 = [!ActivateConfig "DarkClaws\Notes" "EX_ChangingMeters.ini"]


[Variables]
SkinWidth = (#WORKAREAWIDTH# * 0.45)
SkinHeight = (#WORKAREAHEIGHT#)
stroke 	= 3
font 	= Choco cooky
center = (#CURRENTCONFIGWIDTH# * 0.5)
	
;Background color
	bgColor = 0,0,100
;Outline color
	olColor =150,150,150 
;text color
	txColor =170,170,170
;highlight color
	hlColor =0,4,255 
;important color
	imColor =255,255,255 
;copy color
	cpColor =0,255,255
;click color
	clColor = 0,180,255
	
[MeterBG]
Meter = Shape
Shape = Rectangle 0,0,#CURRENTCONFIGWIDTH#,#CURRENTCONFIGHEIGHT# | Fill Color #bgColor# | StrokeWidth #stroke# | Stroke Color #olColor#

[MeterTitle]
Meter = String
MeterStyle = styleText | center
Text = #Title#
FontColor = #white#

[MeterCloseInside]
Meter = Image
ImageName = "#@#X Inside.png"
ImageTint = #bgColor#
X = (#SkinWidth# * 0.91)
Y = (#SkinHeight# * 0.01)
W = (#SkinWidth# * 0.07)
H = (#SkinHeight# * 0.05)
DynamicVariables = 1

[MeterCloseOutline]
Meter = Image
ImageName = "#@#X Outline.png"
ImageTint = #olColor#
X = r
Y = r
W = (#SkinWidth# * 0.07)
H = (#SkinHeight# * 0.05)
MouseOverAction=[!SetOption MeterCloseInside ImageTint #hlColor#]
MouseLeaveAction=[!SetOption MeterCloseInside ImageTint #bgColor#]
LeftMouseDownAction = [!SetOption MeterCloseInside ImageTint #clColor#]
LeftMouseUpAction= [!DeactivateConfig #CURRENTCONFIG#]
DynamicVariables = 1


[styleText]
FontSize = 22
FontFace= #font#
FontColor = #txColor#
AntiAlias= 1

[highlight]
FontColor = #clColor#
MouseOverAction  =[!SetOption #CURRENTSECTION# FontColor #hlColor#]
MouseLeaveAction =[!SetOption #CURRENTSECTION# FontColor #clColor#]
DynamicVariables = 1

[center]
X = (#CURRENTCONFIGWIDTH# * 0.5)
StringAlign = Center

;Click on this meter to copy its text
[CopyClick]
Text = #CURRENTSECTION#
FontColor = #cpColor#
LeftMouseDownAction = [!SetClip #CURRENTSECTION#]
MouseOverAction = [!SetOption #CURRENTSECTION# FontColor #hlColor#]
MouseLeaveAction = [!SetOption #CURRENTSECTION# FontColor #cpColor#]

;Click on this meter to copy a variable with the same name
[CopyClickVar]
FontColor = #cpColor#
LeftMouseDownAction = [!SetClip [#[#CURRENTSECTION]]]
MouseOverAction = [!SetOption #CURRENTSECTION# FontColor #hlColor#]
MouseLeaveAction = [!SetOption #CURRENTSECTION# FontColor #cpColor#]