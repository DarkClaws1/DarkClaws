[Variables]
@include = #@#style.inc
FeedNum =1
CurrentStory =9
SkinWidth = (#rightSize# * #scale#)
SkinHeight = (131 * #scale#)
InputSize = (18 * #scale#)
SkinY = ((#SkinHeight# * 1.08) * #scale#)
Feed1 =Tech
Feed2 =NYT
Feed3 =Science
Feed4 =Animals

ScrollSpeed=1

NewsX = (#SkinWidth# * 0.14)
NewsHeight = (#SkinHeight# * 0.23)

FeedBoxX = (#SkinWidth# * 0.74)
FeedBoxY = 0.03
FeedBoxSpacing = (#SkinWidth#*0.05)

StoryX = (#SkinWidth# * 0.5490)
StoryY = 0.85
StorySpacing = (#SkinWidth# * 0.05)

showStoryX = (#SkinWidth# * 0.1)
showStoryY = (#SkinHeight# * 0.95)
storyBoxBuffer = (#SkinWidth# * 0.1)
largeBoxSize = (20 * #scale#)

HoverColorNews= 0,0,255,64
FeedMax=200

LPicH = (#SkinHeight# * 0.45)
LFeedBoxX = (#SkinHeight# * 0.1)
lTopBarH = (#SkinHeight# * 0.1)
LTitleY = (#SkinHeight# * 0.55)
LTitleH = (#SkinHeight# * 0.4)
LFeedFont = 25 * #scale#
LFont = 38 * #scale#
LFeedBoxW = (#SkinWidth# * 0.25)

; FEED TESTER VARIABLES
FeedName =
FeedLink =
FeedRSS = 
;=================================================================
;				METER STYLES
;=================================================================

[StyleFeedBox]
Text=c
FontFace=Webdings
FontSize=(10 * #scale#)
FontColor=#white#
StringAlign = Left
Y=(#SkinHeight# * #FeedBoxY#) 
AntiAlias=1
MouseOverAction = [!SetOption #CURRENTSECTION# FontColor #Blue#][!Redraw]
MouseLeaveAction = [!SetOption #CURRENTSECTION# FontColor #White#][!Redraw]
MouseScrollUpAction=[!WriteKeyValue Variables FeedNum [NextFeed] Settings.inc][!Refresh]
MouseScrollDownAction=[!WriteKeyValue Variables FeedNum [PrevFeed] Settings.inc][!Refresh]

[StyleFeedBoxLarge]
X = (#SkinWidth# * 0.25)r
Y = (#SkinHeight# * 0.025)
H = #lTopBarH#
FontSize=#LFeedFont#
StringAlign = CenterTop
AntiAlias=1

[StyleStoryBox]
Text=c
FontFace=Webdings
FontSize=(10 * #scale#)
FontColor=#txColor#
Y=(#SkinHeight# * #StoryY#)
AntiAlias=1
MouseOverAction = [!SetOption #CURRENTSECTION# FontColor #hlColor#][!Redraw]
MouseLeaveAction = [!SetOption #CURRENTSECTION# FontColor #txColor#][!Redraw]
MouseScrollUpAction=[!WriteKeyValue Variables CurrentStory [NextStory] DC_News_Variables.inc][!Refresh]
MouseScrollDownAction=[!WriteKeyValue Variables CurrentStory [PrevStory] DC_News_Variables.inc][!Refresh]

[StyleStoryBoxLarge]
Text=c
FontFace=Webdings
FontSize=#largeBoxSize#
FontColor=#txColor#
X=#storyBoxBuffer#r
Y=r
AntiAlias=1
MouseOverAction = [!SetOption #CURRENTSECTION# FontColor #hlColor#][!Redraw]
MouseLeaveAction = [!SetOption #CURRENTSECTION# FontColor #txColor#][!Redraw]
MouseScrollUpAction=[!WriteKeyValue Variables CurrentStory [NextStory] DC_News_Variables.inc][!Refresh]
MouseScrollDownAction=[!WriteKeyValue Variables CurrentStory [PrevStory] DC_News_Variables.inc][!Refresh]
DynamicVariables = 1


[MeterFeedEdit]
X= (#CURRENTCONFIGWIDTH# * 0.5)
W = #CURRENTCONFIGWIDTH#
H = (#CURRENTCONFIGHEIGHT# * 0.2)
ClipString = 1
DynamicVariables = 1




;=================================================================
;				MEASURES
;=================================================================
[RSS]
Measure=WebParser
Url=#URL#
;parse multiple sections the neat way 
RegExp=(?siU)#storysect##storysect##storysect##storysect##storysect##storysect##storysect##storysect##storysect#
ForceReload=1
Debug = 2

[Title]
Measure=WebParser
Url=[RSS]
StringIndex=((#Captures#*#CurrentStory#)+#TitleIndex#)
DecodeCharacterReference=1
RegExpSubstitute=1
Substitute="":"Just a moment...","^\s+":"","<!\[CDATA\[":"","\]\]>":"","!\[CDATA\[":"","\]\]":""

[Link]
Measure=WebParser
Url=[RSS]
StringIndex=((#Captures#*#CurrentStory#)+#LinkIndex#)
DecodeCharacterReference=1
RegExpSubstitute=1
Substitute="^\s+":"","<!\[CDATA\[":"","\]\]>":"","!\[CDATA\[":"","\]\]":""

[Image]
Measure=WebParser
Url=[RSS]
StringIndex=((#Captures#*#CurrentStory#)+#ImageIndex#)
Download=1
Substitute="":"blank1.png"
DecodeCharacterReference=1
