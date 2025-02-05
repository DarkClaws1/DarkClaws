[Variables]
folderW = (#SkinWidth# * 0.07)
folderH = (#SkinHeight# * 0.1)



;The background needs to be in this skin 
; or the layering gets effected
[Background]
Meter = Shape
MeterStyle = styleBG

;------------------------------------------------
;	White Outlines
;------------------------------------------------

[MeterBoxL]
Meter=Shape
Shape =Rectangle 0,(#BoxH# * 0),#BoxW#,#BoxH# | Fill Color #bgColor# | Stroke Color #olColor#
Shape2=Rectangle 0,(#BoxH# * 1),#BoxW#,#BoxH# | Fill Color #bgColor# | Stroke Color #olColor#
Shape3=Rectangle 0,(#BoxH# * 2),#BoxW#,#BoxH# | Fill Color #bgColor# | Stroke Color #olColor#

[MeterBoxC]
Meter = Shape
Shape =Rectangle (#SkinWidth#/4),0,(#SkinWidth#/2),#BoxH# | Fill Color #bgColor#| Stroke Color #olColor#

[MeterBoxR]
Meter = Shape
Shape =Rectangle (#SkinWidth# * 0.75),(#BoxH# * 0),#BoxW#,#BoxH# | Fill Color #bgColor# | Stroke Color #olColor#
Shape2=Rectangle (#SkinWidth# * 0.75),(#BoxH# * 1),#BoxW#,#BoxH# | Fill Color #bgColor# | Stroke Color #olColor#
Shape3=Rectangle (#SkinWidth# * 0.75),(#BoxH# * 2),#BoxW#,#BoxH# | Fill Color #bgColor# | Stroke Color #olColor#


;------------------------------------------------
;	HIGHLIGHTS WHICH SETTING WE ARE ON
;------------------------------------------------
[MeterHighlight1]
Meter=Shape
Shape =Rectangle 0,(#BoxH# * (#Current#-1)),#BoxW#,#BoxH# | Fill Color #hlColor#,100 | Stroke Color #olColor#

;------------------------------------------------
;	CENTER
;------------------------------------------------
[MeterHeader]
Meter=String
MeterStyle = styleText
X=(#SkinWidth#/2)
Y=17
StringAlign = Center
Text=#Header##Editing#

;------------------------------------------------
;	LEFT SIDE
;------------------------------------------------
[Button_Name]
Meter=String
MeterStyle=styleText | textHighlight
X=#BufferX#
Y=(#BoxH# * 0 + #BufferY#)
Text="Name"
StringAlign = Center
LeftMouseUpAction=!Execute [!ActivateConfig "#CURRENTCONFIG#" "Editor_Name.ini"]

[Button_Directory]
Meter=String
MeterStyle=styleText | textHighlight
X=r
Y=(#BoxH# * 1 + #BufferY#)
Text="Directory"
StringAlign = Center
LeftMouseUpAction=!Execute [!ActivateConfig "#CURRENTCONFIG#" "Editor_Directory.ini"]

[Button_Icon]
Meter=String
MeterStyle=styleText | textHighlight
X=r
Y=(#BoxH# * 2 + #BufferY#)
Text="Icon"
StringAlign = Center
LeftMouseUpAction=!Execute [!ActivateConfig "#CURRENTCONFIG#" "Editor_Icon.ini"]

;------------------------------------------------
;	RIGHT SIDE
;------------------------------------------------
[MeterCloseInside]
Meter = Image
ImageName = "#@#X Inside.png"
ImageTint = #bgColor#
X = (#SkinWidth# * 0.83)
Y = (#SkinHeight# * 0.03)
W = (#SkinWidth# * 0.10)
H = (#SkinHeight# * 0.25)
DynamicVariables = 1

[MeterCloseOutline]
Meter = Image
ImageName = "#@#X Outline.png"
ImageTint = #olColor#
X = r
Y = r
W = (#SkinWidth# * 0.10)
H = (#SkinHeight# * 0.25)
MouseOverAction=[!SetOption MeterCloseInside ImageTint #hlColor#]
MouseLeaveAction=[!SetOption MeterCloseInside ImageTint #bgColor#]
LeftMouseDownAction = [!SetOption MeterCloseInside ImageTint #clColor#]
LeftMouseUpAction= [!ActivateConfig #CURRENTCONFIG# "#Main#.ini"]
DynamicVariables = 1

[MeterFolderBox]
Meter = Shape
Shape = Rectangle 0, 0, #folderW#, #folderH# | Stroke Color #olColor# | StrokeWidth 2 | Extend Color
Shape2 = Rectangle (#folderW# * 0.0), (#folderH# * -0.3), (#folderW# * 0.5), (#folderH# * 0.3) | Stroke Color #olColor# | StrokeWidth 2 | Extend Color
X = (#SkinWidth# * 0.85)
Y = (#SkinHeight# * 0.47)
Color = Fill Color #bgColor#
MouseOverAction  =[!SetOption #CURRENTSECTION# Color "Fill Color #hlColor#"]
MouseLeaveAction  =[!SetOption #CURRENTSECTION# Color "Fill Color #bgColor#"]
LeftMouseDownAction = [!SetOption #CURRENTSECTION# Color "Fill Color #clColor#"]
LeftMouseUpAction = [!SetOption #CURRENTSECTION# Color "Fill Color #bgColor#"]["#FolderPath#"]
Hidden = (#Current# = 1) ? 1 : 0

[Button_Next]
Meter=String
MeterStyle=styleText | textHighlight
X = (#SkinWidth# * 0.88)
Y = (#SkinHeight# * 0.69)
FontSize = (40 * #scale#)
FontFace = Webdings
FontColor = #bgColor#
StringEffect = Border
FontEffectColor = 255,255,255
Text = 8
StringAlign = Center
MouseLeaveAction = [!SetOption #CURRENTSECTION# FontColor "#bgColor#"]
LeftMouseDownAction = [!SetOption #CURRENTSECTION# FontColor "#clColor#"]
LeftMouseUpAction=[!ActivateConfig "#CURRENTCONFIG#" "#NextPath#"]


;------------------------------------------------
;	INPUT
;------------------------------------------------
[MeterInputLabel]
Meter=String
MeterStyle = styleText
X=(#CURRENTCONFIGWIDTH# / 2)
Y=(#CURRENTCONFIGHEIGHT# / 3)
W=(#SkinWidth# - (2 * #BoxW#) - 1)
H=(#SkinHeight#* (2/3))
ClipString=1
FontSize=24
StringAlign = Center
Text=[#[#Variable]]
LeftMouseUpAction=[!CommandMeasure MeasureInput "ExecuteBatch 1"]
MouseOverAction= [!SetOption "#CURRENTSECTION#" "SolidColor" #hlColor#,50]
MouseLeaveAction=[!SetOption "#CURRENTSECTION#" "SolidColor" #bgColor#,1]
DynamicVariables=1
Hidden = (#Current# = 3) ? 1 : 0

[MeasureInput]
Measure=Plugin
Plugin=InputText
X=(#CURRENTCONFIGWIDTH# / 4) + 1
Y=(#CURRENTCONFIGHEIGHT# / 3)
W=(#SkinWidth# - (2 * #BoxW#) - 1)
H=(#SkinHeight# * (2/3) - 1)
FontSize=24
FontColor=255,255,255,255
FontFace= Choco Cooky
SolidColor=0,0,0,255
AntiAlias=1
FocusDismiss=1
StringAlign = Center
DefaultValue=[#[#Variable]]
Command1=[!WriteKeyValue Variables #Variable# "$UserInput$" "#ListDir#"][!Refresh]
Hidden = (#Current# = 3) ? 1 : 0

