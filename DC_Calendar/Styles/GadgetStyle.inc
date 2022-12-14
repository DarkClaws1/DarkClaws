[Rainmeter]
AccurateText=0
DefaultAlwaysOnTop=-2
DefaultWindowX=160R
DefaultWindowY=0
Update=1000
Group=CalendarMeter
MouseOverAction=[!ShowMeterGroup Controls][!Redraw]
MouseLeaveAction=[!HideMeterGroup Controls][!Redraw]
MiddleMouseUpAction=[!Refresh]
SkinHeight=(150 * #Scale#)
SkinWidth=(160 * #Scale#)

[Variables]
;BgHeight=150 or 280
BgHeight=(#Bumper.top# + (#C.h#+#Space.y#)*8 + #Bumper.bottom#)
;BgWidth=160
BgWidth=(#C.w#*7 + #Space.x#*6 + #Bumper.x#*2)

ColorBg=0,0,0

;///////////////////////////////////////////////////////////////////////////////////////////////////
;                                             Measures
;///////////////////////////////////////////////////////////////////////////////////////////////////

;------------------------------------------ Localization -------------------------------------------

[MeasureLocalizedDayNames]
Measure=String
String=#DayLabels#
IfMatch=^$
IfMatchAction=[!EnableMeasure MeasureRestart][!CommandMeasure MeasureRunGetDayNames "Run"]
UpdateDivider=-1

[MeasureLocalizedMonthNames]
Measure=String
String=#MonthLabels#
IfMatch=^$
IfMatchAction=[!EnableMeasure MeasureRestart][!CommandMeasure MeasureRunGetMonthNames "Run"]
UpdateDivider=-1

[MeasureRunGetDayNames]
Measure=Plugin
Plugin=RunCommand
Program=powershell.exe
Parameter="-NoProfile -ExecutionPolicy Bypass -NonInteractive -Command "[Console]::OutputEncoding = New-Object -TypeName System.Text.UnicodeEncoding; $a = @('','','','','','',''); for ($i = 0; $i -lt 7; $i++) { $a[$i] = (Get-Culture).DateTimeFormat.ShortestDayNames[$i].Substring(0,1).ToUpper() }; ($a) -Join '|'""
OutputType=UTF16
State=Hide
Timeout=-1
Substitute="#CRLF#":""
FinishAction=[!WriteKeyValue Variables DayLabels [MeasureRunGetDayNames] "#@#CalendarVariables.inc"][!SetVariable Restart 1]

[MeasureRunGetMonthNames]
Measure=Plugin
Plugin=RunCommand
Program=powershell.exe
Parameter="-NoProfile -ExecutionPolicy Bypass -NonInteractive -Command "[Console]::OutputEncoding = New-Object -TypeName System.Text.UnicodeEncoding; ((Get-Culture).DateTimeFormat.AbbreviatedMonthNames[0..11]) -Join '|'""
OutputType=UTF16
State=Hide
Timeout=-1
Substitute="#CRLF#":""
FinishAction=[!WriteKeyValue Variables MonthLabels [MeasureRunGetMonthNames] "#@#CalendarVariables.inc"][!SetVariable Restart 1]

; check if restart required
[MeasureRestart]
Measure=Calc
IfCondition=(#Restart# = 1)
IfTrueAction=[!Log "Calendar localizations applied; restarting!" Notice][!Delay 250][!Refresh]
DynamicVariables=1
Disabled=1

;///////////////////////////////////////////////////////////////////////////////////////////////////
;                                              Meters
;///////////////////////////////////////////////////////////////////////////////////////////////////

; ------------------------------------------ Background --------------------------------------------

[MeterBackground]
Meter=Shape
Shape=Rectangle 0,0,#BgWidth#,#BgHeight# | Fill Color #ColorBg#,1 | StrokeWidth 0
Shape2=Rectangle (4 * #Scale#),(4 * #Scale#),(#BgWidth# - (8 * #Scale#)),(#BgHeight# - (7 * #Scale#)),6 | Fill Color #ColorBg#,((#BgStyle# = 0) ? #BgAlpha# / 2 : ((#BgStyle# = 1) ? #BgAlpha# / 3 : 0)) | StrokeWidth 0
Shape3=Rectangle (5 * #Scale#),(5 * #Scale#),(#BgWidth# - (10 * #Scale#)),(#BgHeight# - (9 * #Scale#)),4 | Fill Color #ColorBg#,((#BgStyle# = 0) ? #BgAlpha# : ((#BgStyle# = 1) ? #BgAlpha# / 3 : 0)) | StrokeWidth 0
Shape4=Rectangle (6 * #Scale#),(6 * #Scale#),(#BgWidth# - (12 * #Scale#)),(#BgHeight# - (11 * #Scale#)),1 | Fill Color ((#BgStyle# = 0) ? 164 : 0),((#BgStyle# = 0) ? 160 : 0),((#BgStyle# = 0) ? 160 : 0),((#BgStyle# = 0) ? #BgAlpha# : ((#BgStyle# = 1) ? #BgAlpha# / 3 : #BgAlpha#)) | StrokeWidth 0
Shape5=Rectangle (7 * #Scale#),(7 * #Scale#),(#BgWidth# - (14 * #Scale#)),(#BgHeight# - (13 * #Scale#)),1 | Fill LinearGradient MyFillGradient | StrokeWidth 0
MyFillGradient=270 | ((#BgStyle# = 0) ? 70 : 0),((#BgStyle# = 0) ? 70 : 0),((#BgStyle# = 0) ? 70 : 0),#BgAlpha# ; 0.0 | #ColorBg#,#BgAlpha# ; 1.0
UpdateDivider=-1

; end Gadgets additions
;---------------------------------------------------------------------------------------------------
; begin Gadgets styling

;===== Meter Styles=====
;All of these meter styles are required.

;Day Label Styles
[LblTxtSty]
H=#C.h#
W=#C.w#
X=(#Space.x#+#C.w#)r
Y=r
FontFace=#FontName#
FontColor=#PaletteColor1#
FontSize=(#FontSize2#*#Scaler#)
FontWeight=#FontWtNormal#
;SolidColor=#PaletteColor1#,40
SolidColor=80,80,80,255
SolidColor2=100,100,100,255
GradientAngle=90
StringAlign=CenterCenter
AntiAlias=1

[LblTxtStart]
X=(#Bumper.x#+#C.w#/2)
Y=(#Bumper.top#+#C.h#*1.5+#Space.y#)

[LblCurrSty]
FontColor=#Clr.Hrl#
FontWeight=#FontWtBold#

;Main Calendar Styles
[TextStyle]
H=#C.h#
W=#C.w#
X=(#Space.x#+#C.w#)r
Y=r
FontColor=#ColorInfoText1#
FontFace=#FontName#
FontSize=(#FontSize1#*#Scaler#)
FontWeight=#FontWtNormal#
StringAlign=Center
AntiAlias=1

[FirstDay]
Y=(#C.h#/2+#Space.y#)r
X=(#Bumper.x#+#C.w#/2)

[NewWk]
Y=#Space.y#R
X=(#Bumper.x#+#C.w#/2)

[CurrentDay]
FontColor=#ColorFontTitle#
FontWeight=#FontWtBold#
; comment out this next line and uncomment the [TodayHL] measure to use underscore indicator
SolidColor=#Clr.Hrl#

[LastWeek]
FontColor=0,0,0,0

[PreviousMonth]
FontColor=255,255,255,80

[NextMonth]
FontColor=255,255,255,80

[HolidayStyle]
FontColor=#PaletteColor2#
FontWeight=#FontWtBold#

[WeekendStyle]

;========== METERS ==========
;These are not required.

;Background Style
[BackgroundStyle]
;SolidColor=#Clr.Bg#
;H=(#Bumper.top#+#Bumper.bottom#+(#C.h#+#Space.y#)*(8-#LastWkHidden#))
;W=(#C.w#*7+#Space.x#*6+#Bumper.x#*2)
;DynamicVariables=1

[mLabel]
Meter=String
Text=#MonthLabel#
W=(#C.w#*7+#Space.x#*6)
X=((#C.w#*7+#Space.x#*6)/2+#Bumper.x#)
Y=#Bumper.top#
H=#C.h#
FontColor=#ColorFontTitle#
FontFace=#FontName#
FontSize=(#FontSize2#*#Scaler#)
FontWeight=#FontWtBold#
StringAlign=Center
AntiAlias=1
DynamicVariables=1

;Control Bar
[ControlForward]
Meter=String
MeterStyle=TextStyle
FontColor=#ColorFontSubtitle#
FontFace=Webdings
FontSize=(10*#Scaler#)
StringAlign=Left
Text="4"
Y=(#Bumper.top# + (2*#Scaler#))
X=((#C.w#*6+#Space.x#*6)+#Bumper.x#+(#C.w#/4))
LeftMouseUpAction=[!CommandMeasure "Lua" "Move(1)"][!Update]
Group=Controls
Hidden=1

[ControlBack]
Meter=String
MeterStyle=TextStyle | ControlForward
Text="3"
X=(#Bumper.x#-(#C.w#/4))
LeftMouseUpAction=[!CommandMeasure "Lua" "Move(-1)"][!Update]

[ControlHome]
Meter=String
MeterStyle=TextStyle | ControlForward
FontColor=#PaletteColor4#
Text="="
X=R
LeftMouseUpAction=[!CommandMeasure "Lua" "Move()"][!Update]

[MeterSettingsButton]
Meter=Image
ImageName="#@#Settings.png"
Antialias=1
X=((#C.w#*6+#Space.x#*5)+#Bumper.x#+(#C.w#/4)-(12*#Scaler#))
Y=(#Bumper.top#+(3*#Scaler#))
W=(12*#Scaler#)
H=(12*#Scaler#)
ToolTipText="Settings"
LeftMouseUpAction=[!ToggleConfig "#CURRENTCONFIG#\Config" "Settings.ini"]
Group=Controls
Hidden=1

;Date Indicator - uncomment to use underscore indicator, see [CurrentDay] above
; [TodayHL]
; Meter=Image
; X=(#Bumper.x#+(#C.w#+#Space.x#)*#Week#)
; Y=(#Bumper.top#+(#C.h#-(2*#Scaler#))+(#C.h#+#Space.y#)*(#ThisWeek#+1))
; H=(2*#Scaler#)
; W=#C.w#
; SolidColor=#Clr.Hrl#
; Hidden=#NotCurrentMonth#
; DynamicVariables=1

[Ghost]
Meter=Image
SolidColor=0,0,0,1
H=1
W=1
X=(#C.w#*7+#Space.x#*6+#Bumper.x#*2-1)
Y=(#Bumper.top#+#Bumper.bottom#+(#C.h#+#Space.y#)*7+#C.h#+1)