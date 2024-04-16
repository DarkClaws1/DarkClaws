[Variables]
CommonSubstitute="&#039;":"'"
Get=(?(?=.*"lat":).*"lat":"(.*)",.*"lon":"(.*)",.*"display_name":"(.*)")
VarPathLoc=#CURRENTPATH#Settings.inc

[MeasureLocations]
Measure=WebParser
URL=https://nominatim.openstreetmap.org/search.php?q=#Loc#&format=json&addressdetails=0
;Header="Accept-Language: #LocaleName#"
RegExp=(?siU)#Get##Get##Get##Get##Get#
;LogSubstringErrors=0
UserAgent = Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/121.0.0.0 Safari/537.36 Edg/121.0.0.0
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
IfMatchAction=[!HideMeter MeterDescription1]
IfNotMatchAction=[!ShowMeter MeterDescription1]

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
IfMatchAction=[!HideMeter MeterDescription2]
IfNotMatchAction=[!ShowMeter MeterDescription2]

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
IfMatchAction=[!HideMeter MeterDescription3]
IfNotMatchAction=[!ShowMeter MeterDescription3]

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
IfMatchAction=[!HideMeter MeterDescription4]
IfNotMatchAction=[!ShowMeter MeterDescription4]

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
IfMatchAction=[!HideMeter MeterDescription5]
IfNotMatchAction=[!ShowMeter MeterDescription5]

[MeasureLatitude6]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=16

[MeasureLongitude6]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=17

[MeasureDescription6]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=18
Substitute=#CommonSubstitute#
IfMatch=^$
IfMatchAction=[!HideMeter MeterDescription6]
IfNotMatchAction=[!ShowMeter MeterDescription6]

[MeasureLatitude7]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=19

[MeasureLongitude7]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=20

[MeasureDescription7]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=21
Substitute=#CommonSubstitute#
IfMatch=^$
IfMatchAction=[!HideMeter MeterDescription7]
IfNotMatchAction=[!ShowMeter MeterDescription7]

[MeasureLatitude8]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=22

[MeasureLongitude8]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=23

[MeasureDescription8]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=24
Substitute=#CommonSubstitute#
IfMatch=^$
IfMatchAction=[!HideMeter MeterDescription8]
IfNotMatchAction=[!ShowMeter MeterDescription8]

[MeasureLatitude9]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=25

[MeasureLongitude9]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=26

[MeasureDescription9]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=27
Substitute=#CommonSubstitute#
IfMatch=^$
IfMatchAction=[!HideMeter MeterDescription9]
IfNotMatchAction=[!ShowMeter MeterDescription9]

[MeasureLatitude10]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=28

[MeasureLongitude10]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=29

[MeasureDescription10]
Measure=Plugin
Plugin=WebParser
URL=[MeasureLocations]
StringIndex=30
Substitute=#CommonSubstitute#
IfMatch=^$
IfMatchAction=[!HideMeter MeterDescription10]
IfNotMatchAction=[!ShowMeter MeterDescription10]