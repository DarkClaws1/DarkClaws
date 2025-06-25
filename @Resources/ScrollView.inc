[Rainmeter]
OnRefreshAction=[!ShowMeterGroup "Icons"][!HideMeterGroup "Warning"]
Update=0
SkinWidth=#SkinWidth#
SkinHeight=#SkinHeight#
SkinHeight=#SkinHeight#

;Custom Menu
RightMouseUpAction=!Execute [!SkinCustomMenu]
ContextTitle		=Edit Program
ContextAction		=[!WriteKeyValue Variables Editing #LastSelect# "Settings.inc"][!ActivateConfig #CURRENTCONFIG# "Editor_Name.ini"]
ContextTitle2		=Delete Program
ContextAction2		=[!WriteKeyValue Variables Editing #LastSelect# "Settings.inc"][!ShowMeterGroup "Warning"][!HideMeterGroup "Icons"]
ContextTitle3		=Refresh
ContextAction3		=[!Refresh]
ContextTitle4 		= Unload Skin
ContextAction4 		= [!DeactivateConfig #CURRENTCONFIG#]
ContextTitle5		=---
ContextTitle6		=Skin Menu
ContextAction6		=[!SkinMenu]
ContextTitle7 		= Settings.inc
ContextAction7		= ["#Settings#"]


;EDITING
Select		=	0
LastSelect 	= 	1

[SmoothScroll]
Measure = Calc
Formula = (SmoothScroll - ((SmoothScroll - #OffsetX#) / #ScrollDivider#))
DynamicVariables = 1

[Background]
Meter=Shape
MeterStyle = styleBG
MouseScrollUpAction		=[!SetVariable OffsetX "(Clamp(#OffsetX# - (#IconWidth# * #ScrollMultiplier#), Min(0, #ScrollLimit#),0))"]
MouseScrollDownAction	=[!SetVariable OffsetX "(Clamp(#OffsetX# + (#IconWidth# * #ScrollMultiplier#), Min(0, #ScrollLimit#),0))"]
DynamicVariables=1


[MeterName]
Meter = String
MeterStyle = styleText
X = (#SkinWidth#/2)
Text = [#name[#Select]]
StringAlign = Center
DynamicVariables = 1
Hidden = 1

;[MeterButton1]
;Meter = Image
;ImageName = #Btn1Name#.png
;X = (#SkinWidth# * 0.85)
;Y = (#SkinHeight# * 0.01)
;W = (#SkinWidth# * 0.075)
;H = (#SkinHeight# * 0.15)
;PreserveAspectRatio = 1
;ToolTipText = #Btn1Name#
;LeftMouseUpAction = !Execute["#Btn1Link#"]

;[MeterButton2]
;Meter = Image
;ImageName = #Btn2Name#.png
;X = (#SkinWidth# * 0.93)
;Y = (#SkinHeight# * 0.01)
;W = (#SkinWidth# * 0.075)
;H = (#SkinHeight# * 0.15)
;PreserveAspectRatio = 1
;ToolTipText = #Btn2Name#
;LeftMouseUpAction = !Execute["#Btn2Link#"]

;----------------------------------------------------------
;		Program ICONS
;----------------------------------------------------------
[1] 
Meter=Image 
MeterStyle=styleProgramIcon 
  
[Box1]
Meter=Shape
MeterStyle=styleProgramBox 

[2] 
Meter=Image 
MeterStyle=styleProgramIcon 
  
[Box2]
Meter=Shape
MeterStyle=styleProgramBox 

[3] 
Meter=Image 
MeterStyle=styleProgramIcon 
  
[Box3]
Meter=Shape
MeterStyle=styleProgramBox 

[4] 
Meter=Image 
MeterStyle=styleProgramIcon 
  
[Box4]
Meter=Shape
MeterStyle=styleProgramBox 

[5] 
Meter=Image 
MeterStyle=styleProgramIcon 
  
[Box5]
Meter=Shape
MeterStyle=styleProgramBox 

[6] 
Meter=Image 
MeterStyle=styleProgramIcon 
  
[Box6]
Meter=Shape
MeterStyle=styleProgramBox 

[7] 
Meter=Image 
MeterStyle=styleProgramIcon 
  
[Box7]
Meter=Shape
MeterStyle=styleProgramBox 

[8] 
Meter=Image 
MeterStyle=styleProgramIcon 
  
[Box8]
Meter=Shape
MeterStyle=styleProgramBox 

[9] 
Meter=Image 
MeterStyle=styleProgramIcon 
  
[Box9]
Meter=Shape
MeterStyle=styleProgramBox 

[10] 
Meter=Image 
MeterStyle=styleProgramIcon 
  
[Box10]
Meter=Shape
MeterStyle=styleProgramBox 

[11] 
Meter=Image 
MeterStyle=styleProgramIcon 
  
[Box11]
Meter=Shape
MeterStyle=styleProgramBox 

[12] 
Meter=Image 
MeterStyle=styleProgramIcon 
  
[Box12]
Meter=Shape
MeterStyle=styleProgramBox 

[13] 
Meter=Image 
MeterStyle=styleProgramIcon 
  
[Box13]
Meter=Shape
MeterStyle=styleProgramBox 

[14] 
Meter=Image 
MeterStyle=styleProgramIcon 
  
[Box14]
Meter=Shape
MeterStyle=styleProgramBox 

[15] 
Meter=Image 
MeterStyle=styleProgramIcon 
  
[Box15]
Meter=Shape
MeterStyle=styleProgramBox 

[16] 
Meter=Image 
MeterStyle=styleProgramIcon 
  
[Box16]
Meter=Shape
MeterStyle=styleProgramBox 

[17] 
Meter=Image 
MeterStyle=styleProgramIcon 
  
[Box17]
Meter=Shape
MeterStyle=styleProgramBox 

[18] 
Meter=Image 
MeterStyle=styleProgramIcon 
  
[Box18]
Meter=Shape
MeterStyle=styleProgramBox 

[19] 
Meter=Image 
MeterStyle=styleProgramIcon 
  
[Box19]
Meter=Shape
MeterStyle=styleProgramBox 

[20] 
Meter=Image 
MeterStyle=styleProgramIcon 
  
[Box20]
Meter=Shape
MeterStyle=styleProgramBox 
  
[MeterScroll]
Meter=Shape
Shape=Rectangle 0, 200, #SkinWidth# , 10, 2 | Fill Color 0,0,0,150 | StrokeWidth 0
Shape2=Rectangle (([SmoothScroll])*(#SkinWidth#)/(#ScrollLimit#-#SkinWidth#)), 200, (-1 * #SkinWidth# * (#SkinWidth#/(#ScrollLimit#-#SkinWidth#))), 10 | Fill Color #hlColor#,255 | StrokeWidth 1 | Stroke Color #olColor#
DynamicVariables=1

[MeterFolderBox]
Meter = Shape
Shape = Rectangle 0, 0, #folderW#, #folderH# | Stroke Color #olColor# | StrokeWidth 2 | Extend Color
Shape2 = Rectangle (#folderW# * 0.0), (#folderH# * -0.3), (#folderW# * 0.5), (#folderH# * 0.3) | Stroke Color #olColor# | StrokeWidth 2 | Extend Color
X = #folderX#
Y = #folderY#
Color = Fill Color #bgColor#
MouseOverAction  =[!SetOption #CURRENTSECTION# Color "Fill Color #hlColor#"]
MouseLeaveAction  =[!SetOption #CURRENTSECTION# Color "Fill Color #bgColor#"]
LeftMouseDownAction = [!SetOption #CURRENTSECTION# Color "Fill Color #clColor#"]
LeftMouseUpAction = [!SetOption #CURRENTSECTION# Color "Fill Color #bgColor#"]["#ImgDir#"]

[MeterHelpButton]
Meter = String
MeterStyle = styleText | textHighlight
FontFace = Webdings
Y = #SkinHeight# * 0.012
X = #SkinWidth# * 0.97
FontSize = 20 * #scale#
StringAlign = CENTER
Text = s
ToolTipText = :testing
LeftMouseUpAction = [!ToggleMeterGroup Help]