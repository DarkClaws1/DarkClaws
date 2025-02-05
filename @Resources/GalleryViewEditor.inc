[Variables]
;Moves the Folder Labels up and down
editorY = (#SkinHeight# * 0.096)
;Makes the boxes taller and shorter
editorH = (#SkinHeight# * 0.045)
InputSize = (15 * #scale#)

[styleFolderInputBox]
Shape = Rectangle 0,0, (#SkinWidth# * 1.0), #editorH# | Extend Look
Y = #editorY#r
Look = Fill Color #bgColor# | StrokeWidth #stroke# | Stroke Color #olColor#

[styleFolderInput]
X = (#SkinWidth# * 0.5)
Y =  #editorY#r
W = (#SkinWidth#)
H = (#editorH#)
ClipString = 1

[styleFolderLabel]
X = #SkinWidth# * 0.5
Y = #editorY#r
W = #SkinWidth#
H = (#editorH#)
StringAlign = CENTER
LeftMouseUpAction = [!SetOption #CURRENTSECTION# FontColor #txColor#]
LeftMouseDownAction = [!SetOption #CURRENTSECTION# FontColor #clColor#]
Text = #CURRENTSECTION#

[MeterBG]
Meter = Shape
MeterStyle = styleBG

[MeasureEscape]
Measure=Plugin
Plugin=HotKey
HotKey=ESCAPE
KeyDownAction=[!ActivateConfig #CURRENTCONFIG# "#MyConfig#"]

;=================================================
;	BOXES
;=================================================

[MeterBox1]
Meter=Shape
MeterStyle = styleFolderInputBox
Y = (#SkinHeight# * 0.1)

[MeterBox2]
Meter=Shape
MeterStyle = styleFolderInputBox

[MeterBox3]
Meter=Shape
MeterStyle = styleFolderInputBox

[MeterBox4]
Meter=Shape
MeterStyle = styleFolderInputBox

[MeterBox5]
Meter=Shape
MeterStyle = styleFolderInputBox

[MeterBox6]
Meter=Shape
MeterStyle = styleFolderInputBox

[MeterBox7]
Meter=Shape
MeterStyle = styleFolderInputBox

[MeterBox8]
Meter=Shape
MeterStyle = styleFolderInputBox

[MeterBox9]
Meter=Shape
MeterStyle = styleFolderInputBox

[MeterBox10]
Meter=Shape
MeterStyle = styleFolderInputBox

;=================================================
;	LABELS
;=================================================

[Folder-1]
Meter=String
MeterStyle = styleText | styleFolderLabel | textHighlight
Y = (#SkinHeight# * 0.05)
LeftMouseUpAction = ["#folder1#"]

[Folder-2]
Meter=String
MeterStyle = styleText | styleFolderLabel | textHighlight
LeftMouseDownAction = [!SetOption #CURRENTSECTION# FontColor #clColor#]["#folder1#"]
LeftMouseUpAction = ["#folder2#"]

[Folder-3]
Meter=String
MeterStyle = styleText | styleFolderLabel | textHighlight
LeftMouseUpAction = ["#folder3#"]

[Folder-4]
Meter=String
MeterStyle = styleText | styleFolderLabel | textHighlight
LeftMouseUpAction = ["#folder4#"]

[Folder-5]
Meter=String
MeterStyle = styleText | styleFolderLabel | textHighlight
LeftMouseUpAction = ["#folder5#"]

[Folder-6]
Meter=String
MeterStyle = styleText | styleFolderLabel | textHighlight
LeftMouseUpAction = ["#folder6#"]

[Folder-7]
Meter=String
MeterStyle = styleText | styleFolderLabel | textHighlight
LeftMouseUpAction = ["#folder7#"]

[Folder-8]
Meter=String
MeterStyle = styleText | styleFolderLabel | textHighlight
LeftMouseUpAction = ["#folder8#"]

[Folder-9]
Meter=String
MeterStyle = styleText | styleFolderLabel | textHighlight
LeftMouseUpAction = ["#folder9#"]

[Folder-10]
Meter=String
MeterStyle = styleText | styleFolderLabel | textHighlight
LeftMouseUpAction = ["#folder10#"]

;=================================================
;	FOLDER NAME DISPLAYS
;=================================================

[folder1]
Meter=String
MeterStyle = styleText | styleInput | styleFolderInput | textHighlight
Y = (#SkinHeight# * 0.1)
ClipString = 1

[folder2]
Meter=String
MeterStyle = styleText | styleInput | styleFolderInput | textHighlight

[folder3]
Meter=String
MeterStyle = styleText | styleInput | styleFolderInput | textHighlight

[folder4]
Meter=String
MeterStyle = styleText | styleInput | styleFolderInput | textHighlight

[folder5]
Meter=String
MeterStyle = styleText | styleInput | styleFolderInput | textHighlight

[folder6]
Meter=String
MeterStyle = styleText | styleInput | styleFolderInput | textHighlight

[folder7]
Meter=String
MeterStyle = styleText | styleInput | styleFolderInput | textHighlight

[folder8]
Meter=String
MeterStyle = styleText | styleInput | styleFolderInput | textHighlight

[folder9]
Meter=String
MeterStyle = styleText | styleInput | styleFolderInput | textHighlight

[folder10]
Meter=String
MeterStyle = styleText | styleInput | styleFolderInput | textHighlight

;=================================================
; CLOSE BUTTON
;=================================================

[MeterCloseInside]
Meter = Image
ImageName = "#@#X Inside.png"
ImageTint = #bgColor#
X = (#SkinWidth# * 0.907)
Y = (#SkinHeight# * 0.00)
W = (#SkinWidth# * 0.09)
H = (#SkinHeight# * 0.1)
DynamicVariables = 1
PreserveAspectRatio = 1

[MeterCloseOutline]
Meter = Image
ImageName = "#@#X Outline.png"
ImageTint = #olColor#
X = r
Y = r
W = (#SkinWidth# * 0.09)
H = (#SkinHeight# * 0.1)
MouseOverAction=[!SetOption MeterCloseInside ImageTint #hlColor#]
MouseLeaveAction=[!SetOption MeterCloseInside ImageTint #bgColor#]
LeftMouseDownAction = [!SetOption MeterCloseInside ImageTint #clColor#]
LeftMouseUpAction= [!ActivateConfig #CURRENTCONFIG# "#MyConfig#"]
DynamicVariables = 1
PreserveAspectRatio = 1

;=================================================
;	HELP MENU
;=================================================

[MeterHelpButton]
Meter = String
MeterStyle = styleText | textHighlight
FontFace = Webdings
Y = #SkinHeight# * 0.015
X = #SkinWidth# * 0.03
StringAlign = CENTER
Text = s
ToolTipText = :testing
LeftMouseUpAction = [!ToggleMeterGroup Help]


[MeterHelpBox]
Meter = Shape
Shape = Rectangle 0,0, (#SkinWidth# * 1.0), (#SkinHeight# * 0.9) | Extend Look
Y = (#SkinHeight# * 0.1)
Look = Fill Color #bgColor# | StrokeWidth #stroke# | Stroke Color #olColor#
Group = Help
Hidden = 1
LeftMouseUpAction = [!HideMeterGroup Help]

[MeterHelpText0]
Meter = String
MeterStyle = styleText
X = (#SkinWidth# * 0.5)
Y = (#SkinHeight# * 0.15)
FontSize = 30
Text = HOW TO COPY A FOLDER PATH
StringAlign = Center
Group = Help
Hidden = 1

[MeterHelpText1]
Meter = String
MeterStyle = styleText
X = (#SkinWidth# * 0.5)
Y = (#SkinHeight# * 0.25)
Text = Click the EMPTY area at the end of the bar
StringAlign = Center
Group = Help
Hidden = 1

[MeterHelpText2]
Meter = String
MeterStyle = styleText
X = (#SkinWidth# * 0.5)
Y = (#SkinHeight# * 0.3)
Text = DO NOT CLICK THE WORDS
FontColor = 255,0,0
StringAlign = Center
Group = Help
Hidden = 1

[MeterHelpImage]
Meter = Image
ImageName = Example
X = (#SkinWidth# * 0.05)
Y = (#SkinHeight# * 0.25)
W = (#SkinWidth# * 0.9)
H = (#SkinHeight# * 0.5)
PreserveAspectRatio = 1
Group = Help 
Hidden = 1

[MeterHelpText3]
Meter = String
MeterStyle = styleText
X = (#SkinWidth# * 0.5)
Y = (#SkinHeight# * 0.65)
W = (#SkinWidth# * 0.95)
H = (#SkinHeight# * 0.1)
Text = If you don't see a space, make the window BIGGER
ClipString = 2
StringAlign = Center
Group = Help
Hidden = 1

[MeterHelpText4]
Meter = String
MeterStyle = styleText
X = (#SkinWidth# * 0.5)
Y = (#SkinHeight# * 0.8)
Text = After clicking, copy the text
StringAlign = Center
Group = Help
Hidden = 1

