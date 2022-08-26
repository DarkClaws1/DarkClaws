[WarningBG]
Meter=Shape
MeterStyle = styleBG
DynamicVariables=1
Group = Warning
Hidden = 1

[MeterBoxCancel]
Meter = Shape
Shape = Rectangle (#SkinWidth# * (0.5 - #WBoxGap# - #WBoxWidth#)), #WBoxY#, #WBoxW#, #WBoxH# | Fill Color #bgColor# | StrokeWidth #stroke# | Stroke Color #olColor#
Group = Warning
Hidden = 1

[MeterBoxDelete]
Meter = Shape
Shape = Rectangle (#SkinWidth# * (0.5 + #WBoxGap#)), #WBoxY#, #WBoxW#, #WBoxH# | Fill Color #bgColor# | StrokeWidth #stroke# | Stroke Color #olColor#
Group = Warning
Hidden = 1

[MeterBoxCancelHL]
Meter = Shape
Shape = Rectangle (#SkinWidth# * (0.5 - #WBoxGap# - #WBoxWidth#)), #WBoxY#, #WBoxW#, #WBoxH#| Fill Color #bgColor# | StrokeWidth #stroke# | Stroke Color #hlColor#
Hidden = 1

[MeterBoxDeleteHL]
Meter = Shape
Shape = Rectangle (#SkinWidth# * (0.5 + #WBoxGap#)), #WBoxY#, #WBoxW#, #WBoxH# | Fill Color #bgColor# | StrokeWidth #stroke# | Stroke Color #hlColor#
Hidden = 1

[MeterWarning]
Meter = String
MeterStyle = styleText 
X = (#SkinWidth# * 0.30)
Y = (#SkinHeight# * 0.02)
Fontsize = (30 * #scale#)
Text = W A R N I N G
Group = Warning
Hidden = 1

[MeterAreYouSure]
Meter = String
MeterStyle = styleText 
X = (#SkinWidth# * 0.50)
Y = (#SkinHeight# * 0.20)
Fontsize = (25 * #scale#)
Text = Are you sure that you want to delete
StringAlign = Center
Group = Warning
Hidden = 1

[MeterWarningName]
Meter = String
MeterStyle = styleText 
X = (#SkinWidth# * 0.50)
Y = (#SkinHeight# * 0.40)
Fontsize = (25 * #scale#)
Text = [#name[#Editing]]
DynamicVariables = 1
StringAlign = Center
Group = Warning
Hidden = 1

[MeterCancel]
Meter = String
MeterStyle = styleText | textHighlight
X = (#CURRENTCONFIGWIDTH# * 0.19)
Y = (#CURRENTCONFIGHEIGHT# * 0.71)
Fontsize = (30 * #scale#)
Text = Cancel
MouseOverAction =  [!SetOption MeterBoxCancelHL Hidden 0][!HideMeterGroup "Icons"]
MouseLeaveAction = [!SetOption MeterBoxCancelHL Hidden 1]
LeftMouseUpAction = [!Refresh]
Group = Warning
Hidden = 1

[MeterDelete]
Meter = String
MeterStyle = styleText | textHighlight
X = (#CURRENTCONFIGWIDTH# * 0.60)
Y = (#CURRENTCONFIGHEIGHT# * 0.71)
Fontsize = (30 * #scale#)
Text = Delete
MouseOverAction =  [!SetOption MeterBoxDeleteHL Hidden 0]
MouseLeaveAction = [!SetOption MeterBoxDeleteHL Hidden 1]
LeftMouseUpAction = [!WriteKeyValue Variables "name#Editing#" "" "#ListDir#"][!WriteKeyValue Variables "dir#Editing#" "" "#ListDir#"][!WriteKeyValue Variables "img#Editing#" "" "#ListDir#"][!Refresh]
Group = Warning
Hidden = 1