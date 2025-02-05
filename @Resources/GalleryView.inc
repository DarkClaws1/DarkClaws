[Variables]
buttonX = (#SkinWidth# * 0.75)
buttonY = (#SkinHeight# * 0.92)
buttonGap = (#SkinWidth# * 0.05)
;THE SIZE OF THE FOLDER
folderW = (30 * #scale#)
folderH = (15 * #scale#)
InputSize = (15 * #scale#)
playButton = F7

;=================================================
;	METERSTYLES
;=================================================
[styleBoxButton]
X = #buttonGap#r
Y = r
Fontsize = 17 * #scale#
Text=c
FontFace=Webdings
LeftMouseUpAction = [!CommandMeasure "MainLua" "ChangeFolder('#CURRENTSECTION#')"]
MouseScrollUpAction = [!CommandMeasure "MainLua" "FolderDown('#folder#')"]
MouseScrollDownAction = [!CommandMeasure "MainLua" "FolderUp('#folder#')"]


;=================================================
;	MEASURES
;=================================================
[MainLua]
Measure=Script
ScriptFile="#CURRENTPATH#Code.lua"
UpdateDivider=1

[MeasureFolder]
Measure = Plugin
Plugin = FileView
Path = #path#
Count = 1
UpdateDivider=1
ShowFolder = 0
ShowDotDot = 0
Extensions="jpg;png;avif;gif"
HideExtensions = 1
SortType = Name

[MeasureCount]
Measure = Plugin
Plugin = FileView
Path = [MeasureFolder]
Type=FileCount
OnChangeAction = [!CommandMeasure "MainLua" "Calculate()"]

[MeasurePic]
Measure = Plugin
Plugin = FileView
Path = [MeasureFolder]
Type=FilePath
Index=1
DynamicVariables=1
UpdateDivider=1

[MeasurePicName]
Measure = Plugin
Plugin = FileView
Path = [MeasureFolder]
Type=FileName
Index=1
DynamicVariables=1

[MeasureFolderName]
Measure = String
String = #path#
RegExpSubstitute=1
Substitute="^(.*)\\(.*)$":"\2"

[MeasureEscape]
Measure=Plugin
Plugin=HotKey
HotKey=#playButton#
KeyDownAction=[!CommandMeasure "MainLua" "ChangePaused()"]

;=================================================
;	METERS
;=================================================
[MeterBG]
Meter = Shape
MeterStyle = styleBG

[MeterPic]
Meter = Image
ImageName = 
X = (#SkinWidth# * 0)
Y = (#SkinHeight# * 0)
W = (#SkinWidth# * 1.0)
H = (#SkinHeight# * 0.85)
PreserveAspectRatio = 1
DynamicVariables=1

[MeterPictureBox]
Meter=Shape
;DO NOT CHANGE THE FIRST TWO ZEROES
Shape = Rectangle 0,0, (#SkinWidth# * 1.0), (#SkinHeight# * 0.85) | Extend Look
X = (#SkinWidth# * 0.0)
Y = (#SkinHeight# * 0.0)
Look = Fill Color #clear# | StrokeWidth #stroke# | Stroke Color #olColor#
MouseScrollUpAction = [!CommandMeasure "MainLua" "Next()"]
MouseScrollDownAction = [!CommandMeasure "MainLua" "Previous()"]

;THIS IS YOUR GEAR ICON METER
[MeterSettings]
Meter = Image
MeterStyle = Settings
X = (#SkinWidth# * 0.9425)
Y = (#SkinHeight# * 0.864)


;=================================================
; 	BUTTONS
;=================================================
[MeterFolder]
Meter = Shape
;This makes the bottom box
Shape = Rectangle 0, 0, #folderW#, #folderH# | Stroke Color #olColor# | StrokeWidth 2 | Extend Color
;This makes the box in the top lefthand corner
Shape2 = Rectangle (#folderW# * 0.0), (#folderH# * -0.3), (#folderW# * 0.5), (#folderH# * 0.3) | Stroke Color #olColor# | StrokeWidth 2 | Extend Color
;THE POSITION OF THE FOLDER
X = (#SkinWidth# * 0.36)
Y = (#SkinHeight# * 0.965)
Color = Fill Color #bgColor#
MouseOverAction  =[!SetOption #CURRENTSECTION# Color "Fill Color #hlColor#"]
MouseLeaveAction  =[!SetOption #CURRENTSECTION# Color "Fill Color #bgColor#"]
LeftMouseDownAction = [!SetOption #CURRENTSECTION# Color "Fill Color #clColor#"]["#path#"]
LeftMouseUpAction = [!SetOption #CURRENTSECTION# Color "Fill Color #bgColor#"]

[MeterPrevious]
Meter=String
MeterStyle = styleText | Bordered
X = (#SkinWidth# * 0.45)
Y = (#SkinHeight# * 0.95)
FontFace = Webdings
Text = 7
StringAlign = Center
LeftMouseUpAction = [!CommandMeasure "MainLua" "Previous()"]

[MeasurePlayPause]
Measure = Calc
IfCondition = (#paused# = 1)
IfTrueAction = [!SetOption MeterPlay Text 4]
IfFalseAction = [!SetOption MeterPlay Text ;]
DynamicVariables = 1


[MeterPlay]
Meter=String
MeterStyle = styleText | Bordered
X = (#SkinWidth# * 0.5)
Y = r
FontFace = Webdings
Text = 4
StringAlign = Center
LeftMouseUpAction = [!CommandMeasure "MainLua" "ChangePaused()"]
DynamicVariables = 1
ToolTipText = Press #playButton# to Play or Pause

[MeterNext]
Meter=String
MeterStyle = styleText | Bordered
X = (#SkinWidth# * 0.55)
Y = r
FontFace = Webdings
Text = 8
StringAlign = Center
LeftMouseUpAction = [!CommandMeasure "MainLua" "Next()"]


;=========================
; FOLDER ICONS
;=========================

[folder1]
Meter=String
MeterStyle = styleText | styleBoxButton | textHighlight
X = #buttonX#
Y = #buttonY#
Hidden = (#folder# = 1)

[folder2]
Meter=String
MeterStyle = styleText | styleBoxButton | textHighlight
Hidden = (#folder# = 2)

[folder3]
Meter=String
MeterStyle = styleText | styleBoxButton | textHighlight
Hidden = (#folder# = 3)

[folder4]
Meter=String
MeterStyle = styleText | styleBoxButton | textHighlight
Hidden = (#folder# = 4)

[folder5]
Meter=String
MeterStyle = styleText | styleBoxButton | textHighlight
Hidden = (#folder# = 5)

[folder6]
Meter=String
MeterStyle = styleText | styleBoxButton | textHighlight
Hidden = (#folder# = 6)
X = #buttonX#
Y = (#SkinHeight# * 0.04)r
Hidden = (#folder# = 6)

[folder7]
Meter=String
MeterStyle = styleText | styleBoxButton | textHighlight
Hidden = (#folder# = 7)

[folder8]
Meter=String
MeterStyle = styleText | styleBoxButton | textHighlight
Hidden = (#folder# = 8)

[folder9]
Meter=String
MeterStyle = styleText | styleBoxButton | textHighlight
Hidden = (#folder# = 9)

[folder10]
Meter=String
MeterStyle = styleText | styleBoxButton | textHighlight
Hidden = (#folder# = 10)

[MeterFilledIn]
Meter=String
MeterStyle = BoxFill
FontSize = 17 * #scale#
X= [folder#folder#:X]
y = [folder#folder#:y]
DynamicVariables=1
MouseScrollUpAction = [!CommandMeasure "MainLua" "FolderDown('#folder#')"]
MouseScrollDownAction = [!CommandMeasure "MainLua" "FolderUp('#folder#')"]