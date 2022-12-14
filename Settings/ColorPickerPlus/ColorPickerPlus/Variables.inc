;///////////////////////////////////////////////////////////////////////////////////////////////////
;                                      ColorPickerPlus Settings
;///////////////////////////////////////////////////////////////////////////////////////////////////

[Variables]
; background
BgAlpha=255
BgStyle=0

; RGB or HSB color selection
scrubberType=RGB

; To incorporate ColorPickerPlus into your suite, you can either change these options directly, or
; you can use !WriteKeyValue bangs from another skin to change these values.
; This value determines the starting color that will be compared to in the color preview
baseColor=255,255,255

; This value determines what will happen when you click the "Save" icon. Color values are accessed
; through inline LUA, using the syntax [&MeasureScript:GetColor('cur_rgb')]. Available colors are:
;   'cur_r', 'cur_g', 'cur_b' - individual rgb components
;   'cur_rgb' - the current RGB string (r,g,b)
;   'cur_hue', 'cur_sat', 'cur_bri' - individual HSB values as floats (0-1)
;   'cur_hsb' - current HSB values as floats (0-1), separated by commas (h,s,l)
;   'disp_hue', 'disp_sat', 'disp_bri' - current HSB values formatted to make sense to humans (degrees for hue, percentage for sat and bri)
;   'disp_hsb' - the previous values formatted into a comma-separated string (deg,%,%)
;   'cur_hex' - the current RGB value in hexadecimal format (FFFFFF)
; There are some other values that you could access, if for some reason you wanted to. To see what
; colors you can retrieve, study the ColorPickerPlus.lua script.
targetConfigGroup=GPUMeter
targetVariable=ColorFontTitle
targetVariablesFile=C:\Documents\Rainmeter\Skins\Gadgets\@Resources\GpuVariables.inc
finishAction=[!WriteKeyValue Variables #targetVariable# "[&MeasureScript:GetColor('cur_rgb')]" "#targetVariablesFile#"][!RefreshGroup #targetConfigGroup#][!DeactivateConfig]
