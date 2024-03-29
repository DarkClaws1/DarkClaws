;///////////////////////////////////////////////////////////////////////////////////////////////////
;                                        Calendar Variables
;///////////////////////////////////////////////////////////////////////////////////////////////////

[Variables]
; background
BgAlpha=255
BgStyle=0
SkinWidth = (#midSize#)
SkinHeight = (#maxHeight# * 1.0)

dayColor = 0,255,255
currentDayColor = 255,255,255
holidayColor = 0,75,255
buffer = 15
boxH = 65
boxW = ((#midSize#-(#buffer#*2))/7)

eventH = 570

; month/year and current day color
ColorFontTitle=255,255,255

; weekday label color
PaletteColor1=180,180,180

; holiday color
PaletteColor2=0,0,255

; current day highlight/background color
PaletteColor3=255,255,255

; control home button
PaletteColor4=236,28,70

;Shape = Rectangle 10,115,90,450 | Stroke Color 0,0,255 | StrokeWidth 5 | FillColor 0,0,0,0

; font appearance
FontName=Segoe UI
FontSize1=20
FontSize2=20
FontSizeS=7
FontWtBold=700
FontWtNormal=400

; scale factor
;Scale=3.0

;Date indicator line color
Clr.Hrl=#PaletteColor3#


numberSize = (23 * #scale#)
eventSize = (11*#scale#)


;===== Positioning options =====
;Cell Dimensions - The dimensions of the individual string meters.
C.w=(79)
C.h=(60)
;Spacers and bumper
;Horizontal space between cells
Space.x=(4)
;Vertical space between cells
Space.y=(5)
;Space on left and right of calendar
Bumper.x=(1)
;Space on top of calendar
Bumper.top=(50)
;Space on bottom of calendar
Bumper.bottom=(7)

;///////////////////////////////////////////////////////////////////////////////////////////////////
;                                        LuaCalendar Options
;///////////////////////////////////////////////////////////////////////////////////////////////////

; Please visit http://smurfier.github.io/LuaCalendar for detailed descriptions of the features listed below.
; Settings file v6.0

;Custom text for Weekday labels. Uses the following format: Sun|Mon|Tue|Wed|Thu|Fri|Sat
DayLabels=S|M|T|W|T|F|S

;Holidays File names
;Note: For Holiday file names, multiple sources can be used by using the pipe delimiter (|).
EventFile=#CURRENTPATH#CalendarEvents.xml

;Custom Text formatting for Month Labels. See Readme for details.
LabelText={$MName} {$Year}

;Custom text for Month labels. Uses the following format: Jan|Feb|Mar|Apr|May|Jun|Jul|Aug|Sep|Oct|Nov|Dec
MonthLabels=January|February|March|April|May|June|July|August|September|October|November|December

;The format for the list of upcoming events. {$day} and {$desc} are valid variables.
NextFormat=