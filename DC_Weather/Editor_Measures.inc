[Variables]
CommonSubstitute="&#039;":"'"
Get=(?(?=.*"lat":).*"lat":"(.*)",.*"lon":"(.*)",.*"display_name":"(.*)")
VarPathLoc=#CURRENTPATH#Settings.inc

[MeasureLocations]
Measure=WebParser
URL=https://nominatim.openstreetmap.org/search.php?q=#Loc#&format=jsonv2&addressdetails=0
Header="Accept-Language: #LocaleName#"
RegExp=(?siU)#Get##Get##Get##Get##Get#
LogSubstringErrors=0
UserAgent = "#ROOTCONFIG#"/1.0.0 (powered by Rainmeter)"
DynamicVariables=1
Disabled = 1

[MeasureLatitude1]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=1


[MeasureLongitude1]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=2

[MeasureDescription1]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=3
Substitute=#CommonSubstitute#
IfMatch=^$
IfMatchAction=[!HideMeter 1]
IfNotMatchAction=[!ShowMeter 1]

[MeasureLatitude2]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=4

[MeasureLongitude2]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=5

[MeasureDescription2]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=6
Substitute=#CommonSubstitute#
IfMatch=^$
IfMatchAction=[!HideMeter 2]
IfNotMatchAction=[!ShowMeter 2]

[MeasureLatitude3]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=7

[MeasureLongitude3]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=8

[MeasureDescription3]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=9
Substitute=#CommonSubstitute#
IfMatch=^$
IfMatchAction=[!HideMeter 3]
IfNotMatchAction=[!ShowMeter 3]

[MeasureLatitude4]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=10

[MeasureLongitude4]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=11

[MeasureDescription4]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=12
Substitute=#CommonSubstitute#
IfMatch=^$
IfMatchAction=[!HideMeter 4]
IfNotMatchAction=[!ShowMeter 4]

[MeasureLatitude5]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=13

[MeasureLongitude5]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=14

[MeasureDescription5]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=15
Substitute=#CommonSubstitute#
IfMatch=^$
IfMatchAction=[!HideMeter 5]
IfNotMatchAction=[!ShowMeter 5]