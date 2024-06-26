[Variables]
SkinHeight = #areaH#
SkinWidth = #midSize#
Settings = #CURRENTPATH#Settings.inc

;Month and Year Header
HeaderY = (#SkinHeight# * 0.00)	
HeaderFontSize = 40 * #scale#

;Arrows for changing the Month
ArrowX = (#SkinWidth# * 0.10)	
ArrowY = (#SkinHeight# * 0.01)

;Days (Sun, Mon, etc)
DaysY = (#SkinHeight# * 0.087)
DaysFontSize = 30 * #scale#

;Box Positions
BoxX = #SideB# + ((#BoxW#+#stroke#)/2)
BoxY = (#CalY# + #stroke#)

;The size of the left and right borders
SideB = (#SkinWidth# * 0.015)

;Shape of the full Calendar
CalY = (#SkinHeight# * 0.15)
CalH = (#SkinHeight# * 0.7)
CalW = (#SkinWidth# - #SideB# * 2)

;Derived Calendar Sizes
BoxW = ((#CalW# - (#stroke#  * 7)) / 7 )
BoxH = (#CalH# / 6)

;Event Text
EventY = (#SkinHeight# * 0.875)
EventFontSize = 25 * #scale#
EventColor = #clColor#

;Alarm Pop Up
AlarmW=(#SkinWidth# * 1)
AlarmH=(#SkinHeight# * 1)

;Box Higlighting
BoxLook = Fill Color #bgColor# | StrokeWidth #stroke# | Stroke Color 100,100,100
BoxLookH = Fill Color #bgColor# | StrokeWidth (#stroke#) | Stroke Color #hlColor#
BoxLookT = Fill Color #bgColor# | StrokeWidth (#stroke#) | Stroke Color #white#

;Leap Year and Month Length
ds_formula=((mMonth = 3) || (mMonth = 11)) ? 3 : (((mMonth = 4) || (mMonth = 7)) ? 6 : ((mMonth = 5) ? 1 : ((mMonth = 6) ? 4 : ((mMonth = 8) ? 2 : (((mMonth = 9) || (mMonth = 12)) ? 5 : ((mMonth = 10) ? 0 : ((cLeapYear = 1) ? ((mMonth = 1) ? 6 : 2) : ((mMonth = 1) ? 0 : 3))))))))


;----------------------------------------
;	STYLES
;----------------------------------------

[Arrow]
X=(#ArrowX#)
Y= (#ArrowY#)
StringAlign = Center
FontSize = #HeaderFontSize#
FontFace = Webdings
FontColor = #bgColor#
StringEffect = Border
StringStyle = Normal
FontEffectColor = 255,255,255
FontWeight = 900
MouseOverAction  = [!SetOption #CURRENTSECTION# FontColor #hlColor#]
MouseLeaveAction =[!SetOption #CURRENTSECTION# FontColor #bgColor#]
LeftMouseDownAction = [!SetOption #CURRENTSECTION# FontColor #clColor#]
AntiAlias = 1


;Style for the Monday, Tuesday, etc
[DayLabel]
MeterStyle = styleText
X=(#BoxW# + #stroke#)r
Y=#DaysY#
StringAlign=CENTER
FontSize = #DaysFontSize#
AntiAlias = 1
ClipString=1
UpdateDivider=-1

;This is the style for each day on the calendar
[Day]
FontSize= 25 * #scale#
StringEffect=SHADOW
StringAlign=Center
AntiAlias = 1
GradientAngle = 90
W=#BoxW#
H=#BoxH# - #stroke#
Text = #CURRENTSECTION#
ClipString=1
DynamicVariables=1
MouseOverAction=[!SetOption CalMainLua Hover #CURRENTSECTION#][!SetVariable "currentEvent" "#CURRENTSECTION#|[mMonth]|[mYear]"][!CommandMeasure "CalMainLua" "ShowEvent()"]
MouseLeaveAction = [!SetOption EventText Hidden 1]
LeftMouseUpAction=[!CommandMeasure "CalMainLua" "AddEvent()"]
ToolTipText = ""


[CalBoxStyle]
Shape = Rectangle (-#BoxW#/2.0),0, (#BoxW#), (#BoxH#) | Extend Look
X = 0
Y = 0
Look = #BoxLook#
MouseOverAction=[!SetOption #CURRENTSECTION# Look "#BoxLookH#"][!UpdateMeter #CURRENTSECTION#]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Look "#BoxLook#"][!UpdateMeter #CURRENTSECTION#]
DynamicVariables = 1

[Today]
Shape = Rectangle (-#BoxW#/2.0),0, (#BoxW#), (#BoxH#) | Extend Look
X = 0
Y = 0
Look = #BoxLookT#
MouseOverAction=[!SetOption #CURRENTSECTION# Look "#BoxLookH#"][!UpdateMeter #CURRENTSECTION#]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Look "#BoxLookT#"][!UpdateMeter #CURRENTSECTION#]
DynamicVariables = 1