[Variables]
@Include1 = #@#style.inc
SkinWidth = (#rightSize# * #scale#)
SkinHeight = (#areaH# * 0.208) 
InputSize = (15 * #scale#)
Settings = #CURRENTPATH#Settings.inc

FolderPath = "D:\Music"
MusicX = 0
MusicHeight = 0
player=winamp
f.color=FFFFFFEE
c.color=FFFFFF99
b.color=FFFFFFFF
Player=WINAMP
StartSong = C:\Users\Andy Banks\Desktop\Andy\Andy Music\N.W.A.\Fuck tha Police.mp3
;StartSong = C:\Users\Andy Banks\Documents\Rainmeter\Skins\DarkClaws\Notes

;WinAmp Mesures

[mWinamp]
Measure=Plugin
Plugin=Plugins\WindowMessagePlugin.dll
WindowClass=Winamp v1.x
Substitute="[Paused]":""," - Winamp":"","[Stopped]":""

[mWinampDuration]
Measure=Calc
Formula=(mWinampCurr<=0)?0:(mWinampCurr/(mWinampFull*1000+1)) 

[mWinampCurr]
Measure=Plugin
Plugin=Plugins\WindowMessagePlugin.dll
WindowClass=Winamp v1.x
WindowMessage=1024 0 105

[mWinampFull]
Measure=Plugin
Plugin=Plugins\WindowMessagePlugin.dll
WindowClass=Winamp v1.x
WindowMessage=1024 1 105

[mWinampCurrMin]
Measure=Calc
Formula=((mWinampCurr / 1000) - ((mWinampCurr / 1000) % 60)) /60

[mWinampCurrSec]
Measure=Calc
Formula=((mWinampCurr / 1000) % 60)/10
Substitute="-":"",".":"","60":"00"

[mWinampFullMin]
Measure=Calc
Formula=(mWinampFull - (mWinampFull % 60)) /60

[mWinampFullSec]
Measure=Calc
Formula=mWinampFull % 60

[mWinampFullZero]
Measure=Calc
Formula=(mWinampFull % 60)  < 10 ? 0 : 1

[WAPlaying]
Measure=Plugin
Plugin=Plugins\WindowMessagePlugin.dll
WindowClass=Winamp v1.x
WindowMessage=1024 0 104
IfEqualAction=!Execute [!RainmeterHideMeter MetPlay][!RainmeterRedraw] [!RainmeterShowMeter MetPause] 
IfEqualValue=1

[WAPlayingP]
Measure=Plugin
Plugin=Plugins\WindowMessagePlugin.dll
WindowClass=Winamp v1.x
WindowMessage=1024 0 104
IfEqualAction=!Execute [!RainmeterHideMeter MetPause][!RainmeterShowMeter MetPlay]
IfEqualValue=3

[WAPlayingS]
Measure=Plugin
Plugin=Plugins\WindowMessagePlugin.dll
WindowClass=Winamp v1.x
WindowMessage=1024 0 104
IfEqualAction=!Execute [!RainmeterHideMeter MetPause][!RainmeterShowMeter MetPlay]
IfEqualValue=0

[MeasureFileBit]
Measure=Plugin
Plugin=Plugins\WindowMessagePlugin.dll
WindowClass=Winamp v1.x
WindowMessage=1024 1 126
UpdateDivider=10