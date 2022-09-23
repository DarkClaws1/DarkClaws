;MAKING A NEW METER
This code can be used for just about any meter
What you put after Meter= changes the type of Meter

[MeterCHANGEME]
Meter = 
X = (#SkinWidth# * 0.0)
Y = (#SkinHeight# * 0.0)
W = (#SkinWidth# * 0.0)
H = (#SkinHeight# * 0.0)

;====================================
; METERS WITH WORDS AND TEXT
;====================================
[MeterCHANGEME]
Meter = String
MeterStyle = styleText 
X = (#SkinWidth# * 0.0)
Y = (#SkinHeight# * 0.0)
Text = Change This

If you want the text to highlight, use this instead
MeterStyle = styleText | textHighlight

You can ADD  any of these as you need
	;22 by default
	FontSize = 	
	;Light Grey by default
	FontColor = 
	;Center by default
	StringAlign = 

;====================================
; METERS THAT ARE BOXES AND RECTANGLES
;====================================
[MeterCHANGEME]
Meter = Shape
Shape = Rectangle (#SkinWidth# * 0.1), (#SkinHeight# * 0.1), (#SkinWidth# * 0.0), (#SkinHeight# * 0.0) | Fill Color #bgColor# | StrokeWidth #stroke# | Stroke Color #olColor#



Those four numbers are the X, Y, W, and H.




;====================================
; METERS THAT HAVE IMAGES AND PICTURES
;====================================
[MeterCHANGEME]
Meter = Image
ImageName = NameOfTheImage.png
X = (#SkinWidth# * 0.0)
Y = (#SkinHeight# * 0.0)
W = (#SkinWidth# * 0.1)
H = (#SkinHeight# * 0.1)

If the image in is the same folder as the skin
ImageName = NameOfTheImage.png

If the image is in the Resources folder
ImageName = #@#NameOfTheImage.png

If you want to make the image not stretch
PreserveAspectRatio = 1

Color the image, change the 255s
ImageTint = 255,255,255


;====================================
; METERS THAT READ INPUT TO CHANGE A VARIABLE
;====================================
The meter goes in your MAIN skin
Add the variable to Settings.inc under [Variables]
Replace $$$ with the EXACT name of the variable.
Replace the $$$ in the name and in the Text
Capitalization matters!

[$$$]
Meter=String
MeterStyle = styleText | styleInput
X = (#CURRENTCONFIGWIDTH# * 0.0)
Y = (#CURRENTCONFIGHEIGHT# * 0.0)
W = (#CURRENTCONFIGWIDTH# * 0.1)
Text = #$$$#

