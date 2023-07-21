[Variables]
SkinWidth = (#leftSize# * #scale#)
SkinHeight = (#areaH# * 0.412)
Settings = #CURRENTPATH#Settings.inc
InputSize = (20 * * #scale#)
Latitude =40.83021000
Longitude=-73.68777850
DaySpacing = 0.2
DayY = 0.50
TempY = 0.85
IconX 	= (#SkinWidth# * -0.07)
IconY 	= (#SkinHeight# * 0.65)
IconW 	= (#SkinWidth# * 0.15)
IconH	= (#SkinWidth# * 0.10)


; Don't change any below here.
Language=en-US
Units=e
UpdateRate=600
DateFormat=%A, %B %#d, %Y
TimeFormat=%#I:%M %p
APIKey=21d8a80b3d6b444998a80b3d6b1449d3
UserAgent=Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:80.0) Gecko/20100101 Firefox/80.0
CommonSubstitute='"':"","^null$":"","\\u002F":"/","\\u005C":"\","\\u003C":"<","\\u003E":">"
URLSite=https://api.weather.com/v3/aggcommon/v3-wx-observations-current;v3-wx-forecast-daily-15day;v3alertsHeadlines;v3-location-point?format=json&geocode=#Latitude#,#Longitude#&units=#Units#&language=#Language#&apiKey=#APIKey#

[styleLocationOption]
MeasureName=MeasureDescription#CURRENTSECTION#
X = (#CURRENTCONFIGWIDTH# * 0.03)
W = (#CURRENTCONFIGWIDTH# * 1.0)
H = 30
ClipString = 1
LeftMouseUpAction = [!WriteKeyValue Variables Latitude "[MeasureLatitude#CURRENTSECTION#:8]" "#VarPathLoc#"][!WriteKeyValue Variables Longitude "[MeasureLongitude#CURRENTSECTION#:8]" "#VarPathLoc#"][!RefreshGroup "Map"][!ActivateConfig #CURRENTCONFIG# "[MeasureConfig].ini"]
DynamicVariables = 1


; NOTE that Location Codes like USVA0944 or other types of codes are no longer supported.

; You must use location Latitude and Longitude.

; You can right click the skin and select "Choose location" to use a litle skin I wrote.
; Simply type any search string into "Search For Location", hit Enter, then click
; the magnifying glass at the bottom left.
; Once you have found the location you want, click on the Latitude,Longitude numbers
; on the right to set that value and refresh the main weather skin.
; Click the Name of the location on the left to see the location on a map in your browser.
; 
; These values can also be found manually for your location at:
; https://nominatim.openstreetmap.org/search.php?q=Your Address Text&format=json
; Where "Your Address Text" can be pretty much anything that can zero in on the location you want.
; https://nominatim.openstreetmap.org/search.php?q=Fort Hunt, Virginia&format=json
; https://nominatim.openstreetmap.org/search.php?q=22308&format=json
; https://nominatim.openstreetmap.org/search.php?q=The White House, Washington D.C.&format=json
; Then copy the lat: and lon: values from that site and paste them below.
; Other alternative sites to get the latitude / longitude are:
; https://support.google.com/maps/answer/18539
; https://www.latlong.net/
; https://www.mapcoordinates.net

