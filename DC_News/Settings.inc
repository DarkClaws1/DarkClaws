[Variables]
@include = #@#style.inc
FeedNum =4
CurrentStory =1
SkinWidth = (#rightSize# * #scale#)
SkinHeight = (131 * #scale#)
InputSize = (18 * #scale#)
SkinY = ((#SkinHeight# * 1.08) * #scale#)
Feed1 =Tech
Feed2 =NYT
Feed3 =Google News
Feed4 =Animals

ScrollSpeed=1

NewsX = (#SkinWidth# * 0.14)
NewsHeight = (#SkinHeight# * 0.23)

FeedBoxX = 0.74
FeedBoxY = 0.03
FeedBoxSpacing = 0.05

StoryX = 0.5490
StoryY = 0.85
StorySpacing = 0.05

HoverColorNews= 0,0,255,64
FeedMax=200

;=================================================================
;				METER STYLES
;=================================================================

[StyleFeedBox]
Text=c
FontFace=Webdings
FontSize=(10 * #scale#)
FontColor=255,255,255
X=(#SkinWidth# * #FeedBoxSpacing#)r
Y=(#SkinHeight# * #FeedBoxY#) 
AntiAlias=1
MouseOverAction = [!SetOption #CURRENTSECTION# FontColor #Blue#][!Redraw]
MouseLeaveAction = [!SetOption #CURRENTSECTION# FontColor #White#][!Redraw]
MouseScrollUpAction=[!WriteKeyValue Variables FeedNum [NextFeed] Settings.inc][!Refresh]
MouseScrollDownAction=[!WriteKeyValue Variables FeedNum [PrevFeed] Settings.inc][!Refresh]

[StyleFeedBoxLarge]
Y=r
H = 45
StringAlign = Center
AntiAlias=1

[StyleStoryBox]
Text=c
FontFace=Webdings
FontSize=(10 * #scale#)
FontColor=#Gray#
X=(#SkinWidth# * #StorySpacing#)r
Y=(#SkinHeight# * #StoryY#)
AntiAlias=1
MouseOverAction = [!SetOption #CURRENTSECTION# FontColor #Blue#][!Redraw]
MouseLeaveAction = [!SetOption #CURRENTSECTION# FontColor #Gray#][!Redraw]
MouseScrollUpAction=[!WriteKeyValue Variables CurrentStory [NextStory] DC_News_Variables.inc][!Refresh]
MouseScrollDownAction=[!WriteKeyValue Variables CurrentStory [PrevStory] DC_News_Variables.inc][!Refresh]

[StyleStoryBoxLarge]
Text=c
FontFace=Webdings
FontSize=20
FontColor=#Gray#
X=50r
Y=r
AntiAlias=1
MouseOverAction = [!SetOption #CURRENTSECTION# FontColor #Blue#][!Redraw]
MouseLeaveAction = [!SetOption #CURRENTSECTION# FontColor #Gray#][!Redraw]
MouseScrollUpAction=[!WriteKeyValue Variables CurrentStory [NextStory] DC_News_Variables.inc][!Refresh]
MouseScrollDownAction=[!WriteKeyValue Variables CurrentStory [PrevStory] DC_News_Variables.inc][!Refresh]


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
